#include <iostream>
#include <time.h>

using namespace std;
int n;
struct Stack
{
	int *arr;
	int count;
};

void Initial (int N, Stack *&p) /// Inicializacia steka 
{
	p = new Stack[N];
	p->arr = new int[N];
	p->count = 0;
}

int CheckFull (Stack *&p) /// Proverka steka na polnotu
{
	if (p->count == n)
		return 1;
	else
		return 0;
}

int CheckEmpty (Stack *&p) /// Proverka steka na pustotu
{
	if (p->count == 0)
		return 1;
	else
		return 0;
}


void push(int a, Stack *&p) /// Dobavlenie elementa v stek
{
	if (CheckFull(p) == 0)
	{
		p->arr[p->count] = a;
		p->count ++;
	}
	else
		cout <<"Error! Stack is full" << endl;
}

void pop (Stack *&p) /// Udalenie elementa iz steka
{
	if (CheckEmpty(p) == 0)
		p->count --;
	else
		cout <<"Error! Stack is empty" << endl;
}

void ShowStack (Stack *&p)
{
	for (int i = 0; i < p->count; i++)
		cout << p->arr[i] << endl;
}

void ShowElement (int num, Stack *&p)
{
	for (int i = 0; i < p->count; i++)
	{
		if (i == (num - 1))
			cout <<"Element ¹" << num << ": " << p->arr[i] << endl;
	}
}

int main()
{
	srand(time(NULL));
	Stack *p;
	cout <<"Enter dimention of stack: ";
	cin >> n;
	Initial (n, p); /// inicializiruem stek

	for(int i = 0; i < n; i++)
		push (rand() % 10, p);

	ShowStack(p); /// vyvodim stek
	pop (p); /// udalyaem element iz steka
	cout << endl;
	cout <<"After delete" << endl;
	ShowStack(p); /// vyvodim stek
	cout << endl;
	ShowElement (2, p); /// pokazyvaem element po nomeru 
	return 0;
}