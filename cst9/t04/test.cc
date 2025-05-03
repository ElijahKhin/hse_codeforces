#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::stack<int> st;
    int maxlen = 0, count = 0;
    st.push(-1);

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.empty()) {
                int len = i - st.top();
                if (len > maxlen) {
                    maxlen = len;
                    count = 1;
                } else if (len == maxlen) {
                    count++;
                }
            } else {
                st.push(i);
            }
        }
    }

    if (maxlen == 0) count = 1;
    std::cout << maxlen << " " << count << "\n";
}
