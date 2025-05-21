class Solution {
public:
  int strStr(string haystack, string needle) {
    size_t haystack_size = haystack.size();
    size_t needle_size = needle.size();

    for (size_t i = 0; i <= haystack_size - needle_size; ++i) {
      if (haystack.substr(i, needle_size) == needle) {
        return i;
      }
    }

    return -1;
  }
};
