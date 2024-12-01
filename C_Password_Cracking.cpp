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

class Solution {
    public:
    void solve() {
        // Root is 1
        // Number of children that i need is leaves
        // Max diameter that i can get is 
        int n, d, l;
        cin >> n >> d >> l;

        int maxDiameter = n - (l - 2) - 1;
        int minHeight = (n-1 + l - 1)/l;
        int extraHeight = (n - 1) % l >= 2;

        int minDiameter = 2 * minHeight - 1 + extraHeight;
        if(n == 2) {
            if(d == 1 & l == 2) {
                cout<<1<<" "<<2<<endl;
            return;}
            pn(-1);
        }
        
        if(d < minDiameter || d > maxDiameter) {
            // cout<<minDiameter<<" "<<maxDiameter<<endl;
            pn(-1);
        }
        int nodeValue = 2;
        for(int i = 0; i < l; i++) {
            cout<<1<<" "<<nodeValue++<<endl;
        }
        // 2 and 3 will always be child of 1
        // first get desired height and fill the remaining children in remaining nodes
        int childrenOf2 = (d % 2) + d/2 - 1;
        // int childrenOf3 = d/2 - 1;
        int childrenOf3 = d - childrenOf2 - 1;
        // cout<<childrenOf2<<" "<<childrenOf3<<"is "<<endl;
        int parent = 2;

        while(childrenOf2-- > 0) {
            cout<<parent<<" "<<nodeValue<<endl;
            parent = nodeValue++;
        }
        parent = 3;
        while(childrenOf3-- > 0) {
            cout<<parent<<" "<<nodeValue<<endl;
            parent = nodeValue++;
        }

        int remainingNodes = n - (nodeValue - 1);
        queue<int> q;
        for(int i = 4; i <= l; i++)
            q.push(i);
        
        // cout<<"Main is done"<<endl;

        while(remainingNodes--) {
            int parent = q.front();
            q.pop();
            q.push(nodeValue);
            
            cout<<parent<<" "<<nodeValue++<<endl;
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
