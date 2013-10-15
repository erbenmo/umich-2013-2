#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int work(vector<int> in);

int main() {
  vector<int> in;
  in.push_back(1);
  in.push_back(2);
  in.push_back(3);
  in.push_back(4);
  in.push_back(5);
  in.push_back(6);
  in.push_back(7);
  in.push_back(8);
  in.push_back(9);
  in.push_back(10);

  cout << work(in) << endl;
}

int work(vector<int> in) {
  stack<int> s;
  for(int i=0; i<in.size(); i++) {
    int cur = in[i];
    if(s.empty()) {
      s.push(cur);
    } else if((s.top() + cur) % 2 == 0) {
      s.pop();
    } else {
      s.push(cur);
    }
  }

  return s.size();
}
