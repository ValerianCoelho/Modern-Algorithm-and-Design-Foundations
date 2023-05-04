#include <iostream>
using namespace std;

#define MAX 20

int W[MAX][MAX];
int C[MAX][MAX];
int R[MAX][MAX];

int n = 4;
int P[MAX] = {2, 3, 1, 2};
int Q[MAX] = {2, 2, 1, 1, 2};
string A[MAX] = {"class", "private", "return", "while"};

void Print_Matrix(){
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            cout << W[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal_Binary_Search(){
    // Initialization
    for(int i=0; i<=n; i++){
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }

    // I-Weighted Matrix
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            cout << "W[" << j << "][" << j+i << "] = " << "P[" << j+i << "] + Q[" << j+i << "] + W[" << j << "][" << j+i-1 << "] = " << P[j+i-1] << "+" << Q[j+1] << "+" << W[j][j+i-1] << " = " << P[j+i-1] + Q[j+i] + W[j][j+i-1]<< endl; 
            W[j][j+i] = P[j+i-1] + Q[j+i] + W[j][j+i-1];
        }
    }

    Print_Matrix();
}

int main()
{
    Optimal_Binary_Search();
    return 0;
}