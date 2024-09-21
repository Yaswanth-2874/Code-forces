#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    string generatePassword(int n) {
        string password = "";
        int queries = 2*n;
        unordered_set<string> badStrings;
        bool addFront = true;

        while(true) {
            if(password.size() == n)
                return password;
            if(addFront) {
            password.push_back('1');
            cout<<"? "<<password<<endl;
            int response;
            cin >> response;
            cout.flush();
            if(response == 1) {
                continue;
            }
            
            password.pop_back();
            password.push_back('0');
            cout<<"? "<<password<<endl;
            cin >> response;
            
            cout.flush();
            if(response == 1) {
                continue;
            }
            password.pop_back();
            addFront = false;

            }
            else {
            password = "1" + password;
            int response;
            cout<<"? "<<password<<endl;
            cin >> response;
            cout.flush();
            if(response == 1) {
                continue;
            }
            password = password.substr(1);
            password = "0" + password;
            }
        }
        return password;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        string res = generatePassword(n);
        cout<<"! "<<res<<endl;
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

