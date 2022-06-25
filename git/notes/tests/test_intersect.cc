#include "src/lib/cpplib.h"
#include "gtest/gtest.h" //hmmm, where's this? I don't see it in the template either...
#include <map>
#include <vector>

//so, this looks like it builds, but no test reports generated...hmmm...
TEST(notes1, intersection432) {
  CPPLib s;
  std::vector<int> input1 = {1,2,3,4};
  std::vector<int> input2 = {6,5,4,3,7,4,3,2};
  float exp = {4,3};
  float act = s.intersect(input1, input2);
  EXPECT_EQ(exp, act);
}