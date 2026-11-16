#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Armas.h"
#include "Utilidades.h"
using namespace std;

int main() {
    srand(time(0));

    vector<Arma*> armas;
    armas.push_back(new PistolaBasica());
    armas.push_back(new M4());
    armas.push_back(new Katana());
    armas.push_back(new CanonDeGrapas());

    int municion = 120;

    for (int i = 0; i < armas.size(); i++) {
        cout << armas[i]->getNombre() << " (municion: " << municion << ")\n";
        int total = armas[i]->atacar(municion);
        cout << "Dano total: " << total << " | municion que queda: " << municion << "\n\n";
    }

    cout << "Katana otra vez\n";
    int total = armas[2]->atacar(municion);
    cout << "Dano total: " << total << "\n\n";

    municion = 5;
    cout << "M4 con solo 5 de municion\n";
    total = armas[1]->atacar(municion);
    cout << "Dano total: " << total << " | municion que queda: " << municion << "\n";

    for (int i = 0; i < armas.size(); i++) {
        delete armas[i];
    }

    pausar();
    return 0;
}