class ConnectionSettings {
	int port;
	std::string addressIP;
	std::string logFile;
public:
	ConnectionSettings() {
		port = 2341; addressIP="192.168.1.100"; logFile="/res/log.txt";
	};
	ConnectionSettings(std::string configFile);
	~ConnectionSettings() {};
	void readSettings();	
};