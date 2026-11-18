#include "Enemigos.h"
#include <iostream>
using namespace std;

ZombiOjeras::ZombiOjeras(int nivel) : Enemigo("Zombi de Ojeras", 14, 1, nivel) {
    golpeDoble = false;
}

void ZombiOjeras::atacar(Entidad* objetivo) {
    int golpes = 1;
    if (golpeDoble) {
        golpes = 2;
    }
    golpeDoble = !golpeDoble;

    for (int i = 0; i < golpes; i++) {
        cout << getNombre() << " golpea: " << getDanio() << " de dano\n";
        objetivo->recibirDanio(getDanio());
    }
}

DronVigilante::DronVigilante(int nivel) : Enemigo("Dron Vigilante", 12, 1, nivel) {
}

void DronVigilante::atacar(Entidad* objetivo) {
    cout << getNombre() << " dispara: " << getDanio() << " de dano\n";
    objetivo->recibirDanio(getDanio());
}

FotocopiadoraTanque::FotocopiadoraTanque(int nivel) : Enemigo("Fotocopiadora Tanque", 20, 2, nivel) {
    turnosCarga = 0;
}

void FotocopiadoraTanque::atacar(Entidad* objetivo) {
    turnosCarga = turnosCarga + 1;

    if (turnosCarga < 3) {
        cout << getNombre() << " esta cargando toner\n";
        return;
    }

    cout << getNombre() << " lanza una rafaga de 3 hojas\n";
    for (int i = 1; i <= 3; i++) {
        cout << "  Hoja " << i << ": " << getDanio() << " de dano\n";
        objetivo->recibirDanio(getDanio());
    }
    turnosCarga = 0;
}