#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        map<int, int> freq;
        set<pair<int, int>> revFreq;
        vector<int> prefix(n), suffix(n);

        for(int i = 0; i < n; i++) {
            if(freq.count(v[i])) {
                revFreq.erase({freq[v[i]], v[i]});
            }
            revFreq.insert({++freq[v[i]], v[i]});

            auto [maxFreq, _] = *revFreq.rbegin();
            int targetFreq = (i+1)/2;

            if(maxFreq > targetFreq)
                prefix[i] = 1;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(!prefix[i])
                break;
            int extra = 1;
            map<int, int> freq;
            set<pair<int, int>> revFreq;

            for(int j = i; j >= 0; j--) {
                if(freq.count(v[j])) {
                    revFreq.erase({freq[v[j]], v[j]});
                }
                revFreq.insert({++freq[v[j]], v[j]});
    
                auto [maxFreq, _] = *revFreq.rbegin();

                int targetFreq = (i-j+1)/2;
                
                if(maxFreq <= targetFreq) {
                    extra = 0;
                    break;
                }
            }

            ans += extra;
        }

        cout<<ans<<endl;
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
