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
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, money;
        cin >> n >> money;
        vector<int> flowers(n);

        input(flowers);
        int left = 0;

        sort(all(flowers));
        int maxMoney = money, maxSpentMoney = 0;

        for(int right = 0; right < n; right++) {
            while(flowers[right] - flowers[left] > 1) {
                money += flowers[left++];
            }
            money -= flowers[right];
            while(money < 0) {
                money += flowers[left++];
            }
            int spentMoney = maxMoney - money;
            maxSpentMoney = max(maxSpentMoney, spentMoney);
        }
        pn(maxSpentMoney);
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
