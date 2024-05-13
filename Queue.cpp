//Implementare Queue
#include <iostream>
template <typename T>
struct Queue
{
	struct node
	{
		T valoare;
		node* urmator = nullptr;
	};

	node* first = nullptr;
	node* last = nullptr;
	int nr_elemente;
	Queue() : first(nullptr), last(nullptr), nr_elemente(0){}

	void push(const T& element)
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
			last = nod_nou;
		}
		nr_elemente++;
	}

	void pop() 
	{
		if (first == nullptr && last == nullptr)
		{
			std::cout << "Eroare. Coada Queue este goala";
			return;
		}
		node*  aux = first;
		first = first->urmator;
		delete aux;
		nr_elemente--;
		if(first==nullptr)
		{
			last = nullptr;
		}
	}

	T front()
	{
		if (first == nullptr && last == nullptr) // if(isEmpty())
		{
			std::cout << "Eroare. Coada Queue este goala";
			return 0;
		}
		else
		{
			return first->valoare;
		}
	}
	T back()
	{
		if (first == nullptr && last == nullptr) // if(isEmpty())
		{
			std::cout << "Eroare. Coada Queue este goala";
			return 0;
		}
		else
		{
			return last->valoare;
		}
	}

	void empty()
	{
		if (first == nullptr)
		{
			std::cout << "Queue este goala";
			return;
		}
	}

	void clear()
	{
		while (first != nullptr)
		{
			pop();
		}

	}

	int size()
	{
		return nr_elemente;
	}

};
template <typename T>
void Compare(Queue <T> Queue1, Queue <T> Queue2)
{
	if (Queue1.size() == Queue2.size())
	{
		while (Queue1.first != nullptr && Queue2.first != nullptr)
		{
			if (Queue1.first->valoare == Queue2.first->valoare)
			{
				Queue1.pop(); Queue2.pop();
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
	Queue<int> queue;
	int valoare; int nr_elem;
	/*std::cout << "Introduceti numarul de elemente pe care vreti sa il intorduceti "; std::cin >> nr_elem;
	for (int i = 1; i <= nr_elem; i++)
	{
		std::cin >> valoare;
		queue.push(valoare);
	}

	std::cout << "Size-ul este:" << queue.size(); std::cout << std::endl;
	std::cout << "Primul numar este:" << queue.front();  std::cout << std::endl;
	std::cout << "Ultimul numar este:" << queue.back();  std::cout << std::endl;*/

	Queue<int> Queue1, Queue2;

	std::cout << "Introduceti numarul de elemente pe care vreti sa il intorduceti "; std::cin >> nr_elem;
	for (int i = 1; i <= nr_elem; i++)
	{
		std::cin >> valoare;
		Queue1.push(valoare);
	}

	std::cout << "Introduceti numarul de elemente pe care vreti sa il intorduceti "; std::cin >> nr_elem;
	for (int i = 1; i <= nr_elem; i++)
	{
		std::cin >> valoare;
		Queue2.push(valoare);
	}

	Compare(Queue1, Queue2);
	return 0;
}

 