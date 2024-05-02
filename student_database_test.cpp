#include "student_database.hpp"

#include <sstream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <catch2/internal/catch_case_sensitive.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

using std::string;
using Catch::CaseSensitive;
using Catch::Matchers::Equals;


TEST_CASE("students must be created from textual input", "[read]") {
  std::istringstream input1("12345\nPat\nHeikkinen\n");
  std::istringstream input2("0\nChris\nJohansson\n");
  std::istringstream input3("987\nMarie\nJonsdottir\n");

  Student s1(read_student(input1));
  Student s2(read_student(input2));
  Student s3(read_student(input3));

  CHECK(s1.id == 12345);
  CHECK_THAT(s1.first_name, Equals("Pat", CaseSensitive::Yes));
  CHECK_THAT(s1.last_name, Equals("Heikkinen", CaseSensitive::Yes));
  CHECK(s2.id == 0);
  CHECK_THAT(s2.first_name, Equals("Chris", CaseSensitive::Yes));
  CHECK_THAT(s2.last_name, Equals("Johansson", CaseSensitive::Yes));
  CHECK(s3.id == 987);
  CHECK_THAT(s3.first_name, Equals("Marie", CaseSensitive::Yes));
  CHECK_THAT(s3.last_name, Equals("Jonsdottir", CaseSensitive::Yes));
}


TEST_CASE("students must be printed correctly", "[print]") {
  std::ostringstream o1;
  std::ostringstream o2;
  std::ostringstream o3;

  Student s1({12345, "Pat", "Heikkinen"});
  Student s2({0, "Chris", "Johansson"});
  Student s3({987, "Marie", "Jonsdottir"});

  print_students(o1, std::vector<Student>{});
  print_students(o2, std::vector<Student>{s1});
  print_students(o3, std::vector<Student>{s1, s2, s3});

  CHECK_THAT(std::move(o1).str(),
             Equals("", CaseSensitive::Yes));
  CHECK_THAT(std::move(o2).str(),
             Equals("Pat Heikkinen (12345)\n", CaseSensitive::Yes));
  CHECK_THAT(std::move(o3).str(),
             Equals("Pat Heikkinen (12345)\n"
                    "Chris Johansson (0)\n"
                    "Marie Jonsdottir (987)\n",
                    CaseSensitive::Yes));
}
