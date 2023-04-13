#ifndef PARTICULA
#define PARTICULA



#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "miniwin.h"
#include "definiciones.h"
#include <cmath>
using namespace miniwin;
using namespace std;

const Color v[6] = {ROJO,VERDE,AZUL,AMARILLO,BLANCO,CYAN};

class Particula{


  private:
    float x,y,dx,dy;
    Color color_particula;

  public:
    Particula();
    Particula (float pos_x, float pos_y);
    void Set_x(float pos_x);
    void Set_y(float pos_y);
    void Set_color(Color elegir);
    void Set_dx(float dif_x);
    void Set_dy(float dif_y);
    float Get_x ()const;
    float Get_y()const;
    float Get_dx()const;
    float Get_dy()const;
    Color Get_color() const;
    void desaparece();
    float distancia_particulas(Particula aux);
    bool Colision(Particula aux);
    float velocidad()const ;

    void pinta_pelota();

    void mueve_pelota();
    void mueve_pelota(int ancho, int alto);

    void rebota(Particula &frente);
};


//ostream& operator<<(ostream &flujo,const Particula &p);

#endif
