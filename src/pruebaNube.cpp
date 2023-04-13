#include "Simulador.h"
#include "Particula.h"
#include "miniwin.h"
#include "Nubeparticulas.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "definiciones.h"

using namespace miniwin;

using namespace std;

ostream& operator<<(ostream &flujo, const Particula &p){
     flujo <<"x: " << p.Get_x()<< endl;
     flujo <<"y: " << p.Get_y()<< endl;

     flujo <<endl;
     return flujo;
}

ostream& operator<<(ostream &flujo, const Nubeparticulas &n){

     for (int i=0; i<n.Get_utils(); i++){
          flujo << "Particula: " << i << ":"<< endl;
          flujo<<n.ObtieneParticula(i) << endl;

     }
     return flujo;

}
int main(){
     vredimensiona(800,800);
     int ancho = 800, alto = 800;
     srand(time(0));

     Nubeparticulas base(3);

     //CONSTRUCTOR DE COPIA
     Nubeparticulas nuevo(base);
     nuevo.Mover(ancho,alto);

     //CONSTRUCTOR DEFECTO
     Nubeparticulas otro;

     //SOBRECARGA DE ASIGNACION
     otro = nuevo;
     otro.Mover(ancho,alto);

     //mostrar

     cout << "\n CONJUNTO INICIAL" << endl;
     cout << base;

     cout << "\n CONJUNTO movido 1" << endl;
     cout << nuevo;

     cout << "\n CONJUNTO movido 2" << endl;
     cout << otro <<endl;

     // PROGRAMAA
     int N;
     Particula p;
     while(tecla()!=ESCAPE){
     otro.Mover(ancho,alto);
     borra();
     for(int i=0; i < otro.Get_utils();i++){
     p = otro.ObtieneParticula(i);
     color(p.Get_color());
     circulo_lleno(p.Get_x(),p.Get_y(),RADIO);
     }
     refresca();

     //agrego 1 particula al conjunto
     Particula nueva;
     nueva.Set_color(v[rand()%5]);
     otro.agrega_particula(nueva);
     espera(10);
}
     vcierra();

     return 0;
}
