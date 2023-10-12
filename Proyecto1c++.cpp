#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

// Función para multiplicar dos matrices
void multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result) {
    int size = matrix1.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    std::clock_t start, end;
    double tiempo;

    int sizeMatriz = 32, opc1 = 0, opc11 = 0, opc12 = 0, caso2 = 0;

    std::cout << "Bienvenido, este código tiene dos modalidades para las cuales se entregará su tiempo de trabajo promedio después de 10 ejecuciones,\n"
              << "1.- Realizar la multiplicación de UNA matriz de valores específicos\n"
              << "2.- Multiplicación sucesiva desde una matriz inicial de 32x32 hasta una de las proporcionadas\n"
              << "3.- Salir" << std::endl;

    while (opc1 != 1 && opc1 != 2 && opc1 != 3) {
        std::cout << "\n(Por favor ingrese 1, 2 o 3 para seleccionar una opción): ";
        std::cin >> opc1;
    }

    switch (opc1) {
        case 1: {
            std::cout << "\n¿De qué tamaño desea que sea la matriz?\n"
                      << "1.- [32x32]\n"
                      << "2.- [64x64]\n"
                      << "3.- [128x128]\n"
                      << "4.- [256x256]\n"
                      << "5.- [512x512]\n"
                      << "6.- [1024x1024]\n"
                      << "7.- [2048x2048]\n"
                      << "8.- [4096x4096]\n"
                      << "9.- Salir" << std::endl;

            while (opc11 < 1 || opc11 > 9) {
                std::cout << "\n(Por favor ingrese una opción válida): ";
                std::cin >> opc11;
            }

            if (opc11 == 9) {
                break;
            }

            sizeMatriz = sizeMatriz * std::pow(2, opc11 - 1);
            int rep = 10;
            double prom = 0;

            do {
                std::vector<std::vector<int>> Matriz1(sizeMatriz, std::vector<int>(sizeMatriz));
                std::vector<std::vector<int>> Matriz2(sizeMatriz, std::vector<int>(sizeMatriz));
                std::vector<std::vector<int>> Matriz3(sizeMatriz, std::vector<int>(sizeMatriz));

                // Inicializar Matriz1 y Matriz2 con valores aleatorios
                for (int i = 0; i < sizeMatriz; i++) {
                    for (int j = 0; j < sizeMatriz; j++) {
                        Matriz1[i][j] = rand() % 128;
                        Matriz2[i][j] = rand() % 128;
                    }
                }

                // Inicializar Matriz3 con ceros
                for (int i = 0; i < sizeMatriz; i++) {
                    for (int j = 0; j < sizeMatriz; j++) {
                        Matriz3[i][j] = 0;
                    }
                }

                start = std::clock();
                // Realizar la multiplicación de matrices
                multiplyMatrices(Matriz1, Matriz2, Matriz3);
                end = std::clock();

                tiempo = static_cast<double>(end - start) / CLOCKS_PER_SEC;

                prom += tiempo;
                rep--;

            } while (rep != 0);

            std::cout << "Tiempo promedio multiplicación matrices [" << sizeMatriz << "x" << sizeMatriz << "] = {"
                      << (prom / 10) / 60 << " minutos}|{" << prom / 10 << " segundos}|{" << (prom / 10) * 1000
                      << " milisegundos}" << std::endl;

            break;
        }

        case 2: {
            std::cout << "\n¿Hasta qué matriz desea medir los tiempos?\n"
                      << "1.- [32x32]\n"
                      << "2.- [64x64]\n"
                      << "3.- [128x128]\n"
                      << "4.- [256x256]\n"
                      << "5.- [512x512]\n"
                      << "6.- [1024x1024]\n"
                      << "7.- [2048x2048]\n"
                      << "8.- [4096x4096]\n"
                      << "9.- Salir" << std::endl;

            while (opc12 < 1 || opc12 > 9) {
                std::cout << "\n(Por favor ingrese un valor entre 1 y 9): ";
                std::cin >> opc12;
            }

            if (opc12 == 9) {
                break;
            }

            caso2 = sizeMatriz * std::pow(2, opc12 - 1);

            do {
                double promedio = 0;
                int rep = 10;

                do {
                    std::vector<std::vector<int>> Matriz1(sizeMatriz, std::vector<int>(sizeMatriz));
                    std::vector<std::vector<int>> Matriz2(sizeMatriz, std::vector<int>(sizeMatriz));
                    std::vector<std::vector<int>> Matriz3(sizeMatriz, std::vector<int>(sizeMatriz));

                    // Inicializar Matriz1 y Matriz2 con valores aleatorios
                    for (int i = 0; i < sizeMatriz; i++) {
                        for (int j = 0; j < sizeMatriz; j++) {
                            Matriz1[i][j] = rand() % 128;
                            Matriz2[i][j] = rand() % 128;
                        }
                    }

                    // Inicializar Matriz3 con ceros
                    for (int i = 0; i < sizeMatriz; i++) {
                        for (int j = 0; j < sizeMatriz; j++) {
                            Matriz3[i][j] = 0;
                        }
                    }

                    start = std::clock();
                    // Realizar la multiplicación de matrices
                    multiplyMatrices(Matriz1, Matriz2, Matriz3);
                    end = std::clock();

                    tiempo = static_cast<double>(end - start) / CLOCKS_PER_SEC;

                    rep--;
                    promedio += tiempo;

                } while (rep != 0);

                std::cout << "\nTiempo promedio multiplicación matrices [" << sizeMatriz << "x" << sizeMatriz << "] = {"
                          << (promedio / 10) / 60 << " minutos}|{" << promedio / 10 << " segundos}|{"
                          << (promedio / 10) * 1000 << " milisegundos}" << std::endl;
                sizeMatriz *= 2;

            } while (sizeMatriz <= caso2);

            break;
        }

        case 3:
            break;
    }

    return 0;
}
