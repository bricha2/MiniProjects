// proj1.cpp
// Brianna Richardson

#include <iostream> 
#include "proj1.h"
#include <cstring>
using namespace std;
int main() {
  return 0;
}
void Decipher(char cip[], char key) {
  key -= 65;
  for (int i = 0; cip[i] != '\0'; i++) {
    if (cip[i] == ' ')
     continue;
    cip[i] = cip[i] - key;
    if (cip[i] < 'A')
      cip[i] += ALPHALEN;
  }
  return;
}
char SolveCipher(const char cip[], char dec[]) {
  for (int j = 0; j < ALPHALEN; j++) {
    strncpy(dec, cip, MAXMSGLEN);
    for (int i = 0; cip[i] != '\0'; i++) {
      if (cip[i] == ' ') 
        continue;
      dec[i] -= j;
      if (dec[i] < 'A')
        dec[i] += ALPHALEN;
    }
    for (int i = 0; i < NUMCRIBS; i++) {
      if (strncmp(dec, cribs[i], strlen(cribs[i])) == 0){
	char letter = j + 65;
	cout << "Key: " << letter << endl;
	cout << dec << endl;
	return letter;
      }
    }
  }
  cout << "The message was not interesting." << endl;
  strncpy(dec, cip, MAXMSGLEN);
  return '\0';
}
