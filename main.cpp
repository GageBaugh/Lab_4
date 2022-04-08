#include <iostream>

#include "linkedStack.h"

using namespace std;

int main()
{
	LinkedStack l;

	for (int i = 1; i <= 100; i++)
	{
		l.push(i);
		cout << "Adding: " << i << endl;
	}
	l.reverse();

	while (!l.isEmpty())
	{
		cout << l.pop() << endl;
	}

	return 0;
}