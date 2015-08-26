#include <iostream>
#include <string>
using namespace std;

struct Equipo {
     string nombre;
     int tiempo;
     int acertados;
     int fallidos;
     int acumulados ;
};

void desplegar(Equipo arr[], int equipos) {

        for(int i = 0; i < equipos; i++)
            cout << i+1 << "-" << arr[i].nombre << " " << arr[i].acertados << " " << arr[i].tiempo << endl;
}

void rankear(Equipo arr[], int equipos)  {
     bool bandera;
     string nombre;
     int acertados, tiempo;

     for (int i = 0; i< equipos && bandera; i++){
        bandera = false;

        for (int j = 0; j < equipos - i; j++) {
            if (arr[j+1].acertados > arr[j].acertados) {
                nombre = arr[j].nombre;
                acertados = arr[j].acertados;
                tiempo = arr[j].tiempo;

                arr[j].nombre = arr[j+1].nombre;
                arr[j].acertados = arr[j+1].acertados;
                arr[j].tiempo = arr[j+1].tiempo;

                arr[j+1].nombre = nombre;
                arr[j+1].acertados = acertados;
                arr[j+1].tiempo = tiempo;

                bandera = true;
            }
            else if (arr[j+1].acertados == arr[j].acertados) {
                if (arr[j+1].tiempo < arr[j].tiempo) {
                    nombre = arr[j].nombre;
                    acertados = arr[j].acertados;
                    tiempo = arr[j].tiempo;

                    arr[j].nombre= arr[j+1].nombre;
                    arr[j].acertados= arr[j+1].acertados;
                    arr[j].tiempo= arr[j+1].tiempo;

                    arr[j+1].nombre = nombre;
                    arr[j+1].acertados = acertados;
                    arr[j+1].tiempo = tiempo;

                    bandera = true;
                }
            }
        }
    }

    for(int i = 0; i < equipos; i++)
            cout << i+1 << "-" << arr[i].nombre << " " << arr[i].acertados << " " << arr[i].tiempo << endl;
}

void calificar(int soluciones, Equipo arr_equipos[], int equipos) {
    string nombre;
    char problema, status;
    int tiempo;

    while (soluciones) {
        cin >> nombre >> problema >> tiempo >> status;

        for (int i = 0; i < equipos; i++) {
            if (arr_equipos[i].nombre == nombre && status == 'A') {

                arr_equipos[i].tiempo += tiempo;
                arr_equipos[i].acertados++;
                arr_equipos[i].acumulados++;
          }
            else if (arr_equipos[i].nombre == nombre && status == 'A' && arr_equipos[i].fallidos > 0) {

                for(int j = 0; j < arr_equipos[i].fallidos; j++)
                    arr_equipos[i].tiempo += 20;
                arr_equipos[i].acertados++;
                arr_equipos[i].acumulados++;
          }
          else if (arr_equipos[i].nombre == nombre && status == 'W') {

                arr_equipos[i].tiempo += tiempo;
                arr_equipos[i].acumulados++;
                arr_equipos[i].fallidos++;
            }
        }
        soluciones--;
    }
    rankear(arr_equipos, equipos);
}


int main()
{
    int equipos, cant_problemas, soluciones;
    string nombre;

    // Inicia el input del programa.
    cin >> equipos >> cant_problemas;

    //Arreglo struct tipo Equipo
    Equipo arr_equipos[equipos];
    for (int i = 0; i < equipos; i++) {
        arr_equipos[i].tiempo = 0;
        arr_equipos[i].acertados = 0;
        arr_equipos[i].acumulados = 0;
        arr_equipos[i].fallidos = 0;
    }
    //Declaración de nombres
    for (int i = 0; i < equipos; i++){
      cin >> nombre;
      arr_equipos[i].nombre = nombre;
    }
    //Decalaración de entrega de soluciones
    cin >> soluciones;
    calificar(soluciones, arr_equipos, equipos);

    return 0;
}
