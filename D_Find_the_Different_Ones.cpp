#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(int &num : array) cin>>num;

void solve() {
    int size;
    cin>>size;
    vector<int> nums(size);

    input(nums);
    vector<int> uniques(size);
    set<int> uniqueNumbers;

    for(int i = 0; i < size; i++) {
        uniqueNumbers.insert(nums[i]);
        uniques[i] = uniqueNumbers.size();
    }
    int queries;
    cin>>queries;
    while(queries--) {
        int l, r;
        cin>>l>>r;
        if(l == 0)
            cout<<uniques[r]<<endl;
        else
            cout<<uniques[r] - uniques[l-1]<<endl;
    }
    cout<<endl;

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
