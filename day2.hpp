#include "day.hpp"

class Day2 : public Day {
 public:
  Day2() : Day{"input/day2.txt"} {}
  ~Day2() override = default;

  auto isUnsafe(int diff, int& crease) {
    return std::abs(diff) > 3 || diff == 0 || (crease > 0 && diff < 0) || (crease < 0 && diff > 0);
  }

  bool isSafe(std::vector<int>& report, bool first) {
    int crease{};
    for (auto it = report.begin(); it != report.end() - 1; ++it) {
      auto diff = *(it+1) - *it;
      if (isUnsafe(diff, crease)) {
        if (first) {
          bool res{};
          for (auto it2 = report.begin(); it2 != report.end(); ++it2) {
            auto val = *it2;
            auto pos = report.erase(it2);
            res |= isSafe(report, false);
            it2 = report.insert(pos, val);
            if (res)
              return res;
          }

          return res;
        }

        crease = 0;
        break;
      }

      crease = diff;
    }

    return crease != 0;
  }

  void run() override {
    bool part2{true};
    int safeReports{};
    for (const auto& line : lines) {
      auto report = getNumbersInLine(line, ' ');
      safeReports += isSafe(report, part2);
    }

    std::cout << safeReports << std::endl;
  }

};
