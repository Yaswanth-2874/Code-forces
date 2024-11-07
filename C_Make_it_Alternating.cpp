#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

// keep track of consectutive
// if consectutive occurances are like 4 2 4 7
// we can calculate minRemoves as summation of ai - 1

// 0 0 0 0 1 1 1 0 0
// then i need to remove 3 zeroes, 2 ones and 1 zero 
// the order in which i remove also matters in the count, so i must use permutations

vector<int> fact;

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;

        char prev = '#';
        int streak = 0;
        vector<int> streaks;
        int maxStreak = 0;
    
        for(char& bitValue : st) {
            if(bitValue == prev || prev == '#') {
                streak++;
                maxStreak = max(maxStreak, streak);
            } else {
                streaks.push_back(streak);
                streak = 1;
            }
            prev = bitValue;
        }
        if(maxStreak == 1) {
            cout<<0<<" "<<1<<endl;
            return;
        }

        streaks.push_back(streak);
        int minimumEliminate = accumulate(all(streaks), 0LL) - streaks.size();
        int possibleRemovals = 1;

        for(int& streak : streaks) {
            possibleRemovals *= streak;
            possibleRemovals %= MOD;
        }

        possibleRemovals *= (fact[minimumEliminate] % MOD);
        possibleRemovals %= MOD;
        cout<<minimumEliminate<<" "<<possibleRemovals<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    int product = 1;
    fact.push_back(1);
    for(int i = 1; i <= 2*1e5; i++) {
        product = ((product % MOD) * i) % MOD;
        fact.push_back(product);
    }
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

