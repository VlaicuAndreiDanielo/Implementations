//Implementare Stack
#include <iostream>
template <typename T>
struct Stack
{
	struct node
	{
		T valoare;
		node* urmator = nullptr;
	};

	node* topStack = nullptr;
	int nrElemente = 0;
	// Stack() : topStack(nullptr), nrElemente(0){}

	void push(const T& element)
	{
		node* elem = new node{ element };
		// elem->valoare=element;
		if (topStack == nullptr)
		{
			topStack = elem;
		}
		else
		{
			elem->urmator = topStack;
			topStack = elem;
		}
		nrElemente++;
	}

	void pop() 
	{
		if (topStack == nullptr)
		{
			std::cout << "Stiva este goala ";
			return;
		}
		node* intermediar = new node;
		intermediar = topStack;
		topStack = topStack->urmator;
		delete intermediar;
		nrElemente--;
	}

	T top()
	{
		if (topStack == nullptr)
		{
			std::cout << "Stiva este vida";
			return 0;
		}
		return topStack.valoare;
	}
	void empty()
	{
		if (topStack == nullptr)
		{
			std::cout << "Stiva este goala";
		}
		else
		{
			std::cout << "Stiva nu este vida";
		}
	}

	void clear()
	{
		node* interm = new node;
		while(topStack!=nullptr)
	    {
			interm = topStack;
			topStack = topStack->urmator;
			delete interm;
		}
		nrElemente = 0;
	}
	T afisare_elemente()
	{
		node* current = new node;
		current = topStack;
		while (current != nullptr)
		{
			std::cout << current->valoare << " ";
			current = current->urmator;
		}
		std::cout << "\n";
		return 0;
	}

	int size()
	{
		return nrElemente;
	}

};
int main()
{
	Stack<int> stack; // std::stack<int> stack;
	int nr, element;
	std::cout << "Numarul de elemente de introdus in stiva este:"; std::cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		std::cin >> element;
		stack.push(element);
	}

	std::cout << "Size-ul stack-ului este: " << stack.size() << "\n";
	stack.empty(); std::cout << "\n";
	std::cout << "Elementele Stack-ului sunt:";
	stack.afisare_elemente();
	return 0;
}