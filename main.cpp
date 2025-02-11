#include <iostream>
#include <string>

using namespace std;

// Functions' prototypes
string compress(string str, int strLen);
string deCompress(string str, int strLen);

int main() {
  string strIn;
  int stringLength = 0;
  string answer;
  cout << "Choose operation: (Write 1-3)" << endl;
  cout << "1. Compress" << endl;
  cout << "2. Decompress" << endl;
  cout << "3. Exit" << endl;
  cin >> answer;
  if (answer == "1") { // Compress
    cout << "Enter string to compress: ";
    cin >> strIn;
    stringLength = strIn.length();
    if (strIn.empty()) {
      cout << "String is empty" << endl;
    } else {
      string output = compress(strIn, stringLength);
      cout << "Output: " << output << endl;
    }
  } else if (answer == "2") { // Decompress
    cout << "Enter string to decompress: ";
    cin >> strIn;
    stringLength = strIn.length();
    if (strIn.empty()) {
      cout << "String is empty" << endl;
    } else {
      string output = deCompress(strIn, stringLength);
      cout << "Output: " << output << endl;
    }
  } else if (answer == "3") {
    exit(0); // Exit
  } else {   // Mistake
    cout << "Invalid input. Try again!" << endl;
  }
}

string compress(string str, int strLen) {
  char *charIn;
  charIn = new char[strLen];
  for (int i = 0; i < strLen; i++) { // String to char array for easier checking
    charIn[i] = str[i];
  }
  str = "";
  int tempInt = 1;
  for (int i = 0; i < strLen; i++) {
    if (charIn[i] < 'a' ||
        charIn[i] > 'z') { // checks if char is a lower-letter
      cout << "Invalid input" << endl;
      exit(0);
    }
    if (i < strLen - 1 &&
        charIn[i] == charIn[i + 1]) { // checking if next char is the same
      tempInt++;
    } else {
      str += charIn[i];
      str += to_string(tempInt);
      tempInt = 1;
    }
  }
  delete[] charIn; // Freeing memory
  return str;
}

string deCompress(string str, int strLen) {
  int count;
  string answer = "";
  int i = 0; // While loop counter
  while (i < strLen) {
    // Check if first character is a letter
    if ((char)str[i] < 'a' || (char)str[i] > 'z') {
      cout << "Invalid input: Must follow <letter> + <number> format" << endl;
      exit(0);
    }

    char letter = str[i++];
    string countStr = "";

    // Extracting the number
    while (i < strLen && isdigit(str[i])) {
      countStr += str[i++];
    }

    if (countStr.empty()) {
      cout << "Invalid input: Missing number after letter" << endl;
      exit(0);
    }

    try {
      count = stoi(countStr); // String to Integer

      // Ensure valid count (must be > 0)
      if (count <= 0) {
        cout << "Invalid input: Count must be > 0" << endl;
        exit(0);
      }

    } catch (...) { // Catching error
      cout << "Invalid input" << endl;
      exit(0);
    }

    for (int i = count; i > 0; i--) { // Print
      answer += letter;
    }
  }
  return answer;
}
