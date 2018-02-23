#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<string> tab;
  tab.push_back("un"); // tab.ajouter("un");
  tab.push_back("deux");
  tab.push_back("trois");
  tab.push_back("quatre");
  tab.push_back("cinq");
  
  sort(tab.begin(), tab.end());
  for(vector<string>::iterator iter=tab.begin();iter!=tab.end();++iter)
    std::cout << *iter << std::endl;

  return 0;
}
