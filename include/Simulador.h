#ifndef SIMULADOR
#define SIMULADOR

#include "Particula.h"
#include "miniwin.h"
#include "Nubeparticulas.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "definiciones.h"
using namespace miniwin;
using namespace std;

class Simulador{

private:
     Nubeparticulas Mi_nube;
     int nro_p;
     int ancho;
     int alto;

public:

     Simulador(int n_particulas, int ancho, int alto);
     ~Simulador();
     void mover();
     void Pintar() const;
};


#endif
