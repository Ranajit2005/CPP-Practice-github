#include <iostream>
using namespace std;

int Quick(int arr[], int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;
    int j = first;

    for (; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[last]);

    return i + 1;
}

void QuickSort(int arr[], int first, int last)
{
    if (first >= last)
        return;

    int pi = Quick(arr, first, last);
    QuickSort(arr, first, pi - 1);
    QuickSort(arr, pi + 1, last);
}

int main()
{
    int n;
    cout << "Give the size of array : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int f=0;
    // int l=n-1;
    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}