#include <iostream>

using namespace std;

int n = 9;
int arr[] = {2, 4, -1, 3, -1, -1, 1, -1, -1};
int Index = 0;

void printTree(int child, int depth){
    // child:
    // 0 - not a left or a right child
    // 1 - Left child
    // -1 - right child
    for(int i=0; i<depth; i++){
        cout << "│   ";
    }

    if(child == -1){
        cout << "├── ";
    }
    else if(child == 1){
        cout << "└── ";
    }

    if(arr[Index] == -1){
        cout << "NULL" << endl;
        return;
    }
    else{
        cout << arr[Index] << endl;
    }

    if(arr[Index+1] == -1 && arr[Index+2] == -1){
        Index = Index + 2;
        return;
    }

    ++Index; printTree(-1, depth+1);
    ++Index; printTree(1, depth+1);
}


int main()
{
    printTree(0, -1); // child, depth

    return 0;
}

// Input : 
// 2 1 -1 -1 4 3 -1 -1 -1 

// Output: 
// 2
// ├── 4
// │   ├── NULL
// │   └── 3
// └── 1