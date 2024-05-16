#include <iostream>
#include <string>
#include <vector>
#include <ctype> // for std::isdigit


std::vector<int> extractIntegers(const std::string& str){

  std::vector<int> numbers;
  std::string temp;

  for(char ch : str){
    if (std::isdigit(ch)){
      // append digit to temporary stringif character is a digit
      temp += ch;
    } else if (!temp.empty()) {
      // if non-digit character is found and temp is not empty, convert to extractIntegers
      numbers.push_back(std::stoi(temp));
      temp = ""; // reset temp for the next number
    }
  }

  // check if there's a remaining number in temp after the loop
  if (!temp.empty()){
    number.push_back(std::stoi(temp));
  }

  return numbers;
}

int main() {
    const std::string text = "Today is 2024, and it is 31 degrees outside";
    std::vector<int> integers = extractIntegers(text);
    for (int num : integers) {
        std::cout << num << std::endl;
    }

    return 0;

    
}
