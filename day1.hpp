#include "day.hpp"

class Day1 : public Day {
 public:
  Day1() : Day{"input/day1.txt"} {}
  ~Day1() override = default;

  void run() override {
    // Part 1
    std::vector<int> leftList{}, rightList{};
    for (const auto& line : lines) {
      auto locationIds = getNumbersInLine(line, ' ');
      leftList.emplace_back(locationIds[0]);
      rightList.emplace_back(locationIds[1]);
    }

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance{};
    for (int i{}; i < leftList.size(); ++i)
      totalDistance += std::abs(leftList[i] - rightList[i]);

    std::cout << totalDistance << std::endl;

    // Part 2
    std::map<int, int> similarityScores{};
    for (const auto& score : rightList)
      similarityScores[score] += score;

    int sum{};
    for (const auto& score : leftList)
      sum += similarityScores[score];

    std::cout << sum << std::endl;
  }
};
