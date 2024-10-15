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
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        input(nums);
        map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        int min = *min_element(all(nums));
        int prev = -2;
        int current = 0;
        int maxi = 0;
        int x = 1;

        vector<pair<int, int>> window;
        for(auto& [num, f] : freq) {
            window.push_back({num, f});
            // cout<<"("<<num<<" , "<<f<<")"<<" ";
        }
        // cout<<endl;

        int left = 0, right = 0;
        while(right < window.size()) {
            auto [num, freq1] = window[right];
            if(num != prev + 1) {
                current = freq1;
                x = 1;
                left = right;
            } else {
                current += freq1;
                x++;
            }
            while(x > k) {
                auto [num2, freq2] = window[left++];
                current -= freq2;
                x--;
            }
            // cout<<left<<" "<<right<<endl;
            maxi = max(maxi, current);
            right++;
            prev = num;
        }
        cout<<maxi<<endl;
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