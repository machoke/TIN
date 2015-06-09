#include "Parser.h"

void RuleStep::Compile(){
	int result = regcomp(&compiled_regex, message.c_str(), REG_EXTENDED);
	if(result == 0){
		compiled = true;
		iSubexpressions = compiled_regex.re_nsub;
	}else{
		cout << "ERROR COMPILACJI REGEXA!" << endl;
		compiled = false;
		iSubexpressions = 0;
	}
}

bool RuleStep::isCompiled(){
	return compiled;
}
int RuleStep::getNumSubexpressions(){
	return iSubexpressions;
}

void Rule::AddStep(RuleStep step){
	step.Compile();
	steps.push_back(step);
}

Parser::Parser(const char* rules_filename){
	RuleID = -1;
	RuleStepID = -1;
	fstream file;
	bool one_connected_rule = false;
	bool drop_current = false;
	bool first_line_of_message = true;
	file.open(rules_filename);
	//rules.clear();

	string line;
	vector<Rule>::iterator rule = rules.begin();
	RuleStep step;
	int line_index = 0;

	while(!file.eof()){
		line_index++;
		getline(file,line);
		RuleType AnalizedType = Rule::AnalizeDirectiveType(line);
		if(AnalizedType != Rule_NONE){
			if(rule != rules.end()){
				rule->AddStep(step);
				step.type = AnalizedType;
				step.message = "";
				first_line_of_message = true;
				if(AnalizedType == Rule_END){
					rule->AddStep(step);
					if(drop_current){
						rule = rules.erase(rule);
						drop_current = false;
					}else{
						rule->CalculateInnerData();
						rule++;
					}
					step.type = Rule_NONE;
				}else
				if(AnalizedType == Rule_CONNECTED){
					cout << "PARSING WARNING, line " << line_index << ": ";
					cout << Rule::GetDirectiveString(AnalizedType);
					cout <<" can be only at the beginning of the rule!" << endl;
					cout << "Interpreted as ANSWER!" << endl;
					step.type = Rule_ANSWER;
				}
			}else{
				Rule r;
				rules.push_back(r);
				rule = rules.end() - 1;
				step.type = AnalizedType;
				step.message = "";
				first_line_of_message = true;
				switch(AnalizedType){
				case Rule_CONNECTED:
					if(one_connected_rule){
						cout << "PARSING WARNING, line " << line_index << ": ";
						cout << Rule::GetDirectiveString(AnalizedType);
						cout << " found more than one time! Ignoring!" << endl;
						drop_current = true;
					}
					one_connected_rule = true;
					break;
				case Rule_END:
				case Rule_ANSWER:
					cout << "PARSING WARNING, line " << line_index << ": ";
					cout << Rule::GetDirectiveString(AnalizedType);
					cout << " can't be the first one! Ignoring!" << endl;
					if(AnalizedType==Rule_END){
						rule = rules.erase(rule);
						step.type = Rule_NONE;
					}else
						drop_current = true;
					break;
				}
			}
		}else{
			if(step.type != Rule_NONE){
				if(first_line_of_message){
					first_line_of_message = false;
				}else
					step.message += '\n';
				step.message += line;
			}
		}
	}

	file.close();
}

Parser::~Parser(){

}

void Parser::Ask(string sentence){
	questions.push(sentence);
	Work();
}

void Parser::Respond(string sentence){
	size_t pos;
	int i = 0;
	int len = 1;
	int lenLimit = 10;
	int size = subexpressions.size();
	while(size >= lenLimit){
		len++;
		lenLimit *= 10;
	}
	char* tag = new char[3+len];
	vector<pair<size_t, int> > changes;
	for(vector<string>::iterator it = subexpressions.begin(); it != subexpressions.end(); it++){
		sprintf(tag, "<%d>", i);
		pos = sentence.find(tag);
		while(pos != string::npos){
			changes.push_back(make_pair(pos, i));
			pos = sentence.find(tag, pos+1);
		}
		i++;
	}

	sort(changes.begin(), changes.end(), Parser::ComparePairsOfSubexpressions);

	len = 3;
	lenLimit = 10;
	for(vector<pair<size_t, int> >::iterator it = changes.begin(); it != changes.end(); it++){
		if(len >= lenLimit){
			len++;
			lenLimit*= 10;
		}
		sentence.replace(it->first, len, subexpressions[it->second]);
	}
	OutsideRespond(sentence);
	delete[] tag;
}


void Parser::Connect(){
	for(unsigned int i = 0; i < rules.size(); i++){
		if(rules[i].steps[0].type == Rule_CONNECTED){
			cout << "CONNECTED found in rule!" << endl;
			RuleID = i;
			RuleStepID = 0;
			subexpressions.clear();
			Work();
			return;
		}
	}
}

void Parser::Work(){
	if(AreWeInsideRule()){
		Rule* rule = &rules[RuleID];
		RuleStep* step = &rules[RuleID].steps[RuleStepID];
		switch(step->type){
		case Rule_QUESTION:
			if(questions.empty())
				return;
			if(rule->AskRule(RuleStepID, questions.front(), maxSubexpressions, pmatch)){
				GetSubExpressionsFromQuestion();
				questions.pop();
				break;
			}else{
				if(RuleStepID == 0){
					questions.pop();
				}else{
					cout << "Wrong question! Searching again!" << endl;
				}
				RuleID = -1;
				RuleStepID = -1;
				Work();
				return;
			}
		case Rule_ANSWER:
		case Rule_CONNECTED:
			Respond(step->message);
			break;
		case Rule_SKIP:
			if(questions.empty())
				return;
			questions.pop();
			break;

		case Rule_END:
			cout << "END of rule!" << endl;
		default:
			RuleID = -1;
			RuleStepID = -1;
			Work();
			return;
		}
		RuleStepID++;
		Work();
		return;
	}else{
		if(!questions.empty()){
			FindFirstQuestion();
			Work();
		}
		return;
	}
}

bool Parser::AreWeInsideRule(){
	if(RuleID < 0 || RuleID >= rules.size())
		return false;
	if(RuleStepID < 0 && RuleStepID >= rules[RuleID].steps.size())
		return false;
	return true;
}

void Parser::FindFirstQuestion(){
	for(unsigned int i = 0; i < rules.size(); i++){
		if(rules[i].AskRule(0, questions.front(), maxSubexpressions, pmatch)){
			cout << Rule::GetDirectiveString(rules[i].steps[0].type);
			cout << " found in rule! id=" << i << endl;
			RuleID = i;
			RuleStepID = 0;
			subexpressions.clear();
			return;
		}
	}
	questions.pop();
}

void Parser::GetSubExpressionsFromQuestion(){
	for(int i = 0; i < maxSubexpressions; i++){
		if(pmatch[i].rm_so < 0)
			return;
		subexpressions.push_back(questions.front().substr(pmatch[i].rm_so, pmatch[i].rm_eo - pmatch[i].rm_so));
	}
}

bool Parser::ComparePairsOfSubexpressions(pair<size_t,int> one, pair<size_t, int> two){
	return one.first > two.first;
}

bool Rule::AskRule(int stepID, string sentence, size_t nmatch, regmatch_t* pmatch){
	if(stepID >= steps.size())
		return false;
	if(stepID < 0)
		return false;
	RuleStep* step = &steps[stepID];
	if(step->type == Rule_SKIP)
		return true;
	if(step->type != Rule_QUESTION)
		return false;

	if(step->isCompiled()){
		if(regexec(&step->compiled_regex, sentence.c_str(), nmatch, pmatch, 0)==0){
			return true;
		}
	}else{
		if(step->message.compare(sentence)==0)
			return true;
	}
	return false;
}

void Rule::CalculateInnerData(){
	iSubexpressions = 0;
	for(unsigned int i = 0; i < steps.size(); i++){
		iSubexpressions += steps[i].getNumSubexpressions();
	}
}
