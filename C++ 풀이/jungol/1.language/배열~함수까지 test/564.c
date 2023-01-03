#include <stdio.h>

int main() {

 char ch;
 int arr[26] = { 0 }, i;

 while (1) {
  scanf(" %c", &ch);
  if (ch >= 'A'&&ch <= 'Z')
   arr[ch - 65]++;
  else
   break;
 }

 for (i = 0; i < 26; i++) {
  if (arr[i] != 0)
   printf("%c : %d \n", i + 65, arr[i]);
 }

 return 0;
}