#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans(n, -1);

        // 1s should only have 0s as friends and vice versa
        // the problem occurs with x and y
        // if difference y-x is even, then y and x are in same state, so it becomes invalid
        // if difference is odd, then not a problem
        // the last index should either be 1 or 2
        
        if((y - x) % 2 == 1) {
            int state = 0;
            for(int i = 0; i < n-1; i++) {
                ans[i] = state;
                state = !state;
            }
            ans[n-1] = ans[n-2] == 1 ? 2 : 1;
            print(ans);
            return;
        }
        //now y and x are on same state, so if i change one to 2, then it is fine
        // there are 2 2s which could lead to issue
        int state = 0; 
        for(int i = 0; i < n-1; i++) {
            ans[(i+x)%n] = state;
            state = !state;
        }
        ans[x-1] = 2;
        print(ans)  
      
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
