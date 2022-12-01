#include <iostream>
#include <cstdlib>
using namespace std;

enum gebaeudetype { empty, TYP1, TYP2, TYP3 };
bool running = true;
int input = 0;
int bbreite = 0;
int bhoehe = 0;
gebaeudetype** bereich;
int posx = 0;
int posy = 0;
int hoehe = 0;
int breite = 0;

//prüft beim Bau eines Gebäudes auf Kollisionen mit andern, bzw ob außerhalb des Bereichs
bool checkKollision(int hoehe, int breite, int posx, int posy) {
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
void placeGebaeude() {
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

//löscht einen Bereich
void deleteBereich() {
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
        cout << "Position außerhalb des Bereichs" << endl;
    }
}

//gibt den Bauplan aus
void printBauplan() {
    for (int i = 0; i < bbreite; i++)
    {
        for (int j = 0; j < bhoehe; j++)
        {
            cout << bereich[i][j] << " ";
        }
        cout << endl;
    }

}

//beendet das Programm
void stop() {
    cout << "Programm wird beendet" << endl;
    running = false;
}

//zeigt ein Menü an, mit dem die Funktionen aufgerufen werden können
void showMenu() {
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
        placeGebaeude();
        break;
    case 2:
        deleteBereich();
        break;
    case 3:
        printBauplan();
        break;
    case 4:
        stop();
        break;
    default:
        cout << "Fehlerhafte Eingabe!" << endl;
        break;
    }
}

//Startmethode
int main(int argc, char* argv[]) {
    bbreite = strtol(argv[1], nullptr, 10);
    bhoehe = strtol(argv[2], nullptr, 10);

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
