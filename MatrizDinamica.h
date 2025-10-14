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

    //Métodos de gestión y operaciones
};