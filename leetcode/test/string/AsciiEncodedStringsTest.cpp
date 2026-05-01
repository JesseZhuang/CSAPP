#include "gtest/gtest.h"
#include "string/AsciiEncodedStrings.hpp"

#include <string>

using namespace std;

namespace {
struct Case { string plain; string encoded; };
const Case CASES[] = {
    {"hello world", "00180141111191123111801801101401"},
    {"HackerRank",  "7010117928411101701997927"},
    {"Go VMWare",   "101411797877682311117"},
    {"Truth Always Wins ", "23511011501782351112179911801562340161171141148"},
};
}  // namespace

TEST(string, ascii_encoded_strings_encode) {
    SolutionAsciiEncodedStrings sol;
    for (const auto& c : CASES) {
        ASSERT_EQ(c.encoded, sol.encode(c.plain)) << c.plain;
    }
}

TEST(string, ascii_encoded_strings_decode) {
    SolutionAsciiEncodedStrings sol;
    for (const auto& c : CASES) {
        ASSERT_EQ(c.plain, sol.decode(c.encoded)) << c.encoded;
    }
}

TEST(string, ascii_encoded_strings_round_trip) {
    SolutionAsciiEncodedStrings sol;
    for (const auto& c : CASES) {
        ASSERT_EQ(c.plain, sol.decode(sol.encode(c.plain))) << c.plain;
    }
}

TEST(string, ascii_encoded_strings_single_char) {
    SolutionAsciiEncodedStrings sol;
    // 'A' has ASCII 65; encode reverses the digits -> "56".
    ASSERT_EQ("56", sol.encode("A"));
    ASSERT_EQ("A", sol.decode("56"));
}

TEST(string, ascii_encoded_strings_only_lowercase) {
    SolutionAsciiEncodedStrings sol;
    string plain = "abc";  // 97 98 99
    string enc = sol.encode(plain);          // reverse("979899") = "998979"
    ASSERT_EQ("998979", enc);
    ASSERT_EQ(plain, sol.decode(enc));
}

TEST(string, ascii_encoded_strings_space_only) {
    SolutionAsciiEncodedStrings sol;
    ASSERT_EQ("23", sol.encode(" "));
    ASSERT_EQ(" ", sol.decode("23"));
}
