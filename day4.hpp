#include "day.hpp"
#include <regex>

class Day4 : public Day {
 public:
  Day4() : Day{"input/day4.txt"} {}
  ~Day4() override = default;

  enum class Direction {
    horizontal,
    vertical,
    diagonalLeft,
    diagonalRight
  };

  auto getMatches(const std::string& s) {
    std::regex matchString("XMAS");
    return std::distance(std::sregex_iterator(s.begin(), s.end(), matchString),
                         std::sregex_iterator());
  }

  void run() override {
    std::map<Direction, std::map<std::pair<int, int>, std::string>> words{};
    int yMax = lines.size() - 1;
    int xMax = lines[0].size() - 1;
    for (int y{}; y <= yMax; ++y) {
      for (int x{}; x <= xMax; ++x) {
        char c = lines[y][x];
        words[Direction::horizontal][std::make_pair(y, 0)] += c;
        words[Direction::vertical][std::make_pair(0, x)] += c;
        words[Direction::diagonalLeft][std::make_pair(std::max(y - (xMax - x), 0), std::min(x + y, xMax))] += c;
        words[Direction::diagonalRight][std::make_pair(std::max(y - x, 0), std::max(x - y, 0))] += c;
      }
    }

    int sum{};
    for (const auto& [direction, lists] : words) {
      for (auto [location, word] : lists) {
        sum += getMatches(word);
        std::reverse(word.begin(), word.end());
        sum += getMatches(word);
      }
    }

    std::cout << sum << std::endl;

    // Part 2
    sum = 0;
    for (int y{1}; y < yMax; ++y) {
      for (int x{1}; x < xMax; ++x) {
        if (lines[y][x] != 'A')
          continue;

        if (((lines[y - 1][x - 1] == 'M' && lines[y + 1][x + 1] == 'S') ||
             (lines[y - 1][x - 1] == 'S' && lines[y + 1][x + 1] == 'M')) &&
            ((lines[y + 1][x - 1] == 'M' && lines[y - 1][x + 1] == 'S') ||
             (lines[y + 1][x - 1] == 'S' && lines[y - 1][x + 1] == 'M'))) {
          ++sum;
        }
      }
    }

    std::cout << sum << std::endl;
  }
};
