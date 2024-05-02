#include "shopping.hpp"

#include <cstdint>
#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using Catch::Matchers::WithinAbs;

TEST_CASE("test calculate grand total", "[empty]") {
  std::vector<Item> items;
  CHECK(calculate_grand_total(items) == 0.0);
}

TEST_CASE("test calculate grand total", "[single]") {
  std::vector<Item> items{{3, "Cucumber", 1.2}};
  CHECK_THAT(calculate_grand_total(items), WithinAbs(3.6, 0.000001));
}

TEST_CASE("test calculate grand total", "[regular]") {
  std::vector<Item> items{{3, "Cucumber", 1.2},
                          {0, "Tomato", 2.5},
                          {1, "Bread", 4.1},
                          {2, "Milk", 1.45},
                         };
  CHECK_THAT(calculate_grand_total(items), WithinAbs(10.6, 0.000001));
}
