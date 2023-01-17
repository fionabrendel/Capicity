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
	zusammensetzung[Holz()] = 3;
	zusammensetzung[Metall()] = 0;
	zusammensetzung[Kunststoff()] = 0;
	grundpreis = 30;
}

char Building::getLabel() {
	return label;
}

string Building::getZusammensetzung() {
	return "";
}

int Building::getGrundpreis() {
	return grundpreis;
}

//class Leer:
Leer::Leer() {
	grundpreis = 0;
	label = 'O';
	zusammensetzung[Holz()] = 0;
	zusammensetzung[Metall()] = 0;
	zusammensetzung[Kunststoff()] = 0;
}

//class Wasserkraftwerk:
Wasserkraftwerk::Wasserkraftwerk() {
	grundpreis = 100;
	label = 'W';
	//zusammensetzung = { Holz(), Holz(), Metall();
	zusammensetzung[Holz()] = 2;
	zusammensetzung[Metall()] = 1;
	zusammensetzung[Kunststoff()] = 0;
}

//class Windkraftwerk:
Windkraftwerk::Windkraftwerk() {
	grundpreis = 70;
	label = 'L';
	zusammensetzung[Holz()] = 0;
	zusammensetzung[Metall()] = 1;
	zusammensetzung[Kunststoff()] = 2;
}

//class Solarpanele:
Solarpanele::Solarpanele() {
	grundpreis = 80;
	label = 'S';
	zusammensetzung[Holz()] = 0;
	zusammensetzung[Metall()] = 1;
	zusammensetzung[Kunststoff()] = 1;
}