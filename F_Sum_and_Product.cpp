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
#define pn(num){cout<<num<<endl; continue;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

// pure math, lets see how this works

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        array(int, v, n);
        freqMap(int, v);

        int q;
        cin >> q;
        while(q--) {
            int sum, product;
            cin >> sum >> product;

            int d = sum * sum - (4 * product);
            if(d < 0) {
                cout<<"0 ";
                continue;
            }
            int sqrt = sqrtl(d);
            if(sqrt * sqrt != d) {
                cout<<"0 ";
                continue;
            }
            
            int val1 = (sum + sqrt)/2;
            int val2 = (sum - sqrt)/2;

            if(val1 == val2) {
                cout<<(freq[val1] * (freq[val1] - 1))/2<<" ";
                continue;
            }
            int ans = freq[val1] * freq[val2];
            cout<<ans<<" ";
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
