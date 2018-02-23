#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  map<int, string> dictionnaire;
  dictionnaire[1] = "un";
  dictionnaire[2] = "deux";
  dictionnaire[3] = "trois";
  dictionnaire[4] = "quatre";
  dictionnaire[5] = "cinq";
  
  cout << "dictionnaire[5]=" << dictionnaire[5] << std::endl;
  cout << "dictionnaire[1]=" << dictionnaire[1] << std::endl;
  cout << "dictionnaire[3]=" << dictionnaire[3] << std::endl;
  cout << "dictionnaire[2]=" << dictionnaire[2] << std::endl;
  cout << "dictionnaire[4]=" << dictionnaire[4] << std::endl;
  
  cout << "---" << std::endl;
  for (map<int, string>::iterator iter = dictionnaire.begin(); iter != dictionnaire.end(); ++iter) {
    cout << "dictionnaire[" << iter->first << "]=" << iter->second << std::endl;
  }

  return 0;
}
