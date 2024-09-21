#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout << "YES\n"; return true;
#define no cout << "NO\n"; return true;
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array) cin >> d;
#define print(array) for(auto& num : array) cout << num << " "; cout << endl;

class Solution {
    int totalSwam = 0;
    int k, m;
    
    bool ifLog(int start, int m, string& path) {
        // cout<<"Current pos : "<<start<<" and jump"<<endl;
        if (start + m >= path.size()) {
            yes;
        }
        for (int i = min(start + m , (int)path.size() - 1); i > start; i--) {
            if (path[i] == 'L') {
                return ifLog(i, m, path);
            }
        }
        for (int i = min(start + m , (int)path.size() - 1); i > start; i--) {
            if (path[i] == 'W') {
                return ifWater(i, path);
            }
        }
        no;
    }
    
    bool ifWater(int start, string& path) {
        // cout<<"Current pos : "<<start<<" and swim"<<endl;
        totalSwam++;
        if (totalSwam == k + 1) {
            no;
        }
        if (start + 1 >= path.size()) {
            yes;
        }
        start++;
        
        if (path[start] == 'C') {
            no;
        }
        if (path[start] == 'L') {
            return ifLog(start, m, path);
        }
        return ifWater(start, path);
    }
    
    public:
    void solve() {
        int n;
        cin >> n >> m >> k;
        string path;
        cin >> path;

        if(m > n) {
            cout<<"YES\n";
            return;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (path[i] == 'L') {
                ifLog(i, m, path);
                return;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            if (path[i] == 'W') {
                ifWater(i, path);
                return;
            }
        }
        cout << "NO\n";
    }

};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
