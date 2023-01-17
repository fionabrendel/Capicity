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

char Building::getLabel() {
	return label;
}

string Building::getZusammensetzung() {
	//Hart reinschreiben
	string temp = "";
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

//class Windkraftwerk:
Windkraftwerk::Windkraftwerk() {
	grundpreis = 70;
	label = 'L';
	zusammensetzung = { Kunststoff(), Kunststoff(), Metall()};
}

//class Solarpanele:
Solarpanele::Solarpanele() {
	grundpreis = 80;
	label = 'S';
	zusammensetzung = { Kunststoff(), Metall() };
}