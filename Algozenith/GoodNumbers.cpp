
/*Description

There are N students and ith student likes all numbers in the range [li ,ri ], both inclusive. A number is good if it is liked by at least K students.

You are even Q queries. Each query consists of two numbers L, R. You have to find how many numbers in the range [L,R] is good.


Input Format

The first line of input contains three integers, N, K (1 ≤ K ≤ N ≤ 1000000), and Q (1 ≤ Q ≤ 1000000).

The next N lines contain two integers li and ri (1 ≤ li ≤ ri≤ 1000000), describing that the i-th student likes all the numbers [li,ri].

The next Q lines contain L and R, (1 ≤ L ≤ R ≤ 1000000).


Output Format

For each query print how many numbers in the range [L,R] is good in a new line.


*/





#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"

int main()
{
    IOS
    ll n,q,k,x,l,r,count = 0;
    cin >> n >> k >> q;
    int p[n+1];
    for(ll i=0;i<=n;i++)
    {
        p[i] = 0;
    }
    x = n;
    while(x--)
    {
        cin >> l >> r;
        p[l]++;
        p[r+1]--;
    }
    for(ll i =1;i<=n;i++)
    {
        p[i] = p[i-1] + p[i];
    }
    for(int i=1;i<=n;i++)
    {
      if(p[i]>=k)
      {
        p[i] = 1;
      }
      else{
        p[i] = 0;
      }
    }

    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        prefixSum[i] = prefixSum[i-1]+p[i];
    }

    while(q--)
    {
        cin >> l>>r;
        cout << prefixSum[r]-prefixSum[l-1] << endl;
    }  
    return 0;
}