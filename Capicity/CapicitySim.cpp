#include "CapicitySim.h"
#include "Building.h"
#include "Blueprint.h"
#include <iostream>
using namespace std;
using namespace Sim;

//Konstruktor
CapicitySim::CapicitySim() {
    running = true;
    //ersten Plan hier erstellen
    while (running)
    {
        showMenu();
    }
}

CapicitySim::CapicitySim(int bbreite, int bhoehe) {
	//hier soll die Area erstellt und das Menü gestartet werden
	running = true;
    //neuen Plan hier erstellen
	while (running)
	{
		showMenu();
	}
}

//Methoden


//beendet das Programm
void CapicitySim::stop() {
    cout << "Programm wird beendet" << endl;
    running = false;
}

//zeigt ein Menü an, mit dem die Funktionen aufgerufen werden können
void CapicitySim::showMenu() {
    cout << "-----------------------" << endl;
    cout << "Waehle eine Aktion:" << endl;
    cout << "1: Gebaeude setzen" << endl;
    cout << "2: Bereich loeschen" << endl;
    cout << "3: Bauplan ausgeben" << endl;
    cout << "4: Programm beenden" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        //placeBuilding();
        break;
    case 2:
        //deleteArea();
        break;
    case 3:
        //printPlan();
        break;
    case 4:
        stop();
        break;
    default:
        cout << "Fehlerhafte Eingabe!" << endl;
        break;
    }
}
