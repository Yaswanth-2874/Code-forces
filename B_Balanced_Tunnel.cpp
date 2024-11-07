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

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> entry(n), exit(n);
        input(entry);
        input(exit);
        set<int> skipped;

        int left2 = 0, fines = 0;

        for(int left1 = 0; left1 < n; left1++) {
            if(skipped.find(entry[left1]) != skipped.end())
                continue;
            while(left2 < n && entry[left1] != exit[left2]) {
                skipped.insert(exit[left2++]);
                fines++;
            }
            if(left2 >= n)
                break;
            left2++;

        }
        pn(fines)
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
