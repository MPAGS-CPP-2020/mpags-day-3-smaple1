#ifndef MPAGS_CAESARCIPHER_HPP
#define MPAGS_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
public:
  explicit CaesarCipher(const size_t key);
  explicit CaesarCipher(const std::string& key);
  size_t key_=0;
};

#endif
