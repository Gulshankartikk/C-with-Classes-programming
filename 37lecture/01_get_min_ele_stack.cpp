#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> s;
    long long minEle;

public:

    void push(int x) {
        if (s.empty()) {
            s.push(0);
            minEle = x;
        } else {
            long long diff = x - minEle;
            s.push(diff);

            if (diff < 0) {
                minEle = x;
            }
        }
    }

    int pop() {
        if (s.empty()) return -1;

        long long topVal = s.top();
        s.pop();

        if (topVal < 0) {
            int val = minEle;
            minEle = minEle - topVal;
            return val;
        } else {
            return minEle + topVal;
        }
    }

    int top() {
        if (s.empty()) return -1;

        long long topVal = s.top();
        if (topVal < 0) return minEle;
        return minEle + topVal;
    }

    int getMin() {
        if (s.empty()) return -1;
        return minEle;
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    SpecialStack st;

    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16);

    cout << "Current Min: " << st.getMin() << endl;  // Expected: 15

    cout << "Top Element: " << st.top() << endl;     // Expected: 16

    cout << "Popped: " << st.pop() << endl;          // Removes 16

    cout << "New Top: " << st.top() << endl;         // Expected: 15

    cout << "Current Min: " << st.getMin() << endl;  // Expected: 15

    return 0;
}