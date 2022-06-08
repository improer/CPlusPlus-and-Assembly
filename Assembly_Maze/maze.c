/* 
Andrew
hw1
This will solve a maze in a txt file
*/
#include "header.h"


int main(int argc, char * argv[]){	
	if(check_error(argc,argv) == 0)//check to make sure the input are valid and there is no error in what the user enter in.
		printf("The program will now terminate. \n");
	else
		run(argv);	

	return 0;
};
