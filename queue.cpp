#include "node.h"
template <class T>
class queue
{
	public:
		queue();
		~queue();
		T front();
		T back();
		int size();
		bool empty();
		void push();
		void pop(T data);
		void pop();
	private:
		node<T> *end;
		int cant;
};

template <typename T>
queue<T>::queue(){
	end=NULL;
	cant=0;
}
template <typename T>
queue<T>::~queue(){
	node<T> *aux = end->getNext();
	end->setNext(NULL);
	while(aux != NULL){
		end = aux;
		aux = aux->getNext();
		delete end;
	}
}
template <typename T>
T queue<T>::front(){
	return end->getNext()->getData();
}
template <typename T>
T queue<T>::back(){
	return end->getData();
}
template <typename T>
int queue<T>::size()
{
	return cant;
}
template <typename T>
bool queue<T>::empty(){
	return (end==NULL;)
}
template <typename T>
void queue<T>::push(T data){
	if(end ==NULL){
		end = new node<T>(data);
		end-setNext(end);
	}
	else{
		end->setNext(new node<T>(T data, end->getNext()));
		end = end->getNext();
	}
	cant++;
}
template <typename T>
void queue<T>::pop(){
	node<T> *aux = end->getNext();
	if(end== end->getNext()){
		end=NULL;
	}
	else{
		end->setNext(aux->getNext());
	}
	delete aux;
	cant--;
}