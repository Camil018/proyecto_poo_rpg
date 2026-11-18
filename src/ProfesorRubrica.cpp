#include "ProfesorRubrica.h"
#include <iostream>
using namespace std;

ProfesorRubrica::ProfesorRubrica() : Enemigo("Profesor Aurelio Rubrica", 80, 2, 4) {
    setVidaMaxima(80);
    fase = 1;
    turno = 0;
}

int ProfesorRubrica::getFase() {
    return fase;
}

void ProfesorRubrica::preguntaCapciosa(Entidad* objetivo) {
    cout << getNombre() << " lanza una Pregunta Capciosa: 2 de dano\n";
    objetivo->recibirDanio(2);
}

void ProfesorRubrica::lluviaDeTiza(Entidad* objetivo) {
    cout << getNombre() << " lanza una Lluvia de Tiza\n";
    for (int i = 1; i <= 3; i++) {
        cout << "  Tiza " << i << ": 2 de dano\n";
        objetivo->recibirDanio(2);
    }
}

void ProfesorRubrica::alzarBoligrafo() {
    cout << getNombre() << " alza el boligrafo rojo, algo malo se viene\n";
}

void ProfesorRubrica::reprobado(Entidad* objetivo) {
    cout << getNombre() << " grita REPROBADO: 5 de dano\n";
    objetivo->recibirDanio(5);
}

void ProfesorRubrica::atacar(Entidad* objetivo) {
    if (fase == 1 && getVida() <= 40) {
        fase = 2;
        turno = 0;
        cout << getNombre() << " entra en fase 2, ahora esta mas molesto\n";
    }

    if (fase == 1) {
        if (turno == 0) {
            preguntaCapciosa(objetivo);
        } else if (turno == 1) {
            lluviaDeTiza(objetivo);
        } else if (turno == 2) {
            alzarBoligrafo();
        } else {
            reprobado(objetivo);
        }
        turno = turno + 1;
        if (turno == 4) {
            turno = 0;
        }
    } else {
        if (turno == 0) {
            preguntaCapciosa(objetivo);
        } else if (turno == 1) {
            alzarBoligrafo();
        } else {
            reprobado(objetivo);
        }
        turno = turno + 1;
        if (turno == 3) {
            turno = 0;
        }
    }
}