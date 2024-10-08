#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class LinkedList {
    public:
    pair<int, int> data;
    LinkedList* next;

    LinkedList(int value, int freq) {
        data = {value, freq};
        next = NULL;
    }
};
class Solution {
    public:
    void solve() {
        int size;
        cin >> size;
        vector<int> nums(size);
        input(nums);
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        LinkedList* head = new LinkedList(0, 0);
        LinkedList* temp = head;

        for(auto& [element, frequency] : freq) {
            LinkedList* newNode = new LinkedList(element, frequency);
            temp->next = newNode;
            temp = temp->next;        
        }

        head = head->next;
        while(head) {
            cout<<"("<<head->data.first<<" , "<<head->data.second<<")";
            if(head ->next)
                cout<<" -> ";
            head = head->next;
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

