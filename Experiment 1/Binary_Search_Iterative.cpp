#include<iostream>
using namespace std;
int pos;
void insertion_sort(int array[], int len) {
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
void print_array(int array[], int len) {
    for(int i=0; i<len; i++)
        cout << array[i] << " ";
}

int binarySearch(int array[], int len, int key) { // 1 2 2 2 3
    int low=0, high=len-1, mid = (low+high)/2;
    while(low<=high)
    {
        if(key>array[mid])
            low = mid+1;
        else if(key<array[mid])
            high = mid-1;
        else {
            pos = mid;
            high = mid-1;
        }
        mid = (low+high)/2;
    }
    if(array[pos] != key)
        return -1;
    else
        return pos;
}
int main() {
    int len;
    int array[10], key, pos;
    cout << "Enter the length of the array : ";
    cin >> len;

    cout << "Enter the array : ";
    for(int i=0; i<len; i++)
        cin >> array[i];

    insertion_sort(array, len);
    cout << "Sorted array is : ";
    print_array(array, len);

    cout << "\nEnter the element to be searched : ";
    cin >> key;

    pos = binarySearch(array, len, key);

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