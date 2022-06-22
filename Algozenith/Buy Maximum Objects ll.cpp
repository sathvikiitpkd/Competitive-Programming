/*
Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have been asked Q queries. In each query, you have been given total money M, and find the maximum number of objects that you can buy.


Input Format

The first line of each test case contains N, the number of objects, and Q, total queries.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.
Next, Q lines contain a number M, the total money.


Output Format

For each query, print a single number in a new line representing the maximum objects that you can buy.


Constraints

1 ≤ N, Q ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108
*/



#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

signed main() {
    IOS
    int x,n,m,q;
    cin >> n >> q;
    vector <int> mt(n,0);
        for(int i =0;i<n;i++)
        {
            cin >> x;
            mt[i] = x;
        }
        sort(mt.begin(), mt.end());
        for(int i =1;i<n;i++)
        {
            mt[i] = mt[i]+mt[i-1];
        }
        while(q--)
        {
            cin >> x;
            int ans = upper_bound(mt.begin(),mt.end(),x) - mt.begin();
        	cout << ans << endl;
        }
    return 0;
}
