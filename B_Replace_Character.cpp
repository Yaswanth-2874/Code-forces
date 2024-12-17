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

vector<int> factorials;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string st;
        cin >> st;

        freqMap(char, st);
        if(freq.size() == 1)
            pn(st);
        int maxFreq = 0, minFreq = LLONG_MAX;
        char maxChar, minChar;

        for(auto& [ch, f] : freq) {
            if(maxFreq < f) {
                maxFreq = f;
                maxChar = ch;
            }
        }
        for(auto& [ch, f] : freq) {
            if(minFreq > f && ch != maxChar) {
                minFreq = f;
                minChar = ch;
            }
        }

        int val1 = factorials[maxFreq] * factorials[minFreq]; // performing no operation
        int val2 = factorials[minFreq - 1] * factorials[maxFreq + 1]; // performedOperation

        if(val1 >= val2)
            pn(val1);
        for(auto& ch : st) {
            if(ch == minChar) {
                ch = maxChar;
                break;
            }
        }
        pn(st);
    }
};

int32_t main() {
    factorials.push_back(1);
    int product = 1;
    for(int i = 1; i <= 10; i++) {
        product *= i;
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
