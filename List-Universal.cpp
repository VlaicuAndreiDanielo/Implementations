//Implementare Lista Dublu-Inlantuita
#include <iostream>

template <typename T>
struct List
{
	
	struct node
	{
		T valoare;
		node* anterior = nullptr;
		node* urmator = nullptr;
		//Constructori//
		// Constructor implicit
		node() : valoare(T()), anterior(nullptr), urmator(nullptr) {}
		// Constructor cu un parametru
		node(T val) : valoare(val), anterior(nullptr), urmator(nullptr) {}
		
	};

	node* first = nullptr;
	node* last = nullptr;
	int nrNoduri = 0;
	//Constructor//
	List() : first(nullptr), last(nullptr), nrNoduri(0) {}

	void push_front(const T& val)
	{
		node* nodNou = new node; //node* nodNou = new node(val) - cu constructor;
		nodNou->valoare = val;
		nrNoduri++;
		if (!nodNou)
		{
			std::cout << "Eroare la alocarea memoriei.";
			return;
		}
		if (first == nullptr)
		{
			first = nodNou;
			last = nodNou;
		}
		else
		{
			nodNou->urmator = first;
			first->anterior = nodNou;
			first = nodNou;
		}
	}
	void push_back(const T& val)
	{
		node* nodNou = new node; //node* nodNou = new node(val) - cu constructor;
		nodNou->valoare = val;
		nrNoduri++;
		if (!nodNou)
		{
			std::cout << "Eroare la alocarea memoriei.";
			return;
		}
		if (last == nullptr)
		{
			first = nodNou;
			last = nodNou;
		}
		else
		{
			nodNou->anterior = last;
			last->urmator = nodNou;
			last = nodNou;
		}

	}
	void pop_front()
	{
		if (first == nullptr)
		{
			std::cout << "Listan este vida. Nu se poate elimina nod.";
			return;
		}
		node* element = first;
		if (first == last)
		{
			first = nullptr;
			last = nullptr;
		}
		else
		{
			first = first->urmator;
			first->anterior = nullptr;
		}
		nrNoduri--;
		delete element;
	}
	void pop_back()
	{
		if (last == nullptr)
		{
			std::cout << "Lista este vida. Nu se poate elimina element";
			return;
		}
		node* element = last;
		if (first == last)
		{
			first = nullptr;
			last = nullptr;
		}
		else
		{
			last = last->anterior;
			last->urmator = nullptr;
		}
		nrNoduri--;
		delete element;
	}
	void empty()
	{
		if (first == nullptr) //((first == last) && (first == nullptr) && (last == nullptr))
			std::cout << "Lista este goala(vida).\n";
		else
			std::cout << "Lista nu e goala.\n";
	}
	void clear()
	{
		node* copy = first;
		while (copy != nullptr) {
			node* next = copy->urmator;
			delete copy;
			copy = next;
		}
		first = nullptr;
		last = nullptr;
	}
	/*In plus fata de STL*/ void print_cap_coada()
	{
		if (first == nullptr)
		{
			std::cout << "Lista este goala.\n";
			return;
		}
		node* current = first;
		while (current != nullptr)
		{
			if (current != nullptr)
			{
				std::cout << current->valoare << " ";
				current = current->urmator;
			}
			else
			{
				break;
			}
		}
		std::cout << std::endl;
	}
	/*In plus fata de STL*/ void print_coada_cap()
	{
		if (last == nullptr)
		{
			std::cout << "Lista este goala.\n";
			return;
		}
		node* current = last;
		while (current != nullptr)
		{
			if (current != nullptr)
			{
				std::cout << current->valoare << " ";
				current = current->anterior;
			}
			else
			{
				break;
			}
		}
		std::cout << std::endl;
	}
	void find(T val)
	{
		node* nod = nullptr;
		if (first != nullptr)
		{
			nod = first;
		}
		while (nod != nullptr)
		{
			if (nod->valoare == val)
			{
				std::cout << val << " A fost gasita.\n";
				return;
			}
			nod = nod->urmator;
		}
		std::cout << val << " Nu a fot gasita.\n";
		return;
	}

	int size()
	{
		return nrNoduri;
	}
	//void size()
	//{
	//	//Daca vreau sa numar nodurile din lista
	//	/*int numar = 0;
	//	node* nod = first;
	//	while (nod != nullptr)
	//	{
	//		numar++;
	//		nod = nod->urmator;
	//	}
	//	//std::cout << "Size = " << numar;
	//	return numar;
	//	*/
	//	//Daca retin numarul de noduri
	//	std::cout << nrNoduri;
	//}
	void eraseNode(node* nod)
	{
		if (nod == nullptr)
		{
			return;
		}

		node* ant = nod->anterior;
		node* urm = nod->urmator;

		if (ant != nullptr)
			ant->urmator = urm;
		if (urm != nullptr)
			urm->anterior = ant;
		nrNoduri--;
		delete nod;
	}
	void remove(const T& val)
	{
		node* nod = nullptr;
		if (first != nullptr)
		{
			nod = first;
		}
		while (nod != nullptr)
		{
			if (nod->valoare == val)
			{
				node* NodIntermediar = nod->urmator;
				eraseNode(nod);
				nod = NodIntermediar;
			}
			else
			{
				nod = nod->urmator;
			}
		}
	}
	/*In plus fata de STL*/ void insertBeforeNod(node* Nod, T val)
	{
		if (Nod == nullptr)
		{
			std::cout << "Eroare.";
			return;
		}
		node* nodnou = new node;
		nodnou->valoare = val;
		nrNoduri++;
		if (Nod->anterior != nullptr)
		{
			nodnou->anterior = Nod->anterior;
			Nod->anterior->urmator = nodnou;
		}
		nodnou->urmator = Nod;
		Nod->anterior = nodnou;
		if (Nod == first)
		{
			first = nodnou;
		}

	} 
	/*In plus fata de STL*/ void insertAfterNod(node* Nod, T val)
	{
		if (Nod == nullptr)
		{
			std::cout << "Eroare.";
			return;
		}
		node* nodnou = new node;
		nodnou->valoare = val;
		nrNoduri++;
		if (Nod->urmator != nullptr)
		{
			Nod->urmator->anterior = nodnou;
			nodnou->urmator = Nod->urmator;
		}
		nodnou->anterior = Nod;
		Nod->urmator = nodnou;
		if (Nod == last)
		{
			last = nodnou;
		}
	}

	void resize(int newSize, const T& valoareImplicita)
	{
		int currentSize = nrNoduri;
		if (newSize < currentSize)
		{
			int nrElDeEliminat = currentSize - newSize;
			for (int i = 0; i < nrElDeEliminat; i++)
			{
				pop_back();
			}
		}
		else
			if (newSize > currentSize)
			{

				int nrElDeAdaugat = newSize - currentSize;
				for (int i = 0; i < nrElDeAdaugat; i++)
				{
					push_back(valoareImplicita);
				}
			}

		if (newSize == currentSize)
		{
			std::cout << "Size-ul anterior si Noul Size sunt egale " << std::endl;;
			return;
		}
	}

	//Functii pentru Iterarea utilizand nodurii
	node* begin()
	{
		return first;
	}
	node* end()
	{
		return nullptr;
	}
	node* rbegin()
	{
		return last;
	}
	node* rend()
	{
		return nullptr;
	}

	void insert(int poz,const T& valoare)
	{
		node* nod = List.first;
		for (int i = 1; i < poz && nod != nullptr; i++)
		{
			nod = nod->urmator;
		}
		if (nod == nullptr)
		{
			std::cout << "Lista nu are cel putin " << poz + 1 << " noduri.\n";
			return;
		}
		nrNoduri++;
		insertBeforeNod(nod, valoare);
	}
	void erase(int poz)
	{
		node* nod = first;
		for (int i = 1; i < poz && nod != nullptr; i++)
		{
			nod = nod->urmator;
		}
		if (nod == nullptr)
		{
			std::cout << "Lista nu are cel putin " << poz + 1 << " noduri.\n";
			return;
		}
		node* ant = nod->anterior;
		node* urm = nod->urmator;

		if (ant != nullptr)
			ant->urmator = urm;
		if (urm != nullptr)
			urm->anterior = ant;
		nrNoduri--;
		delete nod;
	}

	T front()
	{
		return first->valoare;
	}
	T back()
	{
		return last->valoare;
	}


	template<typename U>
	bool same_type(const T& var1,const U& var2) {
		return false;
	}
	bool same_type(const T& var1,const T& var2) {
		return true;
	}
	void swap(List& AltaLista)
	{
		if (AltaLista.size() != size())
		{
			std::cout << "Listele nu au acelasi nr de elemente";
			return;
		}
		if (!same_type(AltaLista.first->valoare, first->valoare))
		{
			std::cout << "Listele nu au acelasi tip de date";
			return;
		}
		node* current1 = first;
		node* current2 = AltaLista.first;
		while (current1 != nullptr && current2 != nullptr)
		{
			T aux = current1->valoare;
			current1->valoare = current2->valoare;
			current2->valoare = aux;

			current1 = current1->urmator;
			current2 = current2->urmator;
		}
	}

    void unique()
{
	if (first == nullptr)
	{
		std::cout << "Lista nu are elemente.";
		return;
	}
	node* current = first;
	while (current != nullptr)
	{
		node* aux = current->urmator;
		while (aux != nullptr)
		{
			if (current->valoare == aux->valoare)
			{
				node* duplicat = aux;
				aux = aux->urmator;
				eraseNode(duplicat);
				nrNoduri--;
			}
			else
			{
				aux = aux->urmator;
			}
		}
		current = current->urmator;
	}
}

    void sort()
{
	T auxiliar;
	if (first == nullptr || last == nullptr)
	{
		std::cout << "Lista nu are elemente.";
		return;
	}
	bool change;
	do
	{
		change = false;
		node* nod = first;
		while (nod->urmator != nullptr)
		{
			if (nod->valoare > nod->urmator->valoare)
			{
				auxiliar = nod->valoare;
				nod->valoare = nod->urmator->valoare;
				nod->urmator->valoare = auxiliar;
				change = true;
			}
			nod = nod->urmator;
		}
	} while (change);
}
    void reverse()
{
	if (first == nullptr || last == nullptr)
	{
		std::cout << "Lista nu are elemente.";
		return;
	}
	node* current = first;
	while (current != nullptr)
	{
		node* aux = current->urmator;
		current->urmator = current->anterior;
		current->anterior = aux;
		current = aux;
	}
	last = first;
	first = current->urmator;
}
    void combine(const List<T>& Lista)
{
	List<T> ListaFinala;
	ListaFinala.nrNoduri = nrNoduri + Lista.nrNoduri;
	node* primul = first;
	node* alDoilea = Lista.first;
	// Combina doua liste ordonate in una singura
	while (primul != nullptr && alDoilea != nullptr)
	{
		if (primul->valoare < alDoilea->valoare)
		{
			ListaFinala.push_back(primul->valoare);
			primul = primul->urmator;
		}
		else
		{
			ListaFinala.push_back(alDoilea->valoare);
			alDoilea = alDoilea->urmator;
		}
	}
	while (primul != nullptr)
	{
		ListaFinala.push_back(primul->valoare);
		primul = primul->urmator;
	}
	while (alDoilea != nullptr)
	{
		ListaFinala.push_back(alDoilea->valoare);
		alDoilea = alDoilea->urmator;
	}
	*this = ListaFinala;
}
    //Destructor
	//~List(){clear();}
};
template <typename T>
void palindrom(List<T> Lista)
{
	typename List<T>::node* nod1 = Lista.first;
	typename List<T>::node* nod2 = Lista.last;
	bool este_palindrom = false;
	if ((nod1 == nullptr) || (nod2 == nullptr))
	{
		std::cout << "Lista este vida";
		return;
	}
	while (nod1 != nod2)
	{
		if (nod1->valoare == nod2->valoare)
		{
			este_palindrom = true;
			nod1 = nod1->urmator;
			nod2 = nod2->anterior;
		}
		else
		{
			este_palindrom = false;
			std::cout << "Lista nu este palindrom";
			return;
		}
	}
	if (este_palindrom == true)
	{
		std::cout << "Lista este palindrom";
		return;
	}
}
template <typename T>
int DecisionList(List<T>& Lista, int& k)
{
	int optiune; T element;
	int poz; int valoare;
	typename List<T>::node* nod;
	std::cout << "Calculele se fac pe Lista " << k;
	k++;

	while (true)
	{
		std::cout << "\n----------- MENIU -----------\n";
		std::cout << "1. Introduceti numarul de elemente de introdus si elementele\n";
		std::cout << "Elementele vor fi introduse cu ajutorul lui push front.\n";
		std::cout << "2. Adauga element la inceput\n";
		std::cout << "3. Adauga element la sfarsit\n";
		std::cout << "4. Sterge element de la inceput\n";
		std::cout << "5. Sterge element de la sfarsit\n";
		std::cout << "6. Cauta o valoare\n";
		std::cout << "7. Afiseaza lista de la cap la coada\n";
		std::cout << "8. Afiseaza lista de la coada la cap\n";
		std::cout << "9. Verifica daca lista este goala\n";
		std::cout << "10. Inserare valoare inainte de un nod de la o anumita pozitie\n";
		std::cout << "11. Inserare valoare dupa un nod de la o anumita pozitie\n";
		std::cout << "12. Eliminarea elemenetelor cu o anumita valoare\n";
		std::cout << "13. Goleste lista\n";
		std::cout << "14. Numarul elementelor din lista\n";
		std::cout << "15. Verificarea listei daca este palindrom\n";
		std::cout << "16. Eliminarea unui element de la o anumita pozitie\n";
		std::cout << "17. Eliminarea elementelor duplicate in lista.\n";
		std::cout << "18. Sortarea listei in mod crescator\n";
		std::cout << "19. Inversarea elementelor dintr-o lista\n";
		std::cout << "20. Redimensionarea listei la o anumita marime.\n";
		std::cout << "21. Iesire (EXIT)\n";
		std::cout << "-----------------------------------------------\n";
		std::cout << "Alegeti optiunea: ";
		std::cin >> optiune;

		switch (optiune)
		{
		case 1:
			std::cout << "Introduceti cate numere vor fi afisate:";
			std::cin >> valoare;
			std::cout << "Introduceti numerele care vor fi introduse:";
			for (int i = 0; i < valoare; i++)
			{
				std::cin >> element;
				Lista.push_front(element);
			}
			system("CLS");
			break;
		case 2:
			std::cout << "Introduce elementul pe care vrei sa il adaugi la inceput:";
			std::cin >> element;
			Lista.push_front(element);
			system("CLS");
			break;
		case 3:
			std::cout << "Introduce elementul pe care vrei sa il adaugi la final:";
			std::cin >> element;
			Lista.push_back(element);
			system("CLS");
			break;
		case 4:
			std::cout << "Doresti sa elimini primul element din lista?.\n";
			std::cout << "Apasa 1 pentru a sterge sau 0 pentru a anula\n";
			std::cin >> valoare;
			switch (valoare)
			{
			case 1:
				Lista.pop_front();
				std::cout << "Elementul a fost eliminat\n";
				break;
			default:
				std::cout << "Procesul a fost anulat\n";
				break;
			}
			system("CLS");
			break;
		case 5:
			std::cout << "Doresti sa elimini ultimul element din lista?.\n";
			std::cout << "Apasa 1 pentru a sterge sau 0 pentru a anula\n";
			std::cin >> valoare;
			switch (valoare)
			{
			case 1:
				Lista.pop_back();
				std::cout << "Elementul a fost eliminat\n";
				break;
			default:
				std::cout << "Procesul a fost anulat\n";
				break;
			}
			system("CLS");
			break;
		case 6:
			std::cout << "Introdu ovaloare pe care doresti sa o cauti in lista\n";
			std::cin >> element;
			system("CLS");
			Lista.find(element);
			break;
		case 7:
			std::cout << "Lista afisata de la cap la coada este:";
			system("CLS");
			Lista.print_cap_coada();
			break;
		case 8:
			std::cout << "Lista afisata de la coada la cap este:";
			system("CLS");
			Lista.print_coada_cap();
			break;
		case 9:
			std::cout << "Lista este:";
			system("CLS");
			Lista.empty();
			break;
		case 10:
			std::cout << "Introdu pozitia inaintea carea vrei sa introduci.\n";
			nod = Lista.first;
			std::cout << "Valoarea introdusa este:\n"; std::cin >> element;
			std::cout << "Pozitia este:"; std::cin >> poz;
			for (int i = 1; i < poz && nod != nullptr; i++)
			{
				nod = nod->urmator;
			}
			if (nod == nullptr)
			{
				std::cout << "Lista nu are cel putin " << poz + 1 << " noduri.\n";
				return 0;
			}
			Lista.insertBeforeNod(nod, element);
			system("CLS");
			break;
		case 11:
			std::cout << "Introdu pozitia dupa care vrei sa introduci.\n";
			nod = Lista.first;
			std::cout << "Valoarea introdusa este:\n"; std::cin >> element;
			std::cout << "Pozitia este:"; std::cin >> poz;
			for (int i = 1; i < poz && nod != nullptr; i++)
			{
				nod = nod->urmator;
			}
			if (nod == nullptr)
			{
				std::cout << "Lista nu are cel putin" << poz + 1 << " noduri.\n";
				return 0;
			}
			Lista.insertAfterNod(nod, element);
			system("CLS");
			break;
		case 12:
			std::cout << "Valoarea pe care o au elementele eliminate este:\n";
			std::cin >> element;
			Lista.remove(element);
			system("CLS");
			break;
		case 13:
			Lista.clear();
			std::cout << "Lista a fost golita\n";
			system("CLS");
			break;
		case 14:
			system("CLS");
			std::cout << "Marimea listei este de:\n " << Lista.size();
			break;
		case 15:
			system("CLS");
			palindrom(Lista);
			break;
		case 16:
			std::cout << "De la ce pozitie doriti sa stergeti un element";
			std::cin >> poz;
			Lista.erase(poz);
			system("CLS");
			break;
		case 17:
			std::cout << "Doresti sa elimini toate elementele duplicate din lista?\n";
			std::cout << "Apasa 1 daca da si 0 daca nu doresti sa elimini elementele\n";
			std::cin >> valoare;
			if (valoare == 1)
			{
				Lista.unique();
				break;
			}
			else
			{
				break;
			}
			system("CLS");
			break;
		case 18:
			system("CLS");
			Lista.sort();
			std::cout << "Lista a fost sortata cu succes.\n";
			break;
		case 19:
			system("CLS");
			Lista.reverse();
			std::cout << "Lista a fost inversata.\n";
			break;
		case 20:
			std::cout << "Introduceti marimea pe care o doriti pentru redimensionati listei:";
			std::cin >> valoare; std::cout << std::endl;
			std::cout << "introduceti valoarea implicita pe care doriti sa o adaugati:";
			std::cin >> element; std::cout << std::endl;
			Lista.resize(valoare, element);
			system("CLS");
			break;
		case 21:
			system("CLS");
			std::cout << "Iesire din program...\n";
			return 0;
		default:
			system("CLS");
			std::cout << "Optiune invalida! Alegeti o optiune valida.\n";
			break;
		}
	}

	return 0;
}
template <typename T>
int Comparare(List<T> Lista1, List<T> Lista2)
{
	typename List<T>::node* nod1 = Lista1.first;
	typename List<T>::node* nod2 = Lista2.first;
	bool identice = false;
	if (nod1 == nullptr || nod2 == nullptr)
	{
		std::cout << "Listele sunt vide";
		return 0;
	}
	while (nod1 != nullptr && nod2 != nullptr)
	{
		if (nod1->valoare == nod2->valoare)
		{
			identice = true;
			nod1 = nod1->urmator;
			nod2 = nod2->urmator;

		}
		else
		{
			std::cout << "Listele nu sunt identice";
			return 0;
		}
	}
	if (identice == true)
	{
		std::cout << "Listele sunt identice.";
		return 1;
	}
}
int main()
{
	int k = 1;
	List<int> Lista1, Lista2;
	DecisionList(Lista1, k);
	DecisionList(Lista2, k);
	    /*std::cout << "Iterare peste elementele Listei 1 folosind begin() si end():\n";
	    for (auto it = Lista1.begin(); it != Lista1.end(); it = it->urmator) {
	    	std::cout << it->valoare << " ";
	    }
	    std::cout << std::endl;
	    std::cout << "Iterare peste elementele Liste 2 in ordine inversa folosind rbegin() si rend():\n";
	    for (auto it = Lista2.rbegin(); it != Lista2.rend(); it = it->anterior) {
	    	std::cout << it->valoare << " ";
	    }*/
	Lista1.print_cap_coada();
	Lista2.print_cap_coada();
	Lista1.swap(Lista2);
	Lista2.combine(Lista1);
	Lista1.print_cap_coada();
	Lista2.print_cap_coada();
	Comparare(Lista1, Lista2);
	Lista1.clear();
	Lista2.clear();
	return 0;
}