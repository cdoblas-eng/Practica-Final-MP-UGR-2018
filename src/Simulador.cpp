#include "Simulador.h"

Simulador::Simulador(int n_particulas, int anchura, int altura):Mi_nube(n_particulas),ancho(anchura),alto(altura){

     //ancho = anchura;
     //alto = altura;
     //Mi_nube = Nubeparticulas crear(n_particulas);
     vredimensiona(ancho,alto);

}

Simulador::~Simulador(){
     vcierra();

}

void Simulador::mover(){
     Mi_nube.Mover(ancho,alto);


}

void Simulador::Pintar() const{

     Mi_nube.pintar();

}
