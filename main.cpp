#include <cstdlib>
#include <ctime>
#include "Juego.h"
using namespace std;

int main() {
    srand(time(0));

    Juego juego;
    juego.iniciar();

    return 0;
}