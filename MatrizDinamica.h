#include <iostream>
using namespace std;

template <typename T>
class MatrizDinamica {
private:
    T **datos;
    int filas;
    int columnas;

public:
    // Constructor 
     MatrizDinamica(int f, int c) {
        filas = f;
        columnas = c;

        datos = new T*[filas];
        for (int i = 0; i < filas; i++)
            datos[i] = new T[columnas];
    }


    //Destructor
    ~MatrizDinamica() {
        for (int i = 0; i < filas; i++)
            delete[] datos[i];
        delete[] datos;
    }

    //Ingresar
    void ingresar() {
        cout << "Ingresa los valores de la matriz (" << filas << "x" << columnas << "):\n";
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "[" << i << "][" << j << "]: ";
                cin >> datos[i][j];
            }
        }
    }

    //Mostrar matriz
    void mostrar() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                cout << datos[i][j] << "\t";
            cout << endl;
        }
    }

    //Multiplicacion
    static MatrizDinamica<T> multiplicar(MatrizDinamica<T>& A, MatrizDinamica<T>& B) {
        if (A.columnas != B.filas) {
            cout << "No se pueden multiplicar (columnas A != filas B)\n";
            exit(1);
        }

        MatrizDinamica<T> C(A.filas, B.columnas);

        for (int i = 0; i < A.filas; i++) {
            for (int j = 0; j < B.columnas; j++) {
                C.datos[i][j] = 0;
                for (int k = 0; k < A.columnas; k++) {
                    C.datos[i][j] += A.datos[i][k] * B.datos[k][j];
                }
            }
        }

        return C;
    }
};