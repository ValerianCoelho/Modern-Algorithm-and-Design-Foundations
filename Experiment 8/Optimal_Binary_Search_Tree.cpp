#include <iostream>
using namespace std;

#define MAX 20
#define INFINITY 999

int n;
int IPIndex = 0; // Inverse Preorder Index

int W[MAX][MAX]; // Weight matrix
int C[MAX][MAX]; // Cost matrix
int R[MAX][MAX]; // Root matrix

int P[MAX]; // Probabilities of successful search
int Q[MAX]; // Probabilities of unsuccessful search
int IP[MAX]; // Inverse Preorder of the final OBST

void printTree(int child, int depth){
    // child:
    // 0 - root
    // 1 - Left child
    // -1 - right child
    int currentNode = IP[IPIndex];
    int rightChild = IP[IPIndex + 1];
    int leftChild = IP[IPIndex + 2];

    // Loop to print the appropriate number of indentation spaces
    for(int i=0; i<depth; i++){
        cout << "│   ";
    }

    // Check the value of child and print the appropriate branch symbol
    if(child == -1){
        cout << "├── ";
    }
    else if(child == 1){
        cout << "└── ";
    }

    // Check if the current element in the inverse preorder array is -1, print "NULL" if it is
    // Otherwise, print the current element
    if(currentNode == -1){
        cout << "NULL" << endl;
        return;
    }
    else{
        cout << currentNode << endl;
    }

    // if both children are -1, indicates we have reached the end of a subtree 
    if(rightChild == -1 && leftChild == -1){
        IPIndex = IPIndex + 2;
        return;
    }

    // Recursively call printTree for the left and right subtrees
    ++IPIndex; printTree(-1, depth+1);
    ++IPIndex; printTree(1, depth+1);
}

// This is necessary for printing the tree
void getInversePreorder(int left, int right){ // preorder is root, left, right: inversePreorder is root, right, left
    if(left == right){
        IP[IPIndex++] = -1;
        return;
    }
    int root = R[left][right];
    IP[IPIndex++] = root;
    getInversePreorder(root, right);
    getInversePreorder(left, root-1);
}

// Function to print a matrix
void Print_Matrix(int M[MAX][MAX]){
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal_Binary_Search(){
    int min, min_preorderIndex;

    // Initialization
    for(int i=0; i<=n; i++){
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }

    // I-Weighted Matrix
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            // Calculate the weight of the sub-tree rooted at node j
            W[j][j+i] = P[j+i-1] + Q[j+i] + W[j][j+i-1];
        }
    }

    // II-Cost Matrix and Root Matrix
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            min = INFINITY;
            for(int k=j+1; k<=j+i; k++){
                // Find the minimum cost of all possible sub-trees rooted at node j
                if(C[j][k-1] + C[k][j+i] < min){
                    min = C[j][k-1] + C[k][j+i];
                    min_preorderIndex = k;
                }
            }
            // Calculate the cost of the sub-tree rooted at node j
            C[j][j+i] = min + W[j][j+i];
            // Record the root of the sub-tree rooted at node j
            R[j][j+i] = min_preorderIndex;
        }
    }

    // Print the weight, cost, and root matrices
    cout << "Weight Matrix :-" << endl;
    Print_Matrix(W);
    cout << "Cost Matrix :-" << endl;
    Print_Matrix(C);
    cout << "Root Matrix :-" << endl;
    Print_Matrix(R);

    cout << "OBST :-" << endl;
    getInversePreorder(0, n); // Will compute the inverse preorder and store the result in IP Array
    IPIndex = 0; // setting IPIndex to zero because, its current value is the size of IP
    printTree(0, -1); // Will display the tree
}

int main()
{
    cout << "Enter the total number of nodes in the Binary Tree : ";
    cin >> n;

    cout << "Enter the Probabilities of Successful Search : ";
    for(int i=0; i<n; i++){
        cin >> P[i];
    }

    cout << "Enter the Probabilities of Unsuccessful Search : ";
    for(int i=0; i<=n; i++){
        cin >> Q[i];
    }
    
    Optimal_Binary_Search();
    return 0;
}

// Output:
// Enter the total number of nodes in the Binary Tree : 4
// Enter the Probabilities of Successful Search : 2 3 1 2
// Enter the Probabilities of Unsuccessful Search : 2 2 1 1 2
// Weight Matrix :-
// 2 6 10 12 16    
// 2 6 8 12        
// 1 3 7 
// 1 5 
// 2 
// Cost Matrix :-  
// 0 6 16 21 32
// 0 6 11 22
// 0 3 10
// 0 5
// 0
// Root Matrix :-
// 0 1 1 2 2
// 0 2 2 2
// 0 3 4
// 0 4
// 0
// OBST :-
// 2
// ├── 4
// │   ├── NULL
// │   └── 3
// └── 1