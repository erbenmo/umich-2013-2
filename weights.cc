#include <iostream>
#include <map>
#include <assert.h>
#include <vector>

using namespace std;

void weight(int target);

int main() {
  for(int i=1; i<251; i++) {
    cout << i << endl;
    weight(i);
    cout << endl << endl;
  }
}

void print(map<int, bool>& l, map<int, bool>& r) {
  cout << "left pan: ";
  for(map<int, bool>::iterator it = l.begin(); it != l.end(); it++) {
    if(it->second == true)
      cout << it->first << " ";
  }
  cout << endl;

  cout << "right pan: ";
  for(map<int, bool>::iterator it = r.begin(); it != r.end(); it++) {
    if(it->second == true)
      cout << it->first << " ";
  }
  cout << endl;
}

void weight(int target) {
  assert(target >= 1);
    
  map<int, bool> l;
  map<int, bool> r;
  vector<int>in3;

  int c = 1;

  while(c*3 <= target) c*=3;

  while(c != 0) {
    int cur = target / c;
    in3.insert(in3.begin(), cur);
    target = target % c;
    c /= 3;
  }

  c = 1;
  for(int i=0; i<in3.size(); i++) {
    int cur = in3[i];
    if(cur == 1) {
      if(r[c] == true) {
	r[c] = false;
	r[c*3] = true;
	l[c] = true;
      } else {
	r[c] = true;
      }
    } else if(cur == 2) {
      r[c*3] = true;
      if(r[c]) {
	r[c] = false;
      } else {
	l[c] = true;
      }
    }

    c *= 3;
  }

  print(l, r);
}

