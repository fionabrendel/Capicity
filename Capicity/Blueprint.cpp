#include "Blueprint.h"
#include <iostream>
using namespace std;

//Default-Konstruktor
Blueprint::Blueprint() {
    input = 0;
    gesamtpreis = 0;
    bbreite = 10;
    bhoehe = 10;
    posx = 0;
    posy = 0;
    breite = 0;
    hoehe = 0;
    countWasser = 0;
    countWind = 0;
    countSolar = 0;
    kennzahl = 0;

    //Gebäudeobjekte zum Werte auslesen
    w1 = new Wasserkraftwerk();
    w2 = new Windkraftwerk();
    s1 = new Solarpanele();

    bereich = new Building * *[bhoehe];
    for (int i = 0; i < bhoehe; i++)
    {
        bereich[i] = new Building * [bbreite];
    }

    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; j < bbreite; j++) {
            bereich[i][j] = new Leer();
        }
    }
}

//Konstruktor
Blueprint::Blueprint(int bbreite, int bhoehe) {
    input = 0;
    gesamtpreis = 0;
    this->bbreite = bbreite;
    this->bhoehe = bhoehe;
    posx = 0;
    posy = 0;
    breite = 0;
    hoehe = 0;
    countWasser = 0;
    countWind = 0;
    countSolar = 0;
    kennzahl = 0;

    //Gebäudeobjekte zum Werte auslesen
    w1 = new Wasserkraftwerk();
    w2 = new Windkraftwerk();
    s1 = new Solarpanele();

    bereich = new Building * *[bhoehe];
    for (int i = 0; i < bhoehe; i++)
    {
        bereich[i] = new Building * [bbreite];
    }

    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; j < bbreite; j++) {
            bereich[i][j] = new Leer();
        }
    }
}

//Methoden

//berechnet Anzahl der Gebäude auf dem Plan
void Blueprint::calcGebaeude() {
    countWasser = 0;
    countWind = 0;
    countSolar = 0;
    for (int i = 0; i < bhoehe; i++) {
        for (int j = 0; j < bbreite; j++) {
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
    //cout << "Wasser: " << std::to_string(countWasser)<<endl;
}

//berechnet den Gesamtpreis aller aktuellen Gebäude
int Blueprint::calcGesamtpreis() {
    gesamtpreis = 0;
    calcGebaeude();
    gesamtpreis = countWasser * w1->getGesamtpreis() + countWind * w2->getGesamtpreis() + countSolar * s1->getGesamtpreis();
    return gesamtpreis;
}

//prüft beim Bau eines Gebäudes auf Kollisionen mit andern, bzw ob außerhalb des Bereichs
bool Blueprint::checkKollision(int posx, int posy, int breite, int hoehe) {
    //außerhalb des Bereichs?
    if (posy >= bhoehe || posx >= bbreite || hoehe + posy >= bhoehe || breite + posx >= bbreite) {
        return false;
    }
    //Kollision mit anderem Gebäude?
    for (int i = posy; i < posy + hoehe; i++) {
        for (int j = posx; j < posx + breite; j++) {
            if (bereich[i][j]->getLabel() == 'W' || bereich[i][j]->getLabel() == 'L' || bereich[i][j]->getLabel() == 'S')
                return false;
        }
    }
    return true;
}

//platziert ein Gebäude im Bereich
void Blueprint::placeBuilding() {
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
                bereich[i][j] = new Solarpanele();
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
void Blueprint::deleteArea() {
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
        cout << "Bereich wurde geloescht" << endl;
    }
    else {
        cout << "Position außerhalb des Bereichs" << endl;
    }
}

//gibt den Bauplan und weitere Informationen aus
void Blueprint::printPlan() {
    //Plan ausgeben
    for (int i = 0; i < bhoehe; i++)
    {
        for (int j = 0; j < bbreite; j++)
        {
            cout << bereich[i][j]->getLabel() << " ";
        }
        cout << endl;
    }

    //Auflistung Gebäude + Zusammensetzung + Grundpreis
    //Wasserkraftwerk:
    cout << "Wasserkraftwerk: " << endl;
    cout << w1->getLabel() << w1->getGesamtpreis() << "$ Zusammensetzung: " << w1->getZusammensetzung() << endl;
    //Windkraftwerk
    cout << "Windkraftwerk: " << endl;
    cout << w2->getLabel() << w2->getGesamtpreis() << "$ Zusammensetzung: " << w2->getZusammensetzung() << endl;
    //Solarpanele
    cout << "Solarpanele: " << endl;
    cout << s1->getLabel() << s1->getGesamtpreis() << "$ Zusammensetzung: " << s1->getZusammensetzung() << endl;;
    //Gesamtpreis aller Gebäude
    cout << "Gesamtpreis aller Gebaeude: " << to_string(calcGesamtpreis()) << endl;
    //Kennzahl des Plans
    cout << "Kennzahl: " << to_string(calcKennzahl()) << endl;
}


//berechnet die Kennzahl des Plans
int Blueprint::calcKennzahl() {
    calcGebaeude();
    kennzahl = 0;
    //Wasserkraftwerk
    /*cout << to_string(countWasser) << endl;
    cout << to_string(w1->getGesamtpreis()) << endl;
    cout << to_string(w1->leistung) << endl;*/
    if (countWasser > 0) {
        kennzahl += w1->leistung / (w1->getGesamtpreis() * countWasser);
        cout << to_string(kennzahl) << endl;
    }
    //Windkraftwerk
    if (countWind > 0) {
        kennzahl += w2->leistung / (w2->getGesamtpreis() * countWind);
    }
    //Solarpanele
    if (countSolar > 0) {
        kennzahl += s1->leistung / (s1->getGesamtpreis() * countSolar);
    }
    return kennzahl;
}

//definiert den Gleichheitsoperator für Blueprint-Pläne
bool Blueprint::operator ==(Blueprint b) {
    if (this->bbreite != b.bbreite || this->bhoehe != b.bhoehe) {
        return false;
    }
    for (int i = 0; i < this->bhoehe; i++) {
        for (int j = 0; j < this->bhoehe; j++) {
            if (this->bereich[i][j]->getLabel() != b.bereich[i][j]->getLabel()) {
                return false;
            }
        }
    }
}