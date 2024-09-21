#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n, m, q;
        cin>>n>>m>>q;

        vector<int> teacherPos(2);
        input(teacherPos);

        int davidPos;
        cin>>davidPos;

        sort(full(teacherPos));

        if(davidPos > teacherPos[1]) {
            int distance = n - teacherPos[1] ;
            cout<<distance<<endl;
            return;
        }
        if(davidPos < teacherPos[0]) {
            int distance = teacherPos[0] - 1;
            cout<<distance<<endl;
            return;
        }

        int leftDistance = davidPos - teacherPos[0];
        int rightDistance = teacherPos[1] - davidPos;

        if(leftDistance == rightDistance) {
            cout<<leftDistance<<endl;
            return;
        }

        if(leftDistance > rightDistance)
            swap(leftDistance, rightDistance);

        int changes = rightDistance - leftDistance;
        int moves = (changes + 1) / 2;
        rightDistance -= moves * 2;
        cout<<moves + min(leftDistance, rightDistance)<<endl;
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}
