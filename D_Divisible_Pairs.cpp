#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

// If i am substracting, then the target to find should be the same number 
// Lets say if my number is 5 (after mod (mod value = 8)), then to find proper substraction number, i need to search for 5 not for 3 as i am subtracting not adding
class Solution {
    public:
    void solve() {
        int n, x, y;
        cin >> n >> x >> y;

        map<pair<int, int>, int> freq;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            int num1 = num % x;
            int num2 = num % y;

            int target1 = (x - num1) % x;
            int target2 = num2;

            // cout<<"{"<<target1<<","<<target2<<"} : ";
            // cout<<freq[{target1, target2}]<<endl;

            if(freq.find({target1, target2}) != freq.end())
                ans += freq[{target1, target2}];
            freq[{num1, num2}]++;
        }

        cout<<ans<<endl;
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

