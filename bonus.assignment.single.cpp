#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class SinglyLinkedList {
private:Node* head;
    Node* tail;
    int counter;
public: SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }
    void MakeNull() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }
    void InsertSorted(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (head == nullptr || head->data >= x) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = newNode;
            counter++;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data < x) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        counter++;
    }
    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.InsertSorted(5);
    list.InsertSorted(2);
    list.InsertSorted(8);
    list.InsertSorted(3);
    list.PrintList();
    list.MakeNull();
    return 0;
}