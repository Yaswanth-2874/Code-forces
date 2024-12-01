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
#define array(type, v, s) vector<type> v(s); input(v);
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
    
        string st;
        cin >> st;

        if(n == 1)
            yes;

        int count = 0;

        st.push_back('0');

        for(char&ch : st) {
            if(ch == '1')
                count++;
            else {
                if(count % 2)
                    no;
                count = 0;
            }
        }
        yes;
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
