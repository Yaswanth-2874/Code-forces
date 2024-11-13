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
        int n, a, b;
        cin >> n >> a >> b;

        int x = 0, y = 0;
        string st;
        cin >> st;

        int trys = 100;
        while(trys--) {
            for(char& ch : st) {
                if(ch == 'N')
                    y++;
                if(ch == 'E')
                    x++;
                if(ch == 'W')
                    x--;
                if(ch == 'S')
                    y--;
                if(x == a && y == b)
                    yes;
            }
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
