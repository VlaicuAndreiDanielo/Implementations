////Implementare Forward_list
//#include <iostream>
//template <typename T>
//struct Forward_List
//{
//	struct node
//	{
//		T valoare;
//		node* urmator = nullptr;
//	};
//
//	node* first = nullptr;
//	int nrElemente = 0;
//	// Forward_List() : first(nullptr), nrElemente(0){}
//
//	void push_front(const T& element)
//	{
//		node* nod = new node{element};
//		if (first == nullptr)
//		{
//			first = nod;
//	    }
//		else
//		{
//			nod->urmator = first;
//			first = nod;
//		}
//		nrElemente++;
//	}
//
//	void pop_front()
//	{
//		if (first == nullptr)
//		{
//			std::cout << "Lista este goala";
//		}
//		else
//		{
//			node* interm = new node;
//			interm = first;
//			first = first->urmator;
//			delete interm;
//		}
//		nrElemente--;
//	}
//
//	void print()
//	{
//		node* parcurgere = first;
//		while (parcurgere != nullptr)
//		{
//			std::cout << parcurgere->valoare << " ";
//			parcurgere = parcurgere->urmator;
//		}
//		std::cout << "\n";
//	}
//	T front()
//	{
//		if (first == nullptr)
//		{
//			std::cout << "Lista este goala";
//			return 0;
//     	}
//		else
//		{
//			return first->valoare;
//		}
//	}
//	void empty()
//	{
//		if (first == nullptr)
//		{
//			std::cout << "Lista este goala";
//		}
//		else
//		{
//			std::cout << "Lista nu este vida";
//		}
//	}
//	void clear()
//	{
//		node* interm = new node;
//		while (first != nullptr)
//		{
//			interm = first;
//			first = first->urmator;
//			delete interm;
//		}
//		nrElemente = 0;
//	}
//	T afisare_elemente()
//	{
//		node* current = new node;
//		current = first;
//		while (current != nullptr)
//		{
//			std::cout << current->valoare << " ";
//			current = current->urmator;
//		}
//		std::cout << "\n";
//		return 0;
//	}
//
//	int size()
//	{
//		return nrElemente;
//	}
//
//	node* begin()
//	{
//		return first;
//	}
//	node* end()
//	{
//		return nullptr;
//	}
//	const node* cbegin() const
//	{
//		return first;
//	}
//	const node* cend() const
//	{
//		return nullptr;
//	}
//
//	node* before_begin()
//	{
//		node* beforeFirst = new node(T());
//		beforeFirst->urmator = first;
//		return beforeFirst;
//	}
//	node* insert_after(node* nod, const T& val)
//	{
//		node* nodNou = new node{ val };
//		nodNou->urmator = nod->urmator;
//		nod->urmator = nodNou;
//		nrElemente++;
//		return nodNou;
//	}
//	const node* cbefore_begin() const
//	{
//		node* beforeFirst = new node(T());
//		beforeFirst->urmator = first;
//		return beforeFirst;
//	}
//	const node* insert_after( const node* nod, const T& val)
//	{
//		node* nodNou = new node(val);
//		nodNou->urmator = nod->urmator;
//		nod->urmator = nodNou;
//		nrElemente++;
//		return nodNou;
//	}
//
//	void insert_after(int poz, T val)
//	{
//		node* nod = new node;
//		node* deInserat = new node{ val };
//		nod = first;
//		for (int i = 0; i < poz; i++)
//		{
//			nod = nod->urmator;
//		}
//			deInserat->urmator = nod->urmator;
//			nod->urmator = deInserat;
//			nrElemente++;
//	}
//	void erase_after(int poz)
//	{
//		if (poz < 0 || poz >= nrElemente)
//		{
//			std::cout << "Pozitia este invalida";
//			return;
//		}
//		node* nod = first;
//		for (int i = 0; i < poz; i++)
//		{
//			nod = nod->urmator;
//		}
//
//		if (nod->urmator == nullptr)
//		{
//			std::cout << "Nu exista un nod dupa pozitia respectiva";
//			return;
//		}
//
//		node* interm = nod->urmator;
//		nod->urmator = interm->urmator;
//		delete interm;
//		nrElemente--;
//	}
//	void resize(int numar)
//	{
//		T valoareImplicita;
//		std::cout << "Introduceti valoarea implicita pe care doriti sa o adaugati ";
//		std::cin >> valoareImplicita;
//		if (numar > nrElemente)
//		{
//			int deAdaugat = numar - nrElemente;
//			for (int i = 0; i < deAdaugat; i++)
//				push_front(valoareImplicita);
//		}
//		if (numar < nrElemente)
//		{
//			int deEliminat = nrElemente - numar;
//			for (int i = 0; i < deEliminat; i++)
//				pop_front();
//		}
//		if (numar == nrElemente)
//		{
//			std::cout << "Size-ul actual este egal cu Size-ul dorit";
//			return;
//		}
//	}
//	void erase_node(node* beforeNode)
//	{
//		if (beforeNode == nullptr || beforeNode->urmator == nullptr)
//		{
//			std::cout << "Nu avem ce sterge";
//			return;
//		}
//		node* currentNode = beforeNode->urmator;
//		beforeNode->urmator = currentNode->urmator;
//		delete currentNode;
//
//	}
//		template<typename U>
//	bool same_type(const T& var1,const U& var2) {
//		return false;
//	}
//	bool same_type(const T& var1,const T& var2) {
//		return true;
//	}
//	void swap(Forward_List<T> OtherList)
//	{
//		if (OtherList.nrElemente != nrElemente)
//		{
//			std::cout << "Listele nu au acelasi nr de elemente";
//			return;
//		}
//		if (!same_type(OtherList.first->valoare, first->valoare))
//		{
//			std::cout << "Listele nu au acelasi tip de date";
//			return;
//		}
//		node* current1 = first;
//		node* current2 = OtherList.first;
//		while (current1 != nullptr && current2 != nullptr)
//		{
//			T aux = current1->valoare;
//			current1->valoare = current2->valoare;
//			current2->valoare = aux;
//
//			current1 = current1->urmator;
//			current2 = current2->urmator;
//		}
//	}
//	void remove(T val)
//	{
//		node* current = first;
//		node* beforeNode = nullptr;
//		while (current != nullptr)
//		{
//			if (current->valoare == val)
//			{
//				if (beforeNode == nullptr)
//				{
//					first = current->urmator;
//					delete current;
//					current = first;
//				}
//				else
//				{
//					erase_node(beforeNode);
//					current = beforeNode->urmator;
//				}
//			}
//			else
//			{
//				beforeNode = current;
//				current = current->urmator;
//			}
//		}
//	}
//	void unique()
//	{
//		if (first == nullptr || first->urmator == nullptr)
//		{
//			std::cout << "Lista nu are elemenete sau are doar un element";
//			return;
//		}
//		node* current = first;
//		while (current != nullptr)
//		{
//			node* next = current;
//			while (next->urmator != nullptr)
//			{
//				if (current->valoare == next->urmator->valoare)
//				{
//					node* duplicat = next->urmator;
//					next->urmator = duplicat->urmator;
//					delete duplicat;
//				}
//				else
//				{
//					next = next->urmator;
//				}
//			}
//			current = current->urmator;
//		}
//
//	}
//	void reverse()
//	{
//
//		if (first == nullptr || first->urmator == nullptr)
//		{
//			std::cout << "Lista nu are elemenete sau are doar un element";
//			return;
//		}
//		node* ant = nullptr;
//		node* current = first;
//		node* urm = nullptr;
//			while (current != nullptr)
//			{
//				urm = current->urmator;
//				current->urmator = ant;
//				ant = current;
//				current = urm;
//			}
//			first = ant;
//	}
//	void sort()
//	{
//		if (first == nullptr || first->urmator == nullptr)
//		{
//			std::cout << "Lista nu are elemente sau are doar un element";
//			return;
//		}
//
//		bool interschimbare;
//		node* curent;
//		node* final = nullptr;
//		do
//		{
//			interschimbare = false;
//			curent = first;
//			while (curent->urmator != final)
//			{
//				if (curent->valoare > curent->urmator->valoare)
//				{
//					T temporar = curent->valoare;
//					curent->valoare = curent->urmator->valoare;
//					curent->urmator->valoare = temporar;
//					interschimbare = true;
//				}
//				curent = curent->urmator;
//			}
//			final = curent;
//		} while (interschimbare);
//	}
//	Forward_List merge(Forward_List<T> OtherList)
//	{
//		Forward_List<T> rezultat;
//		rezultat.nrElemente = nrElemente + OtherList.nrElemente;
//		node* List1 = OtherList.first;
//		node* List2= first;
//		while (List1 != nullptr && List2 != nullptr)
//		{
//			if (List1 <= List2)
//			{
//				rezultat.push_front(List1->valoare);
//				List1 = List1->urmator;
//			}
//			else
//			{
//				rezultat.push_front(List2->valoare);
//				List2 = List2->urmator;
//			}
//		}
//		while (List1 != nullptr)
//		{
//			rezultat.push_front(List1->valoare);
//			List1 = List1->urmator;
//		}
//
//		while (List2 != nullptr)
//		{
//			rezultat.push_front(List2->valoare);
//			List2 = List2->urmator;
//		}
//		*this = rezultat;
//		return *this;
//	}
//};
//int main()
//{
//	Forward_List<int> L1, L2;
//	int valoare; int n;
//	std::cout << "Introduceti numarul de elemente de introdus in L1";
//	std::cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> valoare;
//		L1.push_front(valoare);
//	}
//	std::cout << "Introduceti numarul de elemente de introdus in L2";
//	std::cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> valoare;
//		L2.push_front(valoare);
//	}
//	std::cout << "Size-ul lui L1 este"<< L1.size(); std::cout << "\n";
//	L1.insert_after(2, 15); L2.insert_after(L2.first, 17);
//	L1.print(); L2.print(); L1.remove(15); L2.erase_after(3);
//    L1.sort(); L2.sort(); L1.print(); L2.print(); L1.merge(L2); L1.print(); 
//	L1.sort(); L1.print();
//	L1.clear(); L2.clear();
//	return 0;
//}