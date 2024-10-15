#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;
        map<char, int> freq;
        for(auto& ch : st) {
            freq[ch]++;
        }
        int prevFreq = -1;
        for(auto& [ch, fre] : freq) {
            if(prevFreq == -1)
                prevFreq = fre;
            if(fre != prevFreq)
                pn(-1);
            prevFreq = fre;
        }
        cout<<prevFreq<<endl;
        for(auto& [ch, fre] : freq) {
            while(fre--)
                cout<<ch;
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

