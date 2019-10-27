#include <iostream>
#include <string>

using namespace std;

static string caesar(const string target, const int rot)
{
    string result = target;
    const size_t len = target.length();
    constexpr size_t numOfAlphabets = ('Z' - 'A' + 1);
    for (size_t i = 0; i < len; i++) {
        if (target[i] >= 'A' && target[i] <= 'Z') {
            result[i] = ((target[i] - 'A' + rot) % numOfAlphabets) + 'A';
        }
    }
    return result;
}

string enc(const string plain, const size_t rot)
{
    return caesar(plain, rot);
}

string dec(const string secret, const size_t rot)
{
    return caesar(secret, -rot);
}

int main(void)
{
    const size_t rot = 3;
    const string sampleText = "HELLO, WORLD!";
    const string encodedText = enc(sampleText, rot);
    const string decodedText = dec(encodedText, rot);
    cout << sampleText << endl;
    cout << encodedText << endl;
    cout << decodedText << endl;
    return 0;
}

/*
 * 実行結果
 * HELLO, WORLD!
 * KHOOR, ZRUOG!
 * HELLO, WORLD! 
 */