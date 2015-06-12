#include <iostream>
#include <string>
#include "etc/statement.h"
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include <vector>
#include <pthread.h>
#include <sstream>

#include "Parser/Parser.h"


//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
std::queue<string> CommandBuffor;

Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);
std::vector <std::string> openConf();

Connection* PolaczenieDoWysylki;
Parser* parser;

fstream plikLogow;

bool printLogs = false;


void wyslij(string wiadomosc){
	if(printLogs)
		std::cout << "WYSLANO: " << wiadomosc << endl;
	plikLogow << "W:" << wiadomosc << endl;
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
				std::cout << "ODEBRANO: " << odczyt << endl;
			plikLogow << "O:" << odczyt << endl;
			parser->Ask(odczyt);
		}
	}
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

	plikLogow.open(conn->logFile.c_str(), ios::out);

	
	polaczenie.bindS();
	polaczenie.listenS();
	polaczenie.acceptS();
	
	std::fstream fileLog;	// plik logów
	fileLog.open( "log.txt", std::ios::out );
	//otwieram plik z logami
	if( !fileLog.good() ) {
		std::cout << "Nie utworzono pliku do zapisu" << std::endl;
		exit(1);
	}
	
	std::cout << "Connected!" << std::endl;

	parser = new Parser(conn->rulesFile.c_str());
	PolaczenieDoWysylki = &polaczenie;
	parser->OutsideRespond = wyslij;

	parser->Connect();

	std::string tTemp, tText;
	time_t czas = 0;

	int thread_test = pthread_create( &commThread, NULL, CommunicationThread, 0);

	string command, interpret_cmd;

	cout << "LOGI NA EKRAN!" << endl;
	printLogs = true;
	std::cin.ignore();
	cout << "TRYB KOMEND!" << endl;
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
				if(interpret_cmd.compare("show")==0){
					cout << "LOGI NA EKRAN!" << endl;
					printLogs = true;
					std::cin.ignore();
					cout << "TRYB KOMEND!" << endl;
					printLogs = false;
				}
		interpret_cmd = "";
		command = "";
    }
    
    pthread_mutex_destroy(&bufferMutex);
    polaczenie.close();	
    cout << "ZAMYKAM!" << endl;
	fileLog.close();

	return 0;
}


