#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
using namespace std;

class Muneco : public Entidad {
public:
    Muneco() : Entidad("Muneco de prueba", 100) {
    }

    void atacar(Entidad* objetivo) {
    }
};

int main() {
    srand(time(0));

    Jugador roble;
    Muneco muneco;

    cout << "Prueba 1: estado inicial\n";
    roble.mostrarEstado();
    roble.mostrarArmas();

    cout << "\nPrueba 2: recibir dano (el escudo se gasta primero)\n";
    roble.recibirDanio(3);
    roble.mostrarEstado();
    roble.recibirDanio(4);
    roble.mostrarEstado();

    cout << "\nPrueba 3: regenerar al entrar a una sala\n";
    roble.regenerar();
    roble.mostrarEstado();

    cout << "\nPrueba 4: atacar con la pistola\n";
    roble.atacar(&muneco);
    cout << "Vida del muneco: " << muneco.getVida() << "/" << muneco.getVidaMaxima() << "\n";
    roble.mostrarEstado();

    cout << "\nPrueba 5: agregar armas (maximo 2)\n";
    if (roble.agregarArma(new M4())) {
        cout << "M4 agregada\n";
    }
    Arma* katana = new Katana();
    if (!roble.agregarArma(katana)) {
        cout << "Ya llevas 2 armas, la Katana reemplaza a la Pistola\n";
        roble.reemplazarArma(0, katana);
    }
    roble.mostrarArmas();

    cout << "\nPrueba 6: atacar con M4 y con Katana\n";
    roble.elegirArma(1);
    roble.atacar(&muneco);
    roble.mostrarEstado();
    roble.elegirArma(0);
    roble.atacar(&muneco);
    roble.atacar(&muneco);
    roble.mostrarEstado();

    cout << "\nPrueba 7: habilidad Raices Salvajes\n";
    cout << "Puede usarla (1 = si, 0 = no): " << roble.puedeUsarHabilidad() << "\n";
    roble.usarHabilidad();
    for (int turno = 1; turno <= 6; turno++) {
        cout << "Turno " << turno << ": ";
        if (roble.raicesActivas()) {
            roble.aplicarRaices(&muneco);
        } else {
            cout << "las raices ya se acabaron\n";
        }
    }
    cout << "Puede usarla otra vez: " << roble.puedeUsarHabilidad() << "\n";
    roble.recargarHabilidad();
    cout << "Despues de recargar: " << roble.puedeUsarHabilidad() << "\n";

    cout << "\nPrueba 8: inventario\n";
    roble.mostrarInventario();
    roble.agregarObjeto(new CanonDeGrapas());
    roble.mostrarInventario();
    roble.getObjeto(0)->usar(&roble);
    roble.quitarObjeto(0);
    cout << "Objetos en el inventario: " << roble.getCantidadObjetos() << "\n";

    cout << "\nPrueba 9: limites del escudo\n";
    roble.setEscudoMaximo(10);
    cout << "Escudo maximo despues de pedir 10: " << roble.getEscudoMaximo() << "\n";
    roble.setEscudoMaximo(2);
    roble.mostrarEstado();

    return 0;
}