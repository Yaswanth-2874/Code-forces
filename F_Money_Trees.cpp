#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        array(int, fruits, n);
        array(int, heights, n);

        int left = 0, size = 0;
        int currentFruits = 0;

        for(int right = 0; right < n; right++) {
            currentFruits += fruits[right];
            if(right >= 1 && heights[right-1] % heights[right] != 0) {
                left = right;
                currentFruits = fruits[right];
            }
            while(currentFruits > k) {
                currentFruits -= fruits[left++];
            }
            // cout<<"Current Fruits at "<<left<<" and "<<right<<" are "<<currentFruits<<endl;
            size = max(size, right - left + 1);
        }

        pn(size);
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
