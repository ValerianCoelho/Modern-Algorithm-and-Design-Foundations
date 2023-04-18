#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void longest_common_subsequence(string str1, string str2) {
    // Initializing variables to store the length of the strings
    int len1 = str1.length();
    int len2 = str2.length();

    // Initialize a 2D array to store the length of longest common subsequence
    int C[len2 + 1][len1 + 1];

    // Initialize an empty string to store the longest common subsequence
    string subsequence = "";

    // Initialize a variable to keep track of the index of the last character of the longest common subsequence
    int index = -1;

    // Fill the 2D array using dynamic programming to find the length of longest common subsequence
    for(int i = 0; i < len2 + 1; i++) {
        for(int j = 0; j < len1 + 1; j++) {
            if(i == 0 || j == 0) {
                C[i][j] = 0;
            }
            else if(str2[i-1] == str1[j-1]) {
                C[i][j] = 1 + C[i-1][j-1];
                if(j < index) {
                    // If the index of the last character of the common subsequence is greater than the current index, 
                    // clear the subsequence string to start a new subsequence
                    subsequence = "";
                }
                // Update the index and add the last character to the subsequence string
                index = j;
                subsequence += str1[j-1];
            }
            else if(str2[i-1] != str1[j-1]) {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
        }
    }
    for(int i = 0; i < len2 + 1; i++) {
        for(int j = 0; j < len1 + 1; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Length of the longest common subsequence is : " << C[len2][len1] << endl;
    cout << "The longest common subsequence is : " << subsequence << endl;
}

int main() {
    string str1, str2;
    cout << "Enter the first string : ";
    getline(cin, str1);
    cout << "Enter the second string : ";
    getline(cin, str2);

    longest_common_subsequence(str1, str2);
    return 0;
}
