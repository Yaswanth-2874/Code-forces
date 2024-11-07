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

// I CAN USE PREFIX SUM AND BINARY SEARCH TO FIND TWO UNIQUE ELEMENTS;

class Solution {
    void printDifferent(int l, int r, vector<int>& nums, vector<int>& prefix) {
        int uniques = prefix[r] - prefix[l] + 1;
        // cout<<"Uniques in range ("<<l<<", "<<r<<") : "<<uniques<<endl;
        if(uniques == 1) {
            cout<<-1<<" "<<-1<<endl;
            return;
        }
        int left = l, right = r;
        int target = prefix[l] + 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(prefix[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout<<l<<" "<<(right+1)<<endl;
    }
    public:
    void solve() {
        int size;
        cin >> size;
        vector<int> nums(size), prefix(1, 1);
        int prev = -1;
        int count = 0;

        for(int i = 0; i < size; i++) {
            cin >> nums[i];
            if(prev != nums[i])
                count++;
            prev = nums[i];
            prefix.push_back(count);
        }
        
        int queries;
        cin >> queries;
        while(queries--) {
            int l, r;
            cin >> l >> r;
            printDifferent(l, r, nums, prefix);
        }
        cout<<endl;
        
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

