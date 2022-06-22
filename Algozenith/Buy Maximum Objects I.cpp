/*
Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy?


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of objects, and M, the money you have.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the maximum objects that you can buy.


Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108
Sum of N over all test cases ≤ 5 * 105.
*/




#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

signed main() {
    IOS
    int t,x,n,m;
    cin >> t;
    while (t--) 
    {
        cin >> n>> m;
        vector <int> mt(n,0);
        for(int i =0;i<n;i++)
        {
            cin >> x;
            mt[i] = x;
        }
        sort(mt.begin(), mt.end());
        // for(int i=0;i<n;i++)
        // {
        //     cout << mt[i] << " ";
        // }
        for(int i =1;i<n;i++)
        {
            mt[i] = mt[i]+mt[i-1];
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout << mt[i] << " ";
        // }
        int ans = upper_bound(mt.begin(),mt.end(),m) - mt.begin();
        cout << ans << endl;
    }
    return 0;
}
