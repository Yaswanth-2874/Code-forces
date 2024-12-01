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

// I need to find a way to perform prefix sum on bitwise and, then this question changes to simple binary search
// I cant undo bitwise and.. so think about alternative
// Can i perform prefix sum on bits instead of performing it on elements??


class Solution {
    vector<vector<int>> bitsPrefix;
    void updateAllBitCount(vector<int>& bits, int num) {
        for(int i = 0; i < 32; i++) {
            int bit = 1ll << i;
            if(bit & num)
                bits[i]++;
        }
        bitsPrefix.push_back(bits);
    }
    bool check(vector<int>& bitsPrefix, vector<int>& currentBits, int k, int expectedBits) {
        int andValue = 0;
        for(int i = 0; i < 32; i++) {
            int setBits = currentBits[i] - bitsPrefix[i];
            if(setBits == expectedBits)
                andValue += (1ll << i);
        }
        // cout<<"BitWise and is "<<andValue<<endl;

        return andValue >= k;
    }
    void binarySearch(vector<int>& nums, int left, vector<int>& bitsPrefixBefore, int k) {
        int right = nums.size();
        int l = left;

        while(l <= right) {
            int mid = l + (right - l)/2;
            // cout<<"Checking interval "<<l<<" and "<<right<<endl;
            if(check(bitsPrefixBefore, bitsPrefix[mid], k, mid - left + 1))
                l = mid + 1;
            else
                right = mid - 1;
        }

        if(right == left-1)
            cout<<-1<<" ";
        else
            cout<<right<<" ";
    }
    void answerQuery(vector<int>& nums) {
        int l, k;
        cin >> l >> k;

        vector<int>& bitsBefore = bitsPrefix[l-1];
        binarySearch(nums, l, bitsBefore, k);
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);

        vector<int> bits(32, 0);
        bitsPrefix.push_back(bits);
    
        for(int& num : nums) {
            updateAllBitCount(bits, num);
        }

        int queries;
        cin >> queries;

        while(queries--) {
            answerQuery(nums);
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
