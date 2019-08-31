//
// Created by mauri on 29/08/2019.
//

#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(const int &cFilas,const int &cColumnas) : c_filas(cFilas), c_columnas(cColumnas) {
    dispersion=1+rand()%50;
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
    return MatrizDispersa();
}

int MatrizDispersa::operator[](const int &) {
    return 0;
}

MatrizDispersa::MatrizDispersa():c_filas(0),c_columnas(0),c_noNulos(0),vector_valores(nullptr),
vector_pColumnas(nullptr),vector_pFilas(nullptr),dispersion(0){}

void MatrizDispersa::rellenar() {
    //se asignan valores del 1 al 99 a la matriz
    for (int i=0;i<c_noNulos;i++){
        vector_valores[i]=1+rand()%100;
        // se asignan las coordenadas
        vector_pFilas[i]= rand()%(c_filas+1);
        vector_pColumnas[i]= rand()%(c_columnas+1);
    }

}

void MatrizDispersa::imprimirMatriz() {
    int sup=0;
    int contador=0;
    //se cuenta cantidad de valores en la fila sup
    //impresion prueba
    cout<<"valores no nulos: "<<endl;
    for(int i=0;i<c_noNulos;i++)
        cout<<vector_valores[i]<<"["<<vector_pFilas[i]<<","<<vector_pColumnas[i]<<"] ";
    cout<<endl;
    for (int i=0;i<c_noNulos;i++)
        if (vector_pFilas[i]==sup)
            contador++;

    //se asignan la posicion de columna del valor al vector temporal
    auto *temporal= new tipoEntero[contador];
    auto *row_index= new tipoEntero[contador];
    contador =0;
    for (int i=0;i<c_noNulos;i++){
        if (vector_pFilas[i]==sup){
            temporal[contador]=vector_pColumnas[i];
            row_index[contador]=i;
            contador++;
        }
    }
    //prueba
    cout<<"cantidad de no nulos "<<c_noNulos<<endl;
    cout<<"cantidad no nulos en fila "<<sup<<": "<<contador<<endl;
    for (int i=0;i<contador;i++)
        cout<<"["<<sup<<","<<temporal[i]<<"]"<<" c= "<<row_index[i]<<" v= "<<vector_valores[row_index[i]]<<" || ";
    cout<<endl;
    // se ordena la matriz temporal con su respectivo indice guardado
    MatrizDispersa::mergeSort(temporal,0,contador,row_index);
    // se imprime ordenado
    cout<<"cantidad de no nulos "<<c_noNulos<<endl;
   cout<<"cantidad no nulos en fila "<<sup<<": "<<contador<<endl;
   for (int i=0;i<contador;i++)
       cout<<"["<<sup<<","<<temporal[i]<<"]"<<" c= "<<row_index[i]<<" v= "<<vector_valores[row_index[i]]<<" || ";

    delete [] temporal;
}

void MatrizDispersa::mergeSort(int *A, int p, int r,int *B) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(A, p, q,B);
        mergeSort(A, q + 1, r,B);
        merge(A, p, q, r,B);
    }
}
void MatrizDispersa::merge(int *A, int p,int q, int r,int*B){
        int n1,n2,i,j,k;
        //size of left array=n1
        //size of right array=n2
        n1=q-p+1;
        n2=r-q;
        int L[n1],R[n2];
        int L1[n1],R1[n2];
        //initializing the value of Left part to L[]
        for(i=0;i<n1;i++)
        {
            L[i]=A[p+i];
            L1[i]=B[p+i];
        }
        //initializing the value of Right Part to R[]
        for(j=0;j<n2;j++)
        {
            R[j]=A[q+j+1];
            R1[j]=B[q+j+1];
        }
        i=0,j=0;
        //Comparing and merging them
        //into new array in sorted order
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
        //If Left Array L[] has more elements than Right Array R[]
        //then it will put all the
        // reamining elements of L[] into A[]
        while(i<n1)
        {
            B[k]=L1[i];
            A[k++]=L[i++];
        }
        //If Right Array R[] has more elements than Left Array L[]
        //then it will put all the
        // reamining elements of L[] into A[]
        while(j<n2)
        {
            B[k]=R1[j];
            A[k++]=R[j++];
        }
}

