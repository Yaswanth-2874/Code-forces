#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> questionsList(m);
        for (auto& input : questionsList) {
            cin >> input;
        }
        set<int> known, unknown;

        vector<int> knownQuestions(k);
        for (auto& input : knownQuestions) {
            cin >> input;
            known.insert(input);
        }

        for(int i = 1; i <= n; i++) {
            if(known.find(i) != known.end())
                continue;
            unknown.insert(i);
        }
        string ans = "";

        for(int& question : questionsList) {
            bool erased = false;
            
            if(unknown.find(question) != unknown.end()) {
                erased = true;
            }

            unknown.erase(question);

            if(unknown.empty())
                ans.push_back('1');
            else
                ans.push_back('0');
            
            if(erased)
                unknown.insert(question);
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
