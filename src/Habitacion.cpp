#include "Habitacion.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

Habitacion::Habitacion(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

Habitacion::~Habitacion() {
}

string Habitacion::getNombre() {
    return nombre;
}

string Habitacion::getDescripcion() {
    return descripcion;
}

void Habitacion::agregarSalida(Habitacion* destino) {
    salidas[destino->getNombre()] = destino;
    nombresSalidas.push_back(destino->getNombre());
}

int Habitacion::getCantidadSalidas() {
    return nombresSalidas.size();
}

string Habitacion::getNombreSalida(int indice) {
    return nombresSalidas[indice];
}

Habitacion* Habitacion::getSalida(int indice) {
    return salidas[nombresSalidas[indice]];
}

void Habitacion::mostrarSalidas() {
    cout << "Salidas:\n";
    int cantidad = nombresSalidas.size();
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ") " << nombresSalidas[i] << "\n";
    }
}

void Habitacion::llegar(Jugador* jugador) {
    jugador->setSalaActual(this);
    jugador->regenerar();
    cout << "\nEstas en: " << nombre << "\n";
    cout << descripcion << "\n";
}

bool Habitacion::puedeEntrar() {
    return true;
}