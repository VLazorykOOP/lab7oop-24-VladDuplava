#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// Шаблон
template <typename T>
void swapMinMax(T* arr, int size) {
    int minI = 0, maxI = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minI]) minI = i;
        if (arr[i] > arr[maxI]) maxI = i;
    }
    swap(arr[minI], arr[maxI]);
}

// Спеціалізація для char*
template <>
void swapMinMax<char*>((char*)* arr, int size) {
    int minI = 0, maxI = 0;
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], arr[minI]) < 0) minI = i;
        if (strcmp(arr[i], arr[maxI]) > 0) maxI = i;
    }
    swap(arr[minI], arr[maxI]);
}

template <typename T>
void print(T* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    const int N = 5;

    // int масив
    int a[N];
    for (int i = 0; i < N; i++) a[i] = rand() % 100;
    print(a, N);
    swapMinMax(a, N);
    print(a, N);

    // char* масив
    char* s[N];
    for (int i = 0; i < N; i++) {
        s[i] = new char[100];
        cout << "Введіть рядок " << i+1 << ": ";
        cin.getline(s[i], 100);
    }
    print(s, N);
    swapMinMax(s, N);
    print(s, N);

    for (int i = 0; i < N; i++) delete[] s[i];
    return 0;
}
