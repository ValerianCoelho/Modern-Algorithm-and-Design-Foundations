#include <iostream>
using namespace std;

#define MAX 20
#define INFINITY 999

int n;

int W[MAX][MAX]; // Weight matrix
int C[MAX][MAX]; // Cost matrix
int R[MAX][MAX]; // Root matrix

int P[MAX]; // Probabilities of successful search
int Q[MAX]; // Probabilities of unsuccessful search

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
    int min, min_index;

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
                    min_index = k;
                }
            }
            // Calculate the cost of the sub-tree rooted at node j
            C[j][j+i] = min + W[j][j+i];
            // Record the root of the sub-tree rooted at node j
            R[j][j+i] = min_index;
        }
    }

    // Print the weight, cost, and root matrices
    cout << "Weight Matrix :-" << endl;
    Print_Matrix(W);
    cout << "Cost Matrix :-" << endl;
    Print_Matrix(C);
    cout << "Root Matrix :-" << endl;
    Print_Matrix(R);
}

int main()
{
    // Get input from user
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
    
    // Call the function to calculate optimal binary search tree
    Optimal_Binary_Search();
    return 0;
}
