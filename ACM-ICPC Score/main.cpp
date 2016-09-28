#include <iostream>
#include <string>

using namespace std;

struct datos{
string n;
int acc;
int tiempo;
int arrErr[10];
};

void bubble(datos arreglo[], int n){
int pasada, j;
datos temp;
bool interruptor=true;
for (pasada=0; pasada<n-1 && interruptor; pasada++){
    interruptor=false;
    for (j=0; j<n-1-pasada; j++){
        if(arreglo[j+1].acc>arreglo[j].acc){
            temp=arreglo[j];
            arreglo[j]=arreglo[j+1];
            arreglo[j+1]=temp;
            interruptor=true;
        }
        else if (arreglo[j+1].acc==arreglo[j].acc&&arreglo[j+1].tiempo<arreglo[j].tiempo){
            temp=arreglo[j];
            arreglo[j]=arreglo[j+1];
            arreglo[j+1]=temp;
            interruptor=true;
        }
    }
}
}


void imprimir(datos arreglo[], int n){
int i, num=1;
for (i=0; i<n; i++){
    cout << num << " - " << arreglo[i].n << " " << arreglo[i].acc << " " << arreglo[i].tiempo << endl;
    num++;
}
}

int main()
{
    int T, P, i, j, S, time, acum;
    string name;
    char prob, stat;

    cin >> T >> P;

    datos ArrEq[T];

    for (i=0;i<T;i++){
        cin >> ArrEq[i].n;
        ArrEq[i].tiempo=0;
        ArrEq[i].acc=0;
        for(j=0;j<10;j++){
            ArrEq[i].arrErr[j]=0;
        }
    }

    cin >> S;

    for (i=0; i<S;i++){
        cin >> name >> prob >> time >> stat;
        for (j=0;j<T;j++){
            if (name==ArrEq[j].n){
                if (stat=='A'){
                 ArrEq[j].acc+=1;
                    ArrEq[j].tiempo=+time;
                }
                else if(stat=='W'){
                    ArrEq[j].arrErr[prob-'A']+=1;
                }
            }///si es el mismo equipo
        } ///buscando al equipo correspondiente
    }///ingresando los datos

    ///Procesando Errores
    for(i=0;i<T;i++){
        acum=0;
        for (j=0;j<10;j++){
            acum+=ArrEq[i].arrErr[j];
        }
        ArrEq[i].tiempo+=(20*acum);
    }
    ///Ordenando por puntos y tiempo
    bubble(ArrEq, T);

    ///Imprimiendo
    imprimir(ArrEq, T);


    return 0;
}
