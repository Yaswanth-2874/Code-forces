#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;


int binarySearch(vector<int>& maxHeights, int targetHeight) {
    int left = 0, right = maxHeights.size() - 1;

    while(left <= right) {
        int mid = left + (right - left)/2;
        if(maxHeights[mid] <= targetHeight)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
void solve() {
    int size, queries;
    cin>>size>>queries;

    vector<int> steps(size), maxHeight(size);
    int height = 0;
    for(int i = 0; i < size; i++) {
        cin>>steps[i];
        height = max(height, steps[i]);
        maxHeight[i] = height;
        if(i != 0)
            steps[i] += steps[i-1];
    }
    // print(steps);
    while(queries--) {
        int query;
        cin>>query;
        int pivot = binarySearch(maxHeight, query);
        if(pivot == -1)
            cout<<0<<" ";
        else
        cout<<steps[pivot]<<" ";
    }
    cout<<endl;
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
