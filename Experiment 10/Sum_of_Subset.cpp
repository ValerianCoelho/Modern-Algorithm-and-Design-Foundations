#include <iostream>
#include <string>
using namespace std;

#define MAX 20  // Define a constant maximum size for arrays

int n, m;
int set[MAX]; // Declare an array to store the input set

// Function to generate all the solution vectors recursively
void sumOfSubset(int sum, int item, int remainingCapacity, string vector){
    if(sum == m && remainingCapacity == 0){ // If the required sum is achieved and all elements have been used, print the solution vector
        cout << vector << endl;
    }
    if(sum > m || remainingCapacity == 0){ // If the sum exceeds the required sum or no more elements are available, return
        return;
    }

    // Recursively call the function to include and exclude the next element in the solution vector
    sumOfSubset(sum + set[item], item + 1, remainingCapacity - set[item], vector + "1 "); // Include the current element
    sumOfSubset(sum, item + 1, remainingCapacity - set[item], vector + "0 "); // Exclude the current element
}

int main()
{
    int totalSum = 0; // Declare a variable to store the sum of all elements in the set
    string vector = ""; // Declare a string to store the current solution vector

    cout << "Enter the Number of Elements in the Set : ";
    cin >> n;
    
    cout << "Enter the Elements in the set : ";
    for(int i=0; i < n; i++){ // Input the set from the user and calculate the total sum
        cin >> set[i];
        totalSum += set[i];
    }

    cout << "Enter the Integer : ";
    cin >> m; // Input the target sum

    cout << "The Solution Vectors are :- " << endl;
    sumOfSubset(0, 0, totalSum, vector); // sumOfSubset(sum, item_index, total_sum, soln_vector)
    return 0;
}