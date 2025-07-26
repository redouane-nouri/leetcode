#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                       int maxWidth) {
    int sz = words.size(), end = 0;
    std::vector<std::string> res;

    while (end < sz) {
      int width = 0, start = end;

      while (end < sz &&
             width + words[end].size() + (end == start ? 0 : 1) <= maxWidth) {
        width += words[end].size() + (end == start ? 0 : 1);
        ++end;
      }

      std::string strLine = "";

      // justify between words with 1 space
      for (int i = start; i < end; ++i)
        words[i] += (i + 1 == end ? "" : " ");

      // if not the last line and has more than 1 word, we spread spaces between
      // words
      if (end < sz && start + 1 < end) {
        int j = start, tmpWidth = width;

        while (tmpWidth < maxWidth) {
          words[j++].push_back(' ');
          ++tmpWidth;

          if (j >= end - 1)
            j = start;
        }
      }

      // concatenate words with each other
      for (int i = start; i < end; ++i)
        strLine += words[i];

      // if last line or the line has only word, then left justified
      if (end >= sz || start == end - 1)
        strLine += std::string(maxWidth - width, ' ');

      res.push_back(strLine);
    }

    return res;
  }
};
