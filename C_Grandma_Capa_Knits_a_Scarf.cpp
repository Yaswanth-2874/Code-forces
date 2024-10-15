#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

class Solution {
    int n;
    string given;
    pair<bool, int> isPalindrome(char ch) {
        int left = 0, right = n - 1;
        int deleted = 0;
        
        while(left <= right) {
           if(given[left] != given[right]) {
            while(left < right && given[left] == ch) {
                left++;
                deleted++;
            }
            while(right > left && given[right] == ch) {
                right--;
                deleted++;
            }
            if(given[left] != given[right])
                return {false, 0};
           }
           left++;
           right--;
        }
        return {true, deleted};
    }

    public:
    void solve() {
        cin >> n;
        cin >> given;

        int minAnswer = LLONG_MAX;
        if(isPalindrome('A').first == true)
            pn(0);

        for(int i = 0; i < 26; i++) {
            auto [palindrome, deletedCharacters] = isPalindrome('a' + i);
            if(palindrome)
                minAnswer = min(minAnswer, deletedCharacters);
        }
        
        if(minAnswer == LLONG_MAX)
            pn(-1);
        pn(minAnswer);
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

