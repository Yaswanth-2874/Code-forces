#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"safe\n"; return;}
#define no {cout<<"unsafe\n"; return;}
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
        string path;
        cin >> path;

        int leftEnd = 0;
        int rightEnd = path.size() - 1;
        vector<pair<int, int>> interval;

        for(int i = 0; i < rightEnd; i++) {
            if(path[i] == '.')
                continue;
            
            int num = path[i] - '0';
            int minIndex = max(i - num, 0ll);
            int maxIndex = min(i + num, rightEnd);

            interval.push_back({minIndex, maxIndex});
        }
        sort(all(interval));
        bool ans = true;

        for(int i = 0; i < (int)interval.size() - 1; i++) {
            auto [currLeft, currRight] = interval[i];
            auto [nextLeft, nextRight] = interval[i+1];

            if(currRight >= nextLeft) {
                int currentIntervalLength = currRight - currLeft;
                int nextIntLen = nextRight - nextLeft;

                if(currentIntervalLength != nextIntLen)
                    ans = false;
            }
        }

        if(ans)
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
