#include <queue>

class MyStack {
  std::queue<int> q;

public:
  MyStack() {}

  void push(int x) {
    q.push(x);
    int s = q.size(), i = 0;

    while (i < s - 1) {
      q.push(q.front());
      q.pop();
      ++i;
    }
  }

  int pop() {
    int b = q.front();
    q.pop();
    return b;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};
