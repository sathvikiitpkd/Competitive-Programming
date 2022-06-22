/*
Description

You have given an array A of size N and a positive integer K (≤ N). A1, A2, ..., AN are the elements of the array.
Let Bi = max (Ai, Ai+1, ..., Ai+K-1), for 1 ≤ i ≤ N - K + 1. 
Find Bi values for all is such that 1 ≤ i ≤ N - K + 1.


Input Format

The first line contains T, the number of test cases. 
The first line of each test case contains N, the number of integers in an array A and K.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print array B as B1 B2 ... BN-K+1 in a new line.


Constraints

1 ≤ T ≤ 100000
1 ≤ K ≤ N ≤ 100000
-109 ≤ Ai ≤ 109
Sum of N over all test cases ≤ 5 * 105.
*/

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) 
    {
        int n,k;
        cin >> n>>k;
        int A[n];
        for(int i =0;i<n;i++)
        {
            cin >> A[i];
        }
        multiset <int> M;
        for(int i =0;i<k;i++)
        {
            M.insert(A[i]);
        }
        for (int i = 0; i <= n - k; i++) 
        {
            cout << *(M.rbegin()) << " ";
            M.erase(M.find(A[i]));
            if(i+k <n)
            {
                M.insert(A[i+k]);
            }
        }
        cout << "\n";
    }
    return 0;
}