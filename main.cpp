#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entidad.h"
#include "Objeto.h"
#include "Utilidades.h"
using namespace std;

class MunecoPrueba : public Entidad {
public:
    MunecoPrueba(string nombre, int vida) : Entidad(nombre, vida) {
    }

    void atacar(Entidad* objetivo) {
        cout << getNombre() << " le pega a " << objetivo->getNombre() << "\n";
        objetivo->recibirDanio(3);
    }
};

class CosaPrueba : public Objeto {
public:
    CosaPrueba() : Objeto("Cosa", "un objeto de prueba") {
    }

    void usar(Jugador* jugador) {
        cout << "Usaste la cosa\n";
    }
};

int main() {
    srand(time(0));

    Entidad* a = new MunecoPrueba("Muneco A", 10);
    Entidad* b = new MunecoPrueba("Muneco B", 5);

    cout << a->getNombre() << " tiene " << a->getVida() << " de vida\n";
    cout << b->getNombre() << " tiene " << b->getVida() << " de vida\n";

    a->atacar(b);
    cout << b->getNombre() << " queda con " << b->getVida() << " de vida\n";

    a->atacar(b);
    cout << b->getNombre() << " queda con " << b->getVida() << " de vida\n";
    cout << "Sigue vivo? " << b->estaVivo() << "\n";

    Objeto* o = new CosaPrueba();
    cout << o->getNombre() << ": " << o->getDescripcion() << "\n";
    o->usar(nullptr);

    delete a;
    delete b;
    delete o;

    pausar();
    return 0;
}