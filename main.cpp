#include <iostream>
#include "MatrizDinamica.h"

using namespace std;

int main() {
    cout << "MATRIZ INT\n";
    MatrizDinamica<int> A(2,3);
    MatrizDinamica<int> B(3,2);

    cout<<"Matriz A: \n";
    A.ingresar();

    cout<<"Matriz B: \n";
    B.ingresar();

    cout<<"Multiplicacion de A x B\n";
    MatrizDinamica<int> C = MatrizDinamica<int>::multiplicar(A, B);
    C.mostrar();

    cout << "\nRedimensionando la matriz C a (3x3)...\n";
    C.redimensionar(3, 3);
    C.mostrar();

    cout << "\nMATRIZ FLOAT\n";
    MatrizDinamica<float> X(2, 2);
    MatrizDinamica<float> Y(2, 2);

    cout<<"Matriz X: \n";
    X.ingresar();
    cout<<"Matriz Y: \n";
    Y.ingresar();

    cout<<"Multiplicacion de X x Y\n";
    MatrizDinamica<float> Z = MatrizDinamica<float>::multiplicar(X, Y);
    Z.mostrar();

    cout<<"Memoria liberada\n";
    
    return 0;
}