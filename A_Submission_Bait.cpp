#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;


class Solution {
    public:
    void solve() {
        int size;
        cin>>size;
        vector<int> nums(size);
        input(nums);

        priority_queue<int> pq;
        for(int num : nums)
            pq.push(num);

        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            int count = 1;
            while(!pq.empty() && pq.top() == top) {
                pq.pop();
                count++;
            }
            if(count % 2) {
                yes;
                return;
            }
        }
        no;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}
