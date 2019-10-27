#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cassert>

using namespace std;

char tbl[] = {
               'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
               'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
               '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
               };

uint8_t getKey(const uint8_t* const bin, const size_t binSizeInBit, const size_t startBit, const size_t keyLengthInBit)
{
    assert(keyLengthInBit <= 9);
    const auto startByte = startBit / 8;
    const auto offset = startBit % 8; // 1 バイト内の bit 単位のオフセット (MSB から)
    auto remainBit = keyLengthInBit;
    uint8_t buf[2] = {0};

    auto endBit = min(7, (int)(offset + keyLengthInBit - 1));
    auto l = endBit - offset + 1;
    buf[0] = bin[startByte];
    buf[0] <<= offset;
    buf[0] >>= offset + (7 - endBit);
    remainBit -= l;

    if (remainBit) {
        buf[1] = bin[startByte + 1];
        buf[1] >>= 8 - remainBit;
    }

    // cout << "buf[0] = 0x" << hex << (int)buf[0] << endl;
    // cout << "buf[1] = 0x" << hex << (int)buf[1] << endl;
    // cout << "remainBit = " << remainBit << endl;
    auto key = (buf[0] << remainBit) | buf[1];
    return key;
}

string base64(const uint8_t* const bin, const size_t binSize)
{
    string result;
    const size_t binSizeInBit = binSize * 8;
    constexpr size_t keyLengthInBit = 6;
    for (size_t bit = 0; bit < binSizeInBit; bit += keyLengthInBit) {
        const uint8_t key = getKey(bin, binSizeInBit, bit, keyLengthInBit);
        // cout << "key is " << dec << (int)key << endl;
        assert(key < sizeof(tbl) / sizeof(tbl[0]));
        const char decoded = tbl[key];
        result += string(1, decoded);
    }
    result += string(binSizeInBit % keyLengthInBit % 4, '=');
    return result;
}

int main(void)
{
    const string sampleText = "ABCDEFG";
    cout << base64((const uint8_t* const)sampleText.c_str(), sampleText.length()) << endl;
    return 0;
}