#pragma once
#ifndef __LIST_H__
#define __LIST_H__
template <class T2> // T2 FLOAT //T INT
class List {
	struct Node {
		T2 elem;
		Node* next;

		Node(T2 elem, Node* next = nullptr)
			:elem(elem), next(next) {}
	};

	Node* head;
	int len;

	class Iterator {
		int    pos;
		Node*  aux;
	public:
		Iterator(int pos, Node* aux) : pos(pos), aux(aux) {}
		void operator ++() { pos++; aux = aux->next; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		T2    operator  *() { return aux->elem; }
	};
	Iterator begin() {
		return Iterator(0, head);
	}
	Iterator end() {
		return Iterator(len, nullptr);
	}
public:
	List() :head(nullptr), len(0) {}
	~List() {
		while (head != nullptr)
		{
			Node* aux = head;
			head = head->next;
			delete aux;
		}
	}

	//devuelve 0 si est� llena y 1 si est� vac�a
	bool isEmpty() {
		return len == 0;
	}

	//devuevle el tama�o de la lista
	int size() {
		return len-1;
	}

	//a�ade un nodo al inicio
	void addFirst(T2 elem) {
		/*Node* aux= new Node(elem,head);
		if (aux !=nullptr)
		{
		head = aux;
		++len;
		}*/
		head = new Node(elem, head);
		++len;
	}

	//a�ade un nodo al final
	void addLast(T2 elem) {
		if (len>0)
		{
			aux = head;
			for (int i = 0; i < len; i++)
			{
				aux->next;
			}
			aux->next = new Node(elem, nullptr);
		}
		else
		{
			head = new Node(elem, nullptr);
			++len;
		}
		/*tail->next = new Node(elem);
		tail = tail->next;
		++len;*/
	}

	//a�ade un nodo en una posici�n dada
	void addPos(int pos, T2 elem)
	{
		if (pos == 0)
		{
			addFirst(elem);
		}
		else if (pos>0 && pos<len-1)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos-1; i++)
			{
				aux1 = aux1->next;
			}
			Node* aux2 = new Node(elem, aux1->next);
			aux1->next = aux2;
			++len;
		}
		else if (pos == len-1)
		{
			addFirst(elem);
		}
	}

	//devuelve la posici�n de un elemento
	int find(T2 elem) {
		Node* aux = head;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->elem == elem) {
				return pos;
			}
			aux = aux->next;
			++pos;
		}
		return -1;
	}

	//borra el primer nodo
	void delFirst() {
		if (len>0)
		{
			Node* aux = head;
			head = head->next;
			delete aux;
			--len;
		}
	}

	//borra el ultimo nodo
	void delLast() {
		Node* aux1 = head;
		for (int i = 0; i < len - 2; i++)
		{
			aux1 = aux1->next;
		}
		Node* aux2 = aux1->next;
		aux1->next = nullptr;
		//tail = aux1;
		delete aux2;
		--len;
	}

	//borra un nodo en una posici�n dada
	void delPos(int pos) {
		if (pos == 0)
		{
			delFirst();
		}
		else if (pos>0 && pos<len-1)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos - 1; i++)
			{
				aux1 = aux1->next;
			}
			Node* aux2 = aux1->next;
			aux1->next = aux2->next;
			delete aux2;
			--len;
		}
		else if (pos == len-1)
		{
			delLast();
		}
	}

	//devuelve el contenido del primer nodo
	T2 obtenerInicial() {
		return head->elem;
	}

	//devuelve el contenido del ultimo nodo
	/*T2 obtenerFinal() {
		return tail->elem;

	}*/
	T2 obtenerFinal() {
		Node* aux1 = head;
		for (int i = 0; i < len - 1; i++)
		{
			aux1 = aux1->next;
		}
		return aux1->elem;
	}

	//devuelve el contenido de un nodo en una posici�n dada

	//T2 obtenerPos(int pos) {
	//	if (pos == 0)
	//	{
	//		obtenerInicial();
	//	}
	//	else if (pos>0 && pos<len-1)
	//	{
	//		/*List::Iterator it = _pos(pos);
	//		return *it;*/
	//		Node* aux1 = head;
	//		for (int i = 0; i < pos; i++)
	//		{
	//			aux1 = aux1->next;
	//		}
	//		return aux1->elem;
	//	}
	//	else if (pos == len-1)
	//	{
	//		obtenerFinal();
	//	}
	//}
	T2 obtenerPos(int pos) {
		if (pos == 0)
		{
			obtenerInicial();
		}
		else if (pos>0 && pos<len)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos-1; i++)
			{
				aux1 = aux1->next;
			}
			return aux1->elem;
		}
		else if (pos == len )
		{
			obtenerFinal();
		}
	}

	//cambia el valor del elemento del primer nodo
	void modificarInicial(T2 _elem) {
		head->elem = _elem;
	}

	//cambia el valor del elemento del �ltimo nodo
	/*void modificarFinal(T2 _elem) {
		tail->elem = _elem;
	}*/
	void modificarFinal(T2 _elem) {
		tail->elem = _elem;
	}

	//cambia el valor del elemento de un nodo en una posici�n dada
	void modificarPos(int pos, T2 _elem) {
		if (pos == 0)
		{
			modificarInicial(_elem);
		}
		else if (pos>0 && pos<len-1)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos; i++)
			{
				aux1 = aux1->next;
			}
			aux1->elem = _elem;
		}
		else if (pos == len-1)
		{
			modificarFinal(_elem);
		}
	}

	//usamos iteradores para mostrar los elementos de la lista
	void mostrar() {
		for (List::Iterator it2 = begin(); it2 != end(); ++it2)
		{
			std::cout << *it2 << std::endl;
		}
	}
	void juicio() {
		while (head != nullptr)
		{
			Node* aux = head;
			head = head->next;
			delete aux;
		}
	}
};

#endif // !__LIST_H__

/*
bool    esVacia();									+
uint    longitud();									+
void    agregaInicial(T elem);						+
void    agregaFinal(T elem);						+
void    agregaPos(T elem, uint pos);				+
void    modificarInicial(T elem);					+
void    modificarPos(T elem, uint pos);				+
void    modificarFinal(T elem);						+
void    eliminaInicial();							+
void    eliminaPos(uint pos);						+
void    eliminaFinal();								+
T       obtenerInicial();							+
T       obtenerPos(uint pos);						+
T       obtenerFinal();								+
T       buscar(T elem);								+
*/
