#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        int sumA = 0, sumB = 0;
        int minA = LLONG_MAX, minB = LLONG_MAX;
        for (auto& input : a) {
            cin >> input;
            sumA += input;
            minA = min(minA, input);
        }
        for (auto& input : b) {
            cin >> input;
            sumB += input;
            minB  = min(minB , input);
        }

        int optionA = sumA + minB*n;
        int optionB = sumB + minA*n;

        cout<<min(optionA, optionB)<<endl;     
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
