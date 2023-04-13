#include "Simulador.h"
#include "Particula.h"
#include "miniwin.h"
#include "Nubeparticulas.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "definiciones.h"
#include "menu.h" // FUNCIONES AUXILIARES DEL MENU DEL JUEGO QUE HE CREADO
using namespace miniwin;
using namespace std;

int main(){
     srand(time(0));
     int ancho = 1280, alto = 720, particulas = 20;
     //VARIABLES PARA EL MENU
     int opcion = 0;
     bool salir = false;

     //VARIABLES QUE QUE UTILIZO

     Particula P(0,0);
     Nubeparticulas nb(30);

     mensaje_menu();
     do{
          cin >> opcion;

          switch(opcion){
               case 1:
                    vredimensiona(ancho, alto);

                    nb.pintar();
                    while(tecla() != ESPACIO){
                         espera(200);
                    }

                    while (salir == false && tecla()!= ESCAPE) {
                         while(raton_dentro()!= true){
                             espera(200);
                        }
                       borra();
                       P.Set_x(raton_x());
                       P.Set_y(raton_y());
                       nb.Mover(ancho,alto);
                       nb.pintar();
                       rebote(nb);
                       P.pinta_pelota();

                       for (int i = 0; i<nb.Get_utils(); i++){
                            if (P.Colision(nb.ObtieneParticula(i)) ){
                                P.desaparece();
                                salir = true;
                            }
                       }

                     refresca();
                     espera(25);
                  }
                  vcierra();
               break;
               case 2:

                    vredimensiona(ancho, alto);
                    nb.pintar();
                    while(tecla() != ESPACIO){
                         espera(200);
                    }

                    while (salir == false && tecla()!= ESCAPE) {
                         borra();
                         nb.pintar();
                         change_color(nb);
                         rebote(nb);
                         nb.Mover(ancho,alto);
                         refresca();
                         espera(20);

                    }
                    vcierra();
               break;

               case 3:

               vredimensiona(ancho, alto);
               nb.pintar();
               while(tecla() != ESPACIO){
                    espera(200);
               }

               while (salir == false && tecla()!= ESCAPE) {
                    borra();
                    nb.pintar();
                    elimina(nb);
                    nb.Mover(ancho,alto);
                    refresca();
                    espera(20);

               }
               vcierra();

               break;

               default:
               cout<< "Cerrando el programa..." <<endl;
               salir == true;
               vcierra();
               break;
          }

     }while(salir == false);

     return 0;
}
