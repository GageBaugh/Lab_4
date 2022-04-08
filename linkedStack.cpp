#include "linkedStack.h"
#include<iostream>

using namespace std;

LinkedStack::LinkedStack()
{
	top = nullptr;
}

LinkedStack::~LinkedStack()
{
	makeEmpty();
	delete(top);
}

bool LinkedStack::isEmpty()
{
	if (top == nullptr)
		return true;

	return false;
}

bool LinkedStack::isFull()
{
	Node* temp = new Node();

	if (!temp)
		return true;
	delete(temp);
	
	return false;
}

void LinkedStack::push(itemType value)
{
	if (!isFull())
	{
		Node* temp = new Node();
		temp->data = value;
		temp->link = top;
		top = temp;
	};
}

void LinkedStack::makeEmpty()
{
	while (!isEmpty())
		pop();
}

itemType LinkedStack::pop()
{
	if (!isEmpty())
	{
		itemType value = getTopItem();
		Node* temp = top;
		top = top->link;
		delete(temp);
		return value;
	}
}

itemType LinkedStack::getTopItem()
{
	if(!isEmpty())
		return top->data;
}

void LinkedStack::reverse()
{
	if (!isEmpty())
	{
		itemType item = pop();
		reverse();
		sendToBottom(item);
	}
}


void LinkedStack::sendToBottom(itemType item)
{
	if (!isEmpty())
	{
		itemType tempItem = pop();
		sendToBottom(item);
		push(tempItem);
	}
	else
		push(item);
}
