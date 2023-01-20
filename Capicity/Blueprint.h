#pragma once
#include "Building.h"

class Blueprint
{
public:
	//Variablen:
	int bbreite;
	int bhoehe;
	int posx;
	int posy;
	int breite;
	int hoehe;
	int gesamtpreis;
	int input;
	int kennzahl;
	int countWasser;
	int countWind;
	int countSolar;
	Wasserkraftwerk* w1;
	Windkraftwerk* w2;
	Solarpanele* s1;

	//Konstruktor:
	Blueprint();
	Blueprint(int bbreite, int bhoehe);

	//Funktor:
	bool operator ==(Blueprint b);

	//Methoden:
	bool checkKollision(int posx, int posy, int breite, int hoehe);
	void placeBuilding();
	void deleteArea();
	void printPlan();
	int calcKennzahl();
	void calcGebaeude();

private:
	Building*** bereich;
	int calcGesamtpreis();
};

