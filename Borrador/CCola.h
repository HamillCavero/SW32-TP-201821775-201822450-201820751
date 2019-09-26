
template <class T1>
class CCola {
	struct Node {
		T1 elem;
		Node* next;

		Node(T1 elem, Node* next = nullptr)
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
		T1    operator  *() { return aux->elem; }
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
	CCola() :head(nullptr), len(0) {}
	~CCola() {
		Node* aux = head;
		while (head != nullptr)
		{
			aux = head;
			head = head->next;
			delete aux;
		}
	}

	bool isEmpty() {
		return len == 0;
	}

	int size() {
		return len;
	}

	void addFirst(T1 elem) {
			Node* aux = new Node(elem, head);
			if (aux!=nullptr)
			{
				head = aux;
				++len;
			}
	}

	void addLast(T1 elem) {
		if (len==0)
		{
			Node* aux = new Node(elem, nullptr);
			head = aux;
			++len;
		}
		else
		{

		Node* aux = new Node(elem, nullptr);
		tail->next = aux;
		tail = tail->next;
		++len;
		}
	}

	void delFirst() {
		if (len>0)
		{
			Node* aux = head;
			head = head->next;
			delete aux;
			--len;
		}
	}
	void delLast() {
		Node* aux1 = head;
		for (int i = 0; i < len - 1; i++)
		{
			aux1 = aux1->next;
		}
		Node* aux2 = aux1->next;
		aux1->next = nullptr;
		//tail = aux1;
		delete aux2;
		--len;
	}

	T1 obtenerInicial() {
		return head->elem;
	}
	T1 obtenerPos(int pos) {
		if (pos == 0)
		{
			obtenerInicial();
		}
		else if (pos>0 && pos<=len)
		{
			Node* aux1 = head;
			for (int i = 0; i < pos; i++)
			{
				aux1 = aux1->next;
			}
			return aux1->elem;
		}
		/*else if (pos == len)
		{
			obtenerFinal();
		}*/
	}
	/*T1 obtenerFinal() {
		return tail->elem;
	}*/
	void juicio() {
		while (head != nullptr)
		{
			Node* aux = head;
			head = head->next;
			delete aux;
		}
		tail = nullptr;
	}

};
