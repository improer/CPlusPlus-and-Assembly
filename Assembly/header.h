#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//an object that will hold all the data that the user input in
struct object{
	int array[15];
	char * array2[15];
};
int display_option();//display the user option
int check(int agrc);//check if the user enter in 15 input else said what missing and end the program
int convert_number(char * agrv[],struct object * data);//convert the user input from a string
int exiting(struct object data);//end the program if the user choose option 0
int addition(struct object data);//add all the number up from left to right if the user choose option 1
int substraction(struct object data);//substract all the number up from left to right if the user choose option 2
int multi(struct object data);//multiply all the number up from left to right if the user choose option 3
int division(struct object data);//divide the first and second number in the array if the user choose option 4
int modulo(struct object data);//find the modulo of the first and second number in the array if the user choose option 5
int reverse(struct object data);//reverse the user input if they choose option 6
int reverse_word(char * word);//reverse the word 
int store_word(struct object * data,char * agrv[]);//copy the user input to the data

typedef int operation(struct object data);//define a variable for the dispatch table




