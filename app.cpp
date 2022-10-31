#include <iostream>
using namespace std;

class Cola
{
private:
    class Nodo
    {
    public:
        char dato;
        Nodo *siguiente;
        Nodo(char d)
        {
            dato = d;
            siguiente = NULL;
        }
    };
    Nodo *frente;
    Nodo *fin;

public:
    Cola()
    {
        frente = fin = NULL;
    }
    void insertNodo(char d)
    {
        Nodo *nuevo = new Nodo(d);
        if (frente == NULL)
        {
            frente = nuevo;
            fin = nuevo;
        }
        else
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
    void removeNodo()
    {
        if (frente == NULL)
        {
            cout << "La cola esta vacia" << endl;
        }
        else
        {
            Nodo *aux = frente;
            frente = frente->siguiente;
            delete aux;
        }
    }
    void printCola()
    {
        Nodo *aux = frente;
        while (aux != NULL)
        {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
};

int main()
{
    Cola *cola = new Cola();
    cola->insertNodo('g');
    cola->insertNodo('e');
    cola->insertNodo('f');
    cola->insertNodo('a');
    cola->printCola();
    cola->removeNodo();
    cola->printCola();

    return 0;
}