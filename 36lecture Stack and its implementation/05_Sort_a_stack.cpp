#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, x);

    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, temp);
}

int main() {
    stack<int> st;

    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}