#include <stdio.h>
#include "day1.hpp"

int main(int argc, char* argv[]) {
  Day* day = new Day1{};
  day->run();
  delete day;
  return 0;
}
