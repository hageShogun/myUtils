#include <iostream>
#include <cmath>
#include <vector>

namespace hageShogun_util {

  // general swap
  template<typename T>
  void swap(T& a, T& b) {T t; t=a; a=b; b=t;}

  // gcd (Euclid method)
  int gcd(int a, int b) {
    if (a<b) 
      swap<int>(a,b);
    while (b > 0) {
      int r = a % b;
      a = b;
      b = r;
    }
    return a;
  }

  // Prime number check
  // If x is NOT a prime number, x MUST have a divisor which is less than sqrt(x).
  bool isPrime(int x) {
    if (x == 2)
      return true;
    if (x<2 || (x%2)==0)
      return false;
    int i = 3;
    while (i <= sqrt(x)) {
      if ((x%i)==0)
	return false;
      i += 2;
    }
    return true;
  }

  // Sieve of Eratosthenes
  // return th prime numbers list less than n.
  std::vector<bool> eratosthenes(int n) {
    std::vector<bool> is_prime(n, true);
    
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<=sqrt(n); ++i) {
      if (is_prime[i]) {
	for (int j=2; i*j<=n; ++j)
	  is_prime[i*j] = false;
      }
    }
    return is_prime;
  }

};
