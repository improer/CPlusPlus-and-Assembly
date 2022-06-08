#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//a struct that will keep the maze data 
struct info{
	char ** array;
	int number[6];
	int north;
	int west;
	int east;
	int south;
	int x,y;
};
int check_error(int argc,char * argv[]);//check for error from the user input 
int run(char * argv[]);//run the program
struct info read_in(char * file);//read in the data from the text file and make the maze
int print_maze(char ** array,int numbers[]);//print out the maze to the user 
char ** dynamic_allo(char ** array,int rows,int columns);//dynamically allocate space for the 2d array 
struct info wall_follower(struct info data);//solve the maze by using the wall follower algorighm call function base on what direction user is facing
int check_pos(int x,int y,int numbers[]);//check for the user position to see if they are at the exit or not
struct info south(int x,int y,struct info data);//if the user is facing south 
struct info north(int x,int y,struct info data);//if the user is facing north 
struct info west(int x,int y,struct info data);//if the user is facing west
struct info east(int x,int y,struct info data);//if the user is facing east
struct info move(struct info data);//start to move the user and call the wall follower function to help.
