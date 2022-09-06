#include <assert.h>
#include <iostream>
#include <stack>


std::string bracketBalance(const std::string& string) {
    std::stack<char> bracketStack;
    for (auto i = 0; i < string.size(); ++i) {
        switch (string[i]) {
            case '(':
                bracketStack.push(')');
                break;
            case '[':
                bracketStack.push(']');
                break;
            case '{':
                bracketStack.push('}');
                break;
            case ')':
            case ']':
            case '}':
                if (!bracketStack.empty() && bracketStack.top() == string[i]) {
                    bracketStack.pop();
                    break;
                }
                else {
                    return std::to_string(i + 1);
                }
            default:
                break;
        }
    }
    if (!bracketStack.empty()) {
        for (int i = 0; i < string.size(); ++i) {
            if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
                return std::to_string(i + 1);
            }
        }
    }
    return "Success";
}

int main() {
    assert(bracketBalance("{[]}()") == "Success");
    assert(bracketBalance("{") == "1");
    assert(bracketBalance("foo(bar[i);") == "10");
    return 0;
}
