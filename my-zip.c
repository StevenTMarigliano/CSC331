#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

int main(int argc, char *argv[]){
          FILE *fp;
          char *str = NULL;
          const char space  = ' ';
          const char newline =  '\n';
          char temp;
          size_t size;
          int len, count, i, j;

          if(argc < 1){
              perror("my-zip: file1 [file2...]");
              exit(1);
          }
          for(i = 1; i < argc; i++){ 
              fp = fopen(argv[i], "r");

               if(fp == NULL){
                   perror("my-zip: Cannot find file");
                   exit(1);
               }
              while((len = getline(&str, &size, fp)) > 0){
                     for(j  = 0; j < len; j++){
                          count = 1;
                          while(str[j] == str[j+1]){
                                count++;
                                j++;
                          }
                         temp = str[j];
                         if(temp == space){
                             printf("%c", space);
                         }
                         else if(temp == newline){
                                   printf("%c", newline);
                         }
                         else{
                              printf("%d%c", count, str[j]);
                         }
		     }
               }
          fclose(fp);
          }
         return 0;
}
