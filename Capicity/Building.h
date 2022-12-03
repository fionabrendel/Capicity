#pragma once
#include "Material.h"

class Building
{
	//Variablen
	int grundpreis;
	char label; //soll bei Ausdrucken des Plans abgebildet werden
	Material* zusammensetzung; //soll ein Feld für Materialien werden

	//Konstruktoren
	Building();
};

