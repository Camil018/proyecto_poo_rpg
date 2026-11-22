#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Entidad.h"
#include "Objeto.h"
#include "Armas.h"
using namespace std;

class Habitacion;

class Jugador : public Entidad {
private:
    int escudo;
    int escudoMaximo;
    int municion;
    int municionMaxima;
    vector<Arma*> armas;
    int armaElegida;
    vector<Objeto*> inventario;
    bool habilidadUsada;
    int turnosRaices;
    Habitacion* salaActual;

public:
    Jugador();
    ~Jugador();

    int getEscudo();
    int getEscudoMaximo();
    int getMunicion();
    int getMunicionMaxima();
    void setEscudo(int nuevoEscudo);
    void setEscudoMaximo(int nuevoEscudoMaximo);
    void setMunicion(int nuevaMunicion);

    void recibirDanio(int danio);
    void atacar(Entidad* objetivo);
    void regenerar();

    int getCantidadArmas();
    Arma* getArma(int indice);
    void elegirArma(int indice);
    bool agregarArma(Arma* arma);
    void reemplazarArma(int indice, Arma* nuevaArma);

    int getCantidadObjetos();
    Objeto* getObjeto(int indice);
    void agregarObjeto(Objeto* objeto);
    void quitarObjeto(int indice);

    bool puedeUsarHabilidad();
    void usarHabilidad();
    bool raicesActivas();
    void aplicarRaices(Entidad* enemigo);
    void quitarRaices();
    void recargarHabilidad();

    Habitacion* getSalaActual();
    void setSalaActual(Habitacion* sala);

    void mostrarEstado();
    void mostrarArmas();
    void mostrarInventario();
};

#endif