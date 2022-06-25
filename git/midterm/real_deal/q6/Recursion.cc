#include <iostream>
#include <string>
#include <vector>


enum class Command { kNumberOfVowels, kCheckSum };

struct Result {
  char checksum;
  unsigned int number_of_vowels;
  Result() : checksum('0'), number_of_vowels(0) {}
};