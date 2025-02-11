#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        map<int, int> freq;
        for (auto& input : v) {
            cin >> input;
            freq[input]++;
        }
        multiset<int> ms;
        for(auto& [_, f] : freq)
            ms.insert(f);
        
        int ans = 0;
        while(k > 0 && ms.size()) {
            auto top = ms.begin();
            int val = *top;
            if(k < val)
                break;
            k -= val;
            ms.erase(top);
        }
        if(ms.size() == 0)
            cout<<1<<endl;
        else
        cout<<ms.size()<<endl;

        
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
