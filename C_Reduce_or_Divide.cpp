#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"ALICE\n"; return;}
#define no {cout<<"BOB\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

class Solution {
    void findWinner(int num, bool bobTurn) {
        if(num % 2 == 1) {
            if(bobTurn)
                no;
            yes;
        }
        for(int i = 3; i*i < num; i+=2) {
            if(num % i == 0 && (num/i)%2 == 0)
                return findWinner(num/i, !bobTurn);
        }
        // NOTHING CAN DIVIDE IT INTO AN EVEN NUMBER
        if(bobTurn)
            yes;
        no;
    }

    public:
    void solve() {
        int n;
        cin >> n;
        int myNum = 0;
        string st;
        cin >> st;

        for(int i = 0; i < n; i++) {
            if(st[i] == '1')
                myNum += 1LL<<i;
        }
        findWinner(myNum, true);
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

