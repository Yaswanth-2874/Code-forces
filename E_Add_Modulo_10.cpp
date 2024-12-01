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
#define array(type, v, s) vector<type> v(s); input(v);
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        array(int, v, n);
        
        bool zeroExists = false;
        bool nonZeroExists = false;

        for(int& num : v) {
            int mod10 = num % 10;
            if(mod10 != 5 && mod10 != 0) {
                nonZeroExists = true;
                if(zeroExists)
                    no;
                while(mod10 != 2) {
                    num += mod10;
                    mod10 = num%10;
                }
                num %= 20;
            } else {
                zeroExists = true;
                if(nonZeroExists)
                    no;
                while(mod10 != 0) {
                    num += mod10;
                    mod10 = num%10;
                }
            }
        }

        int num = v[0];
        if(count(all(v), num) != n)
            no;
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
