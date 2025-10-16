#include <iostream>
#include <stdexcept> //para manejar errores

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
        for (int i = 0; i < filas; i++){
            datos[i] = new T[columnas];
            for (int j = 0; j < columnas; j++)
                datos[i][j] = 0;
        }
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
    void mostrar() const{
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

    //Redimensionar la matriz
    void redimensionar(int nuevaF, int nuevaC) {
        // Crear nueva matriz
        T **nueva = new T*[nuevaF];
        for (int i = 0; i < nuevaF; i++){
            nueva[i] = new T[nuevaC];
            for (int j = 0; j < nuevaC; j++)
                nueva[i][j] = 0; // inicializa en 0
        }

        //Copiar los valores
        int minFilas = (nuevaF < filas) ? nuevaF : filas;
        int minCols = (nuevaC < columnas) ? nuevaC : columnas;

        for (int i = 0; i < minFilas; i++)
            for (int j = 0; j < minCols; j++)
                nueva[i][j] = datos[i][j];

        //Liberar la antigua
        for (int i = 0; i < filas; i++)
            delete[] datos[i];
        delete[] datos;

        //Actualizar
        datos = nueva;
        filas = nuevaF;
        columnas = nuevaC;
    }

    // Multiplicación genérica
    static MatrizDinamica<T> multiplicar(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B) {
        if (A.columnas != B.filas)
            throw invalid_argument("Error: no se pueden multiplicar (columnas de A != filas de B)");

        MatrizDinamica<T> C(A.filas, B.columnas);

        for (int i = 0; i < A.filas; i++) {
            for (int j = 0; j < B.columnas; j++) {
                C.datos[i][j] = 0;
                for (int k = 0; k < A.columnas; k++)
                    C.datos[i][j] += A.datos[i][k] * B.datos[k][j];
            }
        }

        return C;
    }



};