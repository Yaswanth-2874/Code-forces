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

        int maxScore = -1, maxLeft = 1, maxRight = 1;
        for(int i = n-1; i >= 0; i--) {
            int& curr = v[i];
            int score = 0;

            for(int j = i+1; j < n; j++) {
                if(curr < v[j]) {
                    score--;
                } else if (curr > v[j]) {
                    score++;
                }

                if(maxScore < score) {
                    maxScore = score;
                    maxLeft = i+1;
                    maxRight = j+1;
                }
            }
        }

        cout<<maxLeft<<" "<<maxRight<<endl;
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
