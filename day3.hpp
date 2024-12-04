#include "day.hpp"
#include <regex>

class Day3 : public Day {
 public:
  Day3() : Day{"input/day3.txt"} {}
  ~Day3() override = default;

  void run() override {
    std::regex regexMult("mul\\(\\d+,\\d+\\)");
    std::regex regexDo("do\\(\\)");
    std::regex regexDont("don\\'t\\(\\)");
    std::smatch smDo, smDont, smMult;
    bool doMult{true};
    int sum{};
    for (auto line : lines) {
      bool res{true};
      while (res) {
        std::regex_search(line, smDo, regexDo);
        std::regex_search(line, smDont, regexDont);
        res = std::regex_search(line, smMult, regexMult);
        if ((smDo.position() < smDont.position() || smDont.empty()) && smDo.position() < smMult.position()) {
          doMult = true;
        } else if (smDont.position() < smMult.position()) {
          doMult = false;
        }

        if (res && doMult) {
          auto pos = smMult.str().find(",");
          sum += std::stoi(smMult.str().substr(4, smMult.str().size())) * stoi(smMult.str().substr(pos + 1, smMult.str().size()));
        }

        line = smMult.suffix();
      }
    }

    std::cout << sum << std::endl;
  }

};
