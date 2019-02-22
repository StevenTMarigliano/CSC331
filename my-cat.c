#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int i;
  FILE *fp;
  char ch;

  for (i = 1; i < argc; i++){
      fp = fopen(argv[i], "r");
      if(fp == NULL){
         perror("my-cat: cannot open file");
         exit(1);
      }

      while((ch = fgetc(fp)) != EOF){
           printf("%c", ch);
      }

      fclose(fp);
  }

  return 0;
}
# CSC331
