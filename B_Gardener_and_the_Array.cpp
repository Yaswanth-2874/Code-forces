#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"Yes\n"; return;}
#define no {cout<<"No\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        map<int, int> setBits;
        vector<vector<int>> bitsPos;

        for(int i = 0; i < n; i++) {
            int count;
            cin >> count;
            vector<int> bitsForEle(count);
            for(int j = 0; j < count; j++) {
                cin >> bitsForEle[j];
                setBits[bitsForEle[j]]++;
            }
            bitsPos.push_back(bitsForEle);
        }

        for(auto& row : bitsPos) {
            bool ans = true;
            for(auto& ele : row) {
                if(setBits[ele] < 2) {
                    ans = false;
                    break;
                }
            }
            if(ans)
                yes;
        }
        no;
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
