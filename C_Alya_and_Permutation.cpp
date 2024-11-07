#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& i : array) cout<<i<<" "; cout<<endl;
#define pn(i){cout<<i<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

vector<int> oneBits;
class Solution {
   vector<int> isOdd(int n) {
        int last = n;
        vector<int> ans = isEven(n-1);
        ans.push_back(last);
        return ans;
   }
   int highestBit(int num) {
        for(int i = 31; i >= 0; i--) {
            if((1LL << i) & num)
                return i;
        }
        return 0;
    }

   vector<int> isEven(int n) {
        if(n == 4)
            return {2, 3, 1, 4};
    
        int maxOneBit = 0;
        for(int i = 0; i < oneBits.size(); i++) {
            if(n < oneBits[i]) {
                maxOneBit = oneBits[i-1];
                break;
            }
        }
        set<int> highest;
        vector<int> ans;

        int high = highestBit(n);
        // cout<<"Highest bit is "<<high<<endl;
        for(int i = 1; i <= n; i++) {
            int bit = 1LL << high;
            if(bit & i && (i != maxOneBit))
                highest.insert(i);
        }

        if(highest.size() == 1) {
            ans = isOdd(n-1);
            ans.push_back(n);
            return ans;
        }

        for(int i = 1; i <= n; i++) {
            if(highest.find(i) == highest.end() && i != maxOneBit)
                ans.push_back(i);
        }

        for(auto& num : highest)
            ans.push_back(num);
        ans.push_back(maxOneBit);

        return ans;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> ans;
        
        if(n%2 == 0)
            ans = isEven(n);
        else
            ans = isOdd(n);

        int value = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                value = value & ans[i];
                // cout<<" & "<<ans[i];
            }
            else {
                value = value | ans[i];
                // cout<<" | "<<ans[i];
            }
        }
        cout<<value<<endl;
        print(ans);

    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= 31; i++)
        oneBits.push_back((1LL<<i)-1);
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

