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
    int totalSheep;
    int findMoves(string& st, int midSheep, set<int> sheepPos) {
        int moves = 0;
        int placedSheep = 1;
        sheepPos.erase(midSheep);

        for(int i = midSheep + 1; i < st.size(); i++) {
            auto nextPos = sheepPos.lower_bound(i);
            if(nextPos == sheepPos.end())
                break;
            moves += *nextPos - i;
            placedSheep++;
            sheepPos.erase(nextPos);
        }

        for(int i = midSheep - 1; i >= 0; i--) {
            if(placedSheep == totalSheep)
                break;
            auto prevPos = sheepPos.lower_bound(i);
            if(prevPos == sheepPos.end()) {
                prevPos = prev(prevPos);
                moves += i - *prevPos;
            }
            placedSheep++;
            sheepPos.erase(prevPos);
        }

        return moves;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        string st;
        cin >> st;

        set<int> sheepPos;
        for(int i = 0; i < n; i++) {
            if(st[i] == '*')
                sheepPos.insert(i);
        }

        totalSheep = sheepPos.size();
        
        if(totalSheep == 0 || totalSheep == 1 || totalSheep == n)
            pn(0);

        int ans = LLONG_MAX;
        int currentSheep = 0;

        for(int i = 0; i < n; i++) {
            if(st[i] == '*')
                currentSheep++;
            
            if(((totalSheep + 1) / 2 == currentSheep || (totalSheep % 2 == 0 && totalSheep/2 + 1 == currentSheep)) && st[i] == '*') {
                ans = min(ans, findMoves(st, i, sheepPos));
            }
        }
        pn(ans);
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
