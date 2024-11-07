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
        int n;
        cin >> n;
        vector<int> a(n);
        input(a);

        map<int, int> freq;
        freq[0] = 0;
        int sum = 0, beautiful = 0;
        int last = 0;

        for(int i = 0; i < n; i++) {
            sum += a[i];

            if(freq.count(sum)) {
                last = i + 1;
                beautiful++;
                freq.clear();
                freq[0] = last;
                sum = 0;
            } else {
                freq[sum] = i + 1;
            }
        }
        cout<<beautiful<<endl;
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

