#include <iostream>
#include <string>
using namespace std;

#define Infinity 999
#define MAX 20

int no_of_vertices;

// Function to find the minimum distance value from the set of vertices that have not yet been visited
int minDistance(int distance[], bool visited[]){
    int min = Infinity;
    int min_index;

    for(int i=0; i < no_of_vertices; i++){
        // If a vertex has been visited (True), then its final shortest path has already been calculated, hence we ignore it
        if(visited[i] == false && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void Dijkstra(int source, int cost[MAX][MAX]){
    int distance[MAX]; // Will hold the shortest distance between source and destination vertex
    bool visited[MAX]; // Will hold boolean values indicating whether the vertex has been visited or not
    string path[MAX]; // Will hold the shortest path between source and destination vertex

    // Initializing all distance, visited and path array elements to Infinity, false and Source-Vertex respectively
    for(int i=0; i < no_of_vertices; i++){
        distance[i] = Infinity;
        visited[i] = false;
        path[i] = to_string(source + 1);
    }

    // Source is the initial vertex, so its minimum distance is '0'
    distance[source] = 0;

    // Find the shortest path for all the vertices
    for(int i=0; i<no_of_vertices; i++){
        int u = minDistance(distance, visited); // Where u is the closest vertex to source that has not yet been visited, u is equal to source in the first iteration
        visited[u] = true;

        // Update the distance and path value of the vertices adjacent to 'u'
        for(int j=0; j < no_of_vertices; j++){ 
            // Update the distance and path value only if 
            if(!visited[j] // the vertex has not been visited,
               && cost[u][j] // there is an edge from u to j,
               && distance[u] + cost[u][j] < distance[j]) // total weight of path from 'source' to 'j' through 'u' < distance[j]
            {
                distance[j] = distance[u] + cost[u][j];
                path[j] = path[u] + " -> " + to_string(j + 1);
            }
        }
    }

    // Printing the results
    cout << "Src" << "\t" << "Destn" << "\t" << "MinCost" << "\t" << "Path" << "\t" << endl;
    for(int i=0; i<no_of_vertices; i++){
        cout << source+1 << "\t";
        cout << i+1 << "\t";
        if(distance[i] == Infinity)     cout << '-' << "\t" << '-' << endl;
        else    cout << distance[i] << "\t" << path[i] << endl;
    }
}
int main(){
    cout << "Enter the Number of Vertices : ";
    cin >> no_of_vertices;
    int cost[MAX][MAX];
    cout << "Enter the Cost Matrix :- " << endl;
    for(int i = 0; i < no_of_vertices; i++){
        for(int j = 0; j < no_of_vertices; j++){
            cin >> cost[i][j];
        }
    }
    cout << endl;
    Dijkstra(0, cost);
    return 0;
}

// INPUT:
// 0 50 45 10 0 0
// 0 0 10 15 0 0
// 0 0 0 0 30 0
// 20 0 0 0 15 0
// 0 20 35 0 0 0
// 0 0 0 0 3 0

// OUTPUT:
// Src     Destn   MinCost Path    
// 1       1       0       1
// 1       2       45      1 -> 4 -> 5 -> 2
// 1       3       45      1 -> 3
// 1       4       10      1 -> 4
// 1       5       25      1 -> 4 -> 5
// 1       6       -       -