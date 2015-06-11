#include "Parser.h"

void RuleStep::PrintStep(){
	if(type == Rule_END)
		cout << Rule::GetDirectiveString(type) << '.' << endl;
	else
		cout << Rule::GetDirectiveString(type) << ':' << message << endl;
}

void Rule::PrintRule(){
	vector<RuleStep>::iterator step = steps.begin();
	while(step != steps.end()){
		step->PrintStep();
		step++;
	}
}

RuleStep::RuleStep(){
	type = Rule_NONE;
	message = "";
}

RuleType Rule::AnalizeDirectiveType(string message){
	if(message.compare("QUESTION:")==0){
		return Rule_QUESTION;
	}
	if(message.compare("ANSWER:")==0){
		return Rule_ANSWER;
	}
	if(message.compare("END.")==0){
		return Rule_END;
	}
	if(message.compare("CONNECTED:")==0){
		return Rule_CONNECTED;
	}
	if(message.compare("SKIP:")==0){
		return Rule_SKIP;
	}
	if(message.compare("WAIT:")==0){
		return Rule_WAIT;
	}
	if(message.compare("CYCLIC:")==0){
		return Rule_CYCLIC;
	}
	return Rule_NONE;
}

string Rule::GetDirectiveString(RuleType type){
	switch(type){
	case Rule_QUESTION:
		return "QUESTION";
	case Rule_ANSWER:
		return "ANSWER";
	case Rule_END:
		return "END";
	case Rule_CONNECTED:
		return "CONNECTED";
	case Rule_SKIP:
		return "SKIP";
	case Rule_WAIT:
		return "WAIT";
	case Rule_CYCLIC:
		return "CYCLIC";
	}
}


void Parser::PrintRules(){
	for(unsigned int i = 0; i < rules.size(); i++){
		cout << "Rule id=" << i << endl;
		rules[i].PrintRule();
		cout << endl;
	}
}
