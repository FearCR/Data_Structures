#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>
using namespace std;
// Nodos del arbol:
template <typename T>
class node{
public:
  // Esta clase es usada por otras clases.
  // Para mayor eficiencia, los atributos se hacen publicos.
  T key;
  node<T> *p, *left, *right;

  // Constructor por omision
  node(){
  };

  // Constructor por copia. Copia el nodo y sus hijos.
  node(const node<T> * obj, node<T> * padre){
    key = obj->key;
    p = padre;
    left = obj->left;
    right = obj->right;
  }

  // Inicializacion de datos miembro
  node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL):key(k), p(w), left(y), right(z){};

  ~node(){
  }
};

// Arbol:
template <typename T>
class tree{
public:
  tree(){
    root = NULL;
  };
  // Constructor. Crea un arbol vacio

  tree(const tree<T>& obj){
    cCopiaRecursivo(obj.getRoot(), NULL);
  };
  // Constructor copia

  ~tree(){
    destructorRecursivo(root);
  };
  // Destructor (borra el arbol)

  void inorderTreeWalk(node<T>* x, stack<T> & pila){
    if(x->left){
      inorderTreeWalk(x->left, pila);
    }
    pila.push(x->key);
    if(x->right){
      inorderTreeWalk(x->right, pila);
    }
  };

  // Efectua un recorrido en orden del sub�rbol cuya raiz es apuntada
  // por x, guardando en cada visita la llave de cada nodo en la pila.
  // Es decir, cada vez que se llega a un nodo se hace
  // pila.push(x->key). Si se hace correctamente, al finalizar el
  // metodo la pila debe contener las llaves de los nodos del
  // subarbol ordenadas de mayor a menor.


  node<T>* treeSearch(const T& k){
    return treeSearchRecursivo(root, k);
  };
  // Busca la llave recursivamente; si la encuentra, devuelve un
  // apuntador al nodo que la contiene, sino devuelve NULL

  node<T>* iterativeTreeSearch(const T& k){
    node<T> *busca = root;
    while(busca!=NULL && (busca->key != k)){
      if(k < busca->key){
        busca = busca->left;
      }
      else{
        busca = busca->right;
      }
    }
    return busca;
  };
  // Lo mismo que en el anterior pero usando un procedimiento
  // iterativo

  node<T>* treeMinimum(){
    node<T>* busca = root;
    while(busca->left!=NULL){
      busca = busca->left;
    }
    return busca;
  };
  // Devuelve el nodo que tiene la llave menor.
  // Si el arbol est� vacio devuelve NULL.

  node<T>* treeMaximum(){
    node<T>* busca = root;
    while(busca->right!=NULL){
      busca = busca->right;
    }
    return busca;
  };
  // Devuelve el nodo que tiene la llave mayor.
  // Si el arbol esta vacio devuelve NULL.

  node<T>* treeSuccessor(const node<T>* x){
    if(x->right!=NULL){
      return subTreeMinimum(x->right);
    }
    else{
      bool has = true;
      node<T> *aux = new node<T>(x, x->p);
      node<T> *suc = aux->p;
      while (has && suc!=NULL) {
        if(suc->left == aux){
          has = false;
        }
        else{
          aux = suc;
          suc = suc->p;
        }
      }
      return suc;
    }
  };
  // Devuelve el nodo cuya llave es la que le sigue a la
  // del nodo x. Si no existe tal nodo devuelve NULL.

  void treeInsert(node<T>* z){
    node<T> *y = NULL;
    node<T> *x = root;
    while (x != NULL){
      y = x;
      if( z->key < x->key ){
        x =x->left;
      }else{
        x =x->right;
      }
    }
    z->p = y;
    if(y==NULL){
      root = z;
    }else if(z->key < y->key){
      y->left = z;
    }else{
      y->right = z;
    }
  };
  // Inserta el nodo z en la posicion que le corresponde en el arbol.
  void insercionSecuencial(node<T> *padre,node<T> *hijoDer){
    hijoDer->p = padre;
    padre->right = hijoDer;
    padre->left = NULL;
  };
  //inserta rapidamente una serie de numeros ascendentes
  node<T>* treeDelete(node<T>* z){
    if(z->left==NULL){
      replace(z, z->right);
    }else if(z->right==NULL){
      replace(z, z->left);
    }else{
      node<T> *aux = subTreeMinimum(z->right);
      if(aux->p != z){
        replace(aux, aux->right);
        aux->right = z->right;
        aux->right->p = aux;
      }
      replace(z, aux);
      aux->left = z->left;
      aux->left->p = aux;
    }
    return z;
  };
  // Saca del arbol la llave contenida en el nodo apuntado por z.
  // Devuelve la direccion del nodo eliminado para que se pueda
  // disponer de ella.

  node<T> * getRoot() const{
    return this->root;
  };
  // Devuelve la raiz del arbol. (Para efectos de revisi�n de la tarea).

private:
  node<T> *root;	// root of the Tree

  node<T>* treeSearchRecursivo(node<T> *raiz, const T& k){
    if(raiz==NULL || k == raiz->key){
      return raiz;
    }
    else if(k < raiz->key){
      return treeSearchRecursivo(raiz->left, k);
    }
    else {
      return treeSearchRecursivo(raiz->right, k);
    }
  };

  void cCopiaRecursivo(node<T> *n, node<T> *m){
    node<T> *z = new node<T>(n->key, m);
    treeInsert(z);
    if(n->left){
      cCopiaRecursivo(n->left, m);
    }
    if(n->right){
      cCopiaRecursivo(n->right, m);
    }
  };
  void destructorRecursivo(node<T> *borra){
    if(borra!=NULL){
      if(borra->left!=NULL){
        destructorRecursivo(borra->left);
      }
      if(borra->right!=NULL){
        destructorRecursivo(borra->right);
      }
      delete borra;
    }
  }
  node<T>* subTreeMinimum(node<T> *z){
    node<T> *n = z;
    while(n->left){
      n = n->left;
    }
    return n;
  };
  void replace(node<T> *u, node<T> *v){
    if(u->p==NULL){
      root = v;
    } else if(u == u->p->left){
      u->p->left = v;
    }else{
      u->p->right = v;
    }
    if(v!=NULL){
      v->p = u->p;
    }
  };

};
#endif	// BINARY_SEARCH_Tree
