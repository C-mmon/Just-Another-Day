class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        int num = 0;
        char op = '+';
        stack<int> stk;

        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }    if (!isdigit(s[i]) && !isspace(s[i]) || i == len - 1) {
                if (op == '-') {
                    num *= -1;
                } else if (op == '*') {
                    num *= stk.top();
                    stk.pop();
                } else if (op == '/') {
                    num = stk.top() / num;
                    stk.pop();
                }
                stk.push(num);
                num = 0;
                op = s[i];
            }
    }

    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}
}
;