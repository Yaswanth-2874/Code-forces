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

class Solution {
    int findExtra(string num, bool firstIsOdd, int index) {
        int start = num[index] - '0';
        if(index >= num.size())
            return 1;

        if(firstIsOdd && start % 2 == 1) {
            int minExtra = (start-1)/2 * pow(5, ((num.size() - index - 1)));
            // cout<<minExtra<<" for index "<<index<<endl;
            return minExtra + findExtra(num, !firstIsOdd, index+1);
        }
        if(!firstIsOdd && start % 2 == 0) {
            int minExtra = (start)/2 * pow(5, ((num.size() - index - 1)));
            // cout<<minExtra<<" for index "<<index<<endl;
            return minExtra + findExtra(num, !firstIsOdd, index+1);
        }
        
        int minExtra = (start+1)/2 * pow(5, ((num.size() - index - 1)));
        // cout<<minExtra<<" for index "<<index<<endl;

        return minExtra;
    }
    public:
    void solve() {
        string num;
        cin >> num;

        int ans = 0;
        int size = num.size();
        int current = 1;

        for(int i = 1; i < size; i++) {
            current *= 5;
            ans += current;
        }
        ans += findExtra(num, true, 0);

        cout<<ans<<endl;
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

