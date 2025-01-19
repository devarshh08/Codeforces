#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, bool> memo;

bool isValid(long long k) {
    if (k == 1) return true;
    if (memo.count(k)) return memo[k]; 

    string s = to_string(k);
    for (char c : s) {
        int digit = c - '0';
        if (digit > 1 && k % digit == 0) { 
            if (isValid(k / digit)) { 
                return memo[k] = true;
            }
        }
    }
    return memo[k] = false; 
}

int main() {
    long long num;
    cin >> num;

    long long count = 0;
    for (long long i = 1; i <= min(num, 100000LL); i++) {
        if (isValid(i)) count++;
    }
    if (num > 100000) {
        count += (num - 100000); 
    }

    cout << count << endl;
    return 0;
}
