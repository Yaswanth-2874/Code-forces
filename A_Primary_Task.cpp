#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

string solve() {
    string num;
    cin>>num;
    int size = num.size();
    if(size <= 2)
        return "NO";

    if(num[0] == '1' && num[1] == '0') {
        if(num[2] >= '2')
            return "YES";
        if(num[2] == '1' && size >= 4)
            return "YES";
        return "NO";
    }

    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
    return 0;
}
