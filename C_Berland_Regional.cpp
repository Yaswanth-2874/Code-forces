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

// 100% sure that i fixed the issue
// made the code slightly faster in worst case

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        array(int, v, n);
        map<int, vector<int>> bestMembers;
        int sum = 0;
        vector<int> ans(n , 0);

        for(int i = 0; i < n; i++) {
            int power;
            cin >> power;

            bestMembers[v[i]].push_back(power);
        }

        for(auto& [university, powerList] : bestMembers) {
            int rank = 1;
            int score = 0;

            sort(all(powerList), greater<int>());
            // cout<<"Power List of "<<university<<" : ";
            // print(powerList)
            vector<int> prefixSum(1, 0);
            int sum = 0;
            for(int i = 0; i < powerList.size(); i++) {
                sum += powerList[i];
                prefixSum.push_back(sum);
            }

            for(int i = 1; i <= n; i++) {
                int num = (powerList.size() / i * i);
                if(num <= 0)
                    break;
                ans[i - 1] += prefixSum[num];
            }
        }

        print(ans);
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
