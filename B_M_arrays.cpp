#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

// TESTCASE
// 1 1 1 5 2 4 4 8 6 7 -> 1 1 1 5 2 4 4 0 6 7 -> 0 1 1 1 2 4 4 5 6 7 -> 0s-1 1s-3 2s-1 3s-0 4s-2 5s-1 6s-1 7s-1
// ans = 1 + (1 + 2) + 1 + 1 + 2
// If this approach works, then i am slowly getting into form


class Solution {
    public:
    void solve() {
        int n, m;
        cin >> n >> m;
        map<int, int> freq;
        int count = 0;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            int mod = num % m;
            freq[mod]++;
        }

        count += freq[0] > 0;

        if(m % 2 == 0)
            count += freq[m/2] > 0;

        for(int i = 1; i < (m + 1)/2; i++) {
            int required = m - i;
            int freqA = freq[i];
            int freqB = freq[required];

            if(freqA == freqB && freqA) {
                count += 1;
                continue;
            }
            int minFreq = min(freqA, freqB); 
            int maxFreq = max(freqA, freqB);
            count += 1;
            maxFreq -= (minFreq + 1);
            minFreq = 0;
            count += maxFreq;
        }
        cout<<count<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

