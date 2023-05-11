#include <iostream>

using namespace std;

#define MAX 20  // Define a constant maximum size for arrays

// Declare global variables
int m, n, j;
int vector[MAX]; // Declare an array to store colors for each vertex
int graph[MAX][MAX]; // Declare an adjacency matrix to represent the graph

// Function to assign a color to a vertex
void assignColor(int vertex){
    while(true){
        vector[vertex] =(vector[vertex] + 1)%(m + 1); // Increment the color for the vertex
        if(vector[vertex] == 0){ // If the color is 0 (i.e., all colors have been tried), return
            return;
        }
        for(j = 0; j < n; j++){ // Check if any adjacent vertex has the same color
            if(graph[vertex][j] == 1 && vector[vertex] == vector[j]){
                break;
            }
        }
        if(j == n){ // If no adjacent vertex has the same color, return
            return;
        }
    }
}

// Recursive function to color all vertices in the graph
void mColor(int vertex){
    while(true){
        assignColor(vertex); // Assign a color to the current vertex
        if(vector[vertex] == 0){ // If no color could be assigned to the current vertex, return
            return;
        }
        if(vertex == n){ // If all vertices have been colored, print the colors and return
            for(int i = 0; i < n; i++){
                cout << vector[i] << " ";
            }
            cout << endl;
            return;
        } 
        else{ // Otherwise, recursively color the next vertex
            mColor(vertex + 1);
        }
    }
}

int main(){
    cout << "Enter the number of vertices in the graph : ";
    cin >> n;

    for(int i=0; i < n; i++) { vector[i] = {0}; }

    cout << "Enter the number of colors to be used : ";
    cin >> m;

    cout << "Enter the adjacency matrix :- " << endl;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    cout << "The Solution Vectors are :-" << endl;

    mColor(0); // Start coloring the graph from vertex 0
    return 0;
}

/*
Input: 
n = 4

Adjacency Matrix :-
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
