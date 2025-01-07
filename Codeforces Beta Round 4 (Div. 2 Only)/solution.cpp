#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int range;
    cin >> range;
    vector<string> words;

    for(int i = 0; i < range; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    for(int i = 0; i < range; i++){
        string word = words[i];
        if(word.size() > 10){
            cout << word[0] << word.size() - 2 << word[word.size() - 1] << endl;
        }
        else{
            cout << word << endl;
        }
    }
    return 0;
}