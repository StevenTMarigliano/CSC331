#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Function declarations for built in commands
int cd(char **args);
int exit();
//definitions for built in commands
char *builtInComms[] = {"cd", "exit"};
int (*builtInFuncs[])(char **) =(&cd, &exit); 
//reads the entire line of arguments passed into the command line
char *readLine(){
	char *arg = NULL;
	size_t buff = 0;
	getline(&arg, &buff, stdin);
	return arg;
}
//splits the arguments passed in to seperate commands, using white space as a delimiter
char **splitArg(char *arg){
	size_t tkBuff = 64, pos = 0;
	char tkDelim[10] = " \t\r\n\a";
	char *tks = malloc(tk_buff * (sizeof(char*));
	char *tk;
	if(!tks){//checks if buffer allocation failed
		printf("grsh: Allocation error shas occured\n");
		exit(EXIT_FAILURE);
	}else{
		tks = strtok(arg,tk_ delim);
		while(tk != NULL){ //if the token isn't a white space
			tks[pos] = tk;
			pos++;
			if(pos >= tk_buff){
				tk_buff += tk_buff;
				arg = realloc(arg, tk_buff * sizeof(char*));
				if(!arg){//checks if buffer allocation failed
					prinft("grsh: Allocation error has occured\n");
					exit(EXIT_FAILURE);
				}
			}
			tk = strtok(NULL, tk_delim);
		}
		tks[pos] = NULL;
	}
	return tks;
}
//function to get the number of built in commands given
int numComms(){
	return sizeof(builtInComm) / sizeof(char *);
}
//checks if command definitions was given
int cd(char **args){
	if(args[1] == NULL){
		printf("grsh: expected \"cd\"\n");
	}else{
		if(chdir(args[1]) != 0){
			printf("grsh ");
		}
	}
	return 1;
}
//function for built in exit command
int exit(){
	return 0;
}
//creates the child process and the run command
int grshStart(char **args){
	pid_t pid, wpid;
	int stat;
	pid = fork();
	if(pid == 0){
		if(execv(arg[0], args) == -1){ //child process
			printf("grsh: ");
		}
		exit(EXIT_FAILURE);
	}else if(pid < 0){
		//fork error
		printf("grsh: ");
	}else{
		do{
		wpid = waitpid(pid, &stat, WUNTRACED); //parent process
		while(!WFEXITED(stat) && !WIFSIGNALED(stat));
		}
	}
	return 1;
}
//executes the commands passed in the terminal
int execComms(char **args){
	if(args[0] == NULL){ //check for no arguments
		return 1;
	}
	for(int i = 0; i < numComms(); i++){
		if(strcmp(args[0], builtInComms[i]) == 0){
			return (*builtInFuncs[i])(args);
		}
	}
	return grshStart(args);
}

int main(int argc, char *argv[]){
	if(argc ==  1){
		char *line;
		char **args;
		int stat;
		do{
			printf("grsh> ");
			line = readLine();
			args = splitArg(line);
			stat = execComm(args);
			free(line);
			free(args);
		}while(status);
	}else if(argc == 2){
		FILE *fp;
		char line[100];
		char **args;
		fp = fopen(filename, "r");
		if(fp == NULL){
			printf("grsh: File Error\n");
			return 1;
		}else{
			printf("File Opened. Parsing...");
			while(fgets(line, sizeof(line), fp) != NULL){
				printf("\n%s", line);
				args = splitArgs(line);
				exec = execComms(args);
			}
		}
		free(args);
		fclose(fp);

	}else{
		printf("Invalid Number of Arguments");
	}
	return 0;
}
