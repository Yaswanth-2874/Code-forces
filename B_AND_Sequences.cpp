#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

vector<int> factorials;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        array(int, v, n);
        int andV = v[0];

        for(int& num : v) {
            andV &= num;
        }

        int countOfandV = count(all(v), andV);
        if(countOfandV <= 1)
            pn(0);
        
        int ans = 1;
        ans *= 1 * countOfandV;
        ans = (ans * (countOfandV - 1)) % MOD;
        int remainingNumbers = n - 2;
        ans =( ans * (factorials[remainingNumbers]) ) % MOD;
        pn(ans);
    }
};

int32_t main() {
    int product = 1;
    int num = 1;
    factorials
    .push_back(1);
    for(int i = 1; i <= 2e5; i++) {
        product *= num++;
        product %= MOD;
        factorials.push_back(product);
    }
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
