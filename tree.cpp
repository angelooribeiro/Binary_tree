#include<iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
    raiz = NULL;
}

bool Tree::insert_t(Nodo *node )
{
    if(raiz == NULL)    //if there is no tree, creates a new tree;
        raiz = node;        //if node == NULL still not existing tree

    else
        return raiz->insert_node(node);     //return 1 if success

    return true;
}

bool Tree::search_t(int numero)
{
    if( raiz->search_node(numero) )
        return true;

    else
        return false;
}

int Tree::tree_high()
{
        return raiz->search_high(raiz);
}

void Tree::imprime_t()
{
    int op = 0;
    cout << "Print as: " << endl;
    cout << "1. Pre-Order" << endl;
    cout << "2. Pos-Order" << endl;
    cout << "3. In-Order" << endl;
    cout << "3. Inverse In-Order" << endl;
    switch(op)
    {
        case(1):
            raiz->imprime_preordem(raiz);
        break;

        case(2):
            raiz->imprime_posordem(raiz);
        break;

        case(3):
            raiz->imprime_emordem(raiz);
        break;

        case(4):
            raiz->imprime_emordem_inv(raiz);
        break;

        default:
        break;
    }
}

int Tree::search_depth_t(int num)
{
    return raiz->search_depth(num, raiz, 0);
}

int Tree::remove_t(int numero)
{
    return raiz->delete_node(raiz, numero);
}
