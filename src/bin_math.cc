#include <iostream>
#include "lib.h"

int main() {
  std::cout << "The answer is: " << mul_from_library(6, 7) << std::endl;
  std::cout << "Also, " << add_from_library(2, 3) << " and " << mul_from_library(2, 3)
            << " are 5 and 6 respectively." << std::endl;
}
