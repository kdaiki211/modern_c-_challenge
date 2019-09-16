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

enum class PasswordValidationMethod {
  Length,
  Symbol,
  Number,
  LowerCase,
  UpperCase
};

const size_t MinimumPasswordLength = 8;
bool ValidatePasswordLength(const string password)
{
  return password.length() >= MinimumPasswordLength;
}

const size_t MinimumSymbolLength = 1;
vector<string> Symbols { "!", "\"", "#", "$", "%", "&", "'", "(", ")", "-", "=", "^", "~", "\\", "|", "@", "`", "[", "{", "]", "}", ";", "+", ":", "*", ",", "<", ".", ">", "/", "?", "_" };
bool ValidateSymbol(const string password)
{
  size_t cnt = 0;
  for (auto s : Symbols) {
    if (password.find(s) != string::npos) {
      cnt++;
    }
  }
  return cnt >= MinimumSymbolLength;
}

const size_t MinimumNumberLength = 1;
bool ValidateNumber(const string password)
{
  size_t cnt = 0;
  for (auto c : password) {
    if (isdigit(c)) cnt++;
    if (cnt >= MinimumNumberLength) return true;
  }
  return false;
}

const size_t MinimumLowerCaseLength = 1;
bool ValidateLowerCase(const string password)
{
  size_t cnt = 0;
  for (auto c : password) {
    if (islower(c)) cnt++;
    if (cnt >= MinimumLowerCaseLength) return true;
  }
  return false;
}

const size_t MinimumUpperCaseLength = 1;
bool ValidateUpperCase(const string password)
{
  size_t cnt = 0;
  for (auto c : password) {
    if (isupper(c)) cnt++;
    if (cnt >= MinimumUpperCaseLength) return true;
  }
  return false;
}

map<PasswordValidationMethod, string> pvmExplanation = {
  { PasswordValidationMethod::Length,
    "Length must be >= " + to_string(MinimumPasswordLength) },
  { PasswordValidationMethod::Symbol,
    "Length of symbols must be >= " + to_string(MinimumSymbolLength) },
  { PasswordValidationMethod::Number,
    "Length of numbers must be >= " + to_string(MinimumNumberLength) },
  { PasswordValidationMethod::LowerCase,
    "Length of lower cases must be >= " + to_string(MinimumLowerCaseLength) },
  { PasswordValidationMethod::UpperCase,
    "Length of upper cases must be >= " + to_string(MinimumUpperCaseLength) }
};

using PasswordValidationFunc = bool (*)(const string);

map<PasswordValidationMethod, PasswordValidationFunc> pvmFunc = {
  { PasswordValidationMethod::Length, ValidatePasswordLength },
  { PasswordValidationMethod::Symbol, ValidateSymbol },
  { PasswordValidationMethod::Number, ValidateNumber },
  { PasswordValidationMethod::LowerCase, ValidateLowerCase },
  { PasswordValidationMethod::UpperCase, ValidateUpperCase }
};

bool ValidatePassword(const string password, vector<PasswordValidationMethod>& reason)
{
  bool isValid = true;
  for (auto f : pvmFunc ) {
    bool ret = f.second(password);
    isValid &= ret;
    if (!ret) {
      reason.push_back(f.first);
    }
  }
  return isValid;
}

void ShowReasonsForInvalid(vector<PasswordValidationMethod>& reason)
{
  for (auto r : reason) {
    cout << pvmExplanation[r] << endl;
  }
}

int main(void)
{
  cout << "Enter password: ";
  string password = InputPassword();

  vector<PasswordValidationMethod> reason;
  bool isValidPassword = ValidatePassword(password, reason);

  if (isValidPassword) {
    cout << "Valid." << endl;
  } else {
    cout << "Invalid." << endl;
    ShowReasonsForInvalid(reason);
  }
  return 0;
}

