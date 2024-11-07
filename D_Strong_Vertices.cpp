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

// Edge between u and v exists if au - av >= bu - bv
// au - bu >= bu - bv
// Simply find the max element (au - bu) and occurances of it

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        input(a);
        input(b);

        for(int i = 0; i < n; i++)
            c[i] = a[i] - b[i];

        int maxC = *max_element(all(c));

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(c[i] == maxC)
                ans.push_back(i+1);
        }
        cout<<ans.size()<<endl;
        print(ans)
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

