//判断表达式中的括号是否匹配
#include <iostream>
#include <stack>
using namespace std;

bool exam(string s);

int main() {
    cout << exam("((((([{[]}])))))");
}

bool exam(string str) {
    stack<char> s;
    //s只存储[, (, {
    for (auto& elem : str) {
        switch (elem) {
            case '(':
            case '[':
            case '{':
                s.push(elem);
                break;
            case ')':
                if (s.empty() || s.top() != '(')
                    return false;
                s.pop();
                break;
            case ']':
                if (s.empty() || s.top() != '[')
                    return false;
                s.pop();
                break;
            case '}':
                if (s.empty() || s.top() != '{')
                    return false;
                s.pop();
                break;
            default:
                break;
        }
    }
    return s.empty();
}
