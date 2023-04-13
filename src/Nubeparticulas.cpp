#include "Nubeparticulas.h"

Nubeparticulas::Nubeparticulas(){
     capacidad = 20;
     Nube = new Particula[capacidad];
     utiles = capacidad;
}

Nubeparticulas::Nubeparticulas(int cap){
 int tamanio_nube = rand() % cap;
 Nube = new Particula[tamanio_nube];
 capacidad = cap;
 utiles = tamanio_nube;
}
Nubeparticulas::~Nubeparticulas(){
 delete [] Nube;
 Nube = NULL;

}

Nubeparticulas::Nubeparticulas(const Nubeparticulas &n){
     this->capacidad = n.Get_capacidad();
     this->utiles = n.Get_utils();
     Particula *aux;

     aux = new Particula[capacidad];
     for (int i = 0; i<this->Get_utils(); i++)
          aux[i] = n.ObtieneParticula(i);

          Nube = aux;
}


Nubeparticulas& Nubeparticulas:: operator=(const Nubeparticulas &n){

     delete[] this->Nube;
     this->capacidad = n.capacidad;
     this->utiles = n.utiles;
     Particula *aux;
     aux = new Particula[n.capacidad];
     for (int i = 0; i<n.utiles; i++)
          aux[i] = n.ObtieneParticula(i);

     this->Nube = aux;
     return *this;
}


int Nubeparticulas::Get_capacidad()const{return capacidad;}
int Nubeparticulas::Get_utils()const{return utiles;}
void Nubeparticulas::Set_utils(int utils_establecer){utiles = utils_establecer;}
void Nubeparticulas::aumenta(int bloques){

     Particula *aux;
     aux = new Particula[Get_utils() + bloques];
     for (int i = 0; i < Get_utils();i++)
        aux[i] = ObtieneParticula(i);

      delete[] Nube;
      Nube = aux;
}

void Nubeparticulas::agrega_particula(Particula aniadir){
     if(utiles<capacidad){
     Nube[utiles] = aniadir;
     Set_utils(Get_utils()+1);
     }
     else{
         cout << "Tamanio maximo alcanzado, aumentando " << TAM_BLOQUE << " casillas..." << endl;
         aumenta(TAM_BLOQUE);
         Nube[utiles] = aniadir;
         utiles++;
     }
}

void Nubeparticulas::BorraParticula(int posicion){
    for (int pos = posicion; pos < Get_utils() - 1; pos++)
        Nube[pos] = Nube[pos + 1];

    Set_utils( Get_utils() - 1);

}

Particula Nubeparticulas::ObtieneParticula(int elemento_vector)const{
return Nube[elemento_vector];
}

void Nubeparticulas::Mover(int ancho, int alto){

          for (int i = 0; i< Get_utils(); i++ ) {
               Nube[i].mueve_pelota(ancho,alto);
          }

}
void Nubeparticulas::pintar()const{

     for (int i = 0; i< Get_utils(); i++ ) {
          Nube[i].pinta_pelota();

     }

}

void Nubeparticulas::rebote(int pos_1, int pos_2){

     Nube[pos_1].rebota(Nube[pos_2]);

}

void Nubeparticulas::cambia_color(int pos_particula, Color elegir){

     Nube[pos_particula].Set_color(elegir);

}

void Nubeparticulas::desaparece (int pos_particula){

     Nube[pos_particula].desaparece();
}
