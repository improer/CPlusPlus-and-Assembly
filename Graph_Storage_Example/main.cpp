//Andrew
//program_5

#include "graph.h"


int main(){

	graph table;
	char res;
	char course_name[100];
	do{
		
		cout<<"What would you like to do? \n";
		cout<<"(A)Enter in a course (B)insert edge (C)Display (D)display all possivle path\n";
		cin>>res;
		cin.ignore(100,'\n');
	
		if(tolower(res) == 'a'){

			cout<<"What is the course name: ";
			cin.get(course_name,100,'\n');
			cin.ignore(100,'\n');

			table.insert_vertex(course_name);
		}
		
		if(tolower(res) == 'b'){
			char temp1[30];
			char temp2[30];

			cout<<"Insert a edge from: ";
			cin.get(temp1,30,'\n');
			cin.ignore(30,'\n');

			cout<<"To: ";
			cin.get(temp2,30,'\n');
			cin.ignore(100,'\n');

			table.insert_edge(temp1,temp2);
		}
	
		if(tolower(res) == 'c'){
			
			char course[30];
			cout<<"What is the course plan you want to see: ";
			cin.get(course,30,'\n');
			cin.ignore(100,'\n');
			
			table.display_all(course);

		}
	
		
	}while(tolower(res) != 'q');


}
