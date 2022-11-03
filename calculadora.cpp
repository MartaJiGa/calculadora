#include <iostream>
#include <string>
#include <fstream>

using namespace std;

double suma(const double DIG1, const double DIG2) {
    return DIG1 + DIG2;
}

double resta(const double DIG1, const double DIG2) {
    return DIG1 - DIG2;
}

double multiplicacion(const double DIG1, const double DIG2) {
    return DIG1 * DIG2;
}

double division(const double DIG1, const double DIG2) {
    return DIG1 / DIG2;
}

double mostrar_tabla(const double DIG1) {
    int i = 0;
    int s_tabla;

    cout << "\nTabla de multiplicar del " << DIG1 << endl;

    while (i <= 10) {
        s_tabla = i * DIG1;
        cout << DIG1 << " x " << i << " = " << s_tabla << endl;
        i++;
    }
    return DIG1;
}

double archivo(const string FICHERO, int operacion) {

    string linea;
    int i = 0;
    double num_soluc;
    double num_soluc_1;
    double solucion;

    ifstream ficheroLectura(FICHERO + ".txt");

    if (!ficheroLectura.is_open()) {
        cout << "Error al abrir el fichero" << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(ficheroLectura, linea)) {

        i++;

        if (operacion == 1) {
            if (i == 1) {
                num_soluc_1 = stod(linea);
                solucion += num_soluc_1;
            }
            else {
                solucion += stod(linea);
            }
        }

        else if (operacion == 2) {
            if (i == 1) {
                num_soluc = stod(linea);
            }
            else {
                solucion += stod(linea);
            }
        }

        else if (operacion == 6) {
            if (i == 1) {
                num_soluc = stod(linea);
            }
            else if (i == 2) {
                num_soluc_1 = stod(linea);

                if (num_soluc > num_soluc_1) {
                    solucion = num_soluc;
                }
                else if (num_soluc < num_soluc_1) {
                    solucion = num_soluc_1;
                }
            }
            else {
                num_soluc_1 = stod(linea);

                if (solucion < num_soluc_1) {
                    solucion = num_soluc_1;
                }
            }
        }

        else if (operacion == 7) {
            if (i == 1) {
                num_soluc = stod(linea);
            }
            else if (i == 2) {
                num_soluc_1 = stod(linea);

                if (num_soluc < num_soluc_1) {
                    solucion = num_soluc;
                }
                else if (num_soluc > num_soluc_1) {
                    solucion = num_soluc_1;
                }
            }
            else {
                num_soluc_1 = stod(linea);

                if (solucion > num_soluc_1) {
                    solucion = num_soluc_1;
                }
            }
        }
    }
    ficheroLectura.close();
    if (operacion == 2) {
        solucion = num_soluc - solucion;
    }
    return solucion;
}

int main() {

    double num1;
    double num2;
    int operacion;
    string fichero;
    char eleccion;
    bool otro = true;

    while (otro == true) {

        /* Declaro la variable "entender" aquí para que, en caso de hacer alguna cuenta que precise que sea false tras la primera ejecución del bucle,
        se vuelva a asignar ese valor al comenzar siguientes bucles en caso de querer hacer más operaciones.*/
        bool entender = false;

        cout << "\n\nQue operacion deseas hacer? (elige un numero)\n 1. Sumar\n 2. Restar\n 3. Multiplicar\n 4. Dividir\n 5. Tabla de multiplicar\n 6. Numero maximo\n 7. Numero minimo\n" << endl;
        cin >> operacion;

        if (operacion == 1) {

            while (entender == false) {
                cout << "Indica con que quieres sumar. N es con numeros y F es con fichero." << endl;
                cin >> eleccion;

                if (eleccion == 'n' || eleccion == 'N') {
                    entender = true;
                    cout << "\nIndica el primer sumando: ";
                    cin >> num1;
                    cout << "Indica el segundo sumando: ";
                    cin >> num2;
                    cout << "Solucion: " << suma(num1, num2) << endl;
                }
                else if (eleccion == 'f' || eleccion == 'F') {
                    entender = true;
                    cout << "\nIndica el fichero con el que quieres hacer la operacion:";
                    cin >> fichero;
                    cout << "Solucion: " << archivo(fichero, operacion) << endl;
                }
                else {
                    cout << "La tecla seleccionada no coincide con las opciones. Prueba de nuevo." << endl;
                }
            }
        }

        else if (operacion == 2) {

            while (entender == false) {
                cout << "Indica con que quieres restar. N es con numeros y F es con fichero." << endl;
                cin >> eleccion;

                if (eleccion == 'n' || eleccion == 'N') {
                    entender = true;
                    cout << "\nIndica el minuendo: ";
                    cin >> num1;
                    cout << "Indica el sustraendo: ";
                    cin >> num2;
                    cout << "Solucion: " << resta(num1, num2) << endl;
                }
                else if (eleccion == 'f' || eleccion == 'F') {
                    entender = true;
                    cout << "\nIndica el fichero con el que quieres hacer la operacion:";
                    cin >> fichero;
                    cout << "Solucion: " << archivo(fichero, operacion) << endl;
                }
                else {
                    cout << "La tecla seleccionada no coincide con las opciones. Prueba de nuevo." << endl;
                }
            }
        }

        else if (operacion == 3) {
            cout << "\nIndica el multiplicando: ";
            cin >> num1;
            cout << "Indica el multiplicador: ";
            cin >> num2;
            cout << "Solucion: " << multiplicacion(num1, num2) << endl;
        }

        else if (operacion == 4) {
            cout << "\nIndica el dividendo: ";
            cin >> num1;
            cout << "Indica el divisor: ";
            cin >> num2;
            cout << "Solucion: " << division(num1, num2) << endl;
        }

        else if (operacion == 5) {
            cout << "\nDe que numero quieres saber la tabla de multiplicar?" << endl;
            cin >> num1;
            mostrar_tabla(num1);
        }

        else if (operacion == 6) {
            cout << "\nIndica el fichero con el que quieres hacer la operacion:";
            cin >> fichero;
            cout << "Solucion: " << archivo(fichero, operacion) << endl;
        }
        else if (operacion == 7) {
            cout << "\nIndica el fichero con el que quieres hacer la operacion:";
            cin >> fichero;
            cout << "Solucion: " << archivo(fichero, operacion) << endl;
        }

        else {
            cout << "\nNumero erroneo" << endl;
        }



        string intr_otro;

        // La variable «entender» se vuelve falsa para que este siguiente bucle se ejecute.
        entender = false;

        // Cada vez que el valor que escribas sea diferente de S/s o N/n, el programa volverá a preguntar si quieres hacer otra operación.
        while (entender == false) {

            cout << "\nQuieres hacer otra operacion?\nS es si y N es no" << endl;
            cin >> intr_otro;

            if (intr_otro == "s" || intr_otro == "S") {
                entender = true;
            }

            else if (intr_otro == "n" || intr_otro == "N") {
                entender = true;
                otro = false;
            }

            else {
                cout << "\nNo te he entendido, vuelve a intentarlo\n" << endl;
            }
        }
    }

    return 0;
}

