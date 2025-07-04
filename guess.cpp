#include <cmath>
#include <iostream>
#include <string>

int main() {
  std::srand(time(0));
  std::string userInput;
  int randNumber = (std::rand() % 100) + 1;
  int userNumber;

  int code = 1;

  std::cout << "Hello world, the program have randomed a number within (0, 100) range, try to guess it" << std::endl;
  std::cout << "Type exit to stop the program" << std::endl;
  // std::cout << randNumber << std::endl;
  while (userNumber != randNumber) {
    std::cout << ">>>:";
    std::getline(std::cin, userInput);

    if (userInput == "exit") {
      break;
    }
    int absoluteNumber;

    try {
      userNumber = std::stoi(userInput);
      absoluteNumber = abs(randNumber - userNumber);
    } catch (const std::invalid_argument e) {
      std::cout << "Not a number, please input a number in range (0, 100)" << std::endl;
      continue;
    }

    if (userNumber > 100 || userNumber < 0) {
      std::cout << "Out of range, please input a number in range (0, 100)" << std::endl;
      continue;
    }

    if (userNumber == randNumber) {
      code = 0;
      break;
    } else if (absoluteNumber <= 5) {
      std::cout << "You are very close (<5)" << std::endl;
    } else if (absoluteNumber <= 10) {
      std::cout << "You are close (<10)" << std::endl;
    } else if (absoluteNumber <= 20) {
      std::cout << "You are relatively close (<20)" << std::endl;
    } else if (absoluteNumber <= 30) {
      std::cout << "You are not close (<30)" << std::endl;
    } else if (absoluteNumber <= 50) {
      std::cout << "You are not close (<=50)" << std::endl;
    } else {
      std::cout << "You are not close (>50)" << std::endl;
    }
  }
  if (code == 0) {
    std::cout << "You have guessed the random  number (" << randNumber << ")." << std::endl;
  } else {
    std::cout << "The number was " << randNumber << ". Better luck next time.";
  }

  return 0;
}