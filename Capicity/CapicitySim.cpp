#include "CapicitySim.h"
#include "Building.h"
#include <iostream>
using namespace std;


//Konstruktor
CapicitySim::CapicitySim() {
    bbreite = 10;
    bhoehe = 10;
    running = true;
    //bis jetzt bloﬂ kopiert:
    bereich = new gebaeudetype * [bhoehe];
    for (int i = 0; i < bhoehe; i++)
    {
        bereich[i] = new gebaeudetype[bbreite];
    }

    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; j < bbreite; j++) {
            bereich[i][j] = gebaeudetype(0);
        }
    }
    while (running)
    {
        showMenu();
    }
}

CapicitySim::CapicitySim(int bbreite, int bhoehe) {
	//hier soll die Area erstellt und das Men¸ gestartet werden
	running = true;
	this->bbreite = bbreite;
	this->bhoehe = bhoehe;

	bereich = new gebaeudetype * [bhoehe];
	for (int i = 0; i < bhoehe; i++)
	{
		bereich[i] = new gebaeudetype[bbreite];
	}

	for (int i = 0; i < bhoehe; i++) {
		for (int j = 0; j < bbreite; j++) {
				bereich[i][j] = gebaeudetype(0);
		}
	}
	while (running)
	{
		showMenu();
	}
}

//Methoden
//pr¸ft beim Bau eines Geb‰udes auf Kollisionen mit andern, bzw ob auﬂerhalb des Bereichs
bool CapicitySim::checkKollision(int posx, int posy, int breite, int hoehe) {
	//auﬂerhalb des Bereichs?
	if (posy >= bhoehe || posx >= bbreite || hoehe + posy >= bhoehe || breite + posx >= bbreite) {
		return false;
	}
	//Kollision mit anderem Geb‰ude?
	for (int i = posy; i < posy + hoehe; i++) {
		for (int j = posx; j < posx + breite; j++) {
			if (bereich[i][j] != 0)
				return false;
		}
	}

	return true;
}

//plaziert ein Geb‰ude im Bereich
void CapicitySim::placeBuilding() {
    enum gebaeudetype art;
    cout << "Welche Art von Gebaeude? 1: Holz, 2: Stein, 3: Sand" << endl;;
    cin >> input;
    switch (input)
    {
    case 1: 	art = TYP1;
        break;
    case 2: 	art = TYP2;
        break;
    case 3: 	art = TYP3;
        break;
    default:
        cout << "Ungueltiger Gebaeudetyp" << endl;
        return;
    }
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
        for (int i = posy; i < posy + hoehe; i++) {
            for (int j = posx; j < posx + breite; j++) {
                bereich[i][j] = art;
            }
        }
        cout << "Gebaeude wurde plaziert" << endl;
    }
    else {
        cout << "Gebaeude kann nicht plaziert werden" << endl;
    }
}

//lˆscht einen Bereich
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
                bereich[i][j] = gebaeudetype(0);
            }
        }
    }
    else {
        cout << "Position auﬂerhalb des Bereichs" << endl;
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

    //Auflistung Geb‰ude + Zusammensetzung + Grundpreis
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
    //Gesamtpreis aller Geb‰ude
}

//beendet das Programm
void CapicitySim::stop() {
    cout << "Programm wird beendet" << endl;
    running = false;
}

//zeigt ein Men¸ an, mit dem die Funktionen aufgerufen werden kˆnnen
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
