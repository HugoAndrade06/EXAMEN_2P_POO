#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {

    int opcion;
    double num1, num2, resultado;
    string nombre;

    double notas[5];
    double sumaNotas = 0;
    double promedio;
    double mayor, menor;
    int aprobados = 0;
    int reprobados = 0;

    do {

        cout << "\n========== MENU ==========" << endl;
        cout << "1. Operaciones basicas" << endl;
        cout << "2. Registro de notas" << endl;
        cout << "3. Guardar resultados" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {

                int operacion;

                cout << "\n--- OPERACIONES BASICAS ---" << endl;

                cout << "Ingrese el primer numero: ";
                cin >> num1;

                cout << "Ingrese el segundo numero: ";
                cin >> num2;

                cout << "\n1. Suma" << endl;
                cout << "2. Resta" << endl;
                cout << "3. Multiplicacion" << endl;
                cout << "4. Division" << endl;
                cout << "Seleccione una operacion: ";
                cin >> operacion;

                if(operacion == 1) {
                    resultado = num1 + num2;
                    cout << "Resultado: " << resultado << endl;
                }
                else if(operacion == 2) {
                    resultado = num1 - num2;
                    cout << "Resultado: " << resultado << endl;
                }
                else if(operacion == 3) {
                    resultado = num1 * num2;
                    cout << "Resultado: " << resultado << endl;
                }
                else if(operacion == 4) {

                    if(num2 != 0) {
                        resultado = num1 / num2;
                        cout << "Resultado: " << resultado << endl;
                    }
                    else {
                        cout << "Error: No se puede dividir para cero" << endl;
                    }
                }
                else {
                    cout << "Operacion invalida" << endl;
                }

                break;
            }

            case 2: {

                cout << "\n--- REGISTRO DE NOTAS ---" << endl;

                sumaNotas = 0;
                aprobados = 0;
                reprobados = 0;

                for(int i = 0; i < 5; i++) {

                    do {

        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];

        if(notas[i] < 0 || notas[i] > 10) {
            cout << "Error: La nota debe estar entre 0 y 10" << endl;
        }

    } while(notas[i] < 0 || notas[i] > 10);

    sumaNotas += notas[i];

    if(i == 0) {
        mayor = notas[i];
        menor = notas[i];
    }

    if(notas[i] > mayor) {
        mayor = notas[i];
    }

    if(notas[i] < menor) {
        menor = notas[i];
    }

    if(notas[i] >= 7) {
        aprobados++;
    }
    else {
        reprobados++;
    }
}

                promedio = sumaNotas / 5;

                cout << "\nPromedio: " << promedio << endl;
                cout << "Nota mayor: " << mayor << endl;
                cout << "Nota menor: " << menor << endl;
                cout << "Aprobados: " << aprobados << endl;
                cout << "Reprobados: " << reprobados << endl;

                break;
            }

            case 3: {

                cout << "\nIngrese el nombre del estudiante: ";
cin.ignore();

do {

    getline(cin, nombre);

    bool valido = true;

    for(int i = 0; i < nombre.length(); i++) {

        if( !(isalpha(nombre[i]) || nombre[i] == ' ') ) {
            valido = false;
        }
    }

    if(!valido) {
        cout << "Error: Solo se permiten letras. Ingrese nuevamente: ";
    }
    else {
        break;
    }

} while(true);

                ofstream archivo("resultados.txt", ios::app);

time_t fechaActual = time(0);
tm *fecha = localtime(&fechaActual);

string dias[] = {
    "Domingo", "Lunes", "Martes",
    "Miercoles", "Jueves", "Viernes", "Sabado"
};

string meses[] = {
    "Enero", "Febrero", "Marzo", "Abril",
    "Mayo", "Junio", "Julio", "Agosto",
    "Septiembre", "Octubre", "Noviembre", "Diciembre"
};
                archivo << "==========================" << endl;
                archivo << "Nombre: " << nombre << endl;
                archivo << "Promedio: " << promedio << endl;
                archivo << "Nota mayor: " << mayor << endl;
                archivo << "Nota menor: " << menor << endl;
                archivo << "Aprobados: " << aprobados << endl;
                archivo << "Reprobados: " << reprobados << endl;
                archivo << "Fecha: "
                << dias[fecha->tm_wday] << " "
                << fecha->tm_mday << " de "
                << meses[fecha->tm_mon] << " del "
                << 1900 + fecha->tm_year
                << endl;
                archivo << "Lenguaje utilizado: C++" << endl;
                archivo << "==========================" << endl;

                archivo.close();

                cout << "Resultados guardados correctamente." << endl;

                break;
            }

            case 4:
                cout << "\nSaliendo del programa..." << endl;
                break;

            default:
                cout << "\nOpcion invalida" << endl;
        }

    } while(opcion != 4);

    return 0;
}