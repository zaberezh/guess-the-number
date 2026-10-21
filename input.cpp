#include "input.h"
#include <cctype>
#include <ios>
#include <iostream>
#include <string>
bool ReadInt(const std::string &prompt, int min, int max, int &numberOut) {
  while (true) {
    std::cout << prompt;

    if (!(std::cin >> numberOut) || numberOut < min || numberOut > max ||
        std::cin.peek() != '\n') {
      if (std::cin.eof()) {
        return false;
      }
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Ошибка: введите число еще раз\n";
      continue;
    }
    std::cin.ignore(1000, '\n');
    return true;
  }
}
bool ReadLine(const std::string &prompt, std::string &LineOut) {
  std::cout << prompt << '\n';
  if (!std::getline(std::cin, LineOut)) return false;
  return true;
}
bool AskYesNo(const std::string &prompt, bool &yesOut) {
  std::string answer;
  std::string no = "no";
  std::string yes = "yes";

  while (true) {
    if(!ReadLine(prompt, answer)) {
      return 0;
    }
    for (int i = 0; i < answer.size(); i++) {
    answer[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(answer[i])));
  }
    if (answer == "y" || answer == yes) {
      yesOut = true;
      return true;
    }
    else if (answer == "n" || answer == no) {
      yesOut = false;
      return true;
    }
    std::cout << "Ответь. Введите ответ еще раз\n";
  }
}