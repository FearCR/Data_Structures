
#include <iostream>
#include <ctime>
#include <random>

#include "llist.h"



#define TAMANO 1000000

using namespace std;

int getRandom(){
    int random=rand() % (2*TAMANO);
    return random;
}


int main(int argc, char const *argv[]){

	llist<int> listaSec;
	llist<int> listaRand;

	double tiempo_prueba=0;
	int busquedas = 0;
	int encontrados = 0;
	int no_encontrados = 0;
  clock_t inicio;

	llnode<int> *temp;
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
	return 0;
}
