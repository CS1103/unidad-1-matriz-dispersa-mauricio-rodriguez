//
// Created by mauri on 29/08/2019.
//

#ifndef UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
#define UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H

typedef unsigned long int tipoEntero;
typedef unsigned int  tipoEntero2;
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
class MatrizDispersa {
private:
    int c_filas;int  dispersion;
    int c_columnas;
    tipoEntero c_noNulos;
    tipoEntero *vector_valores;
    tipoEntero *vector_pFilas;
    tipoEntero *vector_pColumnas;
    int sec_index;
    void mergeSort(tipoEntero A[],int p,tipoEntero r,tipoEntero B[]);
    void merge(tipoEntero A[],int p,tipoEntero q,tipoEntero r,tipoEntero B[]);
    int getElement(int firstIndex,int secondIndex);
public:
    MatrizDispersa();
    MatrizDispersa(const long int &,const  long int &);
    int* operator[](const int &);
    int operator[](const short int &);
    friend MatrizDispersa operator+(const MatrizDispersa &,const MatrizDispersa &);
    void rellenar();
    void ordenarMatriz();
    virtual ~MatrizDispersa();
    MatrizDispersa transpuesta();
};


#endif //UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
