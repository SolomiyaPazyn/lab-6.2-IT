#include <iostream>
#include <climits>
using namespace std;

void Init(int* b, const int size)
{
    for (size_t i = 0; i < size; i++)
        b[i] = -10 + rand() % 21;
}

void Print(const int* const b, const int size)
{
    cout << "{";
    for (size_t i = 0; i < size; i++)
    {
        cout << b[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

int FirstIndex(const int b[], const int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (b[i] % 2 == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int IndexMin(int b[], const int size)
{
    int index = FirstIndex(b, size);
    if (index == -1)
        return index;
    int min = b[index];
    for (int i = 0; i < size; i++)
        if (b[i] < min && b[i] % 2 == 0)
        {
            index = i;
            min = b[i];
        }
    return index;
}

bool Modify(int b[], const int size)
{
    int index = IndexMin(b, size);
    if (index != -1)
    {
        int tmp = b[0];
        b[0] = b[index];
        b[index] = tmp;
        return true;
    }
    else return false;
}

// Нова функція для обчислення середнього арифметичного мін. та макс. елементів
double AverageMinMax(const int* b, const int size)
{
    if (size == 0) return 0.0;

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (b[i] < min) min = b[i];
        if (b[i] > max) max = b[i];
    }

    return (min + max) / 2.0;
}

int main()
{

    srand(time(0));
    int n;
    cout << "n = "; cin >> n;

    int* b = new int[n];

    Init(b, n);
    Print(b, n);
    if (!Modify(b, n))
        cout << "There is no item that matches the condition" << endl;
    Print(b, n);

    // Обчислення та виведення середнього арифметичного
    double avg = AverageMinMax(b, n);
    cout << " Arithmetic average min. and max. elements: " << avg << endl;

    delete[] b;
    b = nullptr;
    return 0;
}