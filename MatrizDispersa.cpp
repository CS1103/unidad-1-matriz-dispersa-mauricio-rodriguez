//
// Created by mauri on 29/08/2019.
//

#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(int &cFilas, int &cColumnas) : c_filas(cFilas), c_columnas(cColumnas) {
    dispersion=rand()%50;
    c_noNulos=(dispersion/100)*c_filas*cFilas;
    vector_pColumnas= new tipoEntero[c_noNulos];
    vector_pFilas= new tipoEntero[c_noNulos];
    vector_valores = new tipoEntero[c_noNulos];
}

MatrizDispersa::~MatrizDispersa() {
    delete [] vector_pColumnas;
    delete [] vector_pFilas;
    delete [] vector_valores;
}
MatrizDispersa operator+(const MatrizDispersa &M1, const MatrizDispersa &M2) {
    return MatrizDispersa();
}

int MatrizDispersa::operator[](const int &) {
    return 0;
}

MatrizDispersa::MatrizDispersa():c_filas(0),c_columnas(0){
    vector_pColumnas= nullptr;
    vector_pFilas= nullptr;
    vector_valores = nullptr;
}

void MatrizDispersa::rellenar() {
    //se asignan valores del 1 al 99 a la matriz
    for (int i=0;i<c_noNulos;i++){
        vector_valores[i]=1+rand()%100;
        // se asignan las coordenadas
        vector_pFilas[i]= rand()%c_filas+1;
        vector_pColumnas[i]= rand()%c_columnas+1;
    }

}

void MatrizDispersa::imprimirMatriz() {
    int sup=0;
    int contador=0;
    int i_temporal=0;
    //se cuenta cantidad de valores en la fila sup
    for (int i=0;i<c_noNulos;i++){
        if (vector_pFilas[i]==sup)
            contador++;
    }
    //se asignan la posicion de columna al vector temporal
    auto *temporal= new tipoEntero[contador];
    for (int i=0;i<c_noNulos;i++){
        if (vector_pFilas[i]==sup){
            temporal[i_temporal]=vector_pColumnas[i];
            i_temporal++;}
    }
    // se comparan

    //imprime
    for (int i=0;i<c_filas;i++){
            if (vector_pFilas[i]==i) {
                for (int j = 0; j <c_columnas; j++) {
                }
            }
            else{
                cout<<0<<"/t";
            }
            cout<<endl;
    }
}
