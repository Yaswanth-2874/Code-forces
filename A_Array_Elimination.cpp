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

// I can always make it a zero if i choose only one element (k = 1)
// 13 = 01101
// 25 = 11001
// 19 = 10011
// 07 = 00111

// I solved a similar type of question , this is easy now
// Inorder to obtain zero, all bits must become zero
// Now ill start from highest valid bit onwards and keep track of number of ones present
// Ill store all those in a map
// so.. map for me would go something like
// 5 -> 2
// 4 -> 2
// 3 -> 2
// 2 -> 2
// 1 -> 4
// Answer would be all divisors of gcd of all the factors

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n), setBitsMap(32);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            for(int bitPos = 31; bitPos >= 0; bitPos--) {
                int bit = 1LL << bitPos;
                
                if((bit & nums[i]) == 0) {
                    setBitsMap[bitPos]++;
                }
            }
        }
        int value = *max_element(all(setBitsMap));
       
        for(int bitsPresent : setBitsMap) {
            if(bitsPresent == 0)
                continue;
            value = gcd(value, bitsPresent);
        }
        for(int i = 1; i <= value; i++) {
            if(value % i == 0)
                cout<<i<<" ";
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

