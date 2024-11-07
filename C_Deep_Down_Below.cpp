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

// For this problem i can try the following
// First create a array in which i store the minPower required to defeat that entire mobs
// Now i can greedily choose a row which requires least power to complete (sort the array for that)
// I need to know the size of that also so that i can calculate bonus power that i obtain, so i use pair<int, int>

class Solution {
    // Thinking that this works, hope no tle
    // I PASSED BY REF ACCIDENTALLY AND MY INPUT VALUES CHANGED! GOT WA
    public:
    void solve() {
        int rows;
        cin >> rows;
        vector<vector<int>> monsters(rows);
        for(int i = 0; i < rows; i++) {
            int rowSize;
            cin >> rowSize;

            while(rowSize--) {
                int monsterArmor;
                cin >> monsterArmor;
                monsters[i].push_back(monsterArmor);
            }
        }
        vector<pair<int,int>> minPower;
        int index = 0;

        for(auto& row : monsters) {
            int minRequiredPower = 0;
            int extraPower = 0;
            for(int armor : row) {
                armor -= extraPower;
                minRequiredPower = max(armor + 1, minRequiredPower);
                extraPower++;
            }
            minPower.push_back({minRequiredPower, index++});
        }
        sort(all(minPower));
        // for(auto& [num, _] : minPower) cout<<num<<" "; cout<<endl;

        int minRequiredPower = 0;
        int extraPower = 0;

        for(auto& [_, index] : minPower) {
            for(int& armor : monsters[index]) {
                armor -= extraPower;
                minRequiredPower = max(armor + 1, minRequiredPower);
                extraPower++;
                // cout<<armor<<" for "<<index<<endl;
            }
            // cout<<minRequiredPower<<" for "<<index<<endl;
        }
        cout<<minRequiredPower<<endl;
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

