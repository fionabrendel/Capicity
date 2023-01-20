#include "Building.h"
#include "Material.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

Building::Building() {
	//Default: besteht nur aus 1 Holz und Label
	label = 'B';
	grundpreis = 30;
	leistung = 10;
}

char Building::getLabel() {
	return label;
}

string Building::getZusammensetzung() {
	string temp = "";
	for (auto& m : zusammensetzung) {
		temp += m.first->toString() + ": ";
		temp += to_string(m.second);
	}
	return temp;
}

int Building::getGesamtpreis() {
	int gesamtpreis = grundpreis;
	for (auto& m : zusammensetzung) {
		for (int i = 0; i < m.second; i++) {
			gesamtpreis += m.first->getPreis();
		}
	}
	return gesamtpreis;
}

//class Leer:
Leer::Leer() {
	grundpreis = 0;
	label = 'O';
	zusammensetzung[new Holz()] = 0;// ({ new Holz(), 0 });
	zusammensetzung.insert({ new Metall(), 0 });
	zusammensetzung.insert({ new Kunststoff(), 0 });
	leistung = 0;
}

//class Wasserkraftwerk:
Wasserkraftwerk::Wasserkraftwerk() {
	grundpreis = 100;
	label = 'W';
	zusammensetzung[new Holz()] = 2; // .insert({ new Holz(), 2 });
	zusammensetzung.insert({ new Metall(), 1 });
	zusammensetzung.insert({ new Kunststoff(), 0 });
	leistung = 20;
}

//class Windkraftwerk:
Windkraftwerk::Windkraftwerk() {
	grundpreis = 70;
	label = 'L';
	zusammensetzung.insert({ new Holz(), 0 });
	zusammensetzung.insert({ new Metall(), 1 });
	zusammensetzung.insert({ new Kunststoff(), 2 });
	leistung = 30;
}

//class Solarpanele:
Solarpanele::Solarpanele() {
	grundpreis = 80;
	label = 'S';
	zusammensetzung.insert({ new Holz(), 0 });
	zusammensetzung.insert({ new Metall(), 1 });
	zusammensetzung.insert({ new Kunststoff(), 1 });
	leistung = 40;
}