#include "secret.h"
#include <iostream>
int main() {
    int lowest = 100;
    int highest = 1;
  for (int i = 0; i <= 100000; i++) {
    int secret = PickSecret(1, 100);
    if (secret < lowest) lowest = secret;
    if ( secret > highest) highest = secret;
  }
  std::cout << "Наименьшее: " << lowest << '\n' << "Наибольшее: " << highest << '\n';
  return 0;
}