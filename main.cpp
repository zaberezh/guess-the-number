#include "input.h"
#include "secret.h"
#include <iostream>
void PrintHistory(const int history[], int count) {
  std::cout << "Твои попытки: ";
  for (int i = 0; i < count; i++) {
    std::cout << history[i] << " ";
  }
}
int main(int argc, char *argv[]) {
  std::cout << "Как тебя зовут? ";
  std::string name;
  std::getline(std::cin, name);
  if (name.empty()) name = "Игрок";
  std::cout << "Привет, " << name << "!\n";
  int min = 1;
  int max = 100;
  int secret = 0;
  bool testMode = false;
  try {
    if (argc == 2) {
      int sec = std::stoi(argv[1]);
      if (sec > 100 || sec < 1) {
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
  while (true) {
    if (!testMode)
      secret = PickSecret(min, max);
    std::cout << "Я загадал число от 1 до 100.\n";
    int guess = 0;
    int tries = 0;
    const int kMaxTries = 7;
    int attempts[kMaxTries]{};
    for (int i = 0; i < kMaxTries; i++) {
      if (!ReadInt("Твой вариант: ", 1, 100, guess))
        return 0;
      attempts[i] = guess;
      tries++;
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
      std::cout << "Угадал за " << tries;
      if ((tries % 10 >= 5 && tries % 10 <= 9 || tries % 10 == 0) ||
          (tries >= 11 && tries <= 14)) {
        std::cout << " попыток\n";
      } else if (tries % 10 >= 2 && tries % 10 <= 4) {
        std::cout << " попытки\n";
      } else {
        std::cout << " попытку\n";
      }
    } else {
      std::cout << "Не угадал, загадано " << secret << '\n';
    }
    PrintHistory(attempts, tries);
    bool again;
    if (!AskYesNo("\nЕщё раунд? [y/n]", again)) {
      return 0;
    }
    if (!again) {
      std::cout << "\nПока, " << name << "!\n";
      break;
    }
  }
}