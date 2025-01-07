#include<iostream>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int main(){
    int n, k, counter, num;
    string inptline;
    cin >> n >> k;
    cin.ignore();
    
    getline(cin, inptline);
    vector<int> inptarr;
    istringstream stream(inptline);

    while(stream>>num){
        inptarr.push_back(num);
    }

    for(int i=0;i<n;i++){
        if(inptarr[i]>=inptarr[k-1] && inptarr[i]>0){
            counter++;
        }
    }

    cout<<counter;
}