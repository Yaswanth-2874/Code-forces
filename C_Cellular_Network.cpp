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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    int n, m;
    bool check(vector<int>& cities, vector<int>& towers, int r) {
        int left1 = 0, left2 = 0;
        while(left1 < n && left2 < m) {
            int lowerRange = towers[left2] - r;
            int upperRange = towers[left2] + r;

            while(left1 < n && (cities[left1] >= lowerRange && cities[left1] <= upperRange))
                left1++;
            if(left1 == n)
                return 1;
            left2++;
        }
        return 0;
    }
    public:
    void solve() {
        cin >> n >> m;

        array(int, cities, n);
        array(int, routers, m);

        int low = 0, high = 1e15; // guessing this would be safe and avoids overflows
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(cities, routers, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        pn(high + 1);
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
