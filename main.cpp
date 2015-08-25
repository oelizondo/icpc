#include <iostream>
#include <string>

using namespace std;

struct Equipo {
    string nombre;
    char problemas[10];
    int tiempo;
    int acertados = 0;
    char status;
};


int main()
{
    int equipos, cant_problemas, soluciones, problemas, tiempo;
    char tipoProblema, status;
    string nombre;

    // Inicia el input del programa.
    cin >> equipos >> cant_problemas;

    //Arreglo struct tipo Equipo
    Equipo arr_equipos[equipos];

    //Declaración de nombres
    for (int i = 0; i < arr_equipos.length(); i++){
      cin >> nombre;
      arr_equipos[i].nombre = nombre;
    }
    //Decalaración de entrega de soluciones
    cin >> soluciones;

    
    while (!archEnt.eof()){

        archEnt >> equipos >> cant_problemas;

        Equipo arr_equipos[equipos];

        for (int i = 0 ; i < equipos; i++)
            archEnt >> arr_equipos[i].nombre;

        archEnt >> soluciones;

        while(soluciones){
          archEnt >> nombre >> tipoProblema >> tiempo >> status;

          for(int i = 0; i < arr_equipos.length(); i++){
            if (arr_equipos[i].nombre == nombre && status == 'A')
              arr_equipos[i].tiempo += tiempo;
              arr_equipos[i].acertados++;
            else if (arr_equipos[i].nombre == nombre && status 'W')
          }
          soluciones--;
        }
    }

    archEnt.close();

    return 0;
}
