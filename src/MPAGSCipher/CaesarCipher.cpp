#include <iostream>
#include <string>
#include <vector>

#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const size_t key)
  : key_{key % alphabet_.size()}
{
}

CaesarCipher::CaesarCipher(const std::string& key)
  : key_{0}
{
  if (!key.empty())
    {
      for ( const auto& elem : key ) {
	if ( ! std::isdigit(elem) ) {
	  std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
		    << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	  return;
	}
      }
      key_ = std::stoul(key) % alphabetSize_; 
    }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const
{
  std::string outputText {""};

  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {
    for (size_t i{0}; i< alphabetSize_; ++i ) {

      if ( origChar == alphabet_[i] ) {
	switch (cipherMode) {
	case CipherMode::Encrypt :
	  processedChar = alphabet_[ (i + key_) % alphabetSize_ ];
	  break;
	case CipherMode::Decrypt :
	  processedChar = alphabet_[ (i + alphabetSize_ - key_) % alphabetSize_ ];
	  break;
	}
	break;
      }
    }
    outputText += processedChar;
  }
  return outputText;
}
