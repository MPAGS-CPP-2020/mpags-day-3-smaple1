#include <iostream>
#include <string>

#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const size_t key)
  : key_{key}
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
      key_ = std::stoul(key); 
    }

}
