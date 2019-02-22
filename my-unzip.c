#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
          FILE *fp;
	  int len, count, frst, sec, num1, num2;
          char *str = NULL;
          size_t size;
          if(argc < 1){
	      perror("my-unzip: file1 {file2...]\n");
	      exit(1);
	  }
          for(int i = 1; i < argc; i++){
		fp = fopen(argv[i], "r");
		if(fp == NULL){
		    perror("my-unzip: cannot open file");
                    exit(1);
                }
 		while((len = getline(&str, &size, fp)) > 0){
                       for(int j = 0; j < len; j++){
		           count = 0;
                           frst = str[j];
	                   sec = str[j+1];
         	           if(isdigit(str[j]) != 0 && isdigit(str[j+1]) != 0){
			        num1 = frst - '0';
                                num2 = sec - '0';
                                count = (num1 * 10) + num2;
                                for(int k = 1; k < count; k++){
 			             printf("%c", str[j+2]);
			        }
			    }else if(isdigit(str[j]) != 0){
				      num1 = frst - '0';
                                      count = num1;
				      for(int k = 1; k < count; k++){
				               printf("%c", str[j+1]);
				       }
			    }else{
                                  printf("%c", str[j]);
                             }
                          }

	 	  }
                  fclose(fp);
	   }
return 0;
}
