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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

// 3 5 5 7
class Solution {
    int binarySearch(vector<int>& v, vector<int>& minEle, int l, int currentValue) {
        int left = 1, right = v.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int minValue = minEle[mid];

            if(minValue < currentValue) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> v(n), maxArrayIndex;
        int maxElement = 0, maxIndex = -1;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(maxElement < v[i]) {
                maxElement = v[i];
                maxIndex = i;
            }
            maxArrayIndex.push_back(maxIndex);
        }
        vector<int> minArray(n);
        int minEle = LLONG_MAX, minIndex = -1;

        for(int i = n-1; i >= 0; i--) {
            if(minEle > v[i]) {
                minEle = v[i];
                minIndex = i;
            }
            minArray[i] = minEle;
        }

        vector<int> ans(n, -1);
        for(int i = maxIndex; i < n; i++) {
            ans[i] = maxElement;
        }

        for(int i = maxIndex - 1; i >= 0; i--) {
            int bestIndex = maxArrayIndex[i];
            int value1 = v[bestIndex];
            int minFutureIndex = binarySearch(v, minArray, bestIndex, value1);
            int value2 = ans[minFutureIndex];

            ans[i] = max(value1, value2);
        }

        print(ans);
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
