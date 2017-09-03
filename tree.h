#ifndef TREE_H
#define TREE_H
#include "nodo.h"

class Tree{
    //private:
    Nodo *raiz;     //pointer for the first element in the tree;

    public:
    Tree();             //constructor
    bool insert_t(Nodo *node = NULL);    //insert an element
    bool search_t(int numero=0);                    //search for an element
    void imprime_t();       //impressao da arvore em pre-ordem, pos-ordem em-ordem
    int tree_high();           //retorna a altura da arvore
    int search_depth_t(int num);
    int remove_t(int numero);
    ~Tree() {};         //destructor
};

#endif // TREE_H
