#include <iostream>

using namespace std;

struct node
{
	char dato;
	node *next;
};

void generateEmpty(node *&start, int n)
{
	//start->dato = NUll; //inserisco dato nel primo elemento
	start->next = NULL; 
	start->next = start; //punto a se stesso
	node *index = start; //creo un indice temporaneo per scorrimento
	
	for (int i = 0; i < n; i++)
	{
		node *n = new node; //creo nuovo nodo

		//n->dato = NULL; //gli metto dentro il dato
		n->next = start; //lo punto all'inizio della lista

		index->next = n; //punto quello che si sposta (che rappresenta il nodo precedente) al nuovo nodo
		index = index->next; //
	}
}

void eliminaLista(node *&start)
{
	node *l = start;
	while (l && l != start)
	{
		node *temp = l;
		l = l->next;
		delete temp;
	}
	delete start;
}

void scorriLista(node *start)
{
	int i = 0;
	for (node *l = start->next; l != start; l = l->next)
	{
		l->dato = 'a' + (i++ % 26);
		cout << l->dato << " ";
		if ('a' + (i - 1) % 26 == 'z')
			cout << endl;
	}
}

node * reverse(node * x) {
   node * t;
   node * y = x;
   node * r = NULL;

   while ( y != NULL ) {
      t = y->next;
      y->next = r;
      r = y;
      y = t;
   }
   return r;
}

int main(int argn, char **args)
{
	node *start = new node;
	generateEmpty(start, 25);
	scorriLista(start);
	eliminaLista(start);
}
