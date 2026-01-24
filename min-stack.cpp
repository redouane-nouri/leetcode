#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
  MinStack() {}
  stack<pair<int, int>> st;
  void push(int val) {
    st.empty() ? st.push({val, val})
               : st.push({val, min(val, st.top().second)});
  }
  void pop() { st.pop(); }
  int top() { return st.top().first; }
  int getMin() { return st.top().second; }
};
