
#include <iostream>
#include <ctime>
#include <random>

#include "llist.h"
#include "bstree.h"


#define TAMANO 1000000

using namespace std;

int getRandom(){
  int random=rand() % (2*TAMANO);
  return random;
}


int main(int argc, char const *argv[]){

  llist<int> listaSec;
  llist<int> listaRand;
  tree<int> arbolBSec;
  tree<int> arbolBRand;
  double tiempo_prueba=0;
  int busquedas = 0;
  int encontrados = 0;
  int no_encontrados = 0;
  clock_t inicio;
  llnode<int> *temp;
  node<int> *temp2;




  //------------------------------------------Linked List------------------------------------------
  cout<<"INICIO DE LA PRUEBA PARA LINKED LIST"<<endl;
  //------------------------------------------INICIO PRUEBA ALEATORIOS------------------------------------------
  cout<<"INICIO DE LA PRUEBA CON NUMEROS ALEATORIOS"<<endl;
  for(int i = 0; i < TAMANO; i++){
    llnode<int> *nodo = new llnode<int>(getRandom());
    listaRand.listInsert(nodo);
  }

  cout<<"La lista se creo satisfactoriamente con "<< TAMANO<<" de elementos aleatorios."<<endl<<endl;
  cout<<"Busqueda de elementos aleatorios en 10 segundos:"<<endl;

  inicio = clock();
  while(tiempo_prueba < 10){
    temp = listaRand.listSearch(getRandom());
    busquedas++;
    if(temp != listaRand.getNil()){
      encontrados++;
    }
    else{
      no_encontrados++;
    }
    tiempo_prueba = (clock() - inicio) / (double) CLOCKS_PER_SEC;
  }

  cout << "cantidad de busquedas totales en 10 segundos: " << busquedas << endl;
  cout << "elementos encontrados: " << encontrados << endl;
  cout << "elementos no encontrados: " << no_encontrados << endl<<endl;

  //------------------------------------------FIN PRUEBA ALEATORIOS------------------------------------------

  tiempo_prueba=0;
  busquedas = 0;
  encontrados = 0;
  no_encontrados = 0;

  //------------------------------------------INICIO PRUEBA SECUENCIALES------------------------------------------
  cout<<"INICIO DE LA PRUEBA CON NUMEROS SECUENCIALES"<<endl;
  for(int i = 0; i < TAMANO; i++){
    llnode<int> *nodo = new llnode<int>(i);
    listaSec.listInsert(nodo);
  }
  cout<<"La lista se creo satisfactoriamente con "<< TAMANO<<" de elementos secuenciales."<<endl<<endl;
  cout<<"Busqueda de elementos aleatorios en 10 segundos:"<<endl;

  inicio = clock();
  while(tiempo_prueba < 10){
    temp = listaSec.listSearch(getRandom());
    busquedas++;
    if(temp != listaSec.getNil()){
      encontrados++;
    }
    else{
      no_encontrados++;
    }
    tiempo_prueba = (clock() - inicio) / (double) CLOCKS_PER_SEC;
  }

  cout << "cantidad de busquedas totales en 10 segundos: " << busquedas << endl;
  cout << "elementos encontrados: " << encontrados << endl;
  cout << "elementos no encontrados: " << no_encontrados << endl<<endl;

  //------------------------------------------FIN PRUEBA SECUENCIALES------------------------------------------
  tiempo_prueba=0;
  busquedas = 0;
  encontrados = 0;
  no_encontrados = 0;
  //------------------------------------------Linked List------------------------------------------



  //------------------------------------------Binary Search Tree------------------------------------------
  cout<<"INICIO DE LA PRUEBA PARA BINARY SEARCH TREE"<<endl<<endl;
  //------------------------------------------INICIO PRUEBA ALEATORIOS------------------------------------------
  cout<<"INICIO DE LA PRUEBA CON NUMEROS ALEATORIOS"<<endl;
  for(int i = 0; i < TAMANO; i++){
    node<int> *nodo = new node<int>(getRandom());
    arbolBRand.treeInsert(nodo);
  }

  cout<<"El arbol se creo satisfactoriamente con "<< TAMANO<<" de elementos aleatorios."<<endl<<endl;
  cout<<"Busqueda de elementos aleatorios en 10 segundos:"<<endl;

  inicio = clock();
  while(tiempo_prueba < 10){
    temp2 = arbolBRand.treeSearch(getRandom());
    busquedas++;
    if(temp2 != NULL){
      encontrados++;
    }
    else{
      no_encontrados++;
    }
    tiempo_prueba = (clock() - inicio) / (double) CLOCKS_PER_SEC;
  }

  cout << "cantidad de busquedas totales en 10 segundos: " << busquedas << endl;
  cout << "elementos encontrados: " << encontrados << endl;
  cout << "elementos no encontrados: " << no_encontrados << endl<<endl;

  //------------------------------------------FIN PRUEBA ALEATORIOS------------------------------------------
  tiempo_prueba=0;
  busquedas = 0;
  encontrados = 0;
  no_encontrados = 0;
  //------------------------------------------INICIO PRUEBA SECUENCIALES------------------------------------------
  cout<<"INICIO DE LA PRUEBA CON NUMEROS SECUENCIALES"<<endl;
  arbolBSec.treeInsert(new node<int>(0));
  node<int> *padre = arbolBSec.getRoot();
  for(int i = 1; i < TAMANO; i++){
    node<int> *nodo = new node<int>(i);
    arbolBSec.insercionSecuencial(padre, nodo);
    padre = nodo;
  }

  cout<<"El arbol se creo satisfactoriamente con "<< TAMANO<<" de elementos secuenciales."<<endl<<endl;
  cout<<"Busqueda de elementos aleatorios en 10 segundos:"<<endl;

  inicio = clock();
  while(tiempo_prueba < 10){
    temp2 = arbolBSec.iterativeTreeSearch(getRandom());
    busquedas++;
    if(temp2 != NULL){
      encontrados++;
    }
    else{
      no_encontrados++;
    }
    tiempo_prueba = (clock() - inicio) / (double) CLOCKS_PER_SEC;
  }

  cout << "cantidad de busquedas totales en 10 segundos: " << busquedas << endl;
  cout << "elementos encontrados: " << encontrados << endl;
  cout << "elementos no encontrados: " << no_encontrados << endl<<endl;

  //------------------------------------------FIN PRUEBA SECUENCIALES------------------------------------------

  //------------------------------------------Binary Search Tree------------------------------------------
  return 0;
}
