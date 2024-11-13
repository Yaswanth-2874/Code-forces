#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; continue;}
#define no {cout<<"NO\n"; continue;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    void checkForPattern(string& st, int index, set<int>& pos) {
        for(int i = index; i >= max(0ll, index - 3); i--) {
            int remaining = (int)st.size() - (i);

            if(remaining < 4) {
                continue;
            }

            string temp = st.substr(i, 4);

            
            if(temp == "1100")
                pos.insert(i);
        }
    }
    public:
    void solve() {
        string st;
        cin >> st;

        int q;
        cin >> q;
        set<int> pos;

        for(int i = 0; i < (int)st.size() - 3; i++) {
            string temp = st.substr(i, 4);
            if(temp == "1100") {
                pos.insert(i);
            }
        }

        while(q--) {
            int index, value;
            cin >> index >> value;

            if(st[index - 1] == value + '0') {
                if(pos.size())
                    yes;
                no;
            }

            st[index - 1] = value + '0';
            for(int i = index - 1; i >= max(0ll, index - 4); i--) {
                if(exists(pos, i))
                    pos.erase(i);
            }
            checkForPattern(st, index-1, pos);
            if(pos.size())
                yes;
            no;
        }
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
