#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

vector<int> factorials;
// im guessing memo would not help much in this, prolly bitmasking could work but lets see if brute force works

class Solution {
    int __builtin_popcount(int num) {
        int count = 0;
        for(int i = 0; i < 62; i++) {
            int bit = 1ll << i;
            if(bit & num)
                count++;
        }
        return count;
    }
    int findMin(int num, int left) {
        int dontPick = __builtin_popcount(num);
        int pick = 1e9;

        for(int i = left; i < factorials.size(); i++) {
            if(num >= factorials[i])
                pick = min(pick, 1 + findMin(num - factorials[i], i+1));
        }
        return min(pick, dontPick);
    }
    public:
    void solve() {
        int n;
        cin >> n;

        cout<<findMin(n, 3)<<endl;
    }
};

int32_t main() {
    int product = 1;
    factorials.push_back(1);
    for(int i = 1; i <= 20; i++) {
        product *= i;
        if(product >= 1e12)
            break;
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
