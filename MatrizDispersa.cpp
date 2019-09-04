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
MatrizDispersa operator+(const MatrizDispersa &M1, const MatrizDispersa &M2) {
    if (M1.c_filas ==M2.c_filas && M1.c_columnas==M2.c_columnas){
        MatrizDispersa M3;
        for (unsigned int i=0;i<M1.c_columnas;i++){

        }
        return M3;
    }
    else
        throw logic_error("Las matrices tienen diferentes dimensiones");
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

void MatrizDispersa::ordenarMatriz() {
    {
    long int sup=0;
    tipoEntero contador=0;
    for (tipoEntero i=0;i<c_noNulos;i++)
        if (vector_pFilas[i]==sup)
            contador++;
    //se asignan la posicion de columna del valor al vector temporal
    auto *temporal= new tipoEntero[contador];
    auto *row_index= new tipoEntero[contador];
    contador =0;
    for (tipoEntero i=0;i<c_noNulos;i++){
        if (vector_pFilas[i]==sup){
            temporal[contador]=vector_pColumnas[i];
            row_index[contador]=i;
            contador++;
        }
    }
    // se ordena la matriz temporal con su respectivo indice guardado
    MatrizDispersa::mergeSort(temporal,0,contador-1,row_index);
   for (tipoEntero i=0;i<contador;i++)
       cout<<"["<<sup<<","<<temporal[i]<<"]"<<" v= "<<vector_valores[row_index[i]]<<" || ";

    delete [] temporal;
    delete [] row_index;
    }
}

void MatrizDispersa::mergeSort(tipoEntero *A, int p, tipoEntero r,tipoEntero *B) {
    tipoEntero q;
    q = (p + r) / 2;
    if (p < r) {
        mergeSort(A, p, q,B);
        mergeSort(A, q + 1, r,B);
        merge(A, p, q, r,B);
    }
}
void MatrizDispersa::merge(tipoEntero *A, int p,tipoEntero q, tipoEntero r,tipoEntero *B){
        tipoEntero n1,n2,i,j,k;
        n1=q-p+1;
        n2=r-q;
        tipoEntero L[n1]; tipoEntero R[n2];
        tipoEntero L1[n1]; tipoEntero R1[n2];
        for(i=0;i<n1;i++)
        {
            L[i]=A[p+i];
            L1[i]=B[p+i];
        }
        for(j=0;j<n2;j++)
        {
            R[j]=A[q+j+1];
            R1[j]=B[q+j+1];
        }
        i=0,j=0;
        for(k=p;i<n1&&j<n2;k++)
        {
            if(L[i]<R[j])
            {
                B[k]=L1[i];
                A[k]=L[i++];
            }
            else
            {
                B[k]=R1[j];
                A[k]=R[j++];
            }
        }
        while(i<n1)
        {
            B[k]=L1[i];
            A[k++]=L[i++];
        }
        while(j<n2)
        {
            B[k]=R1[j];
            A[k++]=R[j++];
        }
}

int MatrizDispersa::operator[](const short int & first_index) {
    cout<<first_index<<sec_index;
    return getElement(first_index, sec_index);
}


int* MatrizDispersa::operator[](const int & second_index) {
    sec_index=second_index;
    return ((*this)[second_index]);
}


int MatrizDispersa::getElement(int firstIndex, int secondIndex) {
    for (unsigned int i=0;i<c_noNulos;i++)
        if(  vector_pFilas[i]==firstIndex &&vector_pColumnas[i]==secondIndex)
            return vector_valores[i];
    return 0;
}

MatrizDispersa MatrizDispersa::transpuesta() {
    MatrizDispersa temp;
    temp.vector_valores=new tipoEntero[c_noNulos];
    temp.vector_pColumnas = new tipoEntero[c_noNulos];
    temp.vector_pFilas= new tipoEntero[c_noNulos];
    for (tipoEntero i=0;i<c_noNulos;i++){
        temp.vector_valores[i]=vector_valores[i];
        temp.vector_pColumnas[i]=vector_pFilas[i];
        temp.vector_pFilas[i]=vector_pColumnas[i];
    }
    return temp;
}
