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
    bool isPrime(int num) {
        int f = 0;

        for(int i = 2; i*i <= num; i++) {
            if(num % i == 0) {
                // cout<<i<<" is a factor of "<<f<<endl;
                f++;
            }
        }
        // cout<<"factors for "<<num<<" is "<<f<<endl;

        return f== 0;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        if(n <= 4)
            pn(-1);
        
        for(int i = 1; i <= n; i+=2)
            cout<<i<<" ";
        int last = n%2 == 0? n-1 : n;
        int used = -1;

        for(int i = 2; i <= n; i+=2) {
            int num = last + i;
            if(!isPrime(num)) {
                cout<<i<<" ";
                used = i;
                break;
            }
        }
    
        for(int i = 2; i <= n; i+= 2) {
            if(i != used)
                cout<<i<<" ";
        }
        cout<<endl;
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
