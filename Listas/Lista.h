#ifndef Clase_Lista
#define Clase_Lista

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Lista{
public:
    T arrDatos[10];
    int iCant;
    Lista();
    ~Lista();
    Lista(T arrDatos[10], int iCant){
        for(int i=0; i<10; i++){
            this->arrDatos[i]=arrDatos[i];
        }
        this->iCant=iCant;
    }
    Lista(Lista<T> *objeto);
    int getCant();
    T getDato(int i);
    int buscar(T dato);
    void ordenar(bool flag);
    void operator=(Lista objeto);
    bool operator==(Lista& objeto){
        bool flag=true;

    if(objeto.getCant()!=this->getCant()){
        flag = false;
    }
    else{
    for(int i=0; i<10; i++){
        if(objeto.getDato(i)!=this->getDato(i))
        {
            flag=false;
            break;
        }
    }
    }
    return flag;
    };
    void print();
    bool add(T elem);

};
///CONSTRUCTOR VACIO
template <typename T>
Lista<T>::Lista(){
    this->iCant=0;
    /*for(int i=0;i<10;i++){
        arrDatos[i]=NULL;
    }*/
}
///COPIA OBJETO BASADO EN OTRO OBJETO
template <typename T>
Lista<T>::Lista(Lista<T> *objeto)
{
    T dato;
    ///copiando cantidad
    int cantidad = objeto->getCant();
    this->iCant=cantidad;
    ///copiando arreglo
    for(int i=0; i<10; i++){
            dato=objeto->arrDatos[i];
            this->arrDatos[i]=dato;
    }
}
///regresa cantidad de informacion de la lista
template <typename T>
int Lista<T>::getCant()
{
    return this->iCant;
}
///regresa dato usando un indice del arreglo
template <typename T>
T Lista<T>::getDato(int i)
{
    return this->arrDatos[i];
}
///FUNCION ADD
template <typename T>
bool Lista<T>::add(T elem)
{
    if(this->iCant<10)
    {
        this->arrDatos[iCant]=elem;
        this->iCant++;
        return true;
    }
    else{
        return false;
    }
}

///BUSCA DATO Y REGRESA POSICION
template <typename T>
int Lista<T>::buscar(T dato)
{
    int pos=-1;
    for(int i=0; i<10; i++){
        if(this->arrDatos[i]==dato)
        {
            pos=i;
        }
    }
    return pos;
}
///ORDENAR DEPENDIENDO DE PARAMETRO BOOLEANO, ASCENDIENTE SI ES TRUE, DESCENDIENTE SI ES FALSE
template <typename T>
void Lista<T>::ordenar(bool flag)
{
    int i, j;
    T temp;
    bool interruptor = true;
    if(flag==true){
    ///ASCENDIENTE
    for(i=0;i<this->iCant-1 && interruptor; i++){
        interruptor=false;
        for(j=0;j<this->iCant-1-i; j++){
            if (this->arrDatos[j+1]<this->arrDatos[j]){
                temp=this->arrDatos[j];
                this->arrDatos[j]=this->arrDatos[j+1];
                this->arrDatos[j+1]=temp;
                interruptor=true;
            }
        }
    }}
    ///DESCENDIENTE
    interruptor=true;
    if(flag==false){
    for(i=0;i<this->iCant-1 && interruptor; i++){
        interruptor=false;
        for(j=0;j<this->iCant-1-i; j++){
            if (this->arrDatos[j+1]>this->arrDatos[j]){
                temp=this->arrDatos[j];
                this->arrDatos[j]=this->arrDatos[j+1];
                this->arrDatos[j+1]=temp;
                interruptor=true;
            }
        }
    }}
}
///ASIGNA UNA LISTA A OTRA CON EL OPERADOR =
 template <typename T>
 void Lista<T>::operator=(Lista objeto)
 {
     for(int i=0; i<this->iCant; i++){
     this->arrDatos[i]=objeto.arrDatos[i];
     }
 }
///IMPRIMIR LA LISTA DE DATOS
template <typename T>
void Lista<T>::print()
{
    for(int i=0; i<iCant;i++)
    {
        cout << arrDatos[i] << "  ";
    }
    cout << endl;
}
#endif // Clase_Lista
