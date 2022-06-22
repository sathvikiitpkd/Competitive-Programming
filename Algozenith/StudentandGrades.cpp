
/*Description

There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A and B were merged.
The students of section B did not want to humiliate themselves, so they decided to sit with students having the same marks as them.
You are given the marks of students of section B in order of their entry in the class.
You have to tell whether the i-th student of section B can sit with a student with the same marks as him.
If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of students in sections A and B respectively.
The second line of each test case contains N space-separated integers A1, A2, …, AN - the grades of students of section A.
The third line of each test case contains M space-separated integers B1, B2, …, BM - the grades of students of section B.


Output Format

For each test case, print M strings on a new line. Print ‘YES’ if there is at least 1 person in the room with the same IQ. Otherwise, print ‘NO’. (without the quotes)
*/


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int,bool> m1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            m1[x] = 1;
        }
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (m1.count(x)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
                m1[x] = 1;
            }
        }

    }
    return 0;
}