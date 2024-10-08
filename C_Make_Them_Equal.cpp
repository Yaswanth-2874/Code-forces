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


// ASHAMED OF SUBMITTING SUCH A SHITTY SOLUTION 
class Solution {
    public:
    void solve() {
        int size;
        char target;
        cin >> size >> target;
        string original;
        cin >> original;

        set<int> unequal ;
        int index = 1;
        int lastSeen = -1;

        for(auto& letter : original) {
            if(letter != target) {
                unequal.insert(index);
            } else {
                lastSeen = index;
            }
            index++;
        }

        if(unequal.empty()) 
            pn(0);

        char lastCharacter = original[size - 1];
        if(lastCharacter == target) {
            cout<<1<<endl;
            pn(size);
        }
        if(lastSeen == -1) {
            cout<<2<<endl;
            cout<<size - 1<<" "<<(size)<<endl;

            return;
        }
        int nextSeen = *unequal.lower_bound(lastSeen);
        if(nextSeen == size) {
            cout<<1<<endl;
            pn(size - 1);
        }
        int factors = 0;
        auto it = unequal.lower_bound(lastSeen);
        while(it != unequal.end()) {
            if(*it % lastSeen == 0)
                factors++;
            it++;
        }
        if(factors == 0) {
            cout<<1<<endl;
            pn(lastSeen);
        }
        cout<<2<<endl;
        cout<<size - 1<<" "<<(size)<<endl;

        // IF LAST CHARACTER IS NOT EQUAL TO TARGET, ANS COULD EITHER BE 1 OR 2
        // THINK OF CASES WHERE ANSWER WOULD BE ONE AND WHERE IT WOULD BE TWO
        // FIND LAST EQUAL INDEX
        // IF THE LAST EQUAL INDEX DOESNT HAVE LAST NUMBER AS MULTIPLE, THEN IT COULD BE THE ANSWER

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

