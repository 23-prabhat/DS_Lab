#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c=='^') return 3;
    if (c=='*'||c=='/') return 2;
    if (c=='+'||c=='-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string out="";
    for (char c : s) {
        if (isalnum(c)) out+=c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while(!st.empty() && st.top()!='('){ out+=st.top(); st.pop(); }
            st.pop();
        } else {
            while(!st.empty() && prec(st.top())>=prec(c)){ out+=st.top(); st.pop(); }
            st.push(c);
        }
    }
    while(!st.empty()){ out+=st.top(); st.pop(); }
    return out;
}

string postfixToInfix(string s) {
    stack<string> st;
    for (char c : s) {
        if (isalnum(c)) st.push(string(1,c));
        else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string t = "(" + a + string(1,c) + b + ")";
            st.push(t);
        }
    }
    return st.top();
}

int main() {
    string inf = "A+B*(C-D)";
    string post = infixToPostfix(inf);
    cout << post << endl;
    cout << postfixToInfix(post) << endl;
}



// python
// def prec(c):
//     if c == '^': return 3
//     if c in ('*','/'): return 2
//     if c in ('+','-'): return 1
//     return -1

// def infix_to_postfix(s):
//     st = []
//     out = ""
//     for c in s:
//         if c.isalnum():
//             out += c
//         elif c == '(':
//             st.append(c)
//         elif c == ')':
//             while st and st[-1] != '(':
//                 out += st.pop()
//             st.pop()
//         else:
//             while st and prec(st[-1]) >= prec(c):
//                 out += st.pop()
//             st.append(c)
//     while st:
//         out += st.pop()
//     return out

// def postfix_to_infix(s):
//     st = []
//     for c in s:
//         if c.isalnum():
//             st.append(c)
//         else:
//             b = st.pop()
//             a = st.pop()
//             st.append("(" + a + c + b + ")")
//     return st[-1]

// exp = "A+B*(C-D)"
// post = infix_to_postfix(exp)
// print(post)
// print(postfix_to_infix(post))
