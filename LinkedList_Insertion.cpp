#include <iostream>
using namespace std;

struct Node {
   int Data;          
   Node* Next;        

   // Constructor to initialize the Node with given data and default Next as nullptr
   Node(int Value = 0) : Data(Value), Next(nullptr) {}
};

class LinkedList {
   Node* head;  // Pointer to the head of the linked list

public:
   // Constructor initializes an empty linked list with head set to nullptr
   LinkedList() : head(nullptr) {}

   // Inserts a new node with given data at the beginning of the list
   void InsertAtFirst(int data) {
       Node* newNode = new Node(data); // Create new node
       newNode->Next = head;           // Link new node to current head
       head = newNode;                 // Make new node the head of the list
   }

   // Inserts a new node with given data at the end of the list
   void InsertAtEnd(int data) {
       Node* newNode = new Node(data); // Create new node

       // If list is empty, make the new node the head
       if (head == nullptr) {
           head = newNode;
           return;
       }

       // Traverse to the end of the list
       Node* temp = head;
       while (temp->Next != nullptr) {
           temp = temp->Next;
       }
       temp->Next = newNode;  // Link new node at the end
   }

   // Inserts a new node at a specified index in the list
   void InsertAtIndex(int index, int data) 
{
     // Check if index is valid
       if (index < 1) {  
           cout << "Index cannot be negative." << endl;
           return;
       }

     // If inserting at the first index, use InsertAtFirst
       if (index == 1) {  
           InsertAtFirst(data);
           return;
       }

       Node* newNode = new Node(data); // Create new node
       Node* temp = head;

       int i = 2;
       // Traverse the list to the index where insertion is to happen
       while (i < index && temp != nullptr) {
           temp = temp->Next;
           i++;
       }

       // If index is out of bounds, print error
       if (temp == nullptr) {
           cout << "Index out of bounds." << endl;
           return;
       }

       // Insert the new node at the correct position
       newNode->Next = temp->Next;
       temp->Next = newNode;
   }

   // Inserts a new node after a specified node (previous)
   void InsertAfterNode(Node* previous, int data) {
       if (previous == nullptr) {  // Check if the previous node is valid
           cout << "Node cannot be NULL/empty" << endl;
           return;
       }

       Node* newNode = new Node(data); // Create new node
       newNode->Next = previous->Next; // Link new node to next node of previous
       previous->Next = newNode;       // Link previous to new node
   }

   // Overloads the stream insertion operator to print the linked list
   friend ostream& operator<<(std::ostream& out, const LinkedList& list) {
       Node* temp = list.head;  // Start from the head
       while (temp != nullptr) {
           out << temp->Data << "  "; // Print each node's data
           temp = temp->Next;
       }
       return out;  // Return the stream object
   }

   // Overloads the subscript operator to access nodes by index
   Node* operator[] (int n) {
       int i = 1;
       Node* temp = head;

       // Traverse the list until the desired index
       while (i < n && temp != nullptr) {
           temp = temp->Next;
           i++;
       }

       // If index is out of bounds, print error
       if (temp == nullptr) {
           cout << "Index out of bounds." << endl;
           return nullptr;
       }

       return temp;  // Return the node at index n
   }

   // Destructor to free the memory allocated for nodes
   ~LinkedList() {
       while (head != nullptr) {
           Node* temp = head;    // Store the current head
           head = head->Next;    // Move head to the next node
           delete temp;          // Delete the current node
       }
   }
};

int main() {
   LinkedList list;

   // Insert elements at the beginning of the list
   list.InsertAtFirst(40);
   list.InsertAtFirst(20);
   list.InsertAtFirst(10);

   cout << "After Inserting element at first: " << list << endl << endl;

   // Insert elements at the end of the list
   list.InsertAtEnd(20);
   list.InsertAtEnd(10);
   cout << "After Inserting element at end: " << list << endl << endl;

   // Insert an element at index 2
   list.InsertAtIndex(2, 30);
   cout << "After Inserting Element at specified Index(2): " << list << endl << endl;

   // Insert an element after node at index 3
   list.InsertAfterNode(list[3], 30);
   cout << "After Inserting Element after specified Node(after index 3): " << list << endl << endl;

   // Print the complete list
   cout << "Complete ";
   cout << "List is: " << list << endl;
  
   return 0;
}
