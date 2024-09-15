#include<iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;

    // parametrized constructor with default values
	Node(int value = 0) : Data(value), Next(nullptr) {}
};

class CircularLinkedList
{
	Node* head;

public:

	CircularLinkedList() : head(NULL) {}

	// insert value at first index of list 
	void InsertAtFirst(int value)
	{
		Node* newNode = new Node(value);
		
		if (head == NULL)
		{
			head = newNode;
			head->Next = head;            // re-pointing to head to make circular link
			return;
		}

		Node* temp = head;
		while (temp->Next != head)
		{
			temp = temp->Next;
		}
		// now temp is the last node of this circular linked list

		temp->Next = newNode;
		newNode->Next = head;
		head = newNode;
	}

	// insert element at end of list
	void InserAtEnd(int value)
	{
		Node* newNode = new Node(value);

		if (head == NULL)
		{
			head = newNode;
			head->Next = head;
			return;
		}

		Node* temp = head;
		while (temp->Next != head)
		{
			temp = temp->Next;
		}

		temp->Next = newNode;
		newNode->Next = head;
	}

	// insert element at given index
	void InsertAtGivenIndex(int index,int value)
	{
        // assumed that linked list will start from 0th index 
		index--;
		if (index == 0)
		{
			InsertAtFirst(value);
		}

		Node* newNode = new Node(value);
		int i = 0;
		Node* temp = head;
		while (i < (index - 1) && temp->Next != head)
		{
			temp = temp->Next;
			i++;
		}

		newNode->Next = temp->Next;
		temp->Next = newNode;
	}

	// insert node after given node
	void InsertNodeAfterNode(Node* Previous, int value)
	{
		if (Previous == NULL)
		{
			cout << "Previous node can't be NULL" << endl;
			return;
		}

		Node* newNode = new Node(value);

		newNode->Next = Previous->Next;
		Previous->Next = newNode;
	}

	// get node of given index
	Node* operator[](size_t n)
	{
		if (head == nullptr)
		{
			cout << "List is empty " << endl;
			return nullptr;
		}

		size_t i = 0;
		Node* temp = head;

		while (i < n && temp->Next != head)
		{
			temp = temp->Next;
			++i;
		}
		if (temp->Next == head && i != n)
		{
			cout << "List out of bound" << endl;
			return nullptr;
		}
		return temp;
	}

	// operator overloaded to print list
	friend ostream& operator<<(ostream& out, const CircularLinkedList& list)
	{
		Node* temp = list.head;
		do
		{
			out << temp->Data << "  ";
			temp = temp->Next;
		} while (temp != list.head);
		return out;
	}

	// destructor to free the allocated memory
	~CircularLinkedList()
	{
		if (head == NULL) return;

		Node* temp = head;
		Node* nextNode;
		do
		{
			nextNode = temp->Next;
			delete temp;
			temp = nextNode;
		} while (temp != head);
		cout << "Destructor invoked" << endl;
	}
};

// main() function to check functionality of every function defined above 
int main()
{
	CircularLinkedList list;

	list.InsertAtFirst(5);
	list.InsertAtFirst(4);
	list.InsertAtFirst(3);
	list.InsertAtFirst(2);
	list.InsertAtFirst(1);
	cout << "After inserting element at first, list: " << list << endl;

	list.InserAtEnd(11);
	list.InserAtEnd(12);
	list.InserAtEnd(13);
	list.InserAtEnd(14);
	list.InserAtEnd(15);
	cout << "After inserting element at end, list: " << list << endl << endl;

	
	list.InsertAtGivenIndex(6, 6);
	list.InsertAtGivenIndex(7, 7);
	list.InsertAtGivenIndex(8, 8);
	list.InsertAtGivenIndex(9, 9);
	list.InsertAtGivenIndex(10, 10);
	cout << endl << "After inserting values at indexes in between , list is: " << list << endl;

	size_t index;
	int value;
	cout << "Enter index to insert a node(after that index): ";
	cin >> index;
	cout << "Enter value to insert after " << index << " index: ";
	cin >> value;
	list.InsertNodeAfterNode(list[index - 1], value);
	cout << "After inserting value after given node, list is: " << list << endl;

	return 0;
}