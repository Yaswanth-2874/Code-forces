#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define all(array) array.begin(), array.end()
#define input(array)      \
    for (auto &d : array) \
        cin >> d;
#define print(array)        \
    for (auto &num : array) \
        cout << num << " "; \
    cout << endl;
#define pn(num)              \
    {                        \
        cout << num << endl; \
        return;              \
    }
#define minHeap(var) var, vector<var>, greater<var>

// if there is one L R, then it becomes disconnected;
// apply breaks position

class Solution
{
    void deal(int i, set<pair<int, int>> &intervals, set<int> &breaks)
    {
        // connection breaks at L R, it breaks after point L and before R
        // So break point in 1 based index should be position of r
        int point = i;
        // I will insert point only if it breaks some connection
        auto it = intervals.lower_bound({point, -1});
        // if (it == intervals.end())
        //     return; (This is where the mistake most likely is)

        if (it != intervals.end() && point == it->first)
        {
            breaks.insert(i);
            // cout << i << " interupts " << it->first << " & " << it->second << endl;
            return;
        }
        

        if (it != intervals.begin()) {
            auto it2 = prev(it);
            if(it2->first <= point && it2->second >= point)
                breaks.insert(i);
        }
        // cout << i << " interupts " << it2->first << " & " << it2->second << endl;
    }

public:
    void solve()
    {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        input(nums);
        string s;
        cin >> s;

        set<pair<int, int>> intervals;

        for (int i = 1; i <= n; i++)
        {
            int target = nums[i - 1];
            if (i == target)
                continue;
            int mini = min(i, target);
            int maxi = max(i, target);
            intervals.insert({mini, maxi});
        }
        set<int> breaks;

        char prev = '#';
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == 'R' && prev == 'L')
            {
                deal(i, intervals, breaks);
            }
            prev = ch;
        }

        while (q--)
        {
            int index;
            cin >> index;
            index--;

            if (s[index] == 'L')
            {
                // i NEED TO PASS INDEX OF R PROPERLY
                int prevIndex = index - 1;
                s[index] = 'R';
                if (s[prevIndex] == 'L')
                    deal(index, intervals, breaks);
                int nextIndex = index + 1;
                if (s[nextIndex] == 'R')
                {
                    breaks.erase(nextIndex);
                    // cout << nextIndex << " no longer interupts " << endl;
                }
            }
            else
            {
                int prevIndex = index - 1;
                s[index] = 'L';
                if (s[prevIndex] == 'L')
                {
                    breaks.erase(index);
                    // cout << index << " no longer interupts " << endl;
                }
                int nextIndex = index + 1;
                if (s[nextIndex] == 'R')
                    deal(index + 1, intervals, breaks);
            }
            if (breaks.size())
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}; 

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solution obj;
        obj.solve();
    }
    return 0;
}
