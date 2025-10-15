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

    cout<<"Multiplicacion de A x B\n";
    MatrizDinamica<int> C = MatrizDinamica<int>::multiplicar(A, B);
    C.mostrar();
    
    return 0;
}