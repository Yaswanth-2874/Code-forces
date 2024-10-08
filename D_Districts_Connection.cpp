#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n";}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

// OPTIMISED IT IN O(N) TIME 
class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> bandits(n);
        input(bandits);
        
        int start = bandits[0];
        int unequalIndex = -1;
        for(int i = 0; i < n; i++) {
            if(start != bandits[i])
                unequalIndex = i + 1;
        }
        if(unequalIndex == -1)
            no;
        yes;

        for(int i = 0; i < n; i++) {
            if(start != bandits[i]) {
                cout << 1 <<" "<< (i + 1) << endl;
                unequalIndex = i+1;
            }
        }
        for(int i = 1; i < n; i++) {
            if(start == bandits[i]) {
                cout<< unequalIndex << " " << (i + 1)<<endl;
            }
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

