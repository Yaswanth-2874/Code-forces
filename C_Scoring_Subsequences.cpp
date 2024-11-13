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

// s1 * s2 * s3 ... sd/ d! should be max
// => s1/1 * s2/2 * s3/3 ...  should be max
// can clearly observe that if any value sn/n is less than 1, then it wont let me obtain the max value
// i can change condition to s1/d * s2 /d-1 * s3/d-2 ...
// if(s1/d is lesser than 1, ill remove it)
// Good question, enjoyed solving it

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> nums(n);
        input(nums);
        int left = 0;

        for(int i = 0; i < n; i++) {
            int denominator = i - left + 1;
            while(nums[left]/denominator == 0) {
                left++;
                denominator--; //denom will never go to zero as nums[left]/1 would never be 0
            }
            int size = i - left + 1;
            cout<<size<<" ";
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
