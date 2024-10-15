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

// INTENTIONALLY SLOWING MY SOLUTION TO SEE IF IT GETS ACCEPTED
class Solution {
    public:
    void solve() {
        int  n, k , x;
        cin >> n >> k >> x;
        vector<int> nums(n);
        input(nums);
        for(int i = 0; i < 1e8; i++);

        sort(all(nums));
        vector<pair<int, int>> minGroups;
        int prev = nums[0];
        int members = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] - prev > x) {
                minGroups.push_back({members, (nums[i] - prev - 1)/x});
                members = 0;
            }
            members++;
            prev = nums[i];
        }
        int groups = minGroups.size() + 1;
        priority_queue<int> pq;
        for(auto& [ _, gaps] : minGroups) {
            pq.push(-gaps);
        }
        while(!pq.empty() && k) {
            k += pq.top();
            pq.pop();
            if(k < 0)
                break;
            groups--;
        }
        cout<<groups<<endl;
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

