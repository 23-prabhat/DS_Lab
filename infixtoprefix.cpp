#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    stack<char> st;
    string out="";
    for(char c:s){
        if(isalnum(c)) out+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){ out+=st.top(); st.pop(); }
            st.pop();
        } else{
            while(!st.empty()&&prec(st.top())>=prec(c)){ out+=st.top(); st.pop(); }
            st.push(c);
        }
    }
    while(!st.empty()){ out+=st.top(); st.pop(); }
    reverse(out.begin(), out.end());
    return out;
}

string prefixToInfix(string s){
    stack<string> st;
    reverse(s.begin(), s.end());
    for(char c:s){
        if(isalnum(c)) st.push(string(1,c));
        else{
            string a=st.top(); st.pop();
            string b=st.top(); st.pop();
            st.push("("+a+string(1,c)+b+")");
        }
    }
    return st.top();
}

int main(){
    string inf="(A-B/C)*(A/K-L)";
    string pre=infixToPrefix(inf);
    cout<<pre<<endl;
    cout<<prefixToInfix(pre)<<endl;
}




// python
// def prec(c):
//     if c == '^': return 3
//     if c in ('*','/'): return 2
//     if c in ('+','-'): return 1
//     return -1

// def infix_to_prefix(s):
//     s = s[::-1]
//     s = list(s)
//     for i in range(len(s)):
//         if s[i] == '(':
//             s[i] = ')'
//         elif s[i] == ')':
//             s[i] = '('
//     s = "".join(s)

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

//     return out[::-1]

// def prefix_to_infix(s):
//     st = []
//     s = s[::-1]
//     for c in s:
//         if c.isalnum():
//             st.append(c)
//         else:
//             a = st.pop()
//             b = st.pop()
//             st.append("(" + a + c + b + ")")
//     return st[-1]

// exp = "(A-B/C)*(A/K-L)"
// pre = infix_to_prefix(exp)
// print(pre)
// print(prefix_to_infix(pre))
