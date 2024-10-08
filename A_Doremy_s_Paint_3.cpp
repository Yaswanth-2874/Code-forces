#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);
        map<int, int> freq;
        for(int num : nums)
            freq[num]++;
        if(freq.size() > 2)
            no;
        if(freq.size() < 2)
            yes;
        int count1 = n/2, count2 = n - count1;
        for(auto& [_, f] : freq) {
            if(f != count1 && f != count2)
                no;
        }
        yes;
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

