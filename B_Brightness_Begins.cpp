#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    int sqrt(int x) {
        int l=0,r=x,num;
    
        while(l<=r){
             num=(l+r)/2;
            if ((double)num<x/(double)num)
                l=num+1;
            else if((double)num>x/(double)num)
                r=num-1;
            else
                return num;
        }
        return l-1;
    }
    public:
    void solve() {
        int k;
        cin >> k;

        int minRoots = sqrt(k);
        int extraRoots = sqrt(k + minRoots) - sqrt(k);

        cout<<k + minRoots + extraRoots<<endl;
        
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

