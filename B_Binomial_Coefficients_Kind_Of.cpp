#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>


vector<int> powers;

class Solution {
    public:
    void solve() {
        int size;
        cin >> size;
        vector<int> nums(size), t(size);
        input(nums);
        // print(nums)
        input(t);
        // print(t)

        for(int i = 0; i < size; i++) {
            cout<<powers[t[i]]<<endl;
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    
    int product = 1;
    for(int i = 0; i <= 1e5 + 1; i++) {
        powers.push_back(product);
        product = product * 2;
        product %= mod;
    }    
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

