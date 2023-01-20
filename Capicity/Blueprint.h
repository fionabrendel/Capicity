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

	//Konstruktor:
	Blueprint();
	Blueprint(int bbreite, int bhoehe);

	//Methoden:
	bool checkKollision(int posx, int posy, int breite, int hoehe);
	void placeBuilding();
	void deleteArea();
	void printPlan();
	int calcKennzahl();
	void calcGebaeude();
	bool checkIdentity();

private:
	Building*** bereich;
	int calcGesamtpreis();
};

