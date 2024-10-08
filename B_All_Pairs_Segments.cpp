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
        int n, q;
        cin >> n >> q;
        int maxOccurances = (n * (n - 1)) / 2;
        vector<int> points(n);
        input(points);
        unordered_map<int, int> occurances;
        int occurance = 0;
        for(int i = 0; i < n - 1; i++) {
            int occurancesAfter = n - i - 1;
            int occurancesBefore = n - i - 1;
            occurancesBefore *= i;
            int totalOccurances = occurancesAfter + occurancesBefore;
            int numElements = points[i+1] - points[i] - 1;
            occurances[totalOccurances] += numElements;
            totalOccurances += i;
            occurances[totalOccurances] += 1;
        }
        occurances[n-1]++;
        while(q--) {
            int que;
            cin >> que;
            cout<<occurances[que]<<" ";
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

