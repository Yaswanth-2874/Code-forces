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
#pragma endregion

// I am ashamed to talk about the time i spent to implement this even though i knew the approach
// GONNA REWRITE THIS IN A BETTER WAY NEXT TIME

class Solution {
    int c;
    void deleteOneAddOne(vector<int>& cuts, vector<int>& v, int& start, int& totalGiven, int& last) {
        int end = cuts.back();
        cuts.pop_back();

        //Deleting one piece
        for(int i = start; i > end; i--) {
            totalGiven -= v[i];
        }
        start = end;

        // cout<<"After removing the piece, taste is "<<totalGiven<<endl;
        //Adding One piece
        int current = 0;
        
        for(int i = last; i >= 0; i--) {
            current += v[i];
            totalGiven += v[i];
            if(current >= c) {
                last = i - 1;
                break;
            }
        }

        // cout<<"After adding back the piece, taste is "<<totalGiven<<" and new last position is "<<last<<endl;
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m >> c;
        // m indicates the number of cuts that i could perform
        
        vector<int> v(n);
        input(v);

        int current = 0;
        int totalTaste = accumulate(all(v), 0ll);
        int pieces = 0;
        int left = 0;
        
        vector<int> cuts;
        cuts.push_back(-1);

        for(int i = 0; i < n; i++) {
            current += v[i];
            if(current >= c) {
                pieces++;
                cuts.push_back(i);
                left = i+1;
                current = 0;
            }
            if(pieces == m)
                break;
        }
        int alicePiece = 0;
        int firstCut = cuts[0];

        for(int i = left; i < n; i++)
            alicePiece += v[i];

        if(cuts.size() <= m)
            pn(-1);
        
        int totalGiven = totalTaste - alicePiece;
        int start = cuts.back(), end = n-1;
        cuts.pop_back();
        // cout<<"Total Given is "<<totalGiven<<endl;
        // print(cuts)

        while(cuts.size()) {
            deleteOneAddOne(cuts, v, start, totalGiven, end);
            alicePiece = max(alicePiece, totalTaste - totalGiven);
        }        

        alicePiece = max(alicePiece, totalTaste - totalGiven);
        pn(alicePiece)

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
