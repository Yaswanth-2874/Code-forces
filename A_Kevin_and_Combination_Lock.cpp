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
    // bool memo(string s) {
    //     int num = stoi(s);
    //     int n  = s.size();
    //     if(num % 33 == 0)
    //         return true;
    //     bool pick = false;
    //     string curr = "";

    //     for(int i = 1; i < n; i++) {
    //         if(s[i] == s[i-1] && s[i] == '3') {
    //             curr.pop_back();
    //             pick = pick | memo(curr+s.substr(i+1));
    //             curr.push_back('3');
    //         }
    //         curr.push_back(s[i]);
    //     }
    //     return false;
    // }
    public:
    void solve() {
        int n;
        cin >> n;

        if(n % 33 == 0)
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
