#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "tree.h"

using namespace std;

void imprime_menu()
{
    cout << "1. insert student" << endl;
    cout << "2. search student" << endl;
    cout << "3. tree high size" << endl;
    cout << "4. Pre-Ordem" << endl;
    cout << "5. Search depth" << endl;
    cout << "6. Delete element" << endl;
    cout << "0 to exit" << endl;
}

int main()
{
    Tree tree;
    Nodo *node;

    int numero = 0;         //numero do aluno
    float media = 0;       //media do aluno
    string nome;        //nome para inserir
    int op = 0;       //para o switch

    do
    {
        imprime_menu();
        cin >> op;

        switch(op)
        {
            case(1):        //inserir novo elemento
                cout << "insert numero" << endl;
                cin >> numero;
                cout << "insert name" << endl;
                cin >> nome;
                cout << "insert media" << endl;
                cin >> media;

                node = new Nodo(numero, media, nome);
                if(tree.insert_t(node))
                    cout << "Aluno inserido\n" << endl;
            break;

            case(2):        //procura de um elemento (nao completa)
                cout << "number of an element to search" << endl;
                cin >> numero;
                tree.search_t(numero);
            break;

            case(3):
                cout << tree.tree_high() << endl;
            break;

            case(4):
                tree.imprime_t();
            break;

            case(5):
                cout << "insert the number of the student" << endl;
                cin >> numero;
                cout << "o elemento esta na profundidade" << tree.search_depth_t(numero) << endl;
            break;

            case(6):
                cout << "insert a number of the element to remove" << endl;
                cin >> numero;
                if( tree.remove_t(numero) == 0)
                    cout<< "element removed with sucess" << endl;
                else
                    cout << "element not removed" << endl;

            default:
            break;
        }
    } while( op!=0 );


    getchar();
    return 0;
}
