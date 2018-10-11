#include <stdio.h>

/* counts characters, vowels, consonants, and punctuation given in str
   - vow, cons, and punct are reference parameters
   author: alexweininger
*/

int count_em(char *str, int *vow, int *cons, int *punct) {
  int i = 0;
  int numChars = 0;
  char *p;
  *vow = 0;
  *cons = 0;
  *punct = 0;

  for(p = str; *p != '\0'; p++) {
    /* lab exercise -- finish loop body to increment
     * appropriate counters */
    // add one to numChars
    numChars++;
    switch(*p) {
    case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': 
    case 'E': case 'I': case 'O': case 'U':
      // add one to vowels
      (*vow)++;
      break;
    case 'b': case 'c': case 'd': case 'f': case 'g': case 'h': 
    case 'j': case 'k': case 'l': case 'm': case 'n': case 'p':
    case 'q': case 'r': case 's': case 't': case 'v': case 'w':
    case 'x': case 'y': case 'z':
    case 'B': case 'C': case 'D': case 'F': case 'G': case 'H':
    case 'J': case 'K': case 'L': case 'M': case 'N': case 'P':
    case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W':
    case 'X': case 'Y': case 'Z':
      // add one to consonants
      (*cons)++;
      break;
    case '.': case ',': case ':': case ';': case '!': case '?':
    case '(': case ')':
      // add one to punctuation
      (*punct)++;
      break;
    }
  }
  return numChars;
}

/* reads file from stdin */
/* usage: a.out < filename.txt */
int main(int argc, char *argv[]) {

  /* this program only works for files whose lines are all shorter than
     2000 characters */
  char buffer[2000];

  int total = 0;
  int vowels = 0;
  int consonants = 0;
  int punc = 0;

  /* read data from stdin */
  for (;;) {
    
    int count = scanf("%1999[^\n]", buffer); /*read up to 1999 chars*/
    if (feof(stdin)) break;
    if (count != 0) {
      int vowels1, consonants1, punc1;
      total += count_em(buffer, &vowels1, &consonants1, &punc1);
      vowels += vowels1;
      consonants += consonants1;
      punc += punc1;
    }
    getc(stdin); /* read newline */
  }

  printf("characters: %d\n", total);
  printf("vowels: %d\n", vowels);
  printf("consonants: %d\n", consonants);
  printf("punctuation: %d\n", punc);

  return 0;
}
