#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> tab;
  tab.push_back("un"); // tab.ajouter("un");
  tab.push_back("deux");
  tab.push_back("trois");
  tab.push_back("quatre");
  tab.push_back("cinq");
  
  vector<string> tab2 = tab;
  for (vector<string>::iterator iter = tab2.begin(); iter != tab2.end(); ++iter)
    cout << *iter << endl;
}
