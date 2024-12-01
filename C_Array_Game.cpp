#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    int findBestPair(vector<int>& differences, int num) {
        // find the index where the sign changes, that could either be the minimum or the index before that could be minimum;

        int left = 0, right = differences.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int current = differences[mid] - num;
            if(current >= 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        int rightV = LLONG_MAX, leftV = LLONG_MAX;
        // Right pointer points at the last value in diff that is less than num

        if(right != -1)
            rightV = abs(num - differences[right]);
        if(right + 1 < differences.size())
            leftV = abs(num - differences[right + 1]);

        return min(leftV, rightV);
    }

    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        input(v);

        if(k > 2)
            pn(0);
        
        sort(all(v));
        int minDiff = LLONG_MAX;
        int ans = *min_element(all(v));

        for(int i = 1; i < n; i++) {
            minDiff = min(minDiff, abs(v[i] - v[i-1]));
        }

        ans = min(ans, minDiff);
        if(k == 1)
            pn(ans);
        
        vector<int> differences;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // cout<<"Difference of "<<(abs(v[j] - v[i]))<<" is inserted"<<endl;
                differences.push_back(abs(v[j] - v[i]));
            }
        }

        sort(all(differences));
        ans = *min_element(all(v));
        ans = min(ans, *min_element(all(differences)));
        
        for(int& num : v) {
            ans = min(ans, findBestPair(differences, num));
        }

        pn(ans);

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