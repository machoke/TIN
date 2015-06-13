#include <iostream>
#include <string>
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include <pthread.h>
#include <sstream>
#include <signal.h>
#include "Parser/Parser.h"

pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
std::queue<string> CommandBuffor;

Connection* PolaczenieDoWysylki;
Parser* parser;
int CyklicznyCzas;

fstream plikLogow;

bool printLogs = false;


void wyslij(string wiadomosc){
	if(printLogs)
		std::cout << "SEND: " << wiadomosc << endl;
	plikLogow << "W[" << PolaczenieDoWysylki->getIP() << ":" << PolaczenieDoWysylki->getPort() << "] " << wiadomosc << endl;
	PolaczenieDoWysylki->write(wiadomosc);
}

void* CommunicationThread(void *ptr){
	string odczyt;
	while(1){
		if(!CommandBuffor.empty()){
			pthread_mutex_lock(&bufferMutex);
			while(!CommandBuffor.empty()){
				wyslij(CommandBuffor.front());
				CommandBuffor.pop();

			}
			pthread_mutex_unlock(&bufferMutex);
		}
		odczyt = PolaczenieDoWysylki->read();
		if(!odczyt.empty()){
			if(printLogs)
				std::cout << "RECEIVED: " << odczyt << endl;
			plikLogow << "O[" << PolaczenieDoWysylki->getIP() << ":" << PolaczenieDoWysylki->getPort() << "] " << odczyt << endl;
			parser->Ask(odczyt);
		}
	}
}

void Zegar(int a){
	parser->Cyclic();
	alarm(CyklicznyCzas);
}

int main(int argc, char **argv)
{
	pthread_t commThread;
	
	ConnectionSettings *conn;
	if(argc == 2)
		conn = new ConnectionSettings(argv[1]);
	else
		conn = new ConnectionSettings("conf_server.ini");
	Connection polaczenie = Connection(conn->port, conn->addressIP);

	plikLogow.open(conn->logFile.c_str(), ios::out|ios::app);

	
	polaczenie.bindS();
	polaczenie.listenS();
	polaczenie.acceptS();

	std::cout << "Connected!" << std::endl;
	plikLogow << "CONNECTED"<< endl;

	parser = new Parser(conn->rulesFile.c_str());
	PolaczenieDoWysylki = &polaczenie;
	parser->OutsideRespond = wyslij;

	parser->Connect();

	CyklicznyCzas = parser->getCyclicTime();
	signal(SIGALRM, Zegar);
	alarm(CyklicznyCzas);

	std::string tTemp, tText;
	time_t czas = 0;

	int thread_test = pthread_create( &commThread, NULL, CommunicationThread, 0);

	string command, interpret_cmd;

	cout << "SHOW MODE!" << endl;
	printLogs = true;
	std::cin.ignore();
	cout << "COMMAND MODE!" << endl;
	printLogs = false;

	delete conn;
	while( 1 )
    {
		getline(std::cin,command);
		stringstream stream(command);
		stream >> interpret_cmd;

		if(interpret_cmd.compare("send")==0){
			pthread_mutex_lock(&bufferMutex);
			CommandBuffor.push(command.substr(5, std::string::npos));
			pthread_mutex_unlock(&bufferMutex);
		}else
		if(interpret_cmd.compare("exit")==0){
			pthread_cancel(commThread);
			break;
		}else
		if(interpret_cmd.compare("debugrules")==0){
			cout << "PRINTING PARSED RULES!" << endl;
			parser->PrintRules();
		}else
		if(interpret_cmd.compare("help")==0){
			cout << "TIN - PROJECT, help:\nAll server commands must be written lowercase.\n\n";
			cout << "help - show this message\n";
			cout << "send <message> - send some message, doesn't initiate a rule at server\n";
			cout << "debugrules - print all parser rules by server\n";
			cout << "show - enter show mode, when you can watch all the traffic that your server is making and receiving. Enter to returtn to command mode.\n";
			cout << "exit - quit the program\n" << endl;
		}else
		if(interpret_cmd.compare("show")==0){
			cout << "SHOW MODE!\nPress ENTER TO GO TO COMMAND MODE!" << endl;
			printLogs = true;
			std::cin.ignore();
			cout << "COMMAND MODE!" << endl;
			printLogs = false;
		}
		interpret_cmd = "";
		command = "";
    }
    
    pthread_mutex_destroy(&bufferMutex);
    polaczenie.close();	
    cout << "CLOSING!" << endl;
    
    plikLogow.close();

	return 0;
}


