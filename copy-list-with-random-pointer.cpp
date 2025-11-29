#include <unordered_map>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
  std::unordered_map<Node *, Node *> alreadyCreated;

  Node *deepCopy(Node *originalNode) {
    if (!originalNode)
      return nullptr;

    auto it = alreadyCreated.find(originalNode);

    if (it != alreadyCreated.end())
      return it->second;

    Node *copiedNode = new Node(originalNode->val);

    alreadyCreated[originalNode] = copiedNode;

    copiedNode->next = deepCopy(originalNode->next);
    copiedNode->random = deepCopy(originalNode->random);

    return copiedNode;
  }

public:
  Node *copyRandomList(Node *head) { return deepCopy(head); }
};
