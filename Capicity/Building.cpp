#include "Building.h"
#include "Material.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"
#include <string>
using namespace std;

Building::Building() {
	//Default: besteht nur aus 1 Holz und Label
	label = 'B';
	zusammensetzung = { Holz() , Holz(), Holz()};
	grundpreis = 30;
}

Building::~Building() {
	//TO DO: alles deleten
}
char Building::getLabel() {
	return label;
}

string Building::getZusammensetzung() {
	string temp = "";
	for (int i = 0; i < zusammensetzung.size(); i++) {
		temp += zusammensetzung.at(i).getName()+ ' ';
	}
	return temp;
}

int Building::getGrundpreis() {
	return grundpreis;
}

string Building::toString() {
	return getLabel() + " " + getGrundpreis() + ' ' + getZusammensetzung();
}

//class Leer:
Leer::Leer() {
	grundpreis = 0;
	label = 'O';
	zusammensetzung = {};
}

//class Wasserkraftwerk:
Wasserkraftwerk::Wasserkraftwerk() {
	grundpreis = 100;
	label = 'W';
	zusammensetzung = { Holz(), Holz(), Metall() };
}

Wasserkraftwerk::~Wasserkraftwerk() {
	
}

//class Windkraftwerk:
Windkraftwerk::Windkraftwerk() {
	grundpreis = 70;
	label = 'L';
	zusammensetzung = { Kunststoff(), Kunststoff(), Metall()};
}

Windkraftwerk::~Windkraftwerk() {

}

//class Solarpanele:
Solarpanele::Solarpanele() {
	grundpreis = 80;
	label = 'S';
	zusammensetzung = { Kunststoff(), Metall() };
}

Solarpanele::~Solarpanele() {

}