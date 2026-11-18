#ifndef PROFESORRUBRICA_H
#define PROFESORRUBRICA_H

#include "Enemigo.h"
using namespace std;

class ProfesorRubrica : public Enemigo {
private:
    int fase;
    int turno;

    void preguntaCapciosa(Entidad* objetivo);
    void lluviaDeTiza(Entidad* objetivo);
    void alzarBoligrafo();
    void reprobado(Entidad* objetivo);

public:
    ProfesorRubrica();
    int getFase();
    void atacar(Entidad* objetivo);
};

#endif