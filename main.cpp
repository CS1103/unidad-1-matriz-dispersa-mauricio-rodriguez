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
    MatrizDispersa m1(10,10);
    m1.rellenar();
    MatrizDispersa m2 =m1.transpuesta();
    MatrizDispersa m3=5*m1;
    MatrizDispersa m4 = m3*m1;
    return 0;
}