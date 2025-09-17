#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class FoodRatings {

  struct Food {
    std::string name;
    int rating;
    bool operator<(const Food &f) const {
      if (rating == f.rating)
        return name < f.name;

      return rating > f.rating;
    };
  };

  std::unordered_map<std::string, std::string> foodToCuisine;
  std::unordered_map<std::string, int> foodToRating;
  std::unordered_map<std::string, std::set<Food>> cuisineFoods;

public:
  FoodRatings(std::vector<std::string> &foods,
              std::vector<std::string> &cuisines, std::vector<int> &ratings) {
    int n = foods.size();

    for (int i = 0; i < n; ++i) {
      foodToCuisine[foods[i]] = cuisines[i];
      foodToRating[foods[i]] = ratings[i];
      cuisineFoods[cuisines[i]].insert({foods[i], ratings[i]});
    }
  }

  void changeRating(std::string food, int newRating) {
    std::string &c = foodToCuisine[food];
    cuisineFoods[c].erase({food, foodToRating[food]});
    foodToRating[food] = newRating;
    cuisineFoods[c].insert({food, newRating});
  }

  std::string highestRated(std::string cuisine) {
    return cuisineFoods[cuisine].begin()->name;
  }
};
