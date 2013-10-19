#include <iostream>
#include <vector>

using namespace std;

void work(vector<int>& in);

int main() {
  vector<int> in;

  in.push_back(1);
  in.push_back(-20);
  in.push_back(4);
  in.push_back(30);
  in.push_back(0);
  in.push_back(-1);
  in.push_back(2);
  work(in);
}

int compute(vector<int>& param, int x) {
  int ret = 0;
  for(int i=0; i<param.size(); i++) {
    ret = ret * x + param[i];
  }

  return ret;
}

void work(vector<int>& param) {
  vector<int> cs;
  cs.push_back(param[param.size()-1]);

  vector<int> vs;
  for(int i=0; i<param.size(); i++) {
    vs.push_back(compute(param, i));
  }

  int sigma = 0;
  for(int i=1; i<vs.size(); i++) {
    int diff = vs[i] - vs[i-1];
    int c = diff - sigma;
    cs.push_back(c);
    sigma += c;
  }

  for(int i=0; i<cs.size(); i++) {
    cout << cs[i] << endl;
  }
}
