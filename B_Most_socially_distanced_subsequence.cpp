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
    vector<int> findSubSequence(vector<int>& v) {
        vector<int> ans;
        int i = 0;
        ans.push_back(v[i++]);

        while(i < v.size()) {
            int start = i;
            // cout<<"Started at "<<start<<endl;
            while(i < v.size() && v[i-1] < v[i])
                i++;
            if(start != i) {
                start = i;
                ans.push_back(v[i-1]);
            }
            // cout<<"Ended at " << start-1<< " and restarted at "<<start<<endl;
            while(i < v.size() && v[i-1] > v[i])
                i++;
            if(start != i) {
                start = i-1;
                ans.push_back(v[i-1]);
            }
            // cout<<"Ended at " << start-1<< " and restarted at "<<start<<endl;    
        }
        cout<<ans.size()<<endl;
        print(ans);
        return ans;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> v(n);
        input(v);

        findSubSequence(v);
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
