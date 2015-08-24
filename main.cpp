#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct equipo {
    string nombre;
    char problemas[10];
    int tiempo;
    char status;
};


int main()
{
    int equipos, cant_problemas, soluciones;

    ifstream archEnt;

    archEnt.open("info.txt");

    while (!archEnt.eof()){

        archEnt >> equipos >> cant_problemas;

        equipo arr_equipos[equipos];

        for (int i = 0 ; i < equipos; i++){
            archEnt >> arr_equipos[i].nombre;
            for (int j = 0; j < cant_problemas; i++)
                archEnt >> arr_equipos[i].problemas[j];
        }

        archEnt >> soluciones;
    }

    archEnt.close();

    while (soluciones) {


    }

    return 0;
}
