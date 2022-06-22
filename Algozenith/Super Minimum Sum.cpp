/*
Description

You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a contiguous block of the original array's elements


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of integers in an array A.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the sum of the minimum of all subarrays of A.


Constraints

1 ≤ T ≤ 100000
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 106
Sum of N over all test cases ≤ 5 * 105.
It is guaranteed that all elements in an array A are distinct.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int inf = 1e9;
int main()
{
    int t,i;
    IOS
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> arr(n+2,0);
        for(int i = 1;i<=n;i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }
        arr[0] = -inf;
        arr[n+1] = -inf;
        stack <int> st;
        vector <int> v1(n+2,0),v2(n+2,0);
        st.push(0);
        for(i = 1;i<=n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                v1[i] = st.top();
                st.push(i);
            }
        }
        while(!st.empty())
        {
            st.pop();
        }
        st.push(n+1);
        for(i = n;i>0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                v2[i] = st.top();
                st.push(i);
            }
        }
        ll ans = 0;
        for(int i =1;i<=n;i++)
        {
            ans += 1LL * arr[i] * (i-v1[i]) * (v2[i] - i);
        }
        cout << ans << endl;
    }
    return 0;
}
