class Solution {
public:
  int findComplement(int num) {
    return ~num & ((1u << (32 - __builtin_clz(num))) - 1u);
  }
};
