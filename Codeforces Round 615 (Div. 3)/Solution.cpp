#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; //t is the number of test cases
    cin >> t;
    int n;
    long N;
    int counter = 0;
    vector<long long>inp_arr;

    for(int i = 0; i<t; i++){
        cin >> n;
        inp_arr.push_back(n);
    }

    for(int i = 0; i< t; i++){
        n = inp_arr[i]; //Enter the number to check product
        N = n; //copying the number
        counter = 0;
        vector<long long>arr;

        for(int i = 2; i*i <= N; i++){ //we loop from 2 till sqrt of number
            if(n%i == 0){ //If it is divisible by i without any remainder, we add it to our array and increment counter by 1
                counter += 1;
                n /= i; //we divide the number by i
                arr.push_back(i); //we have inputed one number to array
            }
            if(counter == 2){
                arr.push_back(n); //if 2 numbers are already found,then the left out number is obviously the third one
                break;
            }
        }
        if(counter<2){ //if less than 3 factors are found
            cout << "NO" << "\n";
        } 
        else if(arr[0] == arr[2] || arr[1] == arr[2]){ //last factor is same as first or second factor
            cout<< "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
        }
    }
    return 0; 
}