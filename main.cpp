#include <iostream>
#include "Enemigo.h"
#include "Utilidades.h"
using namespace std;

class EnemigoPrueba : public Enemigo {
public:
    EnemigoPrueba(int nivel) : Enemigo("Enemigo de prueba", 14, 1, nivel) {
    }

    void atacar(Entidad* objetivo) {
        cout << getNombre() << " golpea con " << getDanio() << " de dano\n";
        objetivo->recibirDanio(getDanio());
    }
};

class MunecoPrueba : public Entidad {
public:
    MunecoPrueba() : Entidad("Muneco", 20) {
    }

    void atacar(Entidad* objetivo) {
    }
};

int main() {
    Entidad* muneco = new MunecoPrueba();

    for (int nivel = 1; nivel <= 3; nivel++) {
        Enemigo* e = new EnemigoPrueba(nivel);
        cout << "Nivel " << e->getNivel() << ": vida " << e->getVida()
             << ", dano " << e->getDanio() << "\n";
        e->atacar(muneco);
        cout << "Al muneco le quedan " << muneco->getVida() << " de vida\n\n";
        delete e;
    }

    delete muneco;

    pausar();
    return 0;
}
