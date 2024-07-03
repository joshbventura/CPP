#ifndef VIGENERE_H
#define VIGENERE_H
#include "Cipher.h"
#include <istream>
#include <string>
using namespace std;

class Vigenere: public Cipher{
 public:
  Vigenere();
  Vigenere(string, bool, string);
  ~Vigenere();
  void Encrypt();
  void Decrypt();
  string ToString();
  string FormatOutput();
 private:
  string m_shift;
 };

#endif