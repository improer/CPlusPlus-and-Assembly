#include "header.h"

//display all the possible option.
int display_option(){
	char * choice[] = {"exit","addition","subtraction","multiplication","division","modulo","reverse"};
	for(int i = 0;i < 7;++i)
		printf("%d. %s \n",i,choice[i]);	
	return 1;
}
//check if the user have enter in the correct number of arguement
int check(int argc){
	if(argc > 16){
		printf("Too many arguement. \n");
		return 0;
	}
	else if(argc < 16){
		printf("Too little arguement. \n");
		return 0;
	}
	return 1;
}
//convert the number from string  to decimal number
int convert_number(char * argv[],struct object * data){
	for(int i = 0;i < 15;++i){
		data -> array[i] = strtol(argv[i + 1],NULL,10);
		if(data -> array[i] == 0){
			data -> array[i] = strtol(argv[i + 1],NULL,16);
		}
	}
	printf("Your number in decimal are ");
	for(int i = 0;i < 15;++i)
		printf("%d ",data -> array[i]);
	printf("\n");
	return store_word(data,argv);
}
//copy the user input to the object structure data
int store_word(struct object * data,char * argv[]){
	for(int i = 0;i < 15;++i){
		data -> array2[i] = argv[i + 1];
	}
	return 1;
}
//end the program if the user choose option 0
int exiting(struct object data){
	printf("The program will now exit. \n");
	return 0;
}
//add up all the number from left to right if option 1
int addition(struct object data){
	int sum = 0;
	for(int i = 0; i < 15; ++i){
		sum = data.array[i] + sum;
	}
	printf("The sum of the array from left to right is %d \n",sum);
	return 1;
}
//substract all the number from left to right if option 2
int substraction(struct object data){
	int sub = data.array[0];
	for(int i = 1;i < 15;++i){
		sub = sub - data.array[i];
	}
	printf("The substraction of the array from left to right is %d \n",sub);
	return 1;
}
//multiply all the number from left to right if option 3
int multi(struct object data){
	long int mult = data.array[0];
	for(int i = 1;i < 15; ++i){
		mult = mult * data.array[i];
	}
	printf("The multiplication of the array from left to right is %ld \n",mult);
	return 1;
}
//divide the first and second number if option 4
int division(struct object data){
	if(data.array[1] == 0){
		printf("cannot be calculate because of division by 0. \n");
		return 2;
	}
	float a = data.array[0];
	float b = data.array[1];
	printf("The division of the first and second number is %f \n",a/b);
	return 1;
}
//find the modulo of the first and second number if option 5
int modulo(struct object data){
	int mod = data.array[0] % data.array[1];
	printf("The modulo of the first and second is %d \n",mod);
	return 1;
}
//reverse the input that the user enter in if option 6
int reverse(struct object data){
	int i = 15;
	do{
		i -= 1;
		reverse_word(data.array2[i]);
		printf(" ");
	}while(i > 0);
	printf("\n");
	return 1;
}
//reverse the word 
int reverse_word(char * word){
	int i = strlen(word);
	do{
		i-=1;
		printf("%c",word[i]);
	}while(i > 0);
	return 1;
}







