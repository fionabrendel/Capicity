#pragma once
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
		enum gebaeudetype { empty, TYP1, TYP2, TYP3 };
		gebaeudetype** bereich;

		//Konstruktor:
		CapicitySim();
		CapicitySim(int bbreite, int bhoehe);
		//Methoden
		bool checkKollision(int posx, int posy, int breite, int hoehe);
		void placeBuilding();
		void deleteArea();
		void printPlan();
		void stop();
		void showMenu();
};

