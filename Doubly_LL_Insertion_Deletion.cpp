#include <iostream>
using namespace std;

// node class ( struct can be used )
class Node
{
public:
    int data;
    Node* next;
    Node* previous;

    Node(int val = 0) : data(val), next(nullptr), previous(nullptr) {}
};

class LinkedList
{
    Node* head;
    Node* tail;                          // tail pointer to point at last node of list
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // insert node at beginning of list
    // worst case time complexity => O(1)
    void insertNodeAtBeginning(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;

        if (head != nullptr)
        {
            head->previous = newNode;
        }
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        size++;
    }

    // insert node after the given key
    // worst case time complexity => O(n)
    void insertNodeInMiddle(int data, int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* newNode = new Node(data);

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << key << " not found in the list!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next = newNode;

        if (newNode->next == nullptr)
        {
            tail = newNode;
        }

        if (newNode->next != nullptr)
        {
            newNode->next->previous = newNode;
        }

        size++;
    }

    //  insert node at end of the list
    // worst case time complexity => O(N)
    void insertNodeAtEnd(int data)
    {
        if (head == nullptr)
        {
            insertNodeAtBeginning(data);
            return;
        }

        Node* temp = head;
        Node* newNode = new Node(data);

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->previous = temp;
        size++;
        tail = newNode;
    }

    // fdelete first node from the list
    // worst case time complexity => O(1)
    bool deleteFirstNode()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return false;
        }
        Node* temp = head;
        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            head->previous = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    // function to delete specified node
    // worst case time complexity => O(N)
    bool deleteNode(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return false;
        }

        if (head->data == key)
        {
            return deleteFirstNode();
        }

        Node* predecessor = head;
        Node* successor = head->next;

        while (successor != nullptr && successor->data != key)
        {
            predecessor = successor;
            successor = successor->next;
        }

        if (successor == nullptr)
        {
            cout << key << " not found in the list!" << endl;
            return false;
        }

        if (successor == tail)
        {
            tail = predecessor;
        }

        predecessor->next = successor->next;

        if (successor->next != nullptr)
        {
            successor->next->previous = predecessor;
        }

        delete successor;
        size--;
        return true;
    }

    //  delete tail node ( i.e last node of the list)
    // worst case time complexity => O(1)
    bool deleteLastNode()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return false;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* temp = tail;
            tail = temp->previous;
            tail->next = nullptr;
            delete temp;
        }
        size--;
        return true;
    }

    // display list ( by traversing through each node of list)
    // worst case time complexity => O(N)
    void display()
    {
        if (head == nullptr)
        {
            cout << "\tList is Empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }

        cout << endl;
    }

    // search item in list
    // worst case time complexity => O(N)
    bool search(int key)
    {
        if (head == nullptr)
        {
            return false;
        }

        Node* temp = head;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    // Sort linked list ( bubble sort algorithm )
    // worst case time complexity => O(N^2)
    void Sort()
    {
        if (head == nullptr)
        {
            cout << "Cannot Sort!" << endl;
            return;
        }

        Node* tempLast = tail;

        for (Node* i = head; i != nullptr; i = i->next)
        {
            for (Node* j = head; j != tempLast; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    swap(j->data, j->next->data);
                }
            }
            tempLast = tempLast->previous;
        }
    }

};

// menu function to show menu
void menu()
{
    cout << "\n--- Doubly Linked List Menu ---\n";
    cout << "1. Insert Node at Beginning\n";
    cout << "2. Insert Node in Middle\n";
    cout << "3. Insert Node at End\n";
    cout << "4. Delete First Node\n";
    cout << "5. Delete Specified Node\n";
    cout << "6. Delete Last Node\n";
    cout << "7. Display List\n";
    cout << "8. Search for a Node\n";
    cout << "9. Sort List\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    LinkedList list;
    int choice, data, key;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            list.insertNodeAtBeginning(data);
            break;

        case 2:
            cout << "Enter data to insert in the middle: ";
            cin >> data;
            cout << "Enter the key after which to insert the new node: ";
            cin >> key;
            list.insertNodeInMiddle(data, key);
            break;

        case 3:
            cout << "Enter data to insert at the end: ";
            cin >> data;
            list.insertNodeAtEnd(data);
            break;

        case 4:
            if (list.deleteFirstNode())
            {
                cout << "First node deleted successfully." << endl;
            }
            break;

        case 5:
            cout << "Enter the key of the node to delete: ";
            cin >> key;
            if (list.deleteNode(key))
            {
                cout << "Node with key " << key << " deleted successfully." << endl;
            }
            break;

        case 6:
            if (list.deleteLastNode())
            {
                cout << "Last node deleted successfully." << endl;
            }
            break;

        case 7:
            cout << "Current list: ";
            list.display();
            break;

        case 8:
            cout << "Enter the key to search for: ";
            cin >> key;
            if (list.search(key))
            {
                cout << "Key " << key << " found in the list." << endl;
            }
            else
            {
                cout << "Key " << key << " not found in the list." << endl;
            }
            break;

        case 9:
            list.Sort();
            cout << "List sorted successfully." << endl;
            break;

        case 10:
            cout << "Exiting the program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
