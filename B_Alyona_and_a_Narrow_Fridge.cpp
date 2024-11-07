#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
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
#pragma endregion

class Solution {
    int n, h;
    // This tc is bounded by O(NlogN) in the worst case
    bool canFit(vector<int>& v, int k) {
        priority_queue<int> pq;

        for(int i = 0; i <= k; i++) {
            pq.push(v[i]);
        }
        int hCopy = h;

        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            hCopy -= top;

            if(hCopy < 0)
                return false;
            if(hCopy == 0)
                return pq.size() <= 1LL;
            if(!pq.empty())
                pq.pop();
        }
        return true;
    }

    public:
    void solve() {
        cin >> n >> h;
        vector<int> v(n);
        input(v);

        int left = 0, right = n-1;

        //log n
        while(left <= right) {
            int mid = left + (right - left)/2;

            if(canFit(v, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }

        //Entire TC is bounded by log^2 N * N, should get accepted
        pn(right + 1);
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
