#include <string>

class ConnectionSettings {
public:

	int port;
	std::string addressIP;
	std::string logFile;

	ConnectionSettings() {
		port = 8888; addressIP="127.0.0.1"; logFile="/res/log.txt";
	};
	ConnectionSettings(std::string nameFile);
	~ConnectionSettings() {};
	void readSettings(std::string nameFile);
};
