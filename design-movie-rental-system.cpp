#include <array>
#include <set>
#include <unordered_map>
#include <vector>

class MovieRentingSystem {
  std::set<std::array<int, 3>> rentedMovies;
  std::unordered_map<int, std::set<std::array<int, 2>>> movieToPriceShop;
  std::unordered_map<int, std::unordered_map<int, int>> moviePrice;

public:
  MovieRentingSystem(int n, std::vector<std::vector<int>> &entries) {
    for (std::vector<int> &entry : entries) {
      moviePrice[entry[1]][entry[0]] = entry[2];
      movieToPriceShop[entry[1]].insert({entry[2], entry[0]});
    }
  }

  std::vector<int> search(int movie) {
    int i = 0;
    std::vector<int> res;

    for (std::set<std::array<int, 2>>::iterator it =
             movieToPriceShop[movie].begin();
         it != movieToPriceShop[movie].end() && i < 5; ++it) {
      if (rentedMovies.count({(*it)[0], (*it)[1], movie}))
        continue;

      ++i;
      res.push_back((*it)[1]);
    }

    return res;
  }

  void rent(int shop, int movie) {
    rentedMovies.insert({moviePrice[movie][shop], shop, movie});
  }

  void drop(int shop, int movie) {
    rentedMovies.erase({moviePrice[movie][shop], shop, movie});
  }

  std::vector<std::vector<int>> report() {
    std::vector<std::vector<int>> res;
    auto it = rentedMovies.begin();

    for (int i = 0; i < 5 && it != rentedMovies.end(); i++, it++)
      res.push_back({(*it)[1], (*it)[2]});

    return res;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
