#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

class Solution {
    public:
    void solve() {
        int n, x;
        cin >> n >>  x;
        map<int, int> freq;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            freq[num]++;
        }
        for(int i = 0; i <= n * 2 + 1; i++) {
            if(freq[i] > 1) {
                int nxtNumber = i + x;
                freq[nxtNumber] += freq[i] - 1;
                freq[i] = 1;
            }
            if(freq[i] == 0)
                pn(i);
        }
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

