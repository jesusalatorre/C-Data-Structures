#include <iostream>

using namespace std;

void imprimirArreglo(int arreglo[4][4]){
int i,j;
for(i=0;i<4;i++){
        cout << endl;
    for (j=0;j<4;j++){
        cout << arreglo[i][j] << " ";
    }
}
}

void voltearMatriz(int arreglo[4][4], int vueltas){
    ///VOLTEA A LA DERECHA
    int mirror[4][4], i, j, k;

    for(i=0;i<vueltas;i++){
        ///inicia proceso de voltear a la derecha
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                mirror[k][3-j]=arreglo[j][k];
            }
        }

        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                arreglo[j][k]=mirror[j][k];
            }
        }
    }

    imprimirArreglo(arreglo);
}

int main()
{
    int vueltas;
    int arreglo[4][4], i, j;
    cin >> vueltas;
    for(i=0; i<4;i++){
        for(j=0; j<4; j++){
            cin >> arreglo[i][j];
    }
}

    if(vueltas>=0){
    vueltas=vueltas%4;
    voltearMatriz(arreglo,vueltas);
    }
    else{
        vueltas=vueltas*-1;
        vueltas=vueltas%4;
        voltearMatriz(arreglo, 4-vueltas);
    }


    return 0;
}
