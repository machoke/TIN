#include <iostream>
#include <string>
#include "etc/statement.h"
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include <vector>

#include "Parser/Parser.h"


//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;

Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);
std::vector <std::string> openConf();

Connection* PolaczenieDoWysylki;


void wyslij(string wiadomosc){
	std::cout << "WYSLANO: " << wiadomosc << endl;
	PolaczenieDoWysylki->write(wiadomosc);
}

int main(int argc, char **argv)
{
	
	// na sztywno ustawione conf.ini w funkcji readSettings()
	ConnectionSettings conn = ConnectionSettings("conf.ini");
	Connection polaczenie = Connection(SERWER_PORT, SERWER_IP);
	
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
	
	std::cout << "Polaczono!" << std::endl;

	Parser parser("rules.txt");
	PolaczenieDoWysylki = &polaczenie;
	parser.OutsideRespond = wyslij;

	parser.Connect();

	std::string tTemp, tText;
	time_t czas = 0;
	while( 1 )
    {
		//Poniższe read jest nieblokujące. Tak chyba powinno być.
		string odczyt = polaczenie.read();
		if(odczyt.empty()){
			sleep(1);
		}else{
			std::cout << "OTRZYMANO: " << odczyt << endl;
			//Poniższa operacja wykonuje reguły do oporu i wysyła w między czasie dane przez
			//OutsideRespond() do zatrzymania. Tak chyba powinno być.
			parser.Ask(odczyt);
		}
    }
    
    polaczenie.close();	
	fileLog.close();

	return 0;
}




/*

void* watekPierwszy( void *_argum) {
	//string odczytanyKomunikat = odczytaniezPliku();
	std::string odczytanyKomunikat = "test";
	
	while (1) {
	
//	pthread_mutex_lock(&bufferMutex);
//	obiekt.setText(odczytanyKomunikat);	// wstawienie do bufora komunikatow z pliku
//	pthread_mutex_unlock(&bufferMutex);
	
	
	
	std::cout << "test nr. : ";
	
	
	// wyslanie zapis do pliku
	//odebranie polaczenia
	//zapis do pliku
	
	}
//pthread_exit(NULL);
 // return 0;
}

/*
/*
void* watekDrugi(void *_argum) {
	// odczyt z klawiatury
	
	// ewentualnhy zapis do kolejki
//	pthread_mutex_lock(&bufferMutex);
//	obiekt.setText(odczytanyKomunikat);	// wstawienie do bufora komunikatow z pliku
//	pthread_mutex_unlock(&bufferMutex);
 * 
 * 
	
pthread_exit(NULL);
 // return 0;
}

*/
