#include<iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;

	// a constructor to initialze the node with given data and set Next to NULL
	Node(int data) : Data(data), Next(NULL) {}
};

class LinkedList
{
	Node* head;
        int size;

public:
	LinkedList() : head(NULL), size(0) {}

	// function to add Data
	void append(int data)
	{
		Node* newNode = new Node(data);

		// checking if the list was already empty or not 
		if (head == NULL)
		{
			// if empty then insert data at beginning of list
			head = newNode;
                        size++;
			return;
		}

		// if list was not empty then insert data at the end of list
		Node* temp = head;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = newNode;
        size++;
	}

	// operator overloaded to print list
	friend ostream& operator<<(ostream& out, const LinkedList& list)
	{
		Node* temp = list.head;
		while (temp != NULL)
		{
			out << temp->Data << "  ";
			temp = temp->Next;
		}
		return out;
	}

	// Destructor for class that will de-allocate the allocated memory
	~LinkedList()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->Next;
			delete temp;
		}
	}

	// deletion at first Node
	void DeleteFirstNode()
	{
		Node* newNode = head;
		head = head->Next;
		delete newNode;
                size--;
	}

	// deleting a node at given index
	void DeleteAtIndex(int index)
	{
        if(index < 1 || index > size || head == NULL)
        {
            cout << "List Is Already Empty." << endl;
            return;
        }

	// condition to delete node from begginning
        if(index == 1)
        {
            DeleteFirstNode();
            return;
        }

	// condition to delete node from end
        if(index == size)
        {
            DeleteLastNode();
            return;
        }

		// if both upper conidtion not matched then delete node from specified index
		Node* temp = head;
		int i = 2;
		while (i < index)
		{
			temp = temp->Next;
			i++;
		}
		Node* newNode = temp->Next;
		temp->Next = newNode->Next;
        size--;
		delete newNode;
	}

	// function to delete last node of list
	void DeleteLastNode()
	{
		Node* temp = head;
		Node* Last = temp->Next;

		while (Last->Next != NULL)
		{
			temp = Last;
			Last = temp->Next;
		}

		temp->Next = NULL;
		delete Last;
        size--;
	}

	// deleting the node with given value
	bool DeleteGivenValues(int value)
	{
		if(head == NULL)
		{
			cout << "List is Empty" << endl;
			return;
		}
		
		Node* temp = head;
		Node* deletingNode = temp->Next;

		while (deletingNode->Data != value && deletingNode->Next != NULL)
		{
			temp = deletingNode;
			deletingNode = temp->Next;
		}

		if (deletingNode->Data == value)
		{
			temp->Next = deletingNode->Next;
			delete deletingNode;
            size--;
			return true;
		}

		return false;
	}
};

// main function that will show functionality of each membor function in the class
int main()
{
	LinkedList list;
	for (int i = 0; i < 10; i++)
		list.append((i * 10) + 10);

	cout << "Before Deletion list is: " << list << endl;

	list.DeleteFirstNode();
	cout << "After Deleting First Node, List is: " << list << endl << endl;

	int index;
	cout << "Enter Index to remove, that node: ";
	cin >> index;
	list.DeleteAtIndex(index-1);
	cout << "After Deleting Values from 5th Index, List is: " << list << endl << endl;

	list.DeleteLastNode();
	cout << "After Deleting Last Node, List is: " << list << endl;

	cout << "Enter Values to Delete:  ";
	cin >> index;
	if (list.DeleteGivenValues(index))
		cout << "After Deleting " << index << " from list: " << list << endl;
	else
		cout << "Element Not found in list. " << endl;

	return 0;
}

