#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

void lireEntreeStandard(map<string, map<string, int>>& dict);
void inserer(map<string, map<string, int>>& dict, vector<string>& phrase);
void afficher(map<string, map<string, int>>& dict);

int main() {
  map<string, map<string, int>> dict;
  lireEntreeStandard(dict);
  //afficher(dict);

  // afficher la cooccurrence de deux mots la plus fréquente dans le texte
  tuple<string, string, int> max = make_tuple("", "", 0);
  for (auto it1 = dict.begin(); it1 != dict.end(); it1++) {
    for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
      if (it2->second > get<2>(max)) {
        max = make_tuple(it1->first, it2->first, it2->second);
      }
    }
  }

  cout << get<0>(max) << " " << get<1>(max) << " " << get<2>(max) << endl;

  return 0;
}

void lireEntreeStandard(map<string, map<string, int>>& dict) {
  while (cin) {
      // lire tous les mots de la phrase
      vector<string> phrase;
      string mot;
      do {
        cin >> mot;
        if (mot.length() >= 3) {
          phrase.push_back(mot);
        }
      // Tant que la phrase n'est pas finie par un point (.), point d'exclamation, point d'interrogation
      } while(cin && mot != "." && mot != "!" && mot != "?");

      inserer(dict, phrase);
  }
}

void inserer(map<string, map<string, int>>& dict, vector<string>& phrase) {
  for (vector<string>::size_type i = 0; i < phrase.size(); i++) {
    const string& mot1 = phrase[i];
    for (vector<string>::size_type j = 0; j < phrase.size(); j++) {
      const string& mot2 = phrase[j];
      if (i == j || mot1 == mot2) {
        continue;
      }
      map<string, map<string, int>>::iterator it1 = dict.find(mot1);
      if (it1 != dict.end()) {
        map<string, int>::iterator it2 = it1->second.find(mot2);
        if (it2 != it1->second.end()) {
          it2->second += 1;
        } else {
          it1->second[mot2] = 1;
        }
      } else {
        dict[mot1][mot2] = 1;
      }
    }
  }
}

void afficher(map<string, map<string, int>>& dict) {
  for (auto it1 = dict.begin(); it1 != dict.end(); it1++) {
    cout << it1->first << endl;
    for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
      cout << it2->first << " => " << it2->second << endl;
    }
    cout << "==========" << endl;
  }
}
