#include "Salas.h"
#include "Jugador.h"
#include "Armas.h"
#include "Pociones.h"
#include "Utilidades.h"
#include "Combate.h"
#include <iostream>
#include <cstdlib>
using namespace std;

SalaEnemigos::SalaEnemigos(string nombre, string descripcion) : Habitacion(nombre, descripcion) {
}

SalaEnemigos::~SalaEnemigos() {
    int cantidad = enemigos.size();
    for (int i = 0; i < cantidad; i++) {
        delete enemigos[i];
    }
}

void SalaEnemigos::agregarEnemigo(Enemigo* enemigo) {
    enemigos.push_back(enemigo);
}

int SalaEnemigos::getCantidadEnemigos() {
    return enemigos.size();
}

Enemigo* SalaEnemigos::getEnemigo(int indice) {
    return enemigos[indice];
}

void SalaEnemigos::quitarEnemigo(int indice) {
    int cantidad = enemigos.size();
    if (indice < 0 || indice >= cantidad) {
        return;
    }

    delete enemigos[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        enemigos[i] = enemigos[i + 1];
    }
    enemigos.pop_back();
}

bool SalaEnemigos::estaLimpia() {
    return enemigos.size() == 0;
}

void SalaEnemigos::entrar(Jugador* jugador) {
    llegar(jugador);

    if (estaLimpia()) {
        cout << "Ya no queda nadie en esta sala\n";
        return;
    }

    cout << "Enemigos en la sala:\n";
    int cantidad = enemigos.size();
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ") " << enemigos[i]->getNombre()
             << " (vida " << enemigos[i]->getVida() << ")\n";
    }

    
}

SalaCofre::SalaCofre(string nombre, string descripcion) : Habitacion(nombre, descripcion) {
    abierto = false;
}

void SalaCofre::entrar(Jugador* jugador) {
    llegar(jugador);

    if (abierto) {
        cout << "El cofre ya esta abierto y vacio\n";
        return;
    }
    abierto = true;

    Arma* arma;
    int sorteo = numeroAleatorio(1, 3);
    if (sorteo == 1) {
        arma = new M4();
    } else if (sorteo == 2) {
        arma = new Katana();
    } else {
        arma = new CanonDeGrapas();
    }

    cout << "Abres el cofre y encuentras: " << arma->getNombre()
         << " (" << arma->getDescripcion() << ")\n";

    if (jugador->agregarArma(arma)) {
        cout << "La guardas en tu equipo\n";
        return;
    }

    cout << "Ya llevas 2 armas. Cual quieres reemplazar?\n";
    jugador->mostrarArmas();
    int opcion = leerOpcion("Elige el arma a reemplazar: ", 1, 2);
    jugador->reemplazarArma(opcion - 1, arma);
    cout << "Ahora llevas " << arma->getNombre() << "\n";
}

SalaTienda::SalaTienda(string nombre, string descripcion) : Habitacion(nombre, descripcion) {
}

void SalaTienda::entrar(Jugador* jugador) {
    llegar(jugador);
    cout << "Aqui no hay monedas, el precio es una estadistica tuya\n";

    int opcion = 0;
    while (opcion != 3) {
        cout << "\n";
        jugador->mostrarEstado();
        cout << "Que quieres comprar?\n";
        cout << "1) Pocion de Vida (cura 3 de vida, cuesta 1 de escudo maximo)\n";
        cout << "2) Pocion de Escudo (sube 1 el escudo maximo, cuesta 1 de vida maxima)\n";
        cout << "3) Salir de la tienda\n";
        opcion = leerOpcion("Elige una opcion: ", 1, 3);

        Pocion* pocion = NULL;
        if (opcion == 1) {
            pocion = new PocionVida();
        } else if (opcion == 2) {
            pocion = new PocionEscudo();
        }

        if (pocion != NULL) {
            if (pocion->puedeComprar(jugador)) {
                pocion->pagarCosto(jugador);
                jugador->agregarObjeto(pocion);
                cout << "Compraste " << pocion->getNombre() << "\n";
            } else {
                delete pocion;
            }
        }
    }
}

SalaPortal::SalaPortal(string nombre, string descripcion, SalaEnemigos* salaA, SalaEnemigos* salaB)
    : Habitacion(nombre, descripcion) {
    this->salaA = salaA;
    this->salaB = salaB;
    cruzado = false;
}

bool SalaPortal::getCruzado() {
    return cruzado;
}

bool SalaPortal::puedeEntrar() {
    if (!salaA->estaLimpia() || !salaB->estaLimpia()) {
        cout << "El portal esta cerrado. Limpia las dos salas de enemigos primero\n";
        return false;
    }
    return true;
}

void SalaPortal::entrar(Jugador* jugador) {
    llegar(jugador);
    cout << "El portal esta abierto\n";
    cout << "1) Cruzar al siguiente nivel\n";
    cout << "2) Quedarte aqui\n";
    int opcion = leerOpcion("Elige una opcion: ", 1, 2);
    if (opcion == 1) {
        cruzado = true;
        cout << "Cruzas el portal\n";
    }
}

SalaJefe::SalaJefe(string nombre, string descripcion) : Habitacion(nombre, descripcion) {
    jefe = new ProfesorRubrica();
}

SalaJefe::~SalaJefe() {
    delete jefe;
}

ProfesorRubrica* SalaJefe::getJefe() {
    return jefe;
}

bool SalaJefe::getVencido() {
    return !jefe->estaVivo();
}

void SalaJefe::entrar(Jugador* jugador) {
    llegar(jugador);
    cout << jefe->getNombre() << " te espera con el boligrafo rojo en la mano\n";
    cout << "Vida del jefe: " << jefe->getVida() << "/" << jefe->getVidaMaxima() << "\n";

    // el combate se conecta aqui en el commit de Combate
}