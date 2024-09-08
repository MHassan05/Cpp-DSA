//#include <iostream>
//
//struct Node {
//    int Data;
//    Node* Next;
//
//    Node(int Value = 0) : Data(Value), Next(nullptr) {}
//};
//
//class LinkedList {
//    Node* head;
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    void InsertAtFirst(int data) {
//        Node* newNode = new Node(data);
//        newNode->Next = head;
//        head = newNode;
//    }
//
//    void InsertAtEnd(int data) {
//        Node* newNode = new Node(data);
//
//        if (head == nullptr) {
//            head = newNode;
//            return;
//        }
//
//        Node* temp = head;
//        while (temp->Next != nullptr) {
//            temp = temp->Next;
//        }
//        temp->Next = newNode;
//    }
//
//    void InsertAtIndex(int index, int data) {
//        if (index < 0) {
//            std::cout << "Index cannot be negative." << std::endl;
//            return;
//        }
//
//        if (index == 0) {
//            InsertAtFirst(data);
//            return;
//        }
//
//        Node* newNode = new Node(data);
//        Node* temp = head;
//
//        int i = 1;
//        while (i < index && temp != nullptr) {
//            temp = temp->Next;
//            i++;
//        }
//
//        if (temp == nullptr) {
//            std::cout << "Index out of bounds." << std::endl;
//            return;
//        }
//
//        newNode->Next = temp->Next;
//        temp->Next = newNode;
//    }
//
//    void InsertAfterNode(Node* previous, int data) {
//        if (previous == nullptr) {
//            std::cout << "Node cannot be NULL/empty" << std::endl;
//            return;
//        }
//
//        Node* newNode = new Node(data);
//        newNode->Next = previous->Next;
//        previous->Next = newNode;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
//        Node* temp = list.head;
//        while (temp != nullptr) {
//            out << temp->Data << "  ";
//            temp = temp->Next;
//        }
//        return out;
//    }
//
//    Node* operator[] (int n) {
//        int i = 0;
//        Node* temp = head;
//        while (i < n && temp != nullptr) {
//            temp = temp->Next;
//            i++;
//        }
//
//        if (temp == nullptr) {
//            std::cout << "Index out of bounds." << std::endl;
//            return nullptr;
//        }
//
//        return temp;
//    }
//
//    ~LinkedList() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->Next;
//            delete temp;
//        }
//    }
//};
//
//int main() {
//    LinkedList list;
//
//    list.InsertAtFirst(40);
//    list.InsertAtFirst(20);
//    list.InsertAtFirst(10);
//
//    std::cout << "After Inserting element at first: " << list << std::endl << std::endl;
//
//    list.InsertAtEnd(20);
//    list.InsertAtEnd(10);
//    std::cout << "After Inserting element at end: " << list << std::endl << std::endl;
//
//    list.InsertAtIndex(2, 30);
//    std::cout << "After Inserting Element at specified Index: " << list << std::endl << std::endl;
//
//    list.InsertAfterNode(list[3], 30);
//    std::cout << "After Inserting Element after specified Node: " << list << std::endl << std::endl;
//
//    std::cout << "Complete ";
//    std::cout << "List is: " << list << std::endl;
//
//    system("pause>0");
//    return 0;
//}
