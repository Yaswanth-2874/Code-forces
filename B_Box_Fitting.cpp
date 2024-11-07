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
#define exists(map, num) map.find(num) != map.end() 

// would greedily filling each row work? it should work right?? Think of edge cases
// Seems like it works, hope no WA

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        input(v);

        map<int, int> freq;
        for(int& num : v) {
            freq[num]++;
        }

        int rows = 0;

        while(!freq.empty()) {
            int gap = k;
            rows++;

            for(auto it = freq.rbegin(); it != freq.rend();) {
                auto& [num, frequ] = *it;
                if(num == 0)
                    break;
                
                while(gap >= num && frequ) {
                    int maxInsertions = min(gap/num, frequ);
                    gap -= (maxInsertions * num);
                    frequ -= maxInsertions;
                }

                it++;
                if(frequ == 0) {
                    freq.erase(num);
                }
                 if(gap == 0)
                    break;
            }
        }
        cout<<rows<<endl;
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

