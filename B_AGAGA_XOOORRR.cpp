#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        int totalXor = 0;

        for (auto& input : v) {
            cin >> input;
            totalXor ^= input;
        }

        // if xor value is zero, then it means that there is def a point where xor(left) = xor(right)
        if(!totalXor)
            /* Print yes*/ {
                cout<<"YES\n";
                return;
            }
        
        // i should try to split the array into 3 pieces, if all its xors are equal then print yes
        // just brute force, n^2 is accepted
        int xor1 = 0;

        for(int i = 0; i < n; i++) {
            xor1 ^= v[i];
            int xor2 = 0;
            for(int j = i+1; j < n-1; j++) {
                xor2 ^= v[j];
                int xor3 = totalXor ^ xor1 ^ xor2;
                if(xor1 == xor2 && xor2 == xor3)
                    /* Print yes*/ {
                        cout<<"YES\n";
                        return;
                    }
            }
        }
        /* Print no*/ {
            cout<<"NO\n";
            return;
        } 
    }
};

int32_t main() {

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
