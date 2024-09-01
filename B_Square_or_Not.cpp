#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin>>n;
    string nums;
    cin>>nums;
    int zeroes = 0;
    int size = sqrt(n);
    if(size != sqrt(n)) {
        cout<<"No"<<endl;
        return;
    }
    for(char ch : nums)
        zeroes += ch == '0';

    int targetZeroes = max(0, size-2);
    targetZeroes *= targetZeroes;
   
    if(targetZeroes == zeroes)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
