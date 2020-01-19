#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <string>
using namespace std;
class Arista;
class Vertice
{
    public:
        Vertice(char);
        Vertice* getSiguiente();
        void setSiguiente(Vertice*);

        Arista* getPrimeraAdy();
        void setPrimerAdy(Arista*);
        char getDato();
        void setDato(char);
    private:
        Vertice* siguiente;
        Arista* primerAdy;
        char dato;

};
class Arista
{
    public:
        Arista(int);

        Arista* getSigarista();
        void setSigArista(Arista*);
        Vertice* getDestino();
        void setDestino(Vertice*);
    private:
        Arista* sigArista;
        Vertice* destino;
        int ponderacion;

};
class Grafo
{
    public:
        Grafo();
        void insertarVertice(char);
        void insertarArista(Vertice*,Vertice*,int);
        Vertice* localiza(char);
        Vertice* getPrimero();
        string toString();
    private:
        Vertice* primero;
};

#endif // GRAFO_H
