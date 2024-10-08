#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> people(n);
        input(people);
        int gold = 0, donated = 0;

        for(int i = 0; i < n; i++) {
            if(people[i] >= k)
                gold += people[i];
            else if (people[i] == 0 && gold > 0) {
                donated++;
                gold--;
                }
        }
        cout<<donated<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

