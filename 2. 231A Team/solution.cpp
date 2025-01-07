#include<iostream>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int main(){
    int range;
    cin >> range;
    int counter = 0;

    for(int i=0; i<=range; i++){
        int internal_counter = 0;
        int num;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while(ss >> num){
            if(num == 1){
                internal_counter++;
            }
        }
        if(internal_counter == 2 || internal_counter>2){
            counter++;
        }
    }
    cout << counter;
}