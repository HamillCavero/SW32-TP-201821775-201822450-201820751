#pragma once
#ifndef __LIST_H__
#define __LIST_H__
//lista simplemente enlazada con puntero al inicio y al final, hecho por Hamill Cavero u201821775

// Lo único que se debería ser sería adaptar esto ( creo )
// Osea ponerle templates, el elemento del nodo debería ser un T porque ahí irían las balas y los enemigos en un futuro, 
// espero que alguno de ustedes lea esto y ponga confirmo o una wea así
class List {
	struct Node {
		float elem;
		Node* next;

		Node(float elem, Node* next = nullptr)
			:elem(elem), next(next) {}
	};

	Node* head;
	Node* tail;
	int len;

	class Iterator {
		int    pos;
		Node*  aux;
	public:
		Iterator(int pos, Node* aux) : pos(pos), aux(aux) {}
		void operator ++() { pos++; aux = aux->next; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		float    operator  *() { return aux->elem; }
	};
	Iterator begin() {
		return Iterator(0, head);
	}
	Iterator end() {
		return Iterator(len, nullptr);
	}
	Iterator _pos(int pos) {
		Iterator it(0, head);
		for (int i = 0; i < pos; i++)
		{
			++it;
		}
		return it;
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

	//devuelve 0 si está llena y 1 si está vacía
	bool isEmpty() {
		return len == 0;
	}

	//devuevle el tamaño de la lista
	int size() {
		return len;
	}

	//añade un nodo al inicio
	void addFirst(float elem) {
		head = new Node(elem, head);
		++len;
	}

	//añade un nodo al final
	void addLast(float elem) {
		tail->next = new Node(elem);
		tail = tail->next;
		++len;
	}

	//añade un nodo en una posición dada
	void addPos(int pos, float elem)
	{
		if (pos == 0)
		{
			addFirst(elem);
		}
		else if (pos>0 && pos<len)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos - 1; i++)
			{
				aux1 = aux1->next;
			}
			Node* aux2 = new Node(elem, aux1->next);
			aux1->next = aux2;
			++len;
		}
		else if (pos == len)
		{
			addLast(elem);
		}
	}

	//devuelve la posición de un elemento
	int find(float elem) {
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
		tail = aux1;
		delete aux2;
		--len;
	}

	//borra un nodo en una posición dada
	void delPos(int pos) {
		if (pos == 0)
		{
			delFirst();
		}
		else if (pos>0 && pos<len)
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
		else if (pos == len)
		{
			delLast();
		}
	}

	//devuelve el contenido del primer nodo
	float obtenerInicial() {
		return head->elem;
	}

	//devuelve el contenido del ultimo nodo
	float obtenerFinal() {
		return tail->elem;
	}

	//devuelve el contenido de un nodo en una posición dada
	float obtenerPos(int pos) {
		if (pos == 0)
		{
			obtenerInicial();
		}
		else if (pos>0 && pos<len)
		{
			List::Iterator it = _pos(pos);
			return *it;
		}
		else if (pos == len)
		{
			obtenerFinal();
		}
	}

	//cambia el valor del elemento del primer nodo
	void modificarInicial(float _elem) {
		head->elem = _elem;
	}

	//cambia el valor del elemento del último nodo
	void modificarFinal(float _elem) {
		tail->elem = _elem;
	}

	//cambia el valor del elemento de un nodo en una posición dada
	void modificarPos(int pos, float _elem) {
		if (pos == 0)
		{
			modificarInicial(_elem);
		}
		else if (pos>0 && pos<len)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos; i++)
			{
				aux1 = aux1->next;
			}
			aux1->elem = _elem;
		}
		else if (pos == len)
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
