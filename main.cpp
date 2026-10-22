#include "input.h"
#include "secret.h"
#include <iomanip>
#include <iostream>
#include <vector>
double Average(const  std::vector<int>& pile) {
  double avg = 0;
  for (int i = 0; i < pile.size(); i++) {
    avg += pile[i];
  }
  return avg / pile.size();
}
void PrintHistory(const std::vector<int> &history) {
  std::cout << "Твои попытки: ";
  for (int i = 0; i < history.size(); i++) {
    std::cout << history[i] << " ";
  }
}
int main(int argc, char *argv[]) {
  const int min = 1;
  const int max = 100;
  int secret = 0;
  bool testMode = false;
  try {
    if (argc == 2) {
      int sec = std::stoi(argv[1]);
      if (sec > max || sec < min) {
        std::cout << "Неверный ввод заранее заданного числа\n";
        return 1;
      }
      secret = sec;
      testMode = true;
    }
  } catch (const std::invalid_argument &) {
    std::cout << "Неверный ввод заранее заданного числа\n";
    return 1;
  } catch (const std::out_of_range &) {
    std::cout << "Заданное заранее число слишком большое\n";
    return 1;
  }
std::vector<int> rounds;
  std::cout << "Как тебя зовут? ";
  std::string name;
  std::getline(std::cin, name);
  if (name.empty())
    name = "Игрок";
  std::cout << "Привет, " << name << "!\n";
  while (true) {
    if (!testMode)
      secret = PickSecret(min, max);
    std::cout << "Я загадал число от " << min << " до " << max << ".\n";
    int guess = 0;
    const int kMaxTries = 7;
    std::vector<int> attempts;
    for (int i = 0; i < kMaxTries; i++) {
      if (!ReadInt("Твой вариант: ", min, max, guess))
        return 0;
      attempts.push_back(guess);
      if (guess == secret) {
        break;
      }
      if (guess < secret) {
        std::cout << "Больше\n";
      } else {
        std::cout << "Меньше\n";
      }
    }
    if (guess == secret) {
      rounds.push_back(attempts.size());
      std::cout << "Угадал за " << attempts.size();
      if ((attempts.size() % 10 >= 5 && attempts.size() % 10 <= 9 || attempts.size() % 10 == 0) ||
          (attempts.size() >= 11 && attempts.size() <= 14)) {
        std::cout << " попыток\n";
      } else if (attempts.size() % 10 >= 2 && attempts.size() % 10 <= 4) {
        std::cout << " попытки\n";
      } else {
        std::cout << " попытку\n";
      }
    } else {
      std::cout << "Не угадал, загадано " << secret << '\n';
    }
    PrintHistory(attempts);
    bool again;
    if (!AskYesNo("\nЕщё раунд? [y/n]", again)) {
      return 0;
    }
    if (!again) {
      int lowest = 7;
      for (int i = 0; i < rounds.size(); i++) {
        if (rounds[i] < lowest)
          lowest = rounds[i];
      }
      std::cout << "Угадано раундов: " << rounds.size();
      if (!rounds.empty()) {
        std::cout << ", лучший результат: " << lowest << ", в среднем: ";
        std::cout << std::fixed << std::setprecision(1) << Average(rounds) << '\n';
      } else {
        std::cout << '\n';
      }
      std::cout << "Пока, " << name << "!\n";
      break;
    }
  }
}