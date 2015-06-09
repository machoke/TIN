
#include "Parser.h"
#include <iostream>
using namespace std;

void Respond(string sentence){
	cout << "RESPOND: " << sentence << endl;
}

int main() {
	Parser parser("rules.txt");
	parser.OutsideRespond = Respond;

	parser.PrintRules();

	string question;

	parser.Connect();
	while(true){
		getline(cin, question);
		if(question.compare("exit")==0)
			break;
		parser.Ask(question);
	}

	return 0;
}
