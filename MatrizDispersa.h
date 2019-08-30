//
// Created by mauri on 29/08/2019.
//

#ifndef UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
#define UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H

typedef int tipoEntero;

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
class MatrizDispersa {
private:
    int c_filas;int  dispersion; int c_columnas;
    int c_noNulos;
    tipoEntero *vector_valores;
    tipoEntero *vector_pFilas;
    tipoEntero *vector_pColumnas;
public:
    MatrizDispersa();
    MatrizDispersa(int &, int &);
    int operator[](const int &);
    friend MatrizDispersa operator+(const MatrizDispersa &,const MatrizDispersa &);
    void rellenar();
    void imprimirMatriz();
    virtual ~MatrizDispersa();
};


#endif //UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
