#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin() + 1, array.end()
#define input(array, size) for(auto& d : array)cin >> d;
#define print(array) for(int num : array) cout << num << " "; cout << endl;

void solve() {
    int size, color;
    cin >> size >> color;
    vector<int> colors(size);
    input(colors, size);
    vector<int> maxGaps(color + 1, 0), secondMaxGaps(color + 1, 0), lastAppeared(color + 1, -1);

    for (int i = 0; i < size; i++) {
        int c = colors[i];
        int distance = i - lastAppeared[c];
        lastAppeared[c] = i;

        if (distance > maxGaps[c]) {
            secondMaxGaps[c] = maxGaps[c];
            maxGaps[c] = distance;
        } else if (distance > secondMaxGaps[c]) {
            secondMaxGaps[c] = distance;
        }
    }

    for (int c = 1; c <= color; c++) {
        int finalDistance = size - lastAppeared[c];

        if (finalDistance > maxGaps[c]) {
            secondMaxGaps[c] = maxGaps[c];
            maxGaps[c] = finalDistance;
        } else if (finalDistance > secondMaxGaps[c]) {
            secondMaxGaps[c] = finalDistance;
        }
    }
    int ans = 1e9;
    int k = color;

    // print(maxGaps);
    // print(secondMaxGaps);

    for (int i = 1; i <= k; ++i) {
        ans = min(ans, max((maxGaps[i] + 1) / 2, secondMaxGaps[i]));
    }
    cout <<ans-1<< "\n";
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

// 2 3 
// 1 3 
// 0
// 6 4 3 
// 1 2 3 
// 1
// 6 5 4 4 5 6 
// 1 2 3 3 2 1 
// 2
// 6 4 3 4 
// 2 3 3 4 
// 2
// 1 
// 1 
// 0

