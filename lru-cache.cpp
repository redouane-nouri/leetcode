#include <list>
#include <unordered_map>

class LRUCache {
  const int capacity;
  std::list<std::pair<int, int>> l;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = m.find(key);

    if (it == m.end())
      return -1;

    l.splice(l.begin(), l, it->second);

    return it->second->second;
  }

  void put(int key, int value) {
    auto it = m.find(key);

    if (it != m.end()) {
      l.splice(l.begin(), l, it->second);
      it->second->second = value;
      return;
    }

    if (l.size() == capacity) {
      m.erase(l.back().first);
      l.pop_back();
    }

    l.push_front({key, value});
    m[key] = l.begin();
  }
};
