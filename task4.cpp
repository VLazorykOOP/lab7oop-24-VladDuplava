#include <iostream>
using namespace std;

// Вузол двозв'язного списку
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Клас для двозв'язного списку
template <typename T>
class DoublyLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Додавання в кінець списку
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Виведення списку
    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Ітератор
    class Iterator {
        Node<T>* current;
    public:
        Iterator(Node<T>* node) : current(node) {}
        bool hasNext() { return current != nullptr; }
        T next() { T val = current->data; current = current->next; return val; }
    };

    Iterator begin() { return Iterator(head); }
};

int main() {
    DoublyLinkedList<int> list;

    // Додавання елементів
    list.append(10);
    list.append(20);
    list.append(30);

    // Виведення списку
    list.display();

    // Ітерація через список
    for (auto it = list.begin(); it.hasNext(); ) {
        cout << it.next() << " ";
    }

    return 0;
}
