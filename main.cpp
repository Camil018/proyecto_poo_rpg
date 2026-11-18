#include <iostream>
#include <vector>
#include "Enemigos.h"
#include "Jugador.h"
using namespace std;

class MunecoPrueba : public Entidad {
public:
    MunecoPrueba() : Entidad("Muneco", 100) {
    }

    void atacar(Entidad* objetivo) {
    }
};

int main() {
    cout << "Prueba 1: estadisticas por nivel\n";
    for (int nivel = 1; nivel <= 3; nivel++) {
        vector<Enemigo*> enemigos;
        enemigos.push_back(new ZombiOjeras(nivel));
        enemigos.push_back(new DronVigilante(nivel));
        enemigos.push_back(new FotocopiadoraTanque(nivel));

        int cantidad = enemigos.size();
        for (int i = 0; i < cantidad; i++) {
            cout << enemigos[i]->getNombre() << " nivel " << enemigos[i]->getNivel()
                 << ": vida " << enemigos[i]->getVida()
                 << ", dano " << enemigos[i]->getDanio() << "\n";
            delete enemigos[i];
        }
        cout << "\n";
    }

    cout << "Prueba 2: seis turnos de cada enemigo (nivel 1) contra un muneco\n";
    vector<Enemigo*> enemigos;
    enemigos.push_back(new ZombiOjeras(1));
    enemigos.push_back(new DronVigilante(1));
    enemigos.push_back(new FotocopiadoraTanque(1));

    int cantidad = enemigos.size();
    for (int i = 0; i < cantidad; i++) {
        MunecoPrueba muneco;
        cout << "\n" << enemigos[i]->getNombre() << "\n";
        for (int turno = 1; turno <= 6; turno++) {
            cout << "Turno " << turno << ":\n";
            enemigos[i]->atacar(&muneco);
        }
        cout << "Al muneco le quedan " << muneco.getVida() << " de vida\n";
        delete enemigos[i];
    }

    cout << "\nPrueba 3: fotocopiadora nivel 2 contra Roble (el escudo se gasta primero)\n";
    Jugador roble;
    Enemigo* fotocopiadora = new FotocopiadoraTanque(2);
    roble.mostrarEstado();
    for (int turno = 1; turno <= 3; turno++) {
        cout << "Turno " << turno << ":\n";
        fotocopiadora->atacar(&roble);
        roble.mostrarEstado();
    }
    delete fotocopiadora;

    return 0;
}