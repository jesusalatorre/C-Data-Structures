#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    int i=0, num, contador=0;
    Lista<int> *iUno = new Lista<int>;
    while(i<10)
    {
        cin >> num;
        if(num>=0){
        iUno->arrDatos[i]=num;
        iUno->iCant++;
        }
        else{
            break;
        }
        i++;
    }

    i=0;

    Lista<int> *iDos = new Lista<int>;

    while(i<10)
    {
        cin >> num;
        if(num>=0){
        iDos->arrDatos[i]=num;
        iDos->iCant++;
        }
        else{
            break;
        }
        i++;
    }

    Lista<int> *iTres = new Lista<int>(iDos);

    if(*iDos==*iTres)
        cout << "iDos e iTres son Iguales" << endl;
    else{
        cout << "iDos e iTres no son iguales" << endl;
    }

    if(*iDos==*iUno)
        cout << "iDos e iUno son Iguales" << endl;
    else{
        cout << "iDos e iUno no son iguales" << endl;
    }

    iUno->print();

    cout <<  "ordenando ascendiente" << endl;

    iUno->ordenar(true);

    iUno->print();

    cout <<  "ordenando descendiente" << endl;

    iUno->ordenar(false);

    iUno->print();

    for (i=0; i<iUno->getCant(); i++){
        if(iUno->buscar(iDos->getDato(i))!=-1&&iDos->getDato(i)!=NULL){
            contador++;
        }
    }


    cout << endl << contador << " elementos de iDos en iUno";





    return 0;
}
