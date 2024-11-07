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
#define exists(map, num) map.find(num) != map.end() 

// If bit is 0, then not optimal to get discount for it !
// Total cost is summation N.. Now goal is to find maxDiscount
// I can pair up max One pos with min one position but any potential issues?
// When no pairs but only one pos is left, then try to mind a left value that is = 0, if found, extra discount

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        string st;
        cin >> st;

        queue<int> ones;
        int cost = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(st[i] == '1')
                ones.push(i+1);
            else {
                if(!ones.empty())
                    ones.pop();
                cost += i+1;
            }
        }

        if(!ones.empty()) {
            int toDelete = ones.size() / 2;
            while(toDelete--)
                ones.pop();
            while(!ones.empty()) {
                cost += ones.front();
                ones.pop();
            }
        }

        cout<<cost<<endl;
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

