
#include "node.h"
template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		int getSize();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int iPos);
		T deleteFirst();
		T deleteLast();
		T del(int iPos);
		int deleteAll();
		T get(int iPos);
		T set(T data, int iPos);
		bool change(int iPos1, int iPos2);
		void print();
		void reverse();
		void shift(int num);
		void spin(int num);
		bool operator==(LinkedList<T>& lista){
		    bool flag=true;
            node<T> *aux1= this->head;
            node<T> *aux2= lista.head;
            if(this->size!=lista.size)
                flag=false;
            else{
                for(int i=0; i<this->size; i++){
                    if(aux1->getData()!=aux2->getData()){
                        flag=false;
                        break;
                    }
                    aux1=aux1->getNext();
                    aux2=aux2->getNext();
                }
            }
            return flag;
		}
		void operator+=(LinkedList<T>& lista){
		    int i;
		    int tam=this->size;
		    node<T> *aux= this->head;
		    node<T> *aux2= lista.head;
		    for(i=0;i<this->size-1;i++){
                aux=aux->getNext();
		    }
            for(i=0; i<lista.size;i++){
                aux->setNext(new node<T>(aux2->getData()));
                aux2=aux2->getNext();
                aux=aux->getNext();
                tam++;
            }
            this->size=tam;
		}
		void operator+=(node<T>& nodo){
        int tam=this->size;
        node<T> *aux = head;
		for(int i=0;i<this->size-1;i++){
                aux=aux->getNext();
		    }

        aux->setNext(new node<T>(nodo.getData()));
        this->size=tam+1;
		}
		LinkedList<T>(LinkedList<T> *lista){
		this->size=lista.size;
		this->head=lista.head;
		}
		void operator=(LinkedList<T> *lista){
		node<T> *aux = this->head;
		node<T> *aux2 = lista.head;
		for(int i=0; i<lista.size-1; i++){
		    if(aux->getNext()!=NULL)
            aux->setData(aux2->getData());
            else{
                aux->setNext(new node<T>(aux2->getData()));
            }
            aux=aux->getNext();
            aux2=aux2->getNext();
		}
		}
	private:
		node<T> *head;
		int size;
		void borraTodo();
};

template <typename T>
void LinkedList<T>::borraTodo()
{
node<T> *aux = head;
	while(head != NULL)
	{
		head = head->getNext();
		delete aux;
		aux=head;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	borraTodo();
}

template <typename T>
LinkedList<T>::LinkedList()
{
	this->head = NULL;
	this->size = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return (this->head==NULL);
}

template <typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template <typename T>
void LinkedList<T>::addFirst(T data)
{
	head = new node<T>(data, head);
	size++;
}

template <typename T>
void LinkedList<T>::addLast(T data)
{
	if (this->isEmpty())
	{
		this->addFirst(data);
	}
	else
	{
		node<T> *aux = this->head;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}

	aux->setNext(new node<T>(data));
	this->size++;
	}
}

template <typename T>
bool LinkedList<T>::add(T data, int iPos)
{
	if (iPos < 0 || iPos > size)
	{
		return false;
	}
	if (iPos==0)
	{
		addFirst(data);
	}
	else if (iPos==size)
	{
		addLast(data);
	}
	else
	{
		node<T> *aux = head;
		for(int iA=1; iA<iPos; iA++)
	{
		aux = aux->getNext();
	}
	aux->setNext(new node<T> (data, aux->getNext()));
	size++;
}
	return true;
}

template <typename T>
T LinkedList<T>::deleteFirst()
{
	if (this->isEmpty())
	{
		return NULL;
	}
	node<T> *aux = head;
	head=head->getNext();
	T dataAux = aux->getData();
	delete aux;
	size--;
	return dataAux;
	}

template <typename T>
T LinkedList<T>::deleteLast()
{
	if(this->size<=1)
	{
		return this->deleteFirst();
	}
	node<T> *aux=head;
	while (aux->getNext()->getNext() != NULL)
		{
			aux=aux->getNext();
		}
		node<T> *aux2 = aux->getNext();
		T dataAux = aux2->getData();
		aux->setNext(NULL);
		delete aux2;
		this->size--;
		return dataAux;
}

template <typename T>
T LinkedList<T>::del(int iPos)
{
	if (iPos >= size)
	{
		return NULL;
	}
	if(iPos==0)
	{
		return deleteFirst();
	}
	if(iPos == size-1)
	{
		return deleteLast();
	}
	node<T> *aux = head;
	for(int iA=0; iA<iPos; iA++)
	{
		aux=aux->getNext();
	}
	node<T> *aux2 = aux->getNext();
	aux->setNext(aux2->getNext());
	T dataAux = aux2->getData();
	delete aux2;
	size--;
	return dataAux;
}
template <typename T>
int LinkedList<T>::deleteAll()
{
	borraTodo();
	int iCant = size;
	size=0;
	return iCant;
}
template <typename T>
T LinkedList<T>::get(int iPos)
{
	if(iPos<0 || iPos>= size)
	{
		return NULL;
	}
	node<T> *aux = head;
	for (int iA=1; iA<=iPos; ++iA)
	{
		aux=aux->getNext();
	}
	return aux->getData();
}
template <typename T>
T LinkedList<T>::set(T data, int iPos)
{
	if(iPos<0 || iPos>= size)
	{
		return NULL;
	}
	node<T> *aux = head;
	for (int iA=1; iA<=iPos; ++iA)
	{
		aux=aux->getNext();
	}
	T dataAux = aux->getData();
	aux->setData(data);
	return dataAux;
}
template <typename T>
bool LinkedList<T>::change(int iPos1, int iPos2)
{
	if (iPos1 <0 || iPos2<0 || iPos1>=size || iPos2>=size){
		return false;
	}
	if (iPos1==iPos2){
		return true;
	}
    node<T> *aux1 = head;
	int iMay=(iPos1>iPos2) ? iPos1 : iPos2;
	int iMen= (iPos1<iPos2) ? iPos1 : iPos2;
	for (int iA=1; iA<=iMen; iA++)
	{
		aux1=aux1->getNext();
	}
	node<T> *aux2=aux1;
	for(int iA=iMen+1; iA<=iMay; iA++)
	{
		aux2=aux2->getNext();
	}
	T dataAux = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(dataAux);
	return true;
}
template <typename T>
void LinkedList<T>::print()
{
	node<T> *aux = head;
	while(aux != NULL)
	{
		cout << aux->getData() <<endl;
		aux = aux->getNext();
	}
}
template <typename T>
void LinkedList<T>::reverse(){
int tam=this->size;

T var = head->getData();
node<T> *aux = head;
node<T> *aux2 = head;

while(tam>1){
for (int i=0; i<tam-1;i++){
    aux=aux->getNext();
}
aux2->setData(aux->getData());
aux->setData(var);
aux2=aux2->getNext();
var=aux2->getData();
aux=aux2;
tam=tam-2;
}
}
template <typename T>
void LinkedList<T>::shift(int num)
{
    int i;
    if(num<0){
        num=num*-1;
        num=num%this->size;
        num=this->size - num;
    }
    else{
        num=num%this->size;
    }

    node<T> *aux = head;
    for(i=0; i<size-1; i++){
        aux=aux->getNext();
    }
    aux->setNext(this->head);
    for(i=0; i<num; i++){
    this->head=head->getNext();
    }

    aux=this->head;
    for(i=0; i<this->size-1; i++){
        aux=aux->getNext();
    }
    aux->setNext(NULL);

}
template <typename T>
void LinkedList<T>::spin(int num){
int rondas = this->size/num;
int sobra = this->size%num;
int i, j, k;
node<T> *aux=head;
node<T> *aux2=head;
node<T> *pos=head;
T var;
int spins=num;
for(i=0; i<rondas; i++){
    while(spins>1){
    for (k=0; k<spins-1;k++){
    aux=aux->getNext();
}
    var=aux2->getData();
    aux2->setData(aux->getData());
    aux->setData(var);
    aux2=aux2->getNext();
    var=aux2->getData();
    aux=aux2;
    spins-=2;
}
    for(j=0; j<num; j++){
        pos=pos->getNext();
    }
    aux=pos;
    aux2=pos;
    spins=num;
}

spins=sobra;

while(spins>1){
        for (k=0; k<spins-1;k++){
    aux=aux->getNext();
}
    var=aux2->getData();
    aux2->setData(aux->getData());
    aux->setData(var);
    aux2=aux2->getNext();
    var=aux2->getData();
    aux=aux2;
    spins-=2;
}



}
