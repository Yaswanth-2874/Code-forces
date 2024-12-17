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
        int n, k;
        cin >> n >> k;

        string given, pattern;
        cin >> given >> pattern;
        
        int diff = n - k;
        if(diff < 0)
            no;
        if(diff % 2 != 0)
            no;
        // I can never delete first or the last character
        if(given[n-1] != pattern[k-1] || given[0] != pattern[0])
            no;
        int left1 = 0, left2 = 0;
        int lastA = -1, lastB = -1;
        
        while(left1 < n && left2 < k) {
            int unmatched = 0;
            if(pattern[left2] == 'A')
                lastA = left2;
            if(pattern[left2] == 'B')
                lastB = left2;

            while(left1 < n && given[left1] != pattern[left2]) {
                left1++;
                unmatched++;
            }
            if(left1 == n || unmatched % 2 != 0)
                no;
            if(given[left1] == pattern[left2]) {
                left1++;
                left2++;
            }
        }
        int remaining = n - left1;
        // cout<<remaining;
        if(left1 == n)
            yes;
        if(remaining % 2 != 0)
            no;
        char first = given[left1];
        for(int i = left1; i < n; i++) {
            if(given[i] != first)
                no;
        }
        if(first == 'A') {
            if(lastB == -1)
                no;
            int extra = k - (lastB + 1);
            // cout<<extra;
            if(extra < 1)
                no;
            yes;
        }
        if(lastA == -1)
            no;
        int extra = k - (lastB + 1);
            cout<<extra;
        if(extra < 1)
            no;
        yes;
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
