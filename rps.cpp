#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <string>

class Rps {
public:
  std::map<char, char> WinConditions = {
      {'R', 'S'},
      {'P', 'R'},
      {'S', 'P'},
  };
};

int main() {
  std::srand(time(0));
  Rps obj;
  int statusCode = 1;
  std::string userInput;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, obj.WinConditions.size() - 1);

  while (true) {
    std::cout << "Rock, Paper or Scissors? (type only first letter) >>: ";
    std::getline(std::cin, userInput);

    if (userInput == "exit" || userInput == "ex") {
      statusCode = 0;
      break;
    }

    auto it = obj.WinConditions.begin();
    std::advance(it, dis(gen));
    char randKey = it->first;

    char userChar = toupper(userInput[0]);

    auto charIt = obj.WinConditions.find(userChar);

    if (charIt == obj.WinConditions.end()) {
      std::cout << "Key " << userChar << " Not found. Please type rock, paper, or scissors" << std::endl;
      continue;
    }

    std::cout << "Computer chose: " << randKey << " Will win if user chose: " << obj.WinConditions[randKey] << std::endl;
    std::cout << "User chose: " << userChar << " Will win if computer chose: " << obj.WinConditions[userChar] << std::endl;

    if (userChar == randKey) {
      std::cout << "Tie." << std::endl;
    }
    if (obj.WinConditions[userChar] == randKey) {
      std::cout << "User won." << std::endl;
    }
    if (obj.WinConditions[randKey] == userChar) {
      std::cout << "Computer won." << std::endl;
    }
  }
  return statusCode;
}