#include "CapicitySim.h"
#include "Building.h"
#include <iostream>
using namespace std;
using namespace Sim;

//Konstruktor
CapicitySim::CapicitySim() {
    gesamtpreis = 0;
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
    //i : Hoehe
    //j : Breite
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

//berechnet den Gesamtpreis aller aktuellen Gebäude
int CapicitySim::calcGesamtpreis() {
    int countWasser = 0;
    int countWind = 0;
    int countSolar = 0;
    Wasserkraftwerk w1;
    Windkraftwerk w2;
    Solarpanele s1;
    gesamtpreis = 0;
    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; i < bbreite; j++) {
            if (bereich[i][j]->getLabel() == 'W') {
                countWasser++;
            }
            if (bereich[i][j]->getLabel() == 'L') {
                countWind++;
            }
            if (bereich[i][j]->getLabel() == 'S') {
                countSolar++;
            }
        }
    }
    gesamtpreis = countWasser * w1.getGesamtpreis() + countWind * w2.getGesamtpreis() + countSolar*s1.getGesamtpreis();
    return gesamtpreis;
}

//prüft beim Bau eines Gebäudes auf Kollisionen mit andern, bzw ob außerhalb des Bereichs
bool CapicitySim::checkKollision(int posx, int posy, int breite, int hoehe) {
	//außerhalb des Bereichs?
	if (posy >= bhoehe || posx >= bbreite || hoehe + posy >= bhoehe || breite + posx >= bbreite) {
		return false;
	}
	//Kollision mit anderem Gebäude?
	for (int i = posy; i < posy + hoehe; i++) {
		for (int j = posx; j < posx + breite; j++) {
			if (bereich[i][j]->getLabel() == 'W'|| bereich[i][j]->getLabel() == 'L'|| bereich[i][j]->getLabel() == 'S')
				return false;
		}
	}
	return true;
}

//platziert ein Gebäude im Bereich
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
    if (checkKollision(posx, posy, breite, hoehe))
    {
        switch (input)  //Gebäudetyp auswählen
        {
        case 1:
                for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Wasserkraftwerk();
                    }
                }
                cout << "Gebaeude wurde platziert" << endl;
                break;
        case 2: for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Windkraftwerk();
                    }
                }
                cout << "Gebaeude wurde platziert" << endl;
                break;
        case 3: for (int i = posy; i < posy + hoehe; i++) {
                    for (int j = posx; j < posx + breite; j++) {
                        bereich[i][j] = new Wasserkraftwerk();
                    }
                }
                cout << "Gebaeude wurde platziert" << endl;
                break;
        default:
            cout << "Ungueltiger Gebaeudetyp" << endl;
            return;
        }
    }
    else {
        cout << "Gebaeude kann nicht platziert werden" << endl;
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
        cout << "Bereich wurde gelöscht" << endl;
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
            cout << bereich[i][j]->getLabel() << " ";
        }
        cout << endl;
    }

    //Auflistung Gebäude + Zusammensetzung + Grundpreis
    //Wasserkraftwerk:
    Wasserkraftwerk w1;
    cout << "Wasserkraftwerk: " << endl;
    cout << w1.getLabel() << w1.getGesamtpreis()<< "$ Zusammensetzung: "<< w1.getZusammensetzung() << endl;
    //Windkraftwerk
    Windkraftwerk w2;
    cout << "Windkraftwerk: " << endl;
    cout << w2.getLabel() << w2.getGesamtpreis() << "$ Zusammensetzung: " << w2.getZusammensetzung()<< endl;
    //Solarpanele
    Solarpanele s3;
    cout << "Solarpanele: " << endl;
    cout << s3.getLabel() << s3.getGesamtpreis() << "$ Zusammensetzung: " << s3.getZusammensetzung() << endl;;
    //Gesamtpreis aller Gebäude
    //cout << "Gesamtpreis aller Gebaeude: " << to_string(calcGesamtpreis()) << endl;
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
