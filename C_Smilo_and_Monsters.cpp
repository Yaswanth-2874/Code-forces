#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#pragma endregion

class Solution {
    // Supercharge should kill as many mobs as possible to min moves
    // kill half the people normally and kill other half using supercharge seems optimal

    //FUCK ME I USED 0 INSTEAD OF 0LL AGAIN!! I NEVER LEARN
    public:
    void solve() {
        int n;
        cin >> n;

        array(int, v, n);
        sort(all(v));
        int sum = accumulate(all(v), 0ll);
        int targetSum = (sum+1)/2;
        int moves = targetSum;
        int currentSum = 0;

        for(int i = 0; i < n; i++) {
            currentSum += v[i];
            if(currentSum > targetSum) {
                int remainining = n - i;
                pn(moves + remainining)
            }
            if(currentSum == targetSum) {
                pn(moves + n - i - 1);
            }
        }
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
