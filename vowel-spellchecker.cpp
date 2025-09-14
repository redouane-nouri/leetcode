#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::string> spellchecker(std::vector<std::string> &wordlist,
                                        std::vector<std::string> &queries) {
    std::unordered_set<std::string> sensitive(wordlist.begin(), wordlist.end());
    std::unordered_map<std::string, std::string *> insensitive;
    std::unordered_map<std::string, std::string *> vowels;

    auto toLower = [](std::string &s) {
      std::string l = s;

      for (char &c : l)
        c = tolower(c);

      return l;
    };

    auto isVowel = [](char &c) {
      switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
        return false;
      }
    };

    auto hideVowels = [&isVowel](std::string &s) {
      std::string h = s;

      for (char &c : h)
        if (isVowel(c))
          c = '_';

      return h;
    };

    for (std::string &w : wordlist) {
      std::string wl = toLower(w), wlhv = hideVowels(wl);
      if (!insensitive.count(wl))
        insensitive[wl] = &w;

      if (!vowels.count(wlhv))
        vowels[wlhv] = &w;
    }

    std::vector<std::string> res;
    res.reserve(queries.size());

    for (std::string &q : queries) {
      if (sensitive.count(q)) {
        res.push_back(q);
        continue;
      }

      std::string wl = toLower(q);

      if (insensitive.count(wl)) {
        res.push_back(*insensitive[wl]);
        continue;
      }

      std::string wlhv = hideVowels(wl);
      if (vowels.count(wlhv)) {
        res.push_back(*vowels[wlhv]);
        continue;
      }

      res.push_back("");
    }

    return res;
  }
};
