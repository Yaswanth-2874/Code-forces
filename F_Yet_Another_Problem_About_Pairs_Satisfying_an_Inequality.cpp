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

// ai < i < aj < j
// => consider only pairs such that ai < i and insert them in vector
// sort them
// now for every i , find min index such that i < aj using binary search

class Solution {
    int bs(int requiredMin, vector<pair<int, int>>& validPairs) {
        int left = 0, right = validPairs.size() - 1;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(validPairs[mid].first >= requiredMin)
                right = mid - 1;
            else
                left = mid + 1;
        }
        // right would point at an index just lesser than requiredMin
        // so my required index would be right + 1
        int requiredIndex = right + 1;
        int remainingElements = validPairs.size() - right - 1;
        // cout<<"Required Index for "<<requiredMin<<" is "<<requiredIndex<<" inc by "<<remainingElements<<endl;
        return remainingElements;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<pair<int, int>> validPairs;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;

            if(num < i)
                validPairs.push_back({num, i});
        }

        sort(all(validPairs));
        int pairs = 0;
        for(int i = 0; i < validPairs.size(); i++) {
            pairs += bs(validPairs[i].second + 1, validPairs); // atleast the value of aj should be i + 1
        }

        pn(pairs);
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
