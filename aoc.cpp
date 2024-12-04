#include <stdio.h>
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"

int main(int argc, char* argv[]) {
  Day* day = new Day4{};
  day->run();
  delete day;
  return 0;
}
