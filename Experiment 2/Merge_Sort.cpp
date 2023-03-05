#include <iostream>
using namespace std;

int arr[100];

void merge(int left, int mid, int right){
    int leftarr[10];
    int rightarr[10];
   
    int sizeOfLeftarr = mid - left + 1;
    int sizeOfRightarr = right - (mid + 1) + 1;

    // Eg:-
    // Left            mid (mid+1)    right
    // ┌────┬────┬────┬────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ 42 │ 63 │ 35 │
    // └────┴────┴────┴────┴────┴────┴────┘
    // Left = 0
    // mid = 3
    // right = 6

    // sizeOfLeftarr = mid - left + 1 = 3 - 0 + 1 = 4
    // sizeOfRightarr = right - (mid + 1) + 1 = 6 - (3+1) + 1 = 3

    // ┌────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ leftarr
    // └────┴────┴────┴────┘
    // ┌────┬────┬────┐
    // │ 42 │ 63 │ 35 │ rightarr
    // └────┴────┴────┘
   
    // Copying Elements from 'arr' to 'leftarr'
    for(int i=0; i<sizeOfLeftarr; i++){
        leftarr[i] = arr[left + i];
    }
   
    // Copying Elements from 'arr' to 'rightarr'
    for(int i=0; i<sizeOfRightarr; i++){
        rightarr[i] = arr[(mid + 1) + i];
    }
   
    int i = 0; // For Left arr index
    int j = 0; // For Right arr index
    int k = left; // For main arr index
   
    while(i < sizeOfLeftarr && j < sizeOfRightarr){
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        }
        else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < sizeOfLeftarr) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < sizeOfRightarr) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
   
    mergesort(left, mid);
    mergesort(mid+1, right);
   
    merge(left, mid, right);
}


int main() {
    int size;
    printf("Enter the number of elements : ");
    cin >> size;
   
    printf("Enter the elements in the array : ");
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    mergesort(0, size-1);
   
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}