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
    string xorV(string& st1, string& st2, int index) {
        string xorValue = "";
        // cout<<st1<<" "<<st2<<endl;
        int iV = 0;
        for(int i = index; i < index + st2.size(); i++) {
            int val1 = st1[i] - '0';
            int val2 = st2[iV++] - '0';
            // cout<<"Compare : "<<val1<<" "<<val2<<endl;
            int x = val1 ^ val2;
            if(x)
                xorValue.push_back('1');
            else
                xorValue.push_back('0');
        }
        return xorValue;
    }
    pair<string, bool> compare(string& s1, string& s2) {
        if(s2.size() > s1.size())
            return {s2, true};
        // cout<<"Compare : "<<s1<<" "<<s2<<endl;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] > s2[i])
                return {s1, false};
            if(s1[i] < s2[i])
                return {s2, true};
        }
        return {s1, false};
    }
    public:
    void solve() {
        string st;
        cin >> st;
        // since first digit is def one, one binary string is of full size, now check for other binary string
        cout<<1<<" "<<st.size()<<" ";
        int i = 1, n = st.size();
        for(i = 1; i < n; i++) {
            if(st[i] == '0')
                break;
        }
        if(i == n) {
            cout<<1<<" "<<1<<endl;
            return;
        }
        // definitely use one at i now
        // my optimal answer should be of size atleast k now, can go n^2
        int size = n - i;
        int index =  i;
        // cout<<index<<" is "<<endl;
        string optimal = "";
        int ansl = -1, ans2 = -1;

        for(int i = 0; i < n-size; i++) {
            string subst = st.substr(i, size);
            string xorValue = xorV(st, subst, index);
            
            // cout<<xorValue<<endl;
            // cout<<xorValue.size()<<endl;

            auto [best, update] = compare(optimal, xorValue);
            if(update) {
                optimal = best;
                ansl = i+1;
                ans2 = i+1 + size - 1;
            }
        }
        cout<<ansl<<" "<<ans2<<endl;

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
