#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
#include "Salas.h"
#include "Enemigos.h"
#include "Pociones.h"
using namespace std;

int main() {
    srand(time(0));

    Jugador roble;
    roble.setEscudoMaximo(6);
    roble.agregarObjeto(new PocionEscudo());
    roble.agregarObjeto(new PocionVida());

    SalaEnemigos sala("Sala de prueba", "Una sala solo para probar el combate.");
    sala.agregarEnemigo(new ZombiOjeras(1));
    sala.agregarEnemigo(new DronVigilante(1));

    cout << "Prueba: pelea contra Zombi y Dron en fila\n";
    cout << "Habilidad disponible (1 = si, 0 = no): " << roble.puedeUsarHabilidad() << "\n";

    sala.entrar(&roble);

    cout << "\nEnemigos que quedan: " << sala.getCantidadEnemigos() << "\n";
    cout << "Habilidad disponible (1 = si, 0 = no): " << roble.puedeUsarHabilidad() << "\n";
    roble.mostrarEstado();
    roble.mostrarInventario();

    return 0;
}