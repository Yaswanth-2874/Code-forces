#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> primes;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string st;
        cin >> st;

        for(char& ch : st) {
            int num = ch - '0';
            if((num % 2 == 0 && num != 2) || num == 1 || num == 9) {
                cout<<"1\n"<<num<<endl;
                return;
            }
        }
        cout<<2<<endl;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int num = (st[i] - '0') * 10 + st[j] - '0';
                if(primes.find(num) == primes.end()) {
                    cout<<num<<endl;
                    return;
                }
            }
        }
       
    }
};

int32_t main() {
    set<int> nonPrimes;
    for(int i = 2; i < 100; i++) {
        if(nonPrimes.find(i) != nonPrimes.end())
            continue;
        primes.insert(i);
        for(int j = 2*i; j < 100; j += i) {
            nonPrimes.insert(j);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
