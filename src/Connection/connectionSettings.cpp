#include "connectionSettings.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

ConnectionSettings::ConnectionSettings(std::string nameFile) {
		readSettings(nameFile);
	};

void ConnectionSettings::readSettings(std::string nameFile) {
	
	std::fstream fileConf;	// plik z konfiguracją
	fileConf.open( nameFile.c_str(), std::ios::in );
	//otwieram plik z komendami do wyswietlenia
	if( !fileConf.good() ) {
		std::cout << "Nie otwarto pliku z wlasciwosciami" << std::endl;
		exit(1);
	}
	
	std::string tText;
	getline(fileConf, tText);
	getline(fileConf, tText);
	getline(fileConf, tText);

	getline(fileConf, tText);
	getline(fileConf, tText);
	port = atoi(tText.c_str());

	getline(fileConf, tText);
	getline(fileConf, tText);
	addressIP=tText;

	getline(fileConf, tText);
	getline(fileConf, tText);
	logFile=tText;


	
	fileConf.close();

}
