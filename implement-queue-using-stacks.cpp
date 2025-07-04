#include <stack>

class MyQueue {
private:
  std::stack<int> s1, s2;

  void fillS2FromS1IfNeeded() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
  }

public:
  MyQueue() = default;

  void push(int x) { s1.push(x); }

  int pop() {
    fillS2FromS1IfNeeded();

    int t = s2.top();
    s2.pop();
    return t;
  }

  int peek() {
    fillS2FromS1IfNeeded();
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }
};
