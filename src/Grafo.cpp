#include "Grafo.h"

Grafo::Grafo()
{
    primero = nullptr;
}

Vertice::Vertice(char dato)
{
    this->dato = dato;
    this->primerAdy = nullptr;
    this->siguiente = nullptr;
}

Vertice* Vertice::getSiguiente()
{
    return siguiente;
}

void Vertice::setSiguiente(Vertice* d)
{
    siguiente = d;
}

Arista* Vertice::getPrimeraAdy()
{
    return primerAdy;
}
Vertice* Grafo::getPrimero()
{
    return primero;
}
void Vertice::setPrimerAdy(Arista* p)
{
    primerAdy = p;
}

char Vertice::getDato()
{
    return dato;
}

void Vertice::setDato(char d)
{
    dato = d;
}

Arista::Arista(int ponderacion)
{
    this->ponderacion = ponderacion;
    this->destino = nullptr;
    this->sigArista = nullptr;
}

Arista* Arista::getSigarista()
{
    return sigArista;
}

void Arista::setSigArista(Arista* ss)
{
    sigArista = ss;
}

Vertice* Arista::getDestino()
{
    return destino;
}

void Arista::setDestino(Vertice* pp)
{
    destino = pp;
}
void Grafo::insertarVertice(char dato)
{
    Vertice* nuevo = new Vertice(dato);

    if(primero == nullptr)
    {
        primero = nuevo;
    }else
    {
        Vertice* aux;
        aux = primero;

        while(aux->getSiguiente() != nullptr)
        {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}
Vertice* Grafo::localiza(char dato)
{
    Vertice* aux;
    aux = primero;

    while(aux != nullptr)
    {
        if(aux->getDato() == dato)
            return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}
void Grafo::insertarArista(Vertice* origen, Vertice* desti, int ponde)
{
    Vertice* aux;
    Arista* nuevo = new Arista(ponde);

    if(origen->getPrimeraAdy() == nullptr)
    {
        origen->setPrimerAdy(nuevo);
        nuevo->setDestino(desti);
    }else
    {
        Arista* aux;
        aux = origen->getPrimeraAdy();
        while(aux->getSigarista() != nullptr)
        {
            aux = aux->getSigarista();
        }
        aux->setSigArista(nuevo);
        nuevo->setDestino(desti);
    }
}
string Grafo::toString()
{
    if(primero == nullptr)
        return "Vacio";
    Vertice* aux;
    aux = primero;
    Arista* auxAris;
    string cadena = "";
    while(aux != nullptr)
    {
        cadena += aux->getDato();
        auxAris = aux->getPrimeraAdy();
         while(auxAris != nullptr)
         {
            cadena+="->";
            cadena+=auxAris->getDestino()->getDato();
            auxAris = auxAris->getSigarista();
         }
         cadena+="\n";
         aux = aux->getSiguiente();
    }
    return cadena;
}
