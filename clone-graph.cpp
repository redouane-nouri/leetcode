#include <unordered_map>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  std::unordered_map<int, Node *> deepCopiedNodes;

  Node *deepCopy(Node *originalNode) {
    auto it = deepCopiedNodes.find(originalNode->val);

    if (it != deepCopiedNodes.end()) {
      return it->second;
    }

    Node *copiedNode = new Node(originalNode->val);
    deepCopiedNodes[copiedNode->val] = copiedNode;

    for (auto &neighbor : originalNode->neighbors)
      copiedNode->neighbors.push_back(deepCopy(neighbor));

    return copiedNode;
  }

public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }

    return deepCopy(node);
  }
};
