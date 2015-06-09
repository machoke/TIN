#include <string>
#include <list>

class Statement {
	std::list <std::string> messageList;
public:
	Statement();
	Statement(std::string nText);
	~Statement();
	std::string getText();
	void insert(std::string nText);
	int size();
	void erase();
};