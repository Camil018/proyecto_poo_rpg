#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Combate.h"
#include "Enemigos.h"
#include "Pociones.h"
#include "Utilidades.h"
using namespace std;

int main() {
    srand(time(0));

    Jugador* roble = new Jugador();
    roble->agregarObjeto(new PocionVida());
    roble->agregarObjeto(new PocionVida());

    Enemigo* enemigo = new ZombiOjeras(1);

    Combate combate(roble, enemigo);
    bool gano = combate.pelear();

    if (gano) {
        cout << "\nGanaste la pelea\n";
    } else {
        cout << "\nPerdiste la pelea\n";
    }

    delete enemigo;
    delete roble;

    pausar();
    return 0;
}