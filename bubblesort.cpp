#include <iostream>
using namespace std;

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

void bubbleSort(int *a, int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1, 4, 2, 54, 12, 32};
    int n = 6;
    printArray(a, n);
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}