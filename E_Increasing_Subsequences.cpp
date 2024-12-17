#include <bits/stdc++.h>
using namespace std;

// Old unsolved question

int log2(int num) {
    int count = 0;
    while(num) {
        num /= 2;
        count++;
    }
    return count;
}
void solve() {
    long long num, remaining;
    cin>>num;
    int logValue = log2(num);
    long long powerVal = 1ll << logValue;
    remaining = num - powerVal;
    vector<int> arr;
    for(int i = 1; i <= logValue; i++) {
        arr.push_back(i);
    }
    long long check = 1ll << 62ll;
    for(int i = 63; i >= 0; i--) {
        if(remaining & check)
            arr.push_back(i);
        check >>= 1;
    }
    if(arr.size() > 200)
        cout<<-1;
    else {
        cout<<arr.size()<<endl;
        for(int num : arr) {
            cout<<num<<" ";
        }
    }
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--) {
        solve();
    }

    return 0;
}