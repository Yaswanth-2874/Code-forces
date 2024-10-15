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
#define minHeap(var) var, vector<var>, greater<var>


class Solution {
    public:
    void solve() {
        string s, t;
        cin >> s >> t;
        if(t.size() < s.size())
            swap(t, s);
        int operations = 0;
        int common = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i])
                break;
            common++;
        }
        operations = s.size() + t.size();
        operations -= common;
        operations += common > 0;
        cout<<operations<<endl;
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

