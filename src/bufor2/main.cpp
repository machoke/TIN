#include <iostream>
#include <string>
#include "statement.h"
#include "connectionSettings.h"
#include <fstream>
#include "connection.h"
#include <ctime>
//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
ConnectionSettings conn = ConnectionSettings();
Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);



int main(int argc, char **argv)
{
	pthread_t id_watku, id_watku_2;                   //identyfikator watku
	
	// otwarcie pliku
	std::cout << "hello\n";
	
	std::cout <<  obiekt.size() <<std::endl;

	//nawiazanie polaczenia
	//.............
	
//	pthread_create(&id_watku_2, NULL, konsument, &argument);
	// .....................
//	pthread_join(id_watku, NULL);
//	pthread_join( id_watku_2, NULL);
	
	//----------------------------------------------------------------------------
	
	Connection polaczenie = Connection(SERWER_PORT, SERWER_IP);

	polaczenie.connectC();


	std::fstream fileLog;	// plik z komendami do wysylania
	fileLog.open( "log.txt", std::ios::out );
	if( !fileLog.good() ) {
		std::cout << "Nie utworzono pliku do zapisu" << std::endl;
		exit(1);
	}
	
	std::string test22 = "ad3";
	fileLog << test22;
	std::string tTemp, tText;
	time_t czas = 0;   //czas	ctime(& czas)
	while( 1 )
    {
/*		sleep(2);
		// odczyt z pliku
		if (!fileSt.eof()) {		
			getline(fileSt, tText);
			obiekt.insert(tText);	// wstawienie do bufora
		}
		
		if ( obiekt.size() > 0 ) { //&& (obiekt.getText() != "") ) {			// gdy znajduje sie cos w buforze to wysylam
			time( & czas );	// aktualny czas
			
			fileLog << "W[" << ctime( & czas ) << "][" << "adres_ip" << ":" << "port" << "]" << obiekt.getText() << "\n";
			polaczenie.write( obiekt.getText()); // wyslanie
			obiekt.erase();	// usuniecie z bufora			
		}	
*/		
		std::string tTemp = polaczenie.readC(); // odebranie
		std::cout << tTemp << std::endl;
//		polaczenie.readC(); // odebranie
		time( & czas );
		fileLog << tTemp;
//        fileLog << "O[" << ctime( & czas ) << "][" << "adres_ip" << ":" << "port" << "]" << obiekt.getText() << "\n";
		
    }
    
    polaczenie.close();
	
//	fileSt.close();
	fileLog.close();
	
	//-------------------------------------------------------------------------------
	
	
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