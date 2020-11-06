#ifndef MPAGS_CAESARCIPHER_HPP
#define MPAGS_CAESARCIPHER_HPP

#include <string>
#include <vector>

class CaesarCipher {
public:
  explicit CaesarCipher(const size_t key);
  explicit CaesarCipher(const std::string& key);
  std::string applyCipher( const std::string& inputText, const bool encrypt) const;
  

private:
  size_t key_=0;
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const std::vector<char>::size_type alphabetSize_ = alphabet_.size();
};
#endif
