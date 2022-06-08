#include "header.h"

//function that check for error
int check_error(int argc,char * argv[]){
	if(argc == 1){//if the user dont input in a maze to use
		printf("Please specify which maze file to use. \n");
		return 0;
	}
	else if(argc > 2){
		printf("Too many arguement. \n ");
		return 0;
	}
	else if((strcmp(argv[1],"maze2.txt")) != 0 && (strcmp(argv[1],"maze3.txt") != 0)){//if they not enter in the correct maze
		printf("Invalid maze file. \n");
		return 0;
	}
	return 1;
}
int run(char * argv[]){
	struct info maze_data;//make the struct
	printf("This is the maze you choose: \n");
	maze_data = read_in(argv[1]);//read in the data from the chosen text file.
	maze_data = wall_follower(maze_data);//call the function to solve for the maze
	printf("solution: \n");
	print_maze(maze_data.array,maze_data.number);//print out the maze
	return 1;
}
//read in the information from the text file
struct info read_in(char * file){
	FILE * fptr;
	struct info data;
	char temp;
	int r = 0;
	int c = 0;
	//check if the file was properly open
	if((fptr = fopen(file,"r")) == NULL){
		printf("ERROR! opening file \n");
		return data;	
	}
	//if it open then read from the file
	if(fptr){
		//read in the maze size and starting/end point from the file
		for(int i = 0;i < 3;++i)
			fscanf(fptr,"%d, %d \n",&data.number[i * 2],&data.number[(i*2) + 1]);
		data.array = dynamic_allo(data.array,data.number[1],data.number[0]);
		temp =fgetc(fptr);//prime the pump to see if there anything to read into the array
		//while not reach the end of the file read in each character from the file and put in the 2d array
		while(temp !=EOF){
			if(temp == '\n'){
				r += 1;
				c = 0;
			}
			else{
				data.array[r][c] = temp;
				c+=1;
			}
			temp = fgetc(fptr);
		}
	}
	//print out the maze and close the file
	print_maze(data.array,data.number);
	fclose(fptr);
	return data;
}
//print out the maze for the user
int print_maze(char ** array,int numbers[]){	
	for(int c = 0; c < numbers[1];++c){
		for(int r = 0;r < numbers[0];++r){
			printf("%c",array[c][r]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;	
}
//dynamic allocate the data for the 2d array
char ** dynamic_allo(char ** array,int rows,int columns){
	array = (char**)malloc(rows * sizeof(char*));
	for(int i = 0; i < rows;i++){
		array[i] = (char*)malloc(columns * sizeof(char));
	}
	return array;
}
//solve the maze for the user
struct info wall_follower(struct info data){
	//track the user x,y coordinate
	data.x = data.number[2];
	data.y = data.number[3];
	//track the direction they are facing assuming they starting with south
	data.north = 0;
	data.west = 0;
	data.east = 0;
	data.south = 1;
	data.array[data.y][data.x] = 'W';
	//keep on moving until the user have reach the end point 
	while(check_pos(data.x,data.y,data.number) == 1){
		data = move(data);
	}
	return data;
}
//move the user base on the direction they are facing 
struct info move(struct info data){
	//if they are facing west then call the west function
	if(data.west == 1){
		data = west(data.x,data.y,data);	
		return data;
	}
	//if they are facing south then call the south function
	else if(data.south == 1){
		data = south(data.x,data.y,data);
		return data;
	}
	//if they are facing east then call the east function
	else if(data.east == 1){
		data = east(data.x,data.y,data);
		return data;
	}
	//if they are facing north the call the north function
	else if(data.north == 1){
		data = north(data.x,data.y,data);	
		return data;
	}
	return data;	
}
//if the user is facing south then move them accordingly 
struct info south(int x,int y,struct info data){
	if((data.array[y][x - 1] == '0') ||  (data.array[y][x - 1] == 'W')){//check for the right see if it a wall if it not then go to the right
		x = x - 1;
		data.array[y][x] = 'W';
		data.x = x;
		data.south = 0;
		data.west = 1;
		return data;	
	}
	else if((data.array[y + 1][x] == '0') || (data.array[y + 1][x] == 'W')){//check for if there a wall in the front if not then move forward
		y = y + 1;
		data.array[y][x] = 'W';
		data.y = y;
		return data;
	}
	else if((data.array[y][x + 1] == '0') || (data.array[y][x + 1] == 'W')){//check if there is a wall to the left if there isn't then move left
		x = x + 1;
		data.array[y][x] = 'W';	
		data.x = x;
		data.south = 0;
		data.east = 1;
		return data;
	}
	else if((data.array[y][x+1] != '0') && (data.array[y][x-1] != '0') && ((data.array[y - 1][x] == 'W') || (data.array[y - 1][x] != '0'))){//if there is wall in the right, left and front then move back one
		y = y - 1;
		data.y = y;
		data.south = 0;
		data.north = 1;
		return data;
	}
	return data;
}
//if the user is facing north then move them accordingly
struct info north(int x,int y,struct info data){
	if((data.array[y][x + 1]) == '0' ||(data.array[y][x + 1]) == 'W'){//check if there is a wall in the right if there isn't one then move right
		x = x + 1;
		data.array[y][x] = 'W';
		data.x = x;	
		data.north = 0;
		data.east = 1;
		return data;
	}
	else if((data.array[y - 1][x] == '0') || (data.array[y - 1][x] == 'W')){//check if there is a wall in the front if there isn't then move forward
		y = y - 1;
		data.array[y][x] = 'W';
		data.y = y;
		return data;
	}
	else if((data.array[y][x - 1] == '0') ||(data.array[y][x - 1] == 'W')){//check if there is a wall on the left if there isn't one then move left
		x = x - 1;
		data.x = x;
		data.north = 0;
		data.west = 1;
		return data;
	}
	else if((data.array[y][x+1] != '0') && (data.array[y][x-1] != '0') && ((data.array[y+1][x] != '0') || (data.array[y+1][x] == 'W'))){//check if there is wall on the right,left and front if there is then move back
		y = y + 1;
		data.y = y;
		data.north = 0;
		data.south = 1;
		return data;
	}
	return data;
}
//if the user is facing west then move them accordingly
struct info west(int x,int y,struct info data){
	if((data.array[y - 1][x] == '0') || (data.array[y - 1][x] == 'W')){//check if there is wall on the right if there isn't then move right
		y = y - 1;
		data.array[y][x] = 'W';
		data.y = y;	
		data.north = 1;
		data.west = 0;
		return data;
	}
	else if((data.array[y][x - 1] == '0') || (data.array[y][x - 1] == 'W')){//check if there is a wall in the front if there isn't then move forward
		x = x - 1;
		data.array[y][x] = 'W';
		data.x = x;
		return data;
	}
	else if((data.array[y + 1][x] == '0') || (data.array[y + 1][x] == 'W')){//check if there is a wall in the left of the user if there isn't then move left
		y = y +  1;
		data.array[y][x] = 'W';	
		data.y = y;
		data.south = 1;
		data.west = 0;
		return data;
	}
	else if((data.array[y + 1][x] != '0') && (data.array[y - 1][x] != '0') && ((data.array[y][x + 1] != '0' || (data.array[y][x+1] == 'W')))){//check if there is a wall on the right,left and front of the user if there isn't then move back one
		x = x - 1;
		data.x = x;
		data.east = 1;
		data.west = 0;
		return data;
	}
	return data;
}
//if the user is facing east then move them accordingly
struct info east(int x,int y,struct info data){
	if((data.array[y + 1][x] == '0') || (data.array[y + 1][x] == 'W')){//check if there is wall on the right if there isn't then move to the right
		y = y + 1;
		data.array[y][x] = 'W';
		data.y = y;	
		data.south = 1;
		data.east = 0;
		return data;
	}
	else if((data.array[y][x + 1] == '0') || (data.array[y][x + 1] == 'W')){//check if there is a wall in front of the user if there isn't then move forward
		x = x + 1;
		data.array[y][x] = 'W';
		data.x = x;
		return data;
	}
	else if((data.array[y - 1][x] == '0') || (data.array[y - 1][x] == 'W')){//check if there is a wall on the left of the user if there isn't then move left
		y = y - 1;
		data.array[y][x] = 'W';	
		data.y = y;
		data.north = 1;
		data.east = 0;
		return data;
	}
	else if((data.array[y + 1][x] != '0') && (data.array[y - 1][x] != '0') && ((data.array[y][x - 1] != '0') || (data.array[y][x - 1] == 'W'))){//if there is wall on the right,left and front then move back one
		x = x - 1;
		data.x = x;
		data.west = 1;
		data.east = 0;
		return data;
	}
	return data;
}
//check the user current position to see if they have reach the exit
int check_pos(int x, int y,int numbers[]){
	if( (x == numbers[4]) && (y == numbers[5]))
		return 0;
	else 
		return 1;
	return 1;
}




