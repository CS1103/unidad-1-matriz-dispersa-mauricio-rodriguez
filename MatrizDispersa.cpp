//
// Created by mauri on 29/08/2019.
//

#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(int &cFilas, int &cColumnas) : c_filas(cFilas), c_columnas(cColumnas) {
    dispersion=rand()%50;
    c_noNulos=c_filas*cFilas-(dispersion/100)*c_filas*cFilas;
    vector_pColumnas= new tipoEntero[c_noNulos];
    vector_pFilas= new tipoEntero[c_noNulos];
    vector_valores = new tipoEntero[c_noNulos];
}

MatrizDispersa::~MatrizDispersa() {
    delete [] vector_pColumnas;
    delete [] vector_pFilas;
    delete [] vector_valores;
}
