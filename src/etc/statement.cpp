#include <iostream>
#include "statement.h"

Statement::Statement() {
	//messageList.push_back("null");
	;
}

Statement::Statement(std::string nText) {
	messageList.push_back(nText);
}

Statement::~Statement() {
	messageList.clear();
}
//wyswietlamy 
std::string Statement::getText() {
	return messageList.front();
}

//wstawiamiy na koniec
void Statement::insert(std::string nText) {
	messageList.push_back(nText);
}

int Statement::size() {
	return messageList.size();
}

void Statement::erase() {
	messageList.pop_back();
	//std::cout << "elemnt z przodu zostal usuniety\n";
}