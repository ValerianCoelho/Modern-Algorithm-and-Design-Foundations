#include <iostream>
using namespace std;

#define MAX 50
#define INFINITY 999
#define Right 1
#define Left -1

int n;

int W[MAX][MAX]; // Weight matrix
int C[MAX][MAX]; // Cost matrix
int R[MAX][MAX]; // Root matrix

int P[MAX]; // Probabilities of successful search
int Q[MAX]; // Probabilities of unsuccessful search

void displayTree(int left, int right, int child, string indent){
    int root = R[left][right];
    cout << indent;

    // Check the child direction and display the appropriate tree structure
    if(child == Right){
        cout << "├── ";
        indent = indent + "│   ";
    }
    else if(child == Left){
        cout << "└── ";
        indent = indent + "    ";
    }
    if(left == right){ // Check if it is a leaf node and display "NULL"
        cout << "NULL" << endl;
        return;
    }
    else{ // Display the root value of the subtree
        cout << root << endl;;
    }
    if(right - left == 1){ // Check if there are only two nodes in the subtree (these two nodes will be NULL nodes)
        return;
    }
    displayTree(root, right, Right, indent); // Recursively display the right subtree rooted at 'root'
    displayTree(left, root-1, Left, indent); // Recursively display the left subtree rooted at 'root-1'
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
            W[j][j+i] = P[j+i-1] + Q[j+i] + W[j][j+i-1]; // Calculate the weight of the sub-tree rooted at node j
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
            C[j][j+i] = min + W[j][j+i]; // Calculate the cost of the sub-tree rooted at node j
            R[j][j+i] = min_preorderIndex; // Record the root of the sub-tree rooted at node j
        }
    }
    cout << "Weight Matrix :-" << endl;  Print_Matrix(W);
    cout << "Cost Matrix :-" << endl;    Print_Matrix(C);
    cout << "Root Matrix :-" << endl;    Print_Matrix(R);
    cout << "OBST :-" << endl;           displayTree(0, n, 0,"");
}

int main(){
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