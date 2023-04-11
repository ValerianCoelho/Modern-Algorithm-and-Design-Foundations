#include <iostream>
using namespace std;

#define MAX 20

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int no_of_items, int capacity_of_knapsack, int weights[], int profits[]){
    int T[MAX][MAX]; // rows = no_of_items + 1, cols = capacity_of_knapsack + 1
    int weight; // Current items weight 
    int profit; // Current items profit/value

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

    for(int i = 0; i < no_of_items + 1; i++){
        for(int j = 0; j < capacity_of_knapsack + 1; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

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
    }

    knapsack(no_of_items, capacity_of_knapsack, weights, profits);
    return 0;
}