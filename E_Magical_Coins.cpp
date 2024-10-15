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
        string num;
        cin >> num;
        int n = num.size();
        if(num.size() == 1)
            no;
        if(num[n-1] != num[n-2])
            no;
        int current = num[n-2];

        for(int i = n-3; i >= 0; i--) {
            if(num[i] - '0' > current)
            no;
            current = min((int)(num[i] - '0'), current);
        }
        yes;
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

