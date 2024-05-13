// Implementare Deque 
#include <iostream>
template <typename T>
struct Deque
{
	struct node
	{
		T valoare;
		node* anterior = nullptr;
		node* urmator = nullptr;
	};

	node* first = nullptr;
	node* last = nullptr;
	int nr_elemente;
	Deque() : first(nullptr), last(nullptr), nr_elemente(0) {}

	void push_back(const T& element)
	{
		node* nod_nou = new node{ element };
		if (first == nullptr && last == nullptr)
		{
			first = nod_nou;
			last = nod_nou;
		}
		else
		{
			last->urmator = nod_nou;
			nod_nou->anterior = last;
			last = nod_nou;
		}
		nr_elemente++;
	}
	void push_front(const T& element)
	{
		node* nod_nou = new node{ element };
		if (first == nullptr && last == nullptr)
		{
			first = nod_nou;
			last = nod_nou;
		}
		else
		{
			nod_nou->urmator = first;
			first->anterior = nod_nou;
			first = nod_nou;
		}
		nr_elemente++;
	}

	void pop_front()
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Eroare. Coada Dequeue este goala";
			return;
		}
		node* aux = first;
		first = first->urmator;
		if (first != nullptr)
		{
			first->anterior = nullptr;
		}
		delete aux;
		nr_elemente--;
	}
	void pop_back()
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Eroare. Coada Dequeue este goala";
			return;
		}
		node* aux = last;
		last = last->anterior;
		if (last != nullptr)
		{
			last->urmator = nullptr;
		}
		delete aux;
		nr_elemente--;
	}

	T front()
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Deque este gol";
			return;
		}
		else
		if (first != nullptr)
		{
			return first->valoare;
		}
	}
	T back()
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Deque este gol";
			return;
		}
		else
			if (last != nullptr)
			{
				return last->valoare;
			}
	}
	void empty()
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Dequeue este goala";
			return;
		}
	}

	void clear_from_front()
	{
		while (first != nullptr)
		{
			pop_front();
		}
	}
	void clear_from_back()
	{
		while (last != nullptr)
		{
			pop_back();
		}
	}
	int size()
	{
		return nr_elemente;
	
	}
	void afisare_dequeue_front()
	{
		node* current = first;
		while (current != nullptr)
		{
			std::cout << current->valoare << " ";
			current = current->urmator;
		}
		std::cout << std::endl;
	}
	void afisare_dequeue_back()
	{
		node* current = last;
		while (current != nullptr)
		{
			std::cout << current->valoare << " ";
			current = current->anterior;
		}
		std::cout << std::endl;
	}

	void emplace_back(const T& element)
	{
		node* nouNode = new node(element);
		if (nr_elemente==0)
		{
			first = last = nouNode;
		}
		else
		{
			last->urmator = nouNode;
			nouNode->anterior = last;
			last = nouNode;
		}
		nr_elemente++;
	}
	void emplace_front(const T& element)
	{
		node* nouNode = new node(element);
		if (nr_elemente == 0)
		{
			first = last = nouNode;
		}
		else
		{
			first->urmator = nouNode;
			nouNode->anterior = first;
			first = nouNode;
		}
		nr_elemente++;
	}

	void resize(int newSize, const T& valoareImplicita)
	{
		int currentSize = nr_elemente;
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

	T at(int poz)
	{
		if (nr_elemente == 0 || poz > nr_elemente)
		{
			std::cout << "Coada nu are niciun element sau suficiente elemente";
			static T default_value;
			return default_value;
		}
		else
		{
			node* nod = first;
			for (int i = 2; i <= poz; i++) 
			{
				nod = nod->urmator;
			}
			std::cout << "Valoarea de la pozitia " << poz << " este: "<< nod->valoare;
			return T();
		}
	}

	T& operator[](int poz)
	{
		if (poz<0 || poz>nr_elemente)
		{
			static T default_value;
			return default_value;
		}

		node* nod = first;
		for (int i = 2; i <= poz; i++)
		{
			nod = nod->urmator;
		}
		return nod->valoare;
	}

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

};
template <typename T> //Compara de la inceputul Deque-ului
void CompareFromHead(Deque<T> deque1, Deque<T> deque2)
{
	if (deque1.size() == deque2.size())
	{
		while (deque1.first != nullptr && deque2.first != nullptr)
		{
			if (deque1.first->valoare == deque2.first->valoare)
			{
				deque1.pop_front(); deque2.pop_front();
			}
			else
			{
				std::cout << "Elementele nu sunt aceleasi";
			    return;
			}
		}
		std::cout << "Cele doua cozi sunt identice";
	}
	else
	{
		std::cout << "Coziile nu au acelasi numar de elemente, deci acestea nu pot fi la fel";
		return;
	}
}
template <typename T> //Compara de la sfarsitul Deque-ului
void CompareFromTail(Deque<T> deque1, Deque<T> deque2)
{
	if (deque1.size() == deque2.size())
	{
		while (deque1.last != nullptr && deque2.last != nullptr)
		{
			if (deque1.last->valoare == deque2.last->valoare)
			{
				deque1.pop_back(); deque2.pop_back();
			}
			else
			{
				std::cout << "Elementele nu sunt aceleasi";
				return;
			}
		}
		std::cout << "Cele doua cozi sunt identice";
	}
	else
	{
		std::cout << "Coziile nu au acelasi numar de elemente, deci acestea nu pot fi la fel";
		return;
	}
}
int main()
{
	Deque<int> dequeue;
	int valoare; int nr_elem;
	std::cout << "Introduceti numarul de elemente pe care doriti sa il introduceti "; std::cin >> nr_elem;
	for (int i = 1; i <= nr_elem; i++)
	{
		std::cin >> valoare;
		dequeue.push_back(valoare);
	}
	int newSize, valoareImplicita;
	

	/*std::cout << "Size-ul este:" << dequeue.size(); std::cout << std::endl;
	dequeue.afisare_dequeue_back();  std::cout << std::endl;
	dequeue.afisare_dequeue_front();  std::cout << std::endl;*/

	/*std::cout << "Introduceti noul size al cozii "; std::cin >> newSize;
	std::cout << "Introduceti valoarea implicita "; std::cin >> valoareImplicita;
	dequeue.resize(newSize, valoareImplicita);*/

	std::cout << "Size-ul este:" << dequeue.size(); std::cout << std::endl;
	dequeue.afisare_dequeue_back();  std::cout << std::endl;
	dequeue.afisare_dequeue_front();  std::cout << std::endl;

	int poz; std::cout << "Introduceti poz de la care doriti sa aflati valoarea "; std::cin >> poz; dequeue.at(poz);
	//dequeue.pop_back();
	//dequeue.pop_front();
	//dequeue.afisare_dequeue_back();  std::cout << std::endl;
	//dequeue.afisare_dequeue_front();  std::cout << std::endl;

	/*std::cout << "Iterare peste elementele Cozii folosind begin() si end():\n";
	for (auto it = dequeue.begin(); it != dequeue.end(); it = it->urmator) {
		std::cout << it->valoare << " ";
	}
	std::cout << std::endl;

	std::cout << "Iterare peste elementele Cozii in ordine inversa folosind rbegin() si rend():\n";
	for (auto it = dequeue.rbegin(); it != dequeue.rend(); it = it->anterior) {
		std::cout << it->valoare << " ";
	}*/

	//Deque<int> deque1, deque2;
	//std::cout << "Introduceti numarul de elemente pe care doriti sa il introduceti "; std::cin >> nr_elem;
	//for (int i = 1; i <= nr_elem; i++)
	//{
	//	std::cin >> valoare;
	//	deque1.push_front(valoare);
	//}

	//std::cout << "Introduceti numarul de elemente pe care doriti sa il introduceti "; std::cin >> nr_elem;
	//for (int i = 1; i <= nr_elem; i++)
	//{
	//	std::cin >> valoare;
	//	deque2.push_front(valoare);
	//}

	//CompareFromHead(deque1, deque2);
	//CompareFromTail(deque1, deque2);
	return 0;
}

