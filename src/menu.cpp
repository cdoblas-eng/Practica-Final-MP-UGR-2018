#include "menu.h"
#include <iostream>
using namespace std;
void mensaje_menu(){

     cout << "Bienvenido al juego de particulas de Carlos Doblas." << endl;
     cout << "Hay tres modalidades de juego:" << endl;
     cout << "Introduzca 1 si quiere jugar a esquivar las bolas con el cursor." << endl;
     cout << "Introduzca 2 si quiere ver el modo guerra colores." << endl;
     cout << "Introduzca 3 si quiere ver el modo supervivencia en el que solo quedara una bola." << endl;
     cout << "Introduzca cualquier otra tecla si desea salir del programa." <<endl;
     cout << "Una vez elegida una opcion para jugar, entre en la ventana de juego y pulse ESPACIO para empezar." <<endl;
     cout << "------------------------------------------------------------------------------------" <<endl;
}


void rebote (Nubeparticulas &nubep){

     for(int i=0; i<nubep.Get_utils();i++){
          for(int j=0;j<nubep.Get_utils();j++){
              if(nubep.ObtieneParticula(i).Colision(nubep.ObtieneParticula(j)) && i!=j)
                   nubep.rebote(i,j);
          }
     }

}

void change_color (Nubeparticulas &nuve){

     for(int i=0; i<nuve.Get_utils();i++){
          for(int j=0;j<nuve.Get_utils();j++){
              if(nuve.ObtieneParticula(i).Colision(nuve.ObtieneParticula(j)) && i!=j)
                    if (nuve.ObtieneParticula(i).velocidad() >= nuve.ObtieneParticula(j).velocidad())
                         nuve.cambia_color(j,nuve.ObtieneParticula(i).Get_color());
          }
     }
}

void elimina (Nubeparticulas &nuve){

     for(int i=0; i<nuve.Get_utils();i++){
          for(int j=0;j<nuve.Get_utils();j++){
              if(nuve.ObtieneParticula(i).Colision(nuve.ObtieneParticula(j)) && i!=j)
                    if (nuve.ObtieneParticula(i).velocidad() > nuve.ObtieneParticula(j).velocidad())
                         nuve.desaparece(j);
          }
     }
}
