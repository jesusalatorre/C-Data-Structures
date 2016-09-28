#include node.h

template <class T>
class stack
{
	public:
		stack();
		~stack();
		bool empty();
		T top();
		void push(T data);
		void pop();
		int size();
	private:
		node<T> *tope;
		int cant;
};

template <typename T>
stack <T>::stack()
{
	tope=NULL;
	cant=0;
}

template <typename T>
stack<T>::~stack()
{
	node<T> *aux = tope;
	while(tope != NULL)
	{
		tope = tope->getNext();
		delete aux;
		aux=tope;
	}
}

template <typename T>
bool stack<T>::empty()
{
	return tope == NULL;
}

template <typename T>
T stack<T>::top()
{
	return tope->getData();
}

template <typename T>
void stack<T>::push(T data)
{
	tope = new node<T>(data, tope);
	cant++;
}

template <typename T>
void stack<T>::pop()
{
	node<T> *aux=tope;
	tope = tope->getNext();
	delete aux;
	cant--;
}

template <typename T>
int stack<T>::size()
{
	return cant;
}
