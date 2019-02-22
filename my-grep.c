#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

          int i;
          if(argc < 2){
              perror("my-grep: Searchterm [File..]");
		exit(1);
          }
	  else {
               for (i = 2; i < argc; i++){
                   FILE *fp = fopen(argv[i],"r");
	           int len;
	           size_t  buff_size = 0;
                   char *str = NULL;
                   char *ch = argv[1];

                   if(fp ==  NULL){
                      perror("my-grep: cannot open file");
	              exit(1);
                   }

                   while((len = getline(&str, &buff_size, fp)) > 0){
		         if (strstr(str, ch)){
	      	             printf("%s", str);
                         }
                   }
                   fclose(fp);
                }

           }
  return 0;
}
