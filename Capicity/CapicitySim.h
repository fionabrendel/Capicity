#pragma once
#include "Building.h"

namespace Sim {
	class CapicitySim
	{
	public:
		//Variablen
		bool running;
		int input;
		int bbreite;
		int bhoehe;
		int posx;
		int posy;
		int breite;
		int hoehe;

		//Konstruktor:
		CapicitySim();
		CapicitySim(int bbreite, int bhoehe);

		//Destruktor
		~CapicitySim();

		//Methoden
		bool checkKollision(int posx, int posy, int breite, int hoehe);
		void placeBuilding();
		void deleteArea();
		void printPlan();
		void stop();
		void showMenu();

	private:
		Building ***bereich;
	};
}

