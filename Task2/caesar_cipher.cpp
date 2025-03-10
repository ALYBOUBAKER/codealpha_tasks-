#include "caesar_cipher.h"

// Encrypt text using Caesar Cipher
std::string encrypt(const std::string& text, int key) {
    std::string result = "";
    for (char ch : text) {
        if (isalpha(ch)) { // Only shift alphabetic characters
            char base = islower(ch) ? 'a' : 'A';
            ch = static_cast<char>((ch - base + key) % 26 + base);
        }
        result += ch; // Non-alphabetic characters remain unchanged
    }
    return result;
}

// Decrypt text using Caesar Cipher
std::string decrypt(const std::string& text, int key) {
    return encrypt(text, 26 - key); // Decryption is just encryption with the inverse key
}
