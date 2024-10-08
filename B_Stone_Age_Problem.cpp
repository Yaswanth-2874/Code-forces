#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n, q;
        cin >> n >> q;
        map<int, int> values;
        int sum = 0;
        int commonValue = -1;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            sum += num;
            values[i] = num;
        }

        while(q--) {
            int choice;
            cin >> choice;
            if(choice == 1) {
                int index, val;
                cin >> index >> val;
                index--;

                if(values.find(index) != values.end()) {
                    sum -= values[index];
                } else 
                    sum -= commonValue;
                values[index] = val;
                sum += val;
                cout<<sum<<endl;
            } else {
                cin >> commonValue;
                sum = commonValue * n;
                values.clear();
                cout<<sum<<endl;
            }
        }

    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

