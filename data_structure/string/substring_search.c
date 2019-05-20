#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* computeTemporaryArray(char* pattern)
{
  int *lps = (int*)malloc(sizeof(int)*strlen(pattern));
  memset(lps,0, sizeof(int)*strlen(pattern));
  int j = 0;
  int i = 1;
  while (pattern[i]) {
    if (pattern[i] == pattern[j]) {
      ++j;
      lps[i] = j;
      ++i;
    }else{
      if (j==0) {
        lps[i] = 0;
        ++i;
      }else{
        j = lps[j-1];
      }
    }
  }

  return lps;
}
int kmp(char* text, char* pattern)
{
  /*
  在字符串text中查找子串pattern，若存在返回在字符串text中的位置，否则返回-1;
  使用KMP字符串匹配算法
  */
  int pos = -1;
  int* lps = computeTemporaryArray(pattern);
  int len_pattern = strlen(pattern);
  int len_text = strlen(text);
  printf("temporarayArray:");
  for (int i = 0; i < len_pattern; i++) {
    printf("%d ", lps[i]);
  }
  printf("\n");

  int i=0,j=0;
  while (i<len_text && j<len_pattern) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    }else{
      if (j!=0) {
        j=lps[j-1];
      }else{
        i++;
      }
    }
  }
  if (j==len_pattern) {
    pos = i-j+1;
  }
  return pos;
}

int main(int argc, char const *argv[])
{
  char* text = "abxabcadyabdabcabdx";
  char* pattern = "abcabdx";
  int pos = kmp(text, pattern);
  printf("substr pos: %d\n", pos);
  return 0;
}
