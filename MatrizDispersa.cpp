//
// Created by mauri on 29/08/2019.
//

#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(const long int &cFilas,const long int &cColumnas) : c_filas(cFilas), c_columnas(cColumnas) {
    dispersion=10+rand()%40;
    c_noNulos=int((dispersion*c_filas*c_columnas)/100);
    vector_pColumnas= new tipoEntero[c_noNulos];
    vector_pFilas= new tipoEntero[c_noNulos];
    vector_valores = new tipoEntero[c_noNulos];
}

MatrizDispersa::~MatrizDispersa() {
    delete [] vector_pColumnas;
    delete [] vector_pFilas;
    delete [] vector_valores;
}

MatrizDispersa::MatrizDispersa():c_filas(0),c_columnas(0),c_noNulos(0),vector_valores(nullptr),
vector_pColumnas(nullptr),vector_pFilas(nullptr),dispersion(0){}

void MatrizDispersa::rellenar() {
    //se asignan valores del 1 al 99 a la matriz
    for (tipoEntero i=0;i<c_noNulos;i++){
        vector_valores[i]=3;
        // se asignan las coordenadas
        vector_pFilas[i] = rand() % (c_filas + 1);
        vector_pColumnas[i] = rand() % (c_columnas + 1);
        // se busca que no se repitan
        for (tipoEntero j=0;j<i;j++){
            if (vector_pFilas[i]==vector_pFilas[j]&&vector_pColumnas[i]==vector_pColumnas[j]){
            vector_pFilas[i]=rand()%(c_filas+1);
            vector_pColumnas[i]=rand()%(c_columnas+1);}
        }
    }
}

int MatrizDispersa::getElement(int firstIndex, int secondIndex) const {
    for (unsigned int i=0;i<c_noNulos;i++)
        if(vector_pFilas[i]==firstIndex &&vector_pColumnas[i]==secondIndex)
            return vector_valores[i];
        else
            return 0;
    return 0;
}

MatrizDispersa MatrizDispersa::transpuesta() {
    MatrizDispersa temp;
    temp.vector_valores=new tipoEntero[c_noNulos];
    temp.vector_pColumnas = new tipoEntero[c_noNulos];
    temp.vector_pFilas= new tipoEntero[c_noNulos];
    temp.c_filas=c_columnas;
    temp.c_columnas=c_filas;
    for (tipoEntero i=0;i<c_noNulos;i++){
        temp.vector_valores[i]=vector_valores[i];
        temp.vector_pColumnas[i]=vector_pFilas[i];
        temp.vector_pFilas[i]=vector_pColumnas[i];
    }
    return temp;
}

MatrizDispersa operator*(const MatrizDispersa & M1, const MatrizDispersa & M2) {
    vector<tipoEntero> temporal_valores;
    vector<tipoEntero> temporal_filas;
    vector<tipoEntero> temporal_columnas;
    int valor=0;
    if (M1.c_columnas==M2.c_filas){
        MatrizDispersa temp;
        for (int k=0;k<M1.c_filas;k++) {
            for (int i = 0; i < M1.c_filas; i++) {
                for (int j = 0; j < M2.c_columnas; j++) {
                    valor += M1.getElement(k, j) * M2.getElement(j, i);
                }
                if (valor != 0) {
                    temporal_valores[i] = valor;
                    temporal_filas[i] = k;
                    temporal_columnas[i]=i;
                }
            }
        }
        temp.vector_valores=new tipoEntero[temporal_valores.size()];
        temp.vector_pColumnas = new tipoEntero[temporal_valores.size()];
        temp.vector_pFilas= new tipoEntero[temporal_valores.size()];
        for (int i=0;i<temporal_valores.size();i++){
            temp.vector_pColumnas[i]=temporal_columnas[i];
            temp.vector_pFilas[i]=temporal_filas[i];
            temporal_valores[i]=temporal_valores[i];
        }
        return temp;
    }
    else throw logic_error("No es posible efectuar la multiplicacion");

}
MatrizDispersa operator+(const MatrizDispersa &M1, const MatrizDispersa &M2) {
    MatrizDispersa M3;
    int suma_index=0;
    for (int i=0;i<M1.c_filas;i++)
        for (int j=0;j<M1.c_columnas;j++)
            if (M1.getElement(i,j) !=0 || M2.getElement(i,j)!=0)
                M3.c_noNulos++;

    M3.vector_valores=new tipoEntero[M3.c_noNulos];
    M3.vector_pColumnas = new tipoEntero[M3.c_noNulos];
    M3.vector_pFilas= new tipoEntero[M3.c_noNulos];
    if (M1.c_filas ==M2.c_filas && M1.c_columnas==M2.c_columnas){
        for (int i=0;i<M1.c_filas;i++){
            for (int j=0;j<M2.c_columnas;j++){
                if (M1.getElement(i,j)==0 && M2.getElement(i,j)){}
                else {
                    M3.vector_valores[suma_index]=M1.getElement(i,j)+M2.getElement(i,j);
                    M3.vector_pFilas[suma_index]=i;
                    M3.vector_pColumnas[suma_index++]=j;
                }
            }
        }
        return M3;
    }
    else
        throw logic_error("Las matrices tienen diferentes dimensiones");
}
int MatrizDispersa::operator[](const short int & first_index) {
    cout<<first_index<<sec_index;
    return getElement(first_index, sec_index);
}


int* MatrizDispersa::operator[](const int & second_index) {
    sec_index=second_index;
    return ((*this)[second_index]);
}

MatrizDispersa operator*(const int & valor, const MatrizDispersa & M1) {
    MatrizDispersa temp;
    temp.vector_valores=new tipoEntero[M1.c_noNulos];
    temp.vector_pColumnas = new tipoEntero[M1.c_noNulos];
    temp.vector_pFilas= new tipoEntero[M1.c_noNulos];
    for (int i=0;i<M1.c_noNulos;i++){
        temp.vector_valores[i]=M1.vector_valores[i]*valor;
        temp.vector_pColumnas[i]=M1.vector_pColumnas[i];
        temp.vector_pFilas[i]=M1.vector_pFilas[i];
    }
    return temp;
}
