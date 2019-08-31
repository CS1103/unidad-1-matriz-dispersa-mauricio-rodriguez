#include <iostream>
#include <cassert>
#include "MatrizDispersa.h"
#include <time.h>
//using namespace std;

int main() {
    srand(time(nullptr));
    //MatrizDispersa M1(4,4);

    //MatrizDispersa M2;
    //MatrizDispersa M3= M1+M2;
    //string resultado;
    auto *m1= new MatrizDispersa(10,10);
    m1->rellenar();
    m1->imprimirMatriz();
    delete m1;
    return 0;
}