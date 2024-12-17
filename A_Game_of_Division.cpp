#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n";}
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
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        array(int, v, n);
        map<int, int> freq;
        for(int num : v) {
            num %= k;
            freq[num]++;
        }
        for(auto& [num, f] : freq) {
            // cout<<num<<" : "<<f<<endl;
            int otherNum = num;
            f--;
            otherNum %= k;
            // cout<<otherNum<<" is "<<num<<endl;
            if(freq[otherNum] == 0) {
                yes;
                for(int i = 0; i < n; i++) {
                    if(v[i] % k == num)
                        pn(i+1)
                }
            }
            f++;
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