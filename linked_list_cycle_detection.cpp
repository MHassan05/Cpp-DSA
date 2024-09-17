#include <iostream>

using namespace std;

/*
 * This program defines a linked list and includes a function to detect cycles within the list.
 * The algorithm used to detect cycles is Floyd's Cycle-Finding Algorithm, also known as the 
 * Tortoise and Hare algorithm. It uses two pointers moving at different speeds to determine 
 * if a cycle exists.
 */

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList 
{
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Function to append a new node with given data to the end of the list
    void append(int data)
     {
        Node* newNode = new Node(data);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to detect a cycle in the linked list using Floyd's Cycle-Finding Algorithm
    bool detectCycle() 
    {
        if (!head || !head->next) return false;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next)
            {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() 
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    // Creating a cycle for testing
    list.head->next->next->next->next = list.head->next;

    if (list.detectCycle()) 
    {
        cout << "Cycle detected in the linked list." << endl;
    }
    else 
    {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
