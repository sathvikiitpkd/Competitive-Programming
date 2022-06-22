/*
Description

Implement a stack that supports the following operations.

push x -- Push element x onto stack.
pop -- Remove the element on top of the stack, if the stack is non-empty. Otherwise do nothing.
top -- Print the top element, if the stack is non-empty. Otherwise, print -1.
getMin -- Print the minimum element in the stack, if the stack is non-empty. Otherwise, print -1.
Initially, the stack is empty.


Input Format

The first line of input contains Q - the number of queries.
Each of next line contains input in one of the four formats mentioned in the problem statement.


Output Format

Print the answer for the top and getMin operations.


Constraints

1 ≤ Q ≤ 106
0 ≤ x ≤ 109
*/



#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class MinStack {
public:
	stack<int> st, minst;
    MinStack() {}

    void push(int x) {
        if(st.empty())
        {
            st.push(x);
            minst.push(x);
            return;
        }
        st.push(x);
        minst.push(min(minst.top(),x));
        return;
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
        minst.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(minst.empty()) return -1;
        return minst.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}
