#include <cstddef>
#include <string>

#include <catch2/internal/catch_case_sensitive.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>


void capitalize(char string[]);
std::size_t str_len(const char str[]);
void str_invert_case(char str[]);
bool str_starts_with(const char str[], const char prefix[]);
bool str_ends_with(const char str[], const char suffix[]);
unsigned str_count(const char str[], const char sub[]);
bool str_is_ascii(const char str[]);
bool str_is_digit(const char str[]);
long str_index(const char str[], const char sub[]);
void str_copy(char dst[], const char src[], std::size_t dst_size);
bool str_equal(const char first[], const char second[]);
void join(const char* array[], std::size_t count, char str[], const char sep[]);

using std::size_t;
using std::string;
using Catch::CaseSensitive;
using Catch::Matchers::Equals;


TEST_CASE("capitalize c string", "[capitalize]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

  capitalize(lower);
  capitalize(upper);
  capitalize(mixed);
  capitalize(special);

  CHECK_THAT(lower, Catch::Matchers::Equals("Abcdef Ghijklmnopqrstuvwxyz",
    Catch::CaseSensitive::Yes));
  CHECK_THAT(upper, Catch::Matchers::Equals("ABCDEF GHIJK",
    Catch::CaseSensitive::Yes));
  CHECK_THAT(mixed, Catch::Matchers::Equals("The Quick Brown Fox Jumps Over The Lazy Dog.",
    Catch::CaseSensitive::Yes));
  CHECK_THAT(special, Catch::Matchers::Equals("Some Punctuation &;-.: 345 !@# Should Be Ok.",
    Catch::CaseSensitive::Yes));
}


TEST_CASE("length of c string", "[str_len]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";
  CHECK(str_len(lower) == string(lower).length());
  CHECK(str_len(upper) == string(upper).length());
  CHECK(str_len(mixed) == string(mixed).length());
  CHECK(str_len(special) == string(special).length());
}


TEST_CASE("invert case", "[invert]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

  str_invert_case(lower);
  str_invert_case(upper);
  str_invert_case(mixed);
  str_invert_case(special);

  CHECK_THAT(lower, Equals("ABCDEF GHIJKLMNOPQRSTUVWXYZ", CaseSensitive::Yes));
  CHECK_THAT(upper, Equals("abcdef ghijk", CaseSensitive::Yes));
  CHECK_THAT(mixed, Equals("tHE QUICK BROWN fOX JUMPS OVER THE LAZY dOG.",
                           CaseSensitive::Yes));
  CHECK_THAT(special, Equals("sOME PUNCTUATION &;-.: 345 !@# SHOULD BE OK.",
                             CaseSensitive::Yes));
}


TEST_CASE("string starts with given prefix", "[starts_with]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

  CHECK(str_starts_with(lower, ""));
  CHECK(str_starts_with(lower, "abcd"));
  CHECK(str_starts_with(lower, "abcdef ghi"));
  CHECK(not str_starts_with(lower, "cdef"));
  CHECK(str_starts_with(upper, "ABCD"));
  CHECK(str_starts_with(special, "Some punctuation &;-.: 345 "));
  CHECK(not str_starts_with(special, "punctuation &;-.: 345 "));
  CHECK(str_starts_with(special, "Some punctuation &;-.: 345 !@# should be ok."));
  CHECK(not str_starts_with(mixed, "The quick brown Fox jumps over the lazy Dog.."));
}


TEST_CASE("string ends with a given suffix", "[ends_with]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

  CHECK(str_ends_with(lower, ""));
  CHECK(str_ends_with(lower, "wxyz"));
  CHECK(str_ends_with(lower, "abcdef ghijklmnopqrstuvwxyz"));
  CHECK(not str_ends_with(lower, "cdef"));
  CHECK(str_ends_with(upper, " GHIJK"));
  CHECK(str_ends_with(special, "should be ok."));
  CHECK(not str_ends_with(special, "punctuation &;-.: 345 "));
  CHECK(str_ends_with(special, "Some punctuation &;-.: 345 !@# should be ok."));
  CHECK(not str_ends_with(mixed, " The quick brown Fox jumps over the lazy Dog."));
}


TEST_CASE("count number of occurances of substring", "[count]") {
  char text[] = "Lorem ipsum dolor sit amet; lorem ipsum dolor sit amet; sit";

  CHECK(str_count(text, "Lorem") == 1);
  CHECK(str_count(text, "ipsum") == 2);
  CHECK(str_count(text, "sit") == 3);
  CHECK(str_count(text, "Dolor") == 0);
  CHECK(str_count(text, "lorem ipsum") == 1);
  CHECK(str_count(text, " ") == 10);
}


TEST_CASE("string only has ascii characters", "[is_ascii]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEF GHIJK";
  char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";
  char extended[] = "Punctuation is ok; German umlauts (äöü) are not.";


  CHECK(str_is_ascii(lower));
  CHECK(str_is_ascii(upper));
  CHECK(str_is_ascii(mixed));
  CHECK(str_is_ascii(special));
  CHECK(not str_is_ascii(extended));
}


TEST_CASE("string only has digits", "[is_digit]") {
  char lower[] = "abcdef ghijklmnopqrstuvwxyz";
  char mixed[] = "123a456";
  char pure[] = "98475320987123049823984759823875203498392785";
  char with_space[] = "095873 345";


  CHECK(not str_is_digit(lower));
  CHECK(not str_is_digit(mixed));
  CHECK(str_is_digit(pure));
  CHECK(not str_is_digit(with_space));
}


TEST_CASE("position of first occurance of `sub` in `str` or -1", "[index]") {
  char text[] = "Lorem ipsum dolor sit amet; lorem ipsum dolor sit amet; sit";

  CHECK(str_index(text, "Lorem") == 0);
  CHECK(str_index(text, "ipsum") == 6);
  CHECK(str_index(text, "sit") == 18);
  CHECK(str_index(text, ";") == 26);
}


TEST_CASE("make a copy of the given string", "[str_copy]") {
  char single[] = "a";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";
  char single_c[2];
  char special_c[100];
  char limited_c[10];
  char large_c[] = "12345678901234567890123456789012345678901234567890";

  str_copy(single_c, single, 2);
  str_copy(special_c, special, 100);
  str_copy(limited_c, special, 10);
  str_copy(large_c, special, 4);

  CHECK_THAT(single_c, Equals("a", CaseSensitive::Yes));
  CHECK_THAT(special_c, Equals("Some punctuation &;-.: 345 !@# should be ok.",
                               CaseSensitive::Yes));
  CHECK_THAT(limited_c, Equals("Some punc",
                               CaseSensitive::Yes));
  CHECK_THAT(large_c, Equals("Som",
                               CaseSensitive::Yes));
  CHECK(large_c[3] == 0);
  CHECK(large_c[4] == '5');

  SECTION("must not crash for large destinations if source is small") {
    str_copy(special_c, special, (size_t) -1);
    CHECK(true);
  }
}


TEST_CASE("compare two strings for equality", "[str_equal]") {
  char single[] = "a";
  char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

  SECTION("determine equality of equal length strings") {
    CHECK(str_equal(single, single));
    CHECK(not str_equal(single, "b"));
    CHECK(str_equal(special, special));
  }

  SECTION("strings of different lengths are never equal") {
    CHECK(not str_equal("123", "12345"));
    CHECK(not str_equal("12345", "123"));
  }
}


TEST_CASE("join array of strings", "[join]") {
  const char* array[] = {"chris", "pat", "Sue", "Steve"};
  char str[100];

  SECTION("regular use cases") {
    join(array, 4, str, " | ");
    CHECK_THAT(str, Equals("chris | pat | Sue | Steve", CaseSensitive::Yes));
    join(array, 4, str, "");
    CHECK_THAT(str, Equals("chrispatSueSteve", CaseSensitive::Yes));
    join(array, 4, str, ",");
    CHECK_THAT(str, Equals("chris,pat,Sue,Steve", CaseSensitive::Yes));
  }

  SECTION("empty array") {
    str[0] = 'x';
    str[1] = 0;
    join({}, 0, str, "");
    CHECK_THAT(str, Equals("", CaseSensitive::Yes));
    str[0] = 'x';
    str[1] = 0;
    join({}, 0, str, ",");
    CHECK_THAT(str, Equals("", CaseSensitive::Yes));
  }

  SECTION("single element") {
    const char* single[] = {"name"};
    join(single, 1, str, "");
    CHECK_THAT(str, Equals("name", CaseSensitive::Yes));
    join(single, 1, str, ",");
    CHECK_THAT(str, Equals("name", CaseSensitive::Yes));
  }
}
