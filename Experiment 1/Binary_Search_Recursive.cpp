#include<iostream>
using namespace std;
int pos;

template <class T>
void insertion_sort(T array[], int len) {
    int i, j, k;
    for(i=1; i<len; i++) {
        k = array[i];
        j = i-1;
        while(j>=0 && k<array[j]) {
            array[j+1] = array[j];
            j=j-1;
        }
        array[j+1] = k;
    }
}

template <class T>
int binarySearch(T array[], int low, int high, T key) {
    int mid;
    mid = (low+high)/2;
    if(low > high)
         return -1;
    else if(key == array[mid]) {
        pos = mid;
        binarySearch(array, low, mid-1, key);
    }
    else if(key < array[mid])
        binarySearch(array, low, mid-1, key);
    else
        binarySearch(array, mid+1, high, key);

    if(array[pos]!=key)
        return -1;
    else
        return pos;
}

template <class T>
void print_array(T array[], int len) {
    for(int i=0; i<len; i++)
        cout << array[i] << " ";
}

int main() {
    char array[10], key;
    int len, pos;
    cout << "Enter the length of the array : ";
    cin >> len;

    cout << "Enter the array : ";
    for(int i=0; i<len; i++)
        cin >> array[i];

    insertion_sort<char>(array, len);
    cout << "Sorted array is : ";
    print_array<char>(array, len);

    cout << "\nEnter the element to be searched : ";
    cin >> key;

    pos = binarySearch<char>(array, 0, len-1, key);

    if(pos == -1) {
        cout << "Element not present in the Array" << endl;
    }
    else {
        while(array[pos] == key) {
            cout << "Element " << key << " found at position :  " << pos+1 << endl;
            pos++;
        }
    }
}