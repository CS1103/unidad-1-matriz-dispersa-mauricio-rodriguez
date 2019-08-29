//
// Created by mauri on 29/08/2019.
//

#ifndef UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
#define UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H

typedef int tipoEntero;

#include <time.h>
#include <cstdlib>
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
    MatrizDispersa &operator+(MatrizDispersa &);

    virtual ~MatrizDispersa();
};


#endif //UNIDAD_1_MATRIZ_DISPERSA_MAURICIO_RODRIGUEZ_MATRIZDISPERSA_H
