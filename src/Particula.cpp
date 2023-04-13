#include "Particula.h"



Particula::Particula(){
  x = drand48() * (MIN_X-0) + 0;
  y = drand48() * (MIN_Y-0) + 0;
  dx = drand48() * (MAX_VEL-0) + 0;
  dy = drand48() * (MAX_VEL-0) + 0;
  color_particula = v[rand()%6];
}

Particula::Particula (float pos_x, float pos_y){
  x = pos_x;  y = pos_y;
  dx = 1;     dy = 1;
  color_particula = v[rand()%6];
}


  void Particula::Set_x(float pos_x){
      x = pos_x;
  }
  void Particula::Set_y(float pos_y){
      y = pos_y;
  }
  void Particula::Set_color(Color elegir){
    color_particula = elegir;
  }
  void Particula::Set_dx(float dif_x){
    dx = dif_x;
  }
  void Particula::Set_dy(float dif_y){
    dy = dif_y;
  }

float Particula::Get_x() const{return x;}
float Particula::Get_y() const{return y;}
float Particula::Get_dx() const{return dx;}
float Particula::Get_dy() const{return dy;}
Color Particula::Get_color() const {return color_particula;}

void Particula::desaparece(){
  Set_color(NEGRO);
  Set_x(-1);
  Set_y(-1);
  Set_dx(0);
  Set_dy(0);
}

float Particula::distancia_particulas(Particula aux){
  return sqrt(pow(aux.Get_x() - this->x,2) + pow(aux.Get_y() - this->y,2));
}
bool Particula::Colision(Particula aux){
  bool choque = false;
  if (distancia_particulas(aux)< UMBRAL )
    choque = true;
}

float Particula::velocidad() const{
return sqrt( pow(Get_dx(),2) + pow(Get_dy(),2) );
}


void Particula::pinta_pelota() {
   color(Get_color());
   circulo_lleno(Get_x(),Get_y(), RADIO);
}

void Particula::mueve_pelota() {
   const float factor = 0.97;
   Set_x(Get_x() + Get_dx());
   Set_y(Get_y()+ Get_dy()) ;
   if (Get_x() > vancho() - RADIO) {
      Set_dx(-Get_dx() * factor);
      Set_x(vancho() - RADIO);
   }
	else if (Get_x() < RADIO) {
      Set_dx(-Get_dx() * factor);
      Set_x(RADIO);
   }
	else if (Get_y() > valto() - RADIO) {
      Set_dy(-Get_dy() * factor);
      Set_y(valto() - RADIO) ;
   }
	else if (Get_y() < RADIO) {
      Set_dy(-Get_dy() * factor);
      Set_y(RADIO);
   }
}
void Particula::mueve_pelota(int ancho, int alto ) {
      const float factor = 0.97;
      Set_x(Get_x() + Get_dx());
      Set_y(Get_y()+ Get_dy()) ;
      if (Get_x() > ancho - RADIO) {
         Set_dx(-Get_dx() * factor);
         Set_x(ancho - RADIO);
      }
   	else if (Get_x() < RADIO) {
         Set_dx(-Get_dx() * factor);
         Set_x(RADIO);
      }
   	else if (Get_y() > alto - RADIO) {
         Set_dy(-Get_dy() * factor);
         Set_y(alto - RADIO) ;
      }
   	else if (Get_y() < RADIO) {
         Set_dy(-Get_dy() * factor);
         Set_y(RADIO);
      }
}

void Particula::rebota(Particula &frente){
     float aux_x, aux_y=0;

     aux_x = this-> dx;
     aux_y = this-> dy;

     this-> dx = frente.Get_dx();
     this-> dy = frente.Get_dy();

     this->x += this-> dx;
     this->y += this-> dy;

     frente.Set_dx(aux_x);
     frente.Set_dy(aux_y);
     frente.Set_x(frente.Get_x() + frente.Get_dx());
     frente.Set_y(frente.Get_y() + frente.Get_dy());


}
