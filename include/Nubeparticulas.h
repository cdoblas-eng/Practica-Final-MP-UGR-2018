#ifndef NUBEPARTICULAS
#define NUBEPARTICULAS
#include <iostream>
#include "Particula.h"
using namespace miniwin;
using namespace std;
int const TAM_BLOQUE = 10;

class Nubeparticulas{

private:
  Particula * Nube;
  int capacidad, utiles;

public:
  Nubeparticulas();
  Nubeparticulas(int cap);
  ~Nubeparticulas();
  Nubeparticulas(const Nubeparticulas &n);
  Nubeparticulas& operator=(const Nubeparticulas &n);
  int Get_capacidad()const;
  //void Set_capacidad(int tam);
  int Get_utils()const;
  void Set_utils(int utils_establecer);
  void aumenta(int bloques);
  void agrega_particula(Particula aniadir);
  void BorraParticula(int posicion);
  Particula ObtieneParticula(int elemento_vector) const;
  void Mover(int ancho, int alto);
  void pintar() const;
  void rebote(int pos_1, int pos_2);
  void cambia_color(int pos_particula, Color elegir);
  void desaparece (int pos_particula);
};
#endif
