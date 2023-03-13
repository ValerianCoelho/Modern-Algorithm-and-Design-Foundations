#include <iostream>
using namespace std;

int arr[100];

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high){
    int pivot = arr[high];
    int i = low;
    int j = high-1;

    while(i<=j){
        while(arr[i] < pivot){ // We use '<' operator because, if array[i] == pivot, we don't want to increase i-index
            i++;
        }
        while(arr[j] >= pivot && j >= i){ // We use '>=' operator because, if array[j] == pivot, we want to decrease j-index
            j--;
        }
        if(i < j){ // i > j, then all the elements are in their place for the current iteration
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]); // swapping the pivot element with array[i]
    return i; // We return the partition element index
}

void quicksort(int low, int high){
    if(low >= high){
        return;
    }
    int pi = partition(low, high);

    quicksort(low, pi-1);
    quicksort(pi+1, high);
}

int main()
{
    int size;
    cout << "Enter the number of elements : ";
    scanf("%d", &size);
   
    cout << "Enter the elements in the array : ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    quicksort(0, size-1);

    cout << "Sorted Array : ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}