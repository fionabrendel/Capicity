#include "CapicitySim.h"
#include "Building.h"
#include <iostream>
using namespace std;
using namespace Sim;

//Konstruktor
CapicitySim::CapicitySim() {
    bbreite = 10;
    bhoehe = 10;
    running = true;
    bereich = new Building ** [bhoehe];
    for (int i = 0; i < bhoehe; i++)
    {
        bereich[i] = new Building*[bbreite];
    }

    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; j < bbreite; j++) {
            bereich[i][j] = new Leer();
        }
    }
    while (running)
    {
        showMenu();
    }
}

CapicitySim::CapicitySim(int bbreite, int bhoehe) {
	//hier soll die Area erstellt und das Menü gestartet werden
	running = true;
	this->bbreite = bbreite;
	this->bhoehe = bhoehe;

	bereich = new Building ** [bhoehe];
	for (int i = 0; i < bhoehe; i++)
	{
		bereich[i] = new Building*[bbreite];
	}

	for (int i = 0; i < bhoehe; i++) {
		for (int j = 0; j < bbreite; j++) {
				bereich[i][j] = new Leer();
		}
	}
	while (running)
	{
		showMenu();
	}
}

//Methoden
//prüft beim Bau eines Gebäudes auf Kollisionen mit andern, bzw ob außerhalb des Bereichs
bool CapicitySim::checkKollision(int posx, int posy, int breite, int hoehe) {
	//außerhalb des Bereichs?
	if (posy >= bhoehe || posx >= bbreite || hoehe + posy >= bhoehe || breite + posx >= bbreite) {
		return false;
	}
	//Kollision mit anderem Gebäude?
	for (int i = posy; i < posy + hoehe; i++) {
		for (int j = posx; j < posx + breite; j++) {
			if (bereich[i][j] != 0)
				return false;
		}
	}
	return true;
}

//plaziert ein Gebäude im Bereich
void CapicitySim::placeBuilding() {
    cout << "Welche Art von Gebaeude? 1: Wasserkraftwerk, 2: Windkraftwerk, 3: Solarpanele" << endl;;
    cin >> input; //dann steht in input, welcher Gebäudetyp es sein soll
    cout << "Position x:";
    cin >> posx;
    cout << "Position y:";
    cin >> posy;
    cout << "Hoehe:";
    cin >> hoehe;
    cout << "Breite:";
    cin >> breite;
    if (posx < 0 || posy < 0 || hoehe < 0 || breite < 0) {
        cout << "Ungueltige Eingabe" << endl;
        return;
    }
    if (checkKollision(hoehe, breite, posx, posy))
    {
        switch (input)
        {
        case 1:
                for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Wasserkraftwerk();
                    }
                }
                cout << "Gebaeude wurde plaziert" << endl;
                break;
        case 2: for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Windkraftwerk();
                    }
                }
                cout << "Gebaeude wurde plaziert" << endl;
                break;
        case 3: for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Wasserkraftwerk();
                    }
                }
                cout << "Gebaeude wurde plaziert" << endl;
                break;
        default:
            cout << "Ungueltiger Gebaeudetyp" << endl;
            return;
        }
    }
    else {
        cout << "Gebaeude kann nicht plaziert werden" << endl;
    }
}

//löscht einen Bereich
void CapicitySim::deleteArea() {
    cout << "Position x:";
    cin >> posx;
    cout << "Position y:";
    cin >> posy;
    cout << "Breite nach rechts:";
    cin >> hoehe;
    cout << "Hoehe nach unten y:";
    cin >> breite;

    if (posx < 0 || posy < 0 || hoehe < 0 || breite < 0) {
        cout << "Ungueltige Eingabe" << endl;
        return;
    }

    if (posx < bbreite && posy < bhoehe && posx + breite < bbreite && posy + hoehe < bhoehe) {
        for (int i = posy; i < posy + hoehe; i++) {
            for (int j = posx; j < posx + breite; j++) {
                bereich[i][j] = new Leer();
            }
        }
    }
    else {
        cout << "Position außerhalb des Bereichs" << endl;
    }
}

//gibt den Bauplan und weitere Informationen aus
void CapicitySim::printPlan() {
    //Plan ausgeben
    for (int i = 0; i < bbreite; i++)
    {
        for (int j = 0; j < bhoehe; j++)
        {
            cout << bereich[i][j] << " ";
        }
        cout << endl;
    }

    //Auflistung Gebäude + Zusammensetzung + Grundpreis
    //Wasserkraftwerk:
    Wasserkraftwerk w1;
    cout << "Wasserkraftwerk: " << endl;
    cout << w1.toString() << endl;
    //Windkraftwerk
    Windkraftwerk w2;
    cout << "Windkraftwerk: " << endl;
    cout << w2.toString() << endl;
    //Solarpanele
    Solarpanele s3;
    cout << "Solarpanele: " << endl;
    cout << s3.toString() << endl;
    //Gesamtpreis aller Gebäude
}

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
        placeBuilding();
        break;
    case 2:
        deleteArea();
        break;
    case 3:
        printPlan();
        break;
    case 4:
        stop();
        break;
    default:
        cout << "Fehlerhafte Eingabe!" << endl;
        break;
    }
}
