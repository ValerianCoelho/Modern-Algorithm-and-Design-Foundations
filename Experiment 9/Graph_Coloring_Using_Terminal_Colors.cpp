#include <iostream>
#include <string>

using namespace std;

#define MAX 20  // Define a constant maximum size for arrays

// Initialize global variables
string color;
int m = 2, n = 4, j;
int vector[MAX] = {0, 0, 0, 0}; // Initialize an array to store colors for each vertex
int graph[MAX][MAX] = {{0, 1, 0, 1}, // Initialize an adjacency matrix to represent the graph
                       {1, 0, 1, 0},
                       {0, 1, 0, 1},
                       {1, 0, 1, 0}};

void displayVector(){
    for(int i = 0; i < n; i++){
        color = "\033[9" + to_string(vector[i]) + "m";
        cout << color << vector[i] << " ";
    }
    cout << "\033[0m";
    cout << endl;
}

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
            displayVector();
            return;
        } 
        else{ // Otherwise, recursively color the next vertex
            mColor(vertex + 1);
        }
    }
}

int main(){
    cout << "The Solution Vectors are :- " << endl;
    mColor(0); // Start coloring the graph from vertex 0
    return 0;
}
