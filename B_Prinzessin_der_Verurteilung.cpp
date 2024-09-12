#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

void solve() {
    int size;
    cin>>size;

    char prev = '#', doublePrev = '#';
    string st;
    cin>>st;
    
    unordered_set<string> exists;

    for(char& ch : st) {
        string curr = "";
        curr += ch;
        exists.insert(curr);
        if(prev != '#') {
            curr = prev + curr;
            exists.insert(curr);
        }
        if(doublePrev != '#') {
            curr = doublePrev + curr;
            exists.insert(curr);
        }
        doublePrev = prev;
        prev = ch;
    }

    for(int i = 0; i < 26; i++) {
        string curr = "";
        curr += i + 'a';
        if(exists.find(curr) == exists.end()) {
            cout<<curr<<endl;
            return;
        }
    }

    for(int i = 0; i < 26; i++) {
        string curr = "";
        curr += i + 'a';
        for(char ch = 'a'; ch <= 'z'; ch++) {
            curr.push_back(ch);
            if(exists.find(curr) == exists.end()) {
                cout<<curr<<endl;
                return;
            }
            curr.pop_back();  
        }
    }

    for(char ch = 'a'; ch <= 'z'; ch++) {
        string curr = "";
        curr.push_back(ch);
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            curr.push_back(ch1);
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                curr.push_back(ch2);
                if(exists.find(curr) == exists.end()) {
                cout<<curr<<endl;
                return;
                }
                curr.pop_back();  
            }
            curr.pop_back(); 
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
