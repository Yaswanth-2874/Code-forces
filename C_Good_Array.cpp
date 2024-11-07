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

// This seems easy, what could go wrong?
// Demn it, i still got wa

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        int sum = 0;
        map<int ,int> numbers;
        vector<int> nums(n);

        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            numbers[nums[i]]++;
            sum += nums[i];
        }
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            numbers[nums[i]]--;
            if(numbers[nums[i]] == 0)
                numbers.erase(nums[i]);

            sum -= nums[i];

            if(sum % 2 == 0) {
                int target = sum/2;
                if(numbers.find(target) != numbers.end()) {
                    ans.push_back(i+1);
                }
            }
            sum += nums[i];
            numbers[nums[i]]++;
        }

        cout<<ans.size()<<endl;
        if(ans.size())
            print(ans);
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

