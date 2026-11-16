#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utilidades.h"
using namespace std;

int main() {
    srand(time(0));

    cout << "Prueba de utilidades\n";
    cout << "Numero aleatorio entre 1 y 6: " << numeroAleatorio(1, 6) << "\n";

    if (probabilidad(50)) {
        cout << "Probabilidad del 50%: salio que SI\n";
    } else {
        cout << "Probabilidad del 50%: salio que NO\n";
    }

    int opcion = leerOpcion("Elige una opcion (1-3): ", 1, 3);
    cout << "Elegiste la opcion " << opcion << "\n";

    pausar();
    return 0;
}