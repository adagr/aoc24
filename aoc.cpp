#include <stdio.h>
#include "day1.hpp"
#include "day2.hpp"

int main(int argc, char* argv[]) {
  Day* day = new Day2{};
  day->run();
  delete day;
  return 0;
}
