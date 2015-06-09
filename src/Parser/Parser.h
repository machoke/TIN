#ifndef PARSERH
#define PARSERH

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <regex.h>
#include <algorithm>

using namespace std;

#define maxSubexpressions 22

enum RuleType{
	Rule_NONE, Rule_QUESTION, Rule_ANSWER, Rule_END, Rule_CONNECTED, Rule_SKIP
};

class RuleStep{
public:
	RuleType type;
	string message;

	regex_t compiled_regex;
	RuleStep();
	void Compile();
	void PrintStep();

	bool isCompiled();
	int getNumSubexpressions();

private:
	bool compiled;
	int iSubexpressions;
};

class Rule{
friend class Parser;
public:
	//Rule();
	//~Rule();
	void AddStep(RuleType type, string message);
	void AddStep(RuleStep step);

	void PrintRule();
	bool AskRule(int stepID, string sentence, size_t nmatch, regmatch_t* pmatch);

	static RuleType AnalizeDirectiveType(string message);
	static string GetDirectiveString(RuleType type);

	void CalculateInnerData();
private:
	vector<RuleStep> steps;
	int iSubexpressions;
};

class Parser{
public:
	Parser(const char* rules_filename);
	~Parser();

	void PrintRules();

	void Ask(string sentence);
	void Respond(string sentence);
	void (*OutsideRespond)(string sentence);
	void Connect();

	void Work();
private:
	vector<Rule> rules;
	queue<string> questions;
	vector<string> subexpressions;

	int RuleStepID, RuleID;

	regmatch_t pmatch[maxSubexpressions];

	bool AreWeInsideRule();
	void FindFirstQuestion();
	void GetSubExpressionsFromQuestion();

	static bool ComparePairsOfSubexpressions(pair<size_t,int> one, pair<size_t, int> two);

};


#endif
