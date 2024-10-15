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

class Solution {
    public:
    void solve() {
        int families, rows;
        cin >> families >> rows;
        vector<int> familySize(families);
        input(familySize);
        int totalMembers = accumulate(all(familySize), 0);
        int emptyRows = (rows * 2 - totalMembers);
        int minAns = 0;
        int usedRows = 0;
        for(int& size : familySize) {
            // cout<<size/2<<endl;
            minAns += (size/2) * 2;
            usedRows += (size/2);
            size = size%2;
        }
        int remainingRows = rows - usedRows;
        // cout<<remainingRows<<endl;
        int remainingPeople = accumulate(all(familySize), 0);
        // print(familySize);
        if(remainingRows >= remainingPeople)
            pn(minAns + remainingPeople);
        remainingPeople -= remainingRows;
        minAns += remainingRows - remainingPeople;
        
        cout<<minAns<<endl;
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

