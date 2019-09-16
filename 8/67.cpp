#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string InputPassword(void)
{
  string password;
  // TODO: disable echoback
  cin >> password;
  // TODO: enable echoback
  return password;
}

class Checker {
public:
  virtual bool isSatisfied(string password) = 0;
};

class LengthChecker : public Checker {
public:
  LengthChecker(size_t minCnt) : minCnt(minCnt) {}
  bool isSatisfied(string password) override {
    return password.length() >= minCnt;
  }
protected:
  size_t minCnt;
};

class ContainsNCharactersChecker : public Checker {
public:
  ContainsNCharactersChecker(size_t minCnt) : minCnt(minCnt) {}
  bool isSatisfied(string password) override {
    size_t cnt = 0;
    for (auto c : password) {
      if (isValidChar(c)) cnt++;
      if (cnt >= minCnt) return true;
    }
    return false;
  }
protected:
  size_t minCnt;
  virtual bool isValidChar(char c) = 0;
};

class ContainsNSymbolsChecker : public ContainsNCharactersChecker {
public:
  ContainsNSymbolsChecker(size_t minCnt) : ContainsNCharactersChecker(minCnt) {}
protected:
  bool isValidChar(char c) override {
    return find(symbols.begin(), symbols.end(), c) != symbols.end();
  }
  vector<char> symbols { '!', '\'', '#', '$', '%', '&', '\'', '(', ')', '-', '=', '^', '~', '\\', '|', '@', '`', '[', '{', ']', '}', ';', '+', ':', '*', ',', '<', '.', '>', '/', '?', '_' };
};

class ContainsNNumbersChecker : public ContainsNCharactersChecker {
public:
  ContainsNNumbersChecker(size_t minCnt) : ContainsNCharactersChecker(minCnt) {}
protected:
  bool isValidChar(char c) override {
    return isdigit(c);
  }
};

class ContainsNLowerCasesChecker : public ContainsNCharactersChecker {
public:
  ContainsNLowerCasesChecker(size_t minCnt) : ContainsNCharactersChecker(minCnt) {}
protected:
  bool isValidChar(char c) override {
    return islower(c);
  }
};

class ContainsNUpperCasesChecker : public ContainsNCharactersChecker {
public:
  ContainsNUpperCasesChecker(size_t minCnt) : ContainsNCharactersChecker(minCnt) {}
protected:
  bool isValidChar(char c) override {
    return isupper(c);
  }
};

class PasswordValidator {
public:
  void addChecker(Checker* checker) {
    this->checker.push_back(checker);
  }
  bool isValid(string password) {
    for (auto c : checker) {
      if (!c->isSatisfied(password)) return false;
    }
    return true;
  }
private:
  vector<Checker*> checker;
};

static void initMyValidator(PasswordValidator& validator)
{
  static LengthChecker lengthChecker(8);
  static ContainsNSymbolsChecker containsNSymbolsChecker(1);
  static ContainsNNumbersChecker containsNNumbersChecker(1);
  static ContainsNLowerCasesChecker containsNLowerCasesChecker(1);
  static ContainsNUpperCasesChecker containsNUpperCasesChecker(1);

  validator.addChecker(&lengthChecker);
  validator.addChecker(&containsNSymbolsChecker);
  validator.addChecker(&containsNNumbersChecker);
  validator.addChecker(&containsNLowerCasesChecker);
  validator.addChecker(&containsNUpperCasesChecker);
}

int main(void)
{
  cout << "Enter password: ";
  string password = InputPassword();

  PasswordValidator validator;
  initMyValidator(validator);

  if (validator.isValid(password)) {
    cout << "Valid." << endl;
  } else {
    cout << "Invalid." << endl;
  }
  return 0;
}

