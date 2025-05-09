#include <iostream>
#include <cstring>  // Для strcmp
using namespace std;

// Функція-шаблон сортування методом вставки
template <typename T>
void insertionSort(T* arr, int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];  // зберігаємо поточний елемент
        int j = i - 1;

        // Переміщаємо елементи, які більші за key, на одну позицію вперед
        while (j >= 0 && arr[j]> key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Вставляємо key на його місце
    }
}
template <>
void insertionSort<char*>(char** arr, int n) {
    for (int i = 1; i < n; i++) {
        char* key = arr[i];  // зберігаємо поточний елемент
        int j = i - 1;

        // Переміщаємо елементи, які більші за key, на одну позицію вперед
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Вставляємо key на його місце
    }
}

int main() {
    const int N = 5;
    char* s[N];

    // Введення даних з клавіатури
    for (int i = 0; i < N; i++) {
        s[i] = new char[100];
        cout << "Введіть рядок " << i + 1 << ": ";
        cin.getline(s[i], 100);  // Вводимо рядок з клавіатури
    }

    // Впорядкування масиву рядків методом вставки
    insertionSort(s, N);

    // Виведення відсортованих рядків
    cout << "Результат після сортування методом вставки:" << endl;
    for (int i = 0; i < N; i++) {
        cout << s[i] << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < N; i++) {
        delete[] s[i];
    }

    return 0;
}
