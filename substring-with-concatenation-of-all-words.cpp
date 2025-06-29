#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    int wordLength = words[0].length(), sLength = s.length(),
        wordsSize = words.size();
    std::vector<int> res;

    if (wordLength * wordsSize > sLength)
      return res;

    int wordsStrLength = wordLength * wordsSize;
    std::unordered_map<std::string, int> wordsMap;

    for (std::string &word : words) {
      ++wordsMap[word];
    }

    for (int i = 0; i < wordLength; i++) {
      std::unordered_map<std::string, int> wordsWindowMap;
      int counter = 0, currentStart = i;

      for (int j = i; j <= sLength - wordLength; j += wordLength) {
        std::string word = s.substr(j, wordLength);

        if (wordsMap.count(word)) {
          ++wordsWindowMap[word];
          ++counter;

          while (wordsWindowMap[word] > wordsMap[word]) {
            --wordsWindowMap[s.substr(currentStart, wordLength)];
            --counter;
            currentStart += wordLength;
          }

          if (counter == wordsSize) {
            res.push_back(currentStart);
            --wordsWindowMap[s.substr(currentStart, wordLength)];
            --counter;
            currentStart += wordLength;
          }
        } else {
          counter = 0;
          wordsWindowMap.clear();
          currentStart = j + wordLength;
        }
      }
    }

    return res;
  }
};
