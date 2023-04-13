#include <iostream>
using namespace std;

#define MAX 20

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int no_of_items, int capacity_of_knapsack, int weights[], int profits[]){
    int T[MAX][MAX]; // rows = no_of_items + 1, cols = capacity_of_knapsack + 1
    int weight; // Current items weight 
    int profit; // Current items profit/value
    int max_profit;

    for(int i = 0; i < no_of_items + 1; i++){
        weight = weights[i-1];
        profit = profits[i-1];
        for(int j = 0; j < capacity_of_knapsack + 1; j++){
            // i - represents the item number
            // j - represents the the current temporary capacity of the knapsack
            if(i == 0){
                T[i][j] = 0;
            }
            else if(j == 0){
                T[i][j] = 0;
            }
            else if(weight > j){
                T[i][j] = T[i-1][j];
            }
            else if(weight <= j){
                T[i][j] = max(T[i-1][j], profit + T[i-1][j-weight]);
            }
        }
    }
    max_profit = T[no_of_items][capacity_of_knapsack];

    // Displaying the Matrix
    for(int i = 0; i < no_of_items + 1; i++){
        for(int j = 0; j < capacity_of_knapsack + 1; j++){
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }cout << endl;

    int s = 0;
    int selection_set[MAX];

    // Calculating the items to be selected
    for(int i=no_of_items; i>0; i--){
        if(T[i][capacity_of_knapsack] != T[i-1][capacity_of_knapsack]){
            selection_set[s++] = i;
            capacity_of_knapsack -= weights[i-1];
        }
    }

    cout << "Selection Set : ";
    for(int i=0; i<s; i++){
        cout << "Item " << selection_set[i] << ", ";
    }
    cout << "\nMaximum Profit : " << max_profit;
    cout << "\nCapacity after the items are inserted : " << capacity_of_knapsack;
    return 0;
}

int main()
{
    int capacity_of_knapsack;
    int no_of_items;

    int weights[MAX];
    int profits[MAX];

    cout << "Enter the Number of items : ";
    cin >> no_of_items;

    cout << "Enter the Maximum Capacity of the Knapsack : ";
    cin >> capacity_of_knapsack;

    cout << "Enter the Weights : ";
    for(int i=0; i<no_of_items; i++){
        cin >> weights[i];
    }

    cout << "Enter the Profits : ";
    for(int i=0; i<no_of_items; i++){
        cin >> profits[i];
    }cout << endl;

    knapsack(no_of_items, capacity_of_knapsack, weights, profits);
    return 0;
}