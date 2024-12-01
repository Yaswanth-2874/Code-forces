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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    int maxSmall;
    int count = 0;

    int check(vector<int>& c) {
        count++;
        set<int> cc;
        // print(c);
        int n = c.size();
        for(int i = 2; i < n; i++) {
            for(int j = 0; j < i; j++) {
                for(int k = j+1; k < i; k++) {
                    // cout<<j<<" "<<k<<" "<<i<<endl;
                    if(c[i] <= (c[j] + c[k])) {
                        cc.insert(i);
                        // cout<<j<<" "<<k<<" "<<i<<endl;
                    }
                }
            }
        }
        // cout<<"Count for above is "<<count<<endl;
        return cc.size();
    }
    void generate(vector<int>& a, vector<int>& b, vector<int>& c, int i) {
        if (i == a.size()) {
            maxSmall = max(maxSmall, check(c));
            return;
        }

        c[i] = a[i];
        generate(a, b, c, i + 1);

        c[i] = b[i];
        generate(a, b, c, i + 1);
    }

    public:
    void solve() {
        int n;
        cin >> n;
        maxSmall = 0;

        array(int, a, n);
        array(int, b, n);
        vector<int> c(n);

        generate(a, b, c, 0);
        cout<<"Count is "<<count<<endl;
        pn(maxSmall)

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
