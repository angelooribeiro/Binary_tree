#include<iostream>
#include<cstring>
#include<queue>
#include "nodo.h"

using namespace std;

Nodo::Nodo(int numero, float media, string nome)
{
    this->numero = numero;
    this->media = media;
    this->nome = nome;
    this->left = NULL;
    this->right = NULL;
}

bool Nodo::insert_node(Nodo *node)
{
            //////goes left//////
    if(node->numero < this->numero)     //if the left is smaller goes left
    {

        if(this->left == NULL)          //if is empty
        {
            cout << "left" << endl;
            (this->left) = node; //insert a new nod with the date

            return true;        //return success
        }
        else
            (this->left)->insert_node(node);        //check the next in left
    }

        ///////goes right//////
    else  if(node->numero > this->numero)     //if the right is smaller goes right
        {
            if(this->right == NULL)         //if is empty
            {
                cout << "right" << endl;
                (this->right) = node; //insert a new nod with the date
                return true;
            }
            else
                (this->right)->insert_node(node);
        }

            ///////error/////
    else
        cerr << "Aluno " << numero << " - " << nome << " ja existe" << endl;
        return false;
}

bool Nodo::search_node(int numero)
{
    if(numero == this->numero)
    {
        cout << "encontrado:\n numero: " << numero << "\n nome: " << nome << "\n media: " << media << endl;
        return true;
    }

    //////goes left//////
    else if( (numero < this->numero)  &&  (this->left != NULL) )     //if the left is smaller goes left, if possible
            (this->left)->search_node(numero);        //check the next in left

        ///////goes right//////
    else  if( (numero > this->numero)  &&  (this->right != NULL) )     //if the right is smaller goes right, if possible
                (this->right)->search_node(numero);     //check the next one in the right

            ///////error/////
    else
        cerr << "Aluno " << numero << " nao existe" << endl;
        return false;
}

//raiz, esq, dta
void Nodo::imprime_preordem(Nodo *node)
{
    if(node!=NULL)      //se existir um nodo neste "nivel"
    {
        cout << "\nnome: " << node->nome << "\nnumero: " << node->numero << "\nmedia : " << node->media << endl;   //passa pela raiz
        imprime_preordem(node->left);     //vai para direita
        imprime_preordem(node->right);     //vai para esquerda
    }
    else
        return;
}

//esq, dta, raiz
void Nodo::imprime_posordem(Nodo *node)
{
    if(node!=NULL)      //se existir um nodo neste "nivel"
    {
        imprime_preordem(node->left);     //vai para direita
        imprime_preordem(node->right);     //vai para esquerda
        cout << "\nnome: " << node->nome << "\nnumero: " << node->numero << "\nmedia : " << node->media << endl;   //passa pela raiz
    }
    else
        return;
}

//esq, raiz, dta
void Nodo::imprime_emordem(Nodo *node)
{
    if(node!=NULL)      //se existir um nodo neste "nivel"
    {
        imprime_preordem(node->left);     //vai para direita
        cout << "\nnome: " << node->nome << "\nnumero: " << node->numero << "\nmedia : " << node->media << endl;   //passa pela raiz
        imprime_preordem(node->right);     //vai para esquerda
    }
    else
        return;
}

//esquerda, raiz, direita
void Nodo::imprime_emordem_inv(Nodo *node)
{
    if(node!=NULL)      //se existir um nodo neste "nivel"
    {
        imprime_preordem(node->right);     //vai para direita
        cout << "\nnome: " << node->nome << "\nnumero: " << node->numero << "\nmedia : " << node->media << endl;   //passa pela raiz
        imprime_preordem(node->left);     //vai para esquerda
    }
    else
        return;
}

int Nodo::search_high(Nodo *node)
{
    if(node != NULL)
    {
        int depth_left, depth_right;
        depth_left = search_high(node->left);
        depth_right = search_high(node->right);

        if(depth_left < depth_right)
            return ++depth_right;
        else
            return ++depth_right;
    }
    else
        return -1;
}

int Nodo::search_depth(int num, Nodo *node, int nivel)
{
    if(node != NULL)
    {
        if(num == node->numero)
            return nivel;
        else {
            ++nivel;

            if(num < node->numero)
                nivel = search_depth(num, node->left, nivel);
            else if(num > node->numero)
                nivel = search_depth(num, node->left, nivel);
        }
        return nivel;
    }
    else
        return -1;
}

Nodo* Nodo::noMaior(Nodo *node)
{
    Nodo *temp = NULL;

    if(temp->right == NULL)
    {
        node = node->left;
        return node;
    } else
    return noMaior(node -> right);
}

int Nodo::delete_node(Nodo *node, int numero)
{
    Nodo *temp = NULL;

    if(node == NULL)
        return 1;
    if(numero == node->numero)
    {
        temp = node;
        if(node->left == NULL)
            node = node->right;
        else
            if(node->right == NULL)
            node = node->left;
        else
        {
            temp = noMaior(node->left);
            node->numero = temp->numero;
        }
        delete temp;
        return 0;
    } else if( numero < node->numero)
        return delete_node(node->left, numero);
    else
        return delete_node(node->right, numero);
}
