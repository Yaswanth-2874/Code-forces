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

class Solution {
    bool check(vector<int>& v, int k) {
        int count = 0;
        // cout<<k<<endl;
        for(int i = 0; i < v.size() - 1; i++) {
            if(v[i + 1] - v[i] > k) {
                count++;
                if(count == 2) {
                    return false;
                }
            } else {
                i++;
            }
        }
        return true;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        input(v);
        priority_queue<int> gaps;
       
        if(n % 2 == 0) {
            for(int i = 0; i < n; i+=2) {
                gaps.push(v[i+1] - v[i]);
            }
            int maxGap = gaps.top();
            pn(maxGap);
        } 

        int l = 1, r = LLONG_MAX;

        // check(v, 2);
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(check(v, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        pn(r+1);
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

