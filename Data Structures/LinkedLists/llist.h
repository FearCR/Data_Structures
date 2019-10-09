#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia los atributos se dejan publicos.
		T key;
		llnode<T> *prev, *next;
		//enum colors color;

		// Constructor por omision.
		llnode(){
		};

      // Inicializacion de los datos miembro.
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};

		~llnode(){

		}
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{
	public:
		llist(){
      nil=new llnode<T>();
      nil->prev=nil;
      nil->next=nil;
		};
			// Constructor (crea una lista vacia)

		llist(const llist<T>& obj){
      nil=new llnode<T>*(obj.getNil()->key);
      nil->prev=nil;
      nil->next=nil;
      llnode<T> *nodoC=obj.getNil()->next;
      while(nodoC!=nil){
        listInsert(new llnode<T>(nodoC->key));
        nodoC=nodoC->next;
      }

		};
			// Constructor copia

		~llist(){
      llnode<T> *borra = nil->next;
      while(borra != nil){
        llnode<T> *tmp = borra->next;
        delete borra;
        borra = tmp;
      }
		};
			// Destructor (borra la lista)

		llnode<T>* listSearch(const T& k){
    llnode<T> *busca;
    busca=nil->next;
    while(busca!=nil && busca->key!=k){
      busca=busca->next;
    }
    return busca;
		};
			// Busca la llave iterativamente. Si la encuentra, devuelve un
            // apuntador al nodo que la contiene; sino devuelve NULL.

		void listInsert(llnode<T>* x){
      x->next=nil->next;
      nil->next->prev=x;
      nil->next=x;
      x->prev=nil;

		};
			// Inserta el nodo x en la lista.

		llnode<T>* listDelete(llnode<T>* x){
      x->prev->next=x->next;
      x->next->prev=x->prev;
      return x;
		};
			// Saca de la lista la llave contenida en el nodo apuntado por x.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		llnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve el nodo centinela. (Para efectos de revision de la tarea).

		private:

		llnode<T> *nil;	    // nodo centinela

};

#endif	// LINKED_LIST_llist
