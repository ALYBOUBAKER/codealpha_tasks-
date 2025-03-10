#ifndef CAESAR_CIPHER_H_INCLUDED
#define CAESAR_CIPHER_H_INCLUDED

#include <string>

// Function to encrypt text using Caesar Cipher
std::string encrypt(const std::string& text, int key);

// Function to decrypt text using Caesar Cipher
std::string decrypt(const std::string& text, int key);


#endif // CAESAR_CIPHER_H_INCLUDED
