#pragma once
#include <string>
bool ReadInt(const std::string& prompt, int min, int max, int& numberOut);
bool AskYesNo(const std::string& prompt, bool& yesOut);
bool ReadLine(const std::string& prompt, std::string& LineOut);