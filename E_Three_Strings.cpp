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
    string a, b, c;
    vector<vector<int>> memo;
    int findMinMoves(int indexA, int indexB, int indexC) {
        if(indexA >= a.size()) {
            int changes = 0;
            for(int i = indexB; i < b.size(); i++) {
                if(c[indexC++] != b[i])
                    changes++;
            }
            return changes;
        }
        if(indexB >= b.size()) {
            int changes = 0;
            for(int i = indexA; i < a.size(); i++) {
                if(c[indexC++] != a[i])
                    changes++;
            }
            return changes;
        }
        if(memo[indexA][indexB] != -1)
            return memo[indexA][indexB];
        int st1 = findMinMoves(indexA+1, indexB, indexC+1) + (a[indexA] != c[indexC]);
        int st2 = findMinMoves(indexA, indexB+1, indexC+1) + (b[indexB] != c[indexC]);

        return memo[indexA][indexB] = min(st1, st2);
    }
    public:
    void solve() {
        cin >> a >> b >> c;
        int aSize = a.size();
        int bSize = b.size();

        memo = vector<vector<int>> (aSize+1, vector<int> (bSize+1, -1));
        cout<<findMinMoves(0, 0, 0)<<endl;
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
