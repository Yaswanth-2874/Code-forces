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
        int n;
        cin >> n;

        array(int, v, n);
        set<int> zeroes, ones, twos;

        for(int i = 0; i < n; i++) {
            int& num = v[i];
            if(num == 0)
                zeroes.insert(i);
            else if(num == 1)
                ones.insert(i);
            else
                twos.insert(i);
        }

        int left = 0;
        int zeroSize = zeroes.size();
        int oneSize = ones.size();
        vector<pair<int, int>> ans;

        while(left < zeroSize) {
            if(v[left] == 0) {
                left++;
                continue;
            }

            if(v[left] == 2) {
                int nextOne = *ones.rbegin();
                ans.push_back({left+1, nextOne+1});
                swap(v[left], v[nextOne]);
                twos.erase(left);
                twos.insert(nextOne);
                ones.erase(nextOne);
                ones.insert(left);
            }

            if(v[left] == 1) {
                int nextZero = *zeroes.rbegin();
                ans.push_back({left+1, nextZero + 1});
                swap(v[left], v[nextZero]);
                zeroes.erase(nextZero);
                zeroes.insert(left);
                ones.erase(left);
                ones.insert(nextZero);
            }

            left++;
        }
        // cout<<left<<endl;
        // print(v);

        while(left < zeroSize + oneSize) {
            if(v[left] == 1) {
                left++;
                continue;
            }

            int nextOne = *ones.rbegin();
            ans.push_back({left+1, nextOne+1});
            swap(v[left], v[nextOne]);
            twos.erase(left);
            twos.insert(nextOne);
            ones.erase(nextOne);
            ones.insert(left);
            left++;
        }
        // print(v);
        // if(ans.size() > n || !is_sorted(all(v)))
        //     no;
        // yes;

        cout<<ans.size()<<endl;
        if(!ans.empty()) {
            for(auto& [l, r] : ans)
                cout<<l<<" "<<r<<endl;
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
