#include <iostream>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

void goldbach(int n);

int main() {
  goldbach(32000);
  /*
  for(int i=4; i<=20; i+=2) {
    cout << i << endl;
    goldbach(i);
    cout << endl << endl;
  }
  */
}

bool isPrime(int x) {
  int lower = ceil(sqrt(x));
  for(int i=2; i<=lower; i++) {
    if(x % i == 0)
      return false;
  }

  return true;
}

void goldbach(int n) {
  // construct prime
  vector<int> primes;
  map<int, bool> is_prime;
  for(int i=2; i<=n-2; i++) {
    if(isPrime(i)) {
      primes.push_back(i);
      is_prime[i] = true;
    }
  }

  for(int i=0; i<primes.size(); i++) {
    if(primes[i] > n/2)
      break;
    
    int rest = n-primes[i];
    if(is_prime[rest]) {
      cout << " " << primes[i] << " "  << rest << endl;
    }
  }
}
