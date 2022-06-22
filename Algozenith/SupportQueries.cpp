/*
Description

Design a Data Structure which can support the following queries:

1 x: Add x in structure
2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.
3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.

Initially, the structure is empty.


Input Format

The first line of input contains Q - the number of queries.
Next, Q lines contain queries of the format specified in the statement.


Output Format

For queries of type 3, 4 and 5, print the answer in a new line.


Constraints

1 ≤ Q ≤ 105
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
    int maximum = neginf;
    int minimum = inf;
    int sum = 0;
    int num = 0;
    multiset <int> mt;
    void insert(int x)
    {
        minimum = min(minimum,x);
        maximum = max(maximum,x);
        mt.insert(x);
        sum +=x;
        num++;
    }
    void remove(int x)
    {
       // cout << "BULL SHIT...\n";
        if(mt.find(x) != mt.end())
        {
            if(x == *mt.begin())
            {
                minimum= *prev(mt.begin(),-1);
            }
            else if(x == *mt.rbegin())
            {
                maximum= *prev(mt.rbegin(),1);
            }
            mt.erase(mt.find(x));
            num--;
            sum = sum -x;
        }
    }
    int getsum()
    {
        return sum;
    }
    int getmax()
    {
        return *mt.rbegin();
    }
    int getmin()
    {
        return *mt.begin();
    }
    int knowsize()
    {
        return num;
    }
};

signed main() {
    IOS
    int t,x,y;
    char c;
    cin >> t;
    data b;
    while(t--)
    {
        cin >> x;
        if(x == 3 || x==4 || x==5)
        {
            cin >> c;
            if(x==3)
            {
                if(b.knowsize() != 0)
                {
                    cout << b.getmin() << endl;
                }
                else
                {
                    cout << "-1\n";
                }
            }
            else if(x==4)
            {
                if(b.knowsize() != 0)
                {
                    cout << b.getmax() << endl;
                }
                else
                {
                    cout << "-1\n";
                }
            }
            else if(x==5)
            {
                if(b.knowsize() != 0)
                {
                    cout << b.getsum() << endl;
                }
                else
                {
                    cout << "0\n";
                }
            }
        }
        else if(x==1 || x==2)
        {
            cin >> y;
            if(x==1)
            {
                b.insert(y);
            }
            else if(x==2)
            {
                b.remove(y);
            }
        }
    }
    return 0;
}
