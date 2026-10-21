#include "secret.h"
#include <random>
int PickSecret(int min, int max) {
     static std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> die{min, max};
    return die(gen);
}
