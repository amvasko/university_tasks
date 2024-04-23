#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isPrime(int num) {
  if (num <= 1)
    return false;
  for (int i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int digitSum(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

bool isDivisible(int num) {
  int firstTwo = num / 100;
  int lastTwo = num % 100;
  int sum = firstTwo + lastTwo;
  return (num % sum == 0);
}

int firstBiggerPrime(int num) {
  while (true) {
    num++;
    if (isPrime(num))
      return num;
  }
}

int main() {
  // Task 1: Four-digit numbers divisible by the sum of their first two and last
  // two digits
  int divisibleCount = 0;
  cout << "Task 1: Four-digit numbers divisible by the sum of their first two "
          "and last two digits:\n";
  for (int i = 1000; i < 1100; ++i) {
    if (isDivisible(i)) {
      cout << i << " ";
      divisibleCount++;
    }
  }
  cout << "\nTotal count: " << divisibleCount << "\n\n";

  // Task 2: Difference between a given number and the first bigger prime number
  int input = 10;
  int nextPrime = firstBiggerPrime(input);
  cout << "Task 2: First bigger prime number after " << input << ": "
       << nextPrime << endl;
  cout << "Difference: " << nextPrime - input << "\n\n";

  // Task 3: Prime numbers smaller than 1000 whose sum of digits is also prime
  int primeSumCount = 0;
  cout << "Task 3: Prime numbers smaller than 1000 whose sum of digits is also "
          "prime:\n";
  for (int i = 2; i < 1000; ++i) {
    if (isPrime(i) && isPrime(digitSum(i))) {
      cout << i << " ";
      primeSumCount++;
    }
  }
  cout << "\nTotal count: " << primeSumCount << endl;

  return 0;
}
