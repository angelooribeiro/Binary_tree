#ifndef NODO_H
#define NODO_H
#include "info.h"
#include <string>
#include <iostream>

using namespace std;

class Nodo{
    Nodo *left;     //pointer for the left
    Nodo *right;    //pointer for the right
    //Nodo *info;
    int numero;
    string nome;
    float media;

    public:
    Nodo(int, float, string);      //constructor, default
    bool insert_node(Nodo *node = NULL);        //insert an element in the tree
    bool search_node(int numero=0);        //search for an element returns the adress
    void imprime_preordem(Nodo *node = NULL);   // impressao em pre ordem
    void imprime_posordem(Nodo *node = NULL);   // pos ordem
    void imprime_emordem(Nodo *node = NULL);    //e em ordem
    void imprime_emordem_inv(Nodo *node = NULL); //em ordem inversa
    int search_high(Nodo *node = NULL);       //profundidade da arvore
    int search_depth(int num, Nodo *node = NULL, int nivel=0);   //procura a que profundidade se encontra um determinado nodo
    Nodo* noMaior(Nodo *node = NULL);
    int delete_node(Nodo *node = NULL, int numero = 0);      //remove um elemento
    ~Nodo() {};    //default destructor
};

#endif // NODO_H
