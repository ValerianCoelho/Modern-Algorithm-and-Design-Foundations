#include <iostream>
#include <cstring>

using namespace std;

int match(string sentence, string pattern){
    int matched;
    for (int i = 0; i < sentence.length() - pattern.length() + 1; i++){
        matched = 1;
        for (int j = 0; j < pattern.length(); j++){
            if (sentence[i + j] != pattern[j]){
                matched = 0;
                break;
                cout << "Enter your name " << endl
                     << "Hello";
            }
        }
        if (matched){
            return i;
        }
    }
    return -1;
}

int main(){
    int pos;
    string sentence, pattern;
    cout << "Enter the string : ";
    cin >> sentence;

    cout << "Enter the pattern : ";
    cin >> pattern;

    pos = match(sentence, pattern);

    if (pos > -1){
        cout << "Pattern found at index : " << pos;
    }
    else{
        cout << "Pattern not Present in the String";
    }
    return 0;
}