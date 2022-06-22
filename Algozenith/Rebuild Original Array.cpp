/*
Description

Your class teacher wrote N integers on the board. One of your classmates was being mischievous, he replaced the N integers with all possible subset sums of the array when the teacher was not in the class. 
Suppose that the integers on the board were [2,1] then the subsets will be: {}, {2}, {1}, {2,1} and the subset sums will be: {0,2,1,3}. 
Your task is to rebuild the original array given by your teacher.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the number of elements in the initial array.
The second line of each test case contains 2N space-separated integers, the new values on the board.


Output Format

For each test case, print N space-separated integers in non-decreasing order.
It is guaranteed that a solution always exists.


Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 15
0 ≤ Ai ≤ 1015
*/



#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int inf = 1e9;

int main()
{
    ll t,j,n,x;
    IOS
    cin >> t;
    while(t--)
    {
        cin >> n;
        j = 1 << n;
        multiset <ll> arr;
        for(auto i=0;i<j;i++)
        {
            cin >> x;
            arr.insert(x);
        }
        vector <ll> orig;
        vector <ll> newgen;
        multiset <ll> generated;      
        generated.insert(0);
        arr.erase(0);   
        while(!arr.empty())
        {
            auto smallest = *arr.begin();
            orig.push_back(smallest);
            for(auto i : generated)
            {      
                newgen.push_back(i+smallest);
                arr.erase(arr.find(i+smallest));
            }
            for(auto i : newgen)
            {
                generated.insert(i);
            }
            newgen.clear();
        }
        
        for(auto i : orig)
        {
            cout << i << " ";
        }
        cout << endl;
    }
	return 0;
}
