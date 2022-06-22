/*
Description

Design a Data Structure which can support the following queries:

Initially, the structure is empty. You have given an integer K. 

The structure is arranged in the order from greater elements to smaller elements. So when we say top K elements, we mean the top K largest elements.

1 x: Add x in structure.

2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.

3 ?: Print the sum of the top K elements. If the structure contains less than K elements, then print the sum of all elements present in the structure. If the structure is empty, then print 0.


Input Format

The first line of input contains Q and K - the number of queries.
Next, Q lines contain queries of the format specified in the statement. 


Output Format

For queries of type 3, print the answer in a new line.


Constraints

1 ≤ Q, K ≤ 105
0 ≤ x ≤ 109

*/




#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
int inf = 1e9;
int mod = 1e9 + 7;
int neginf = -1e9;

struct data
{
    int sum = 0;
    multiset <int> mt,mr;
    void insert(int x,int k)
    {
        mt.insert(x);
        sum +=x;
        if(mt.size() > k)
        {
            sum =sum - *mt.begin();
            mr.insert(*mt.begin());
            mt.erase(mt.find(*mt.begin()));
        }
    }
    void remove(int x,int k)
    {
       // cout << "BULL SHIT...\n";
        if(mt.find(x) != mt.end())
        {
            mt.erase(mt.find(x));
            sum = sum -x;
            // cout << "BULL SHIT....\n";
        }
        else if(mr.find(x) != mr.end())
        {
            mr.erase(mr.find(x));
        }
        if(mt.size() < k)
        {
            if(!mr.empty())
            {
                mt.insert(*mr.rbegin());
                sum = sum + *mr.rbegin();
                mr.erase(mr.find(*mr.rbegin()));
            }
        }
    }
    void print()
    {
        cout << sum << endl;
    }
};

signed main() {
    IOS
    int t,x,y,k;
    char c;
    cin >> t>>k;
    data b;
    while(t--)
    {
        cin >> x;
        if(x == 3)
        {
            cin >> c;
            if(x==3)
            {
                b.print();
            }
        }
        else if(x==1 || x==2)
        {
            cin >> y;
            if(x==1)
            {
                b.insert(y,k);
            }
            else if(x==2)
            {
                b.remove(y,k);
            }
        }
    }
    return 0;
}
