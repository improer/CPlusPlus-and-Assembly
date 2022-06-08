/*
Andrew
program_4
*/

#include "BST.h"


int main(){
	BST tree;
	location place;

	place.name = new char[100];
	place.country = new char[100];
	place.summary = new char[100];
	place.review = new char[100];
	place.sites = new char[100];
	
	char res;
	char temp_res[20];

	do{
	
		cout<<"Press Q or q to quit the program. \n";
		cout<<"What would you like to do? \n";
		cout<<"(A)Enter a place (B)display all (C)remove all 5 rate (D)remove a place \n";
		cin>>res;
		cin.ignore(100,'\n');

		cout<<" \n";


		if(tolower(res) == 'a'){

			cout<<"What is the place name: ";
			cin.get(place.name,100,'\n');
			cin.ignore(100,'\n');
		
			cout<<"What is the country: ";
			cin.get(place.country,100,'\n');
			cin.ignore(100,'\n');
		

			cout<<"Summary of the thing you do: ";
			cin.get(place.summary,100,'\n');
			cin.ignore(100,'\n');
		
		
			cout<<"Your review of the place: ";
			cin.get(place.review,100,'\n');
			cin.ignore(100,'\n');
		
			cout<<"List 5 sites you visits: ";
			cin.get(place.sites,100,'\n');	
			cin.ignore(100,'\n');
		
			cout<<"What your rating: ";
			cin>>place.rate;
			cin.ignore(100,'\n');

			tree.insert(place);
			
		}
	
		if(tolower(res) == 'b'){

			int temp = tree.height();

			tree.display();

			cout<<"The height of your tree is: "<<temp<<" \n";

		}
		
		if(tolower(res) == 'c'){

			tree.remove_5();

			int temp = tree.height();

			cout<<"The height of your tree is: "<<temp<<" \n";


		}

		if(tolower(res) == 'd'){

			cout<<"What the place name you want to remove: ";
			
			cin.get(temp_res,20,'\n');

			cin.ignore(100,'\n');

			tree.remove(temp_res);

			int temp = tree.height();

			cout<<"The height of your tree is: "<<temp<<" \n";
			

		}

	}while(tolower(res) != 'q');





}
