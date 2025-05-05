#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int front, rear, capacity, count;

public:
    Queue(int size = 10) : capacity(size), front(0), rear(-1), count(0) {
        data = new T[capacity];
    }

    ~Queue() { delete[] data; }

    // Додавання елемента в кінець черги
    void enqueue(const T& element) {
        if (count == capacity) {
            cout << "Черга переповнена!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        data[rear] = element;
        count++;
    }

    // Видалення елемента з початку черги
    T dequeue() {
        if (count == 0) {
            cout << "Черга порожня!" << endl;
            return T();  // Повертаємо значення за замовчуванням
        }
        T element = data[front];
        front = (front + 1) % capacity;
        count--;
        return element;
    }

    // Перевірка, чи пуста черга
    bool isEmpty() const {
        return count == 0;
    }

    // Перший елемент черги
    T frontElement() const {
        if (count == 0) {
            cout << "Черга порожня!" << endl;
            return T();  // Повертаємо значення за замовчуванням
        }
        return data[front];
    }
};

int main() {
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Перший елемент: " << q.frontElement() << endl;

    q.dequeue();
    cout << "Перший елемент після dequeue: " << q.frontElement() << endl;

    q.enqueue(40);
    cout << "Перший елемент після enqueue 40: " << q.frontElement() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Перший елемент після двох dequeues: " << q.frontElement() << endl;

    q.dequeue();  // Черга порожня

    return 0;
}
