#include <iostream>
#include "MatrizDinamica.h"

using namespace std;

int main() {
    MatrizDinamica<int> A(2,3);
    MatrizDinamica<int> B(3,2);

    cout<<"Matriz A: \n";
    A.ingresar();

    cout<<"Matriz B: \n";
    B.ingresar();
    
    return 0;
}