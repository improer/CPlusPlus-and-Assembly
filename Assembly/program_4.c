#include "header.h"

int main(int argc,char * argv[]){
	struct object value;//create an object
	int option;//store the user choice of operation
	//check to see if the user have enter in 15 number
	if(check(argc) == 0){
		printf("The program will now exit. \n");
		return 0;
	}
	convert_number(argv,&value);//convert the input into number and store in the struct
	operation * dispatch_table[7] = {exiting,addition,substraction,multi,division,modulo,reverse};//create an dispatch table and bind it with the function

	do{
		printf("What operation would you like to run? \n");
		//display the available option to use
		display_option();
		printf("Please enter in a option: ");
		//scan in the input and check if it valid
		if(!scanf("%d",&option)){
			printf("You have enter in an invalid option. The program will now terminate. \n");
			return 0;
		}
	}while(dispatch_table[option](value) != 0);//call the right function base on the user choice
	
	return 1;
}

