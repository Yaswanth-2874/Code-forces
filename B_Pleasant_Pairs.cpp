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

// ai.aj = i + j <= 2n
// ai.aj <= 2n
// aj <= 2n/ai

// CONSIDER ENTIRE PRODUCT (ai.aj)
// I already have value of ai
// now aj value could go from 1 to k till ai.aj <= 2n
// Find index of aj (if it exists) and then check if i + j = ai.aj

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        unordered_map<int, int> reverseMap;
        vector<int> nums(n);
        input(nums);

        for(int i = 1; i <= n; i++) {
            reverseMap[nums[i-1]] = i;
        }
        int count = 0;

        for(int i = 1; i <= n; i++) {
            int ai = nums[i-1];
            for(int aj = 1; aj * ai <= 2*n; aj++) {
                if(ai == aj)
                    continue;
                if(reverseMap.find(aj) != reverseMap.end()) {
                    int index = reverseMap[aj];
                    if(index + i == ai *aj)
                        count++;
                }
            }
        }
        pn(count/2);
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

