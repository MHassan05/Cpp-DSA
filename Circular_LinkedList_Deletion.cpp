#include<iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;

	Node(int value) : Data(value), Next(nullptr) {}
};

class CircularLinkedList
{
	Node* head;
public:
	CircularLinkedList() : head(nullptr) {}

	// destructor to delete list
	~CircularLinkedList()
	{
		if (head == NULL)
			return;

		Node* temp = head;
		Node* nextNode;
		do
		{
			nextNode = temp->Next;
			delete temp;
			temp = nextNode;
		} while (temp != head);
	}

	//  operator overloaded to print list
	friend ostream& operator << (ostream& out, const CircularLinkedList& obj)
	{
		if (obj.head == NULL)
		{
			cout << "List is empty " << endl;
			return out;
		}
		Node* temp = obj.head;

		do
		{
			cout << temp->Data << " ";
			temp = temp->Next;
		} while (temp != obj.head);
		return out;
	}

	// function to insert data in list 
	void append(int value)
	{
		Node* newNode = new Node(value);

        // if list is null then insert at beginning 
		if (head == NULL)
		{
			head = newNode;
			head->Next = head;
			return;
		}

        // other wise insert at end of list
		Node* temp = head;
		while (temp->Next != head)
		{
			temp = temp->Next;
		}

		temp->Next = newNode;
		newNode->Next = head;
	}

	// function to delete first node
	void DeleteFirstNode()
	{
		if (head == NULL)
			return;

		if (head == head->Next)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* temp = head;
		Node* last = head;

		while (last->Next != head)
		{
			last = last->Next;
		}

		last->Next = head->Next;
		head = head->Next;

		delete temp;
	}

	// function to delete last node
	void DeleteLastNode()
	{
		if (head == NULL)
			return;
		if (head == head->Next)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;
		Node* last = head->Next;

		while (last->Next != head)
		{
			temp = temp->Next;
			last = last->Next;
		}

		temp->Next = head;
		delete last;
	}

	// function to delete given index 
	void DeleteGivenIndex(size_t& index)
	{
		if (head == NULL)
			return;
		if (head->Next == head)
		{
			delete head;
			head = NULL;
			return;
		}
		if (index == 0)
		{
			DeleteFirstNode();
			return;
		}

		size_t i = 0;
		Node* temp = head;
		while (i < index - 1 && temp->Next != head)
		{
			temp = temp->Next;
			i++;
		}

		if (temp->Next == head)
		{
			cout << "List out of Bound" << endl;
			return;
		}

		Node* newNode = temp->Next;
		temp->Next = newNode->Next;
		delete newNode;

	}

	// function to delete given value
	void DeleteGivenValue(int value)
	{
		if (head == nullptr)
			return;
		if (head->Data == value)
		{
			DeleteFirstNode();
			return;
		}
		Node* temp = head;
		Node* deletingNode = head->Next;
		while (deletingNode->Data != value && deletingNode->Next != head)
		{
			deletingNode = deletingNode->Next;
			temp = temp->Next;
		}
		if (deletingNode->Next == head)
		{
			cout << "Value does not exist" << endl;
			return;
		}

		temp->Next = deletingNode->Next;
		delete deletingNode;
	}

};

int main()
{
	CircularLinkedList list;
	for (int i = 0; i < 10; i++)
		list.append(i * 10 + 10);

	cout << "Before operations, list: " << list << endl;
	
	list.DeleteFirstNode();
	cout << "After deleting first node, list: " << list << endl;

	list.DeleteLastNode();
	cout << "After deleting last node, list: " << list << endl;

	size_t index;
	cout << "\nEnter Index to delete: ";
	cin >> index;
	if (index > 0)
	{
		index -= 1;
		list.DeleteGivenIndex(index);
		cout << "After deleting " << index + 1 << " index, list: " << list << endl;
	}
	else
		cout << "Index out of bound." << endl;

	index = static_cast<int>(index);
	cout << "\nEnter Value to delete from list: ";
	cin >> index;
	list.DeleteGivenValue(index);
	cout << "After Deleting given value, list: " << list << endl;

	return 0;
}
