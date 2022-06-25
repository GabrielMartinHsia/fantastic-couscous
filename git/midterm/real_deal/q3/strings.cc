#include <iostream>
#include <string>

// It should return true if v1 and v2 are equal ignoring the case and false
// otherwise.
bool CompareStringsCaseInsensitive(const std::string& v1,
                                   const std::string& v2) {
  if (v1.size() != v2.size()){return false;}                                   
  for (int i = 0; i < v1.size(); i++) {
    if (std::tolower(v1[i]) != std::tolower(v2[i])) {
      return false;
    }
  }
  return true;
}

int main(){
    std::string s1 = "1 2,7,a b";
    std::string s2 = "cats";

    bool result = CompareStringsCaseInsensitive(s1, s2);
    std::cout<<"t/f: "<<result<<std::endl;
}