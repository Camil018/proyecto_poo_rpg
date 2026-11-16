#include "Utilidades.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int numeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

bool probabilidad(int porcentaje) {
    return numeroAleatorio(1, 100) <= porcentaje;
}

int leerOpcion(string mensaje, int minimo, int maximo) {
    int opcion;
    while (true) {
        cout << mensaje;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opcion invalida. Escribe un numero.\n";
        } else if (opcion < minimo || opcion > maximo) {
            cout << "Opcion invalida. Elige entre " << minimo << " y " << maximo << ".\n";
        } else {
            cin.ignore(1000, '\n');
            return opcion;
        }
    }
}

void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.get();
}