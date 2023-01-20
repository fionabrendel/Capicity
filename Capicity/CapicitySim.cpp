#include "CapicitySim.h"
#include "Building.h"
#include "Blueprint.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace Sim;

//Konstruktor
CapicitySim::CapicitySim() {
    running = true;
    plans.push_back(new Blueprint(10, 10));
    while (running)
    {
        showMenu();
    }
}

CapicitySim::CapicitySim(int bbreite, int bhoehe) {
	//hier soll die Area erstellt und das Men� gestartet werden
	running = true;
    plans.push_back(new Blueprint(bbreite, bhoehe));
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

//erstellt einen neuen Plan
void CapicitySim::createPlan() {
    int bbreite = 0;
    int bhoehe = 0;
    cout << "Breite des Plans:" << endl;
    cin >> bbreite;
    cout << "Hoehe des Plans: " << endl;
    cin >> bhoehe;
    plans.push_back(new Blueprint(bbreite, bhoehe));
}

//zeigt ein Men� an, mit dem die Funktionen aufgerufen werden k�nnen
void CapicitySim::showMenu() {
    cout << "-----------------------" << endl;
    cout << "Waehle eine Aktion:" << endl;
    cout << "1: Gebaeude setzen im aktuellen Plan" << endl;
    cout << "2: Bereich loeschen im aktuellen Plan" << endl;
    cout << "3: Bauplan ausgeben" << endl;
    cout << "4: Alle Pl�ne ausgeben" << endl;
    cout << "5: Neuen Bauplan erstellen und aktuellen abspeichern" << endl;
    cout << "6: Programm beenden" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        plans.back()->placeBuilding();
        break;
    case 2:
        plans.back()->deleteArea();
        break;
    case 3:
        plans.back()->printPlan();
        break;
    case 4:
        //print all plans--> Vektor durchlaufen
        //sortieren nach Kennzahlen mit Lambda Ausdruck
        break;
    case 5:
        
        //aktuellen auf Gleichheit pr�fen
        if (plans.back()->checkIdentity()) {
            //wenn gleicher existiert delete
            cout << "Aktueller Plan gleicht einem alten. Keine Speicherung m�glich" << endl;
            cout << "Neuer Plan wird erstellt" << endl;
        }
        else{
            cout << "Alter Plan wird gespeichert und neuer erstellt" << endl;
        }
        createPlan();
        break;
    case 6:
        stop();
        break;
    default:
        cout << "Fehlerhafte Eingabe!" << endl;
        break;
    }
}
