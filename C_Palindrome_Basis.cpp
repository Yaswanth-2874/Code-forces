#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve(vector<int>& count) {
        int n;
        cin >> n;

        cout<<count[n]<<endl;
    }
};

bool isPalindrome(int n) {
    int copyN = n;
    int revN = 0;

    while(copyN) {
        revN = (revN * 10) + (copyN % 10);
        copyN /= 10;
    }
    return n == revN;
}

int32_t main() {
    vector<int> palindromes;
    const int mod = 1e9 + 7;

    for(int i = 1; i <= 4e4; i++) {
        if(isPalindrome(i))
            palindromes.push_back(i);
    }
    vector<int> count(4e4 + 1, 0);
    count[0] = 1;
    
    for(int palindrome : palindromes) {
        for(int i = 1; i <= 4e4; i++) {
            if(palindrome > i)
                continue;
            count[i] += count[i - palindrome];
            count[i] %= mod;
        }
    }  
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve(count);
    }

    return 0; 
}
