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
    int findUnique(char prev, char next) {
        for(int i = 0; i < 26; i++) {
            if(!(prev == (char)(i + 'a') || next == (char)(i + 'a')))
                return i;
        }
        return 1;
    }
    public:
    void solve() {
        string st;
        cin >> st;

        char prev = '#';
        for(char& ch : st) {
            if(ch == prev) {
                ch = '#';
            }
            prev = ch;
        }

        for(int i = 1; i < st.size(); i++) {
            if(st[i] == '#') {
                char next = '$';
                if(i < st.size() - 1)
                    next = st[i+1];
                char ch = findUnique(st[i-1], next) + 'a';
                st[i] = ch;
            }
        }
        cout<<st<<endl;
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
