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

// i spam emotes in the order 1 + 2 + 3 + .... k + k-1 + k-2 +... 1 and so on
// first find the sum, then i can know how many cycles i can complete
// last cycle can be done manually using binary search

class Solution {
    int sum(int x) {
        return (x * (x + 1))/2;
    }
    int bs(int target, bool increasing, int k) {
        if(increasing) {
            int left = 1, right = k;
            while(left <= right) {
                int mid = left + (right - left)/2;
                if(sum(mid) >= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // cout<<(right + 1)<<" ";
            return right + 1;
        }
        int left = k - 1, right = 1;
        while(left >= right) {
            int mid = left + (right - left)/2;
            int cSum = sum(k-1) - sum(mid - 1);

            // cout<<"Mid is "<<mid<<" and sum is "<<cSum<<" while target is "<<target<<endl;

            if(cSum >= target)
                right = mid + 1;
            else
                left = mid - 1;
                
        }
        return k - right + 1;
    }
    public:
    void solve() {
        int k, x;
        cin >> k >> x;

        int sum = k*k;
        int turns = 0;

        if(x >= sum)
            pn(2 * k - 1);

        int normalSum = (k * (k + 1))/2;
        if(normalSum == x)
            pn(k);
        if(normalSum > x)
            pn(bs(x, true, k));
        x -= normalSum;
        
        pn(k + bs(x, false, k))

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
