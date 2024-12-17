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
class Solution {
    int sigma(int n) {
        return (n * (n+1))/2ll;
    }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        if(n == 1)
            pn(0);
        if(k >= n)
            pn(1);

        int maxOutlets =  sigma(k-1) + 1;
        if(n > maxOutlets)
            pn(-1);

        int l = 1, r = k-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            // mid indicates the number that i am using starting from max
            // if i am using mid number, then my least value that i am using is k - mid + 1
            int leastUsing = k - mid + 1;
            int currentOutlets = maxOutlets - sigma(leastUsing - 2);
            // cout<<mid<<" "<<currentOutlets<<endl;
            if(currentOutlets >= n) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        pn(r+1)
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
