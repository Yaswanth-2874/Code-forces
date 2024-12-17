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

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;

        int sum = 0;
        map<int, int> count;

        for(char& ch : st) {
            int num = ch - '0';
            if(num == 2 || num == 3) {
                count[num]++;
            }
            sum += num;
        }
        int mod = sum % 9;
        if(mod == 0)
            yes;
        int target;
        if(mod % 2 == 0) {
            target = 18 - mod;
        } else {
            target = 9 - mod;
        }
        // cout<<target;
        // cout<<count[3];
        while(target >= 6 && count[3]) {
            target -= 6;
            count[3]--;
        }

        while(target >= 2 && count[2]) {
            target -= 2;
            count[2]--;
        }
        if(target == 0)
            yes;
        no;
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
