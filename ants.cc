#include <iostream>
#include <map>
#include <string>

using namespace std;

#define SENT -2147483647

int work(string s);

int main() {
  string s = "SEEENWSSENENWSES";
  cout << work(s) << endl;
}

int work(string s) {
  map<pair<int, int>, pair<int, int> > ancestor;

  pair<int, int> cur, prev;
  cur.first = cur.second = 0;
  prev.first = prev.second = SENT;
  ancestor[cur] = prev;

  for(int i=0; i<s.size(); i++) {
    prev = cur;

    char dir = s.at(i);
    if(dir == 'E') {
      cur.first += 1;
    } else if(dir == 'S') {
      cur.second -= 1;
    } else if(dir == 'W') {
      cur.first -= 1;
    } else {
      cur.second += 1;
    }

    if(ancestor.find(cur) == ancestor.end()) {
      ancestor[cur] = prev;
    }
  }

  int count = 0;
  while(ancestor.find(cur) != ancestor.end() &&
	ancestor[cur].first != SENT &&
	ancestor[cur].second != SENT) {
    cur = ancestor[cur];
    count++;
  }

  return count;
}
