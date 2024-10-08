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
        priority_queue<int, vector<int>, greater<int>> pq;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            pq.push(num);
        }
        while(pq.size() > 1) {
            int  top = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(top + (top2 - top)/2);
        }
        cout<<pq.top()<<endl;

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

