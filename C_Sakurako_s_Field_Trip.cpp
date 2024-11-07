// #include <bits/stdc++.h>
// using namespace std;

// #define MOD 1000000007
// #define int long long
// #define yes {cout<<"YES\n"; return;}
// #define no {cout<<"NO\n"; return;}
// #define all(array) array.begin(), array.end()
// #define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
// #define pn(num){cout<<num<<endl; return;}
// #define minHeap(var) var, vector<var>, greater<var>

// class Solution {
//     public:
//     void solve() {
//         int n;
//         cin >> n;
//         vector<int> nums(n);
//         input(nums);
//         int ans = 0;
        

//         for(int i = 0; i < n; i++) {
//             int noSwap = 0;
//             int j = n - i - 1;

//             if(i >= 1 && nums[i] == nums[i-1])
//                 noSwap++;
//             if(i < n-1 && nums[i] == nums[i+1])
//                 noSwap++;
//             if(j >= 1 && nums[j] == nums[j-1])
//                 noSwap++;
//             if(j < n-1 && nums[j] == nums[j+1])
//                 noSwap++;
            
//             swap(nums[i], nums[j]);
//             int swapi= 0;
//             if(i >= 1 && nums[i] == nums[i-1])
//                 swapi++;
//             if(i < n-1 && nums[i] == nums[i+1])
//                 swapi++;
//             if(j >= 1 && nums[j] == nums[j-1])
//                 swapi++;
//             if(j < n-1 && nums[j] == nums[j+1])
//                 swapi++;

//             if(swapi >= noSwap) {
//                 swap(nums[i], nums[j]);
//             }
//         }

//         int prev = -1;
//         print(nums);

//         for(int num : nums ) {
//             if(num == prev)
//                 ans++;
//             prev = num;
//         }
    
//         cout<<ans<<endl;
        
//     }
// };

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     cin >> t;
//     while (t--) {
//         Solution obj;
//         obj.solve();
//     }
//     return 0; 
// }

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        
        if(n%2 == 1){
            int i=n/2-1;
            int j=n/2+1;
            int cnt = 0;
            while(i > 0 && j < n-1){
                    if(v[i-1] == v[i] && v[j+1] != v[i]){
                        swap(v[j+1], v[i-1]);
                    }
                    else if(v[j+1] == v[j] && v[i-1] != v[j]){
                        swap(v[i-1], v[j+1]);
                    }
                    i--;
                    j++;
            }
            
            for(int i=0; i<n-1; i++){
                if(v[i] == v[i+1]) cnt++;
            }
            cout<<cnt<<endl;
        }
        else{
            int i = n/2-1;
            int j = n/2;
            int cnt  =0;
            while(i > 0 && j < n-1){
                    if(v[i-1] == v[i] && v[j+1] != v[i]){
                        swap(v[j+1], v[i-1]);
                    }
                    else if(v[j+1] == v[j] && v[i-1] != v[j]){
                        swap(v[i-1], v[j+1]);
                    }
                    i--;
                    j++;
            }
            
            for(int i=0; i<n-1; i++){
                if(v[i] == v[i+1]) cnt++;
            }
            print(v);
            cout<<cnt<<endl;
        }
    }
    
    return 0;
}

