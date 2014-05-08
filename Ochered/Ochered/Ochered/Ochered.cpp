#include <iostream>
#include <time.h>

using namespace std;
int n; /// razmernost ocheredi

struct Queue
{
	int *arr;
	int first;
	int last;
	int count;
};

void Initial (int N, Queue *&p)  /// Inicializacia ocheredi
{
	p = new Queue[N];
	p->arr = new int[N];
	p->first = 0;
	p->last = 0;
	p->count = 0;
}

bool Full (Queue *&p)  /// Proverka na polnotu 
{
	if (p->count == n)
		return true;
	else
		return false;
}

bool Empty (Queue *&p)   /// Proverka na puctotu
{
	if (p->count == 0)
		return true;
	else
		return false;
}

void add (int a, Queue *&p)  /// Dobavlenie v ochered
{
	if (Full(p) == false)
	{
		p->arr[p->last] = a;
		p->last ++;
		if (p->last == n)
		p->last = 0;
		p->count ++;
	}
	else
		cout <<"Error! Queue is full" << endl;
}

void del (Queue *&p) /// Udalenie iz ocheredi
{
	if (Empty(p) == false)
	{
		p->arr[p->first] = 0;
		p->first ++;
		if (p->first == n)
		p->first = 0;
		p->count --;
	}
	else
		cout <<"Error! Queue is empty" << endl;
}

void Show(Queue *p) ///  Vyvod ocheredi
{
	int i,temp; 
	for (i = p->first, temp=0; temp < p->count ; temp ++, i++) 
	{ 
		if (i == n) 
			i = 0; 
		cout << p->arr[i] << " "; 
	}
}

int main()
{
	Queue *p;
	cout <<"Enter dimention of queue: ";
	cin >> n;
	Initial (n, p);///  Inicializiruem ochered

	for (int i = 0; i < n; i++) ///  zapolnyaem ee
		add (rand() % 10, p);

	Show (p);
	cout << endl;
	cout <<"After delete" <<endl;
	del (p);
	Show (p);
	return 0;
}

