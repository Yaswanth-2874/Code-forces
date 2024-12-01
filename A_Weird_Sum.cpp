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
    // Easy but taken a lot of time :(, Loved this question
    int findAns(vector<int>& v) {
        if(v.size() == 1)
            return 0;

        sort(all(v));
        vector<int> prefixSum(1, 0);

        int sum = 0;
        for(int& num : v) {
            sum += num;
            prefixSum.push_back(sum);
        }
        int ans = 0;

        for(int i = 0; i < v.size(); i++) {
            int sum = prefixSum[v.size()] - prefixSum[i+1];
            int terms = v.size() - i - 1;
            ans += sum - (terms * v[i]);
        }

        return ans;
    }
    public:
    void solve() {
        int m , n;
        cin >> m >> n;

        map<int, vector<int>> colorsRow, colorsCol;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int color;
                cin >> color;
                colorsRow[color].push_back(i);
                colorsCol[color].push_back(j);
            }
        }
        int ans = 0;

        for(auto& [color, v] : colorsRow) {
            ans += findAns(v);
            ans += findAns(colorsCol[color]);
        }

        pn(ans);
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
