// C++ program to implement dual pivot QuickSort
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int* arr, int low, int high, int* lp);

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DualPivotQuickSort(int* arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

int partition(int* arr, int low, int high, int* lp)
{
    srand(time(NULL));
    int a,b;
    a=low+(rand()%(low-high));
    b=a+(rand()%(high-a));
    swap(&arr[a],&arr[low]);
    swap(&arr[b],&arr[high]);

    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (arr[k] < p) {
            swap(&arr[k], &arr[j]);
            j++;
        }

            // if elements are greater than or equal
            // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            swap(&arr[k], &arr[g]);
            g--;
            if (arr[k] < p) {
                swap(&arr[k], &arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    swap(&arr[low], &arr[j]);
    swap(&arr[high], &arr[g]);

    // returning the indices of the pivots.
    *lp = j; // because we cannot return two elements
    // from a function.

    return g;
}

// Driver code
int main()
{
    int nos;
    std::cout<<"PLEASE ENTER THE NUMBER OF ELEMENTS IN THE ARRAY\n";
    std::cin>>nos;
    int array[nos];
    for (int i = 0; i < nos; ++i) {
        std::cout<<"PLEASE ENTER THE ELEMENT "<<i<<"\n";
        std::cin>>array[i];
    }

    DualPivotQuickSort(array, 0, nos-1);
    cout << "Sorted array: ";
    for (int i = 0; i < nos; i++)
        cout << array[i] << " ";
    cout << endl;
}