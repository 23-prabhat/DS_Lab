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
