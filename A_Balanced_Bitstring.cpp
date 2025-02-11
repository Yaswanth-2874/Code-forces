#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        string st;
        cin >> st;

        int ones = 0, zeroes = 0, questions = 0;

        for(int i = 0; i < k; i++) {
            ones += st[i] == '1';
            zeroes += st[i] == '0';
            questions += st[i] == '?';
        }
        int required = k/2;
        int requiredOnes = required - ones;
        int requiredZeroes = required - zeroes;
        if(requiredZeroes < 0 || requiredOnes < 0 || requiredOnes + requiredZeroes < questions)
            /* Print no*/ {
                cout<<"NO\n";
                return;
            }
        zeroes = ones = required;
        int left = 0;

        for(int right = k; right < n; right++) {
            st[right] == '1' ? ones++ : st[right] == '0' ? zeroes++ : questions++;
            st[left] == '1' ? ones-- : st[left] == '0' ? zeroes-- : questions--;
            int requiredOnes = required - ones;
            int requiredZeroes = required - zeroes;


            if(requiredZeroes < 0 || requiredOnes < 0 || requiredOnes + requiredZeroes < questions)
                /* Print no*/ {
                    cout<<"NO\n";
                    return;
            }

           left++;
        }
        /* Print yes*/ {
            cout<<"YES\n";
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
