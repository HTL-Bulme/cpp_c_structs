#include "complex_numbers.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using Catch::Matchers::WithinAbs;


TEST_CASE("adding complex numbers", "[addition]") {
  Complex a{5, 5};
  Complex b{7, 1.5};
  Complex c{7.5, -3};
  Complex d{3, -2};
  Complex e{-5, 0};
  Complex f{0, -3};
  Complex zero{0, 0};

  SECTION("regular") {
    Complex result = add(a, b);
    CHECK(result.real == 12.0);
    CHECK_THAT(result.imag, WithinAbs(6.5, 0.000001));

    result = add(a, c);
    CHECK_THAT(result.real, WithinAbs(12.5, 0.000001));
    CHECK(result.imag == 2.0);

    result = add(d, c);
    CHECK_THAT(result.real, WithinAbs(10.5, 0.000001));
    CHECK(result.imag == -5.0);

    result = add(d, e);
    CHECK(result.real == -2.0);
    CHECK(result.imag == -2.0);

    result = add(d, f);
    CHECK(result.real ==  3.0);
    CHECK(result.imag == -5.0);
  }


  SECTION("zero") {
    Complex result = add(d, zero);
    CHECK(result.real == d.real);
    CHECK(result.imag == d.imag);

    result = add(zero, d);
    CHECK(result.real == d.real);
    CHECK(result.imag == d.imag);

    result = add(zero, zero);
    CHECK(result.real == 0.0);
    CHECK(result.imag == 0.0);
  }
}


TEST_CASE("subtracting complex numbers", "[subtraction]") {
  Complex a{5, 5};
  Complex b{7, 1.5};
  Complex c{7.5, -3};
  Complex d{3, -2};
  Complex e{-5, 0};
  Complex f{0, -3};
  Complex zero{0, 0};

  SECTION("regular") {
    Complex result = sub(a, b);
    CHECK(result.real == -2.0);
    CHECK_THAT(result.imag, WithinAbs(3.5, 0.000001));

    result = sub(a, c);
    CHECK_THAT(result.real, WithinAbs(-2.5, 0.000001));
    CHECK(result.imag == 8.0);

    result = sub(d, c);
    CHECK_THAT(result.real, WithinAbs(-4.5, 0.000001));
    CHECK(result.imag == 1.0);

    result = sub(d, e);
    CHECK(result.real ==  8.0);
    CHECK(result.imag == -2.0);

    result = sub(d, f);
    CHECK(result.real == 3.0);
    CHECK(result.imag == 1.0);
  }


  SECTION("zero") {
    Complex result = sub(d, zero);
    CHECK(result.real == d.real);
    CHECK(result.imag == d.imag);

    result = sub(zero, d);
    CHECK(result.real == -d.real);
    CHECK(result.imag == -d.imag);

    result = sub(zero, zero);
    CHECK(result.real == 0.0);
    CHECK(result.imag == 0.0);
  }
}


TEST_CASE("multiplying complex numbers", "[multiplication]") {
  Complex a{5, 5};
  Complex b{7, 1.5};
  Complex c{7.5, -3};
  Complex d{3, -2};
  Complex e{-5, 0};
  Complex f{0, -3};
  Complex zero{0, 0};

  SECTION("regular") {
    Complex result = mul(a, b);
    CHECK_THAT(result.real, WithinAbs(27.5, 0.000001));
    CHECK_THAT(result.imag, WithinAbs(42.5, 0.000001));

    result = mul(a, c);
    CHECK_THAT(result.real, WithinAbs(52.5, 0.000001));
    CHECK_THAT(result.imag, WithinAbs(22.5, 0.000001));

    result = mul(d, c);
    CHECK_THAT(result.real, WithinAbs(16.5, 0.000001));
    CHECK_THAT(result.imag, WithinAbs(-24.0, 0.000001));

    result = mul(d, e);
    CHECK(result.real == -15.0);
    CHECK(result.imag ==  10.0);

    result = mul(d, f);
    CHECK(result.real == -6.0);
    CHECK(result.imag == -9.0);
  }


  SECTION("zero") {
    Complex result = mul(d, zero);
    CHECK(result.real == 0.0);
    CHECK(result.imag == 0.0);

    result = mul(zero, d);
    CHECK(result.real == 0.0);
    CHECK(result.imag == 0.0);

    result = mul(zero, zero);
    CHECK(result.real == 0.0);
    CHECK(result.imag == 0.0);
  }
}
