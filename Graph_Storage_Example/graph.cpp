
#include "graph.h"


graph::graph(){

	size = 5;	
	tail = NULL;			
	adjacency_list = new vertex[size];

	for(int i = 0; i < size; ++i)

		adjacency_list[i].head = NULL;

}



graph::~graph(){

if(adjacency_list){
	for(int i = 0; i < size; ++i){
		delete [] adjacency_list[i].course;
		adjacency_list[i].course = NULL;
		remove_list(adjacency_list[i].head);
		delete tail;
		tail = NULL;
	}
	delete [] adjacency_list;
	adjacency_list = NULL;
}

}

int graph::remove_list(node *& head){

	if(!head)
		return 0;

	remove_list(head -> next);

	head -> adjacent = NULL;
	delete head;
	head = NULL;
}


int graph::insert_vertex(char * course_name){

	for(int i = 0; i < size; ++i){
	
		if(!adjacency_list[i].course){
	
			adjacency_list[i].course = new char[strlen(course_name) + 1];
			strcpy(adjacency_list[i].course, course_name);
			return 1;
		}

	}

	return 0;

}


int graph::insert_edge(char * current_vertex, char * to_attach){


	int temp_index = find_index(to_attach);
	int current_index = find_index(current_vertex);

	if(!adjacency_list[current_index].head){

		adjacency_list[current_index].head = new node;
		adjacency_list[current_index].head -> adjacent = &adjacency_list[temp_index];
		adjacency_list[current_index].head -> next = NULL;
		tail = adjacency_list[current_index].head;
		return 1;
	}

	node * temp = new node;
	temp -> adjacent = &adjacency_list[temp_index];
	temp -> next = NULL;
	tail -> next = temp;
	tail = temp;
	return 1;

}

int graph::display_all(char * key_value){

	int index = find_index(key_value);
	cout<< adjacency_list[index].course <<" \n";

	if(!adjacency_list[index].head)
		return 0;
		
	node * current = adjacency_list[index].head;
	while(current){

		cout<< current -> adjacent -> course << " \n";
		current = current -> next;

	}

	return 1;

}

void graph::depth_first(char * key){
	
	bool * visited = new bool[size];
	for(int i = 0; i < size; ++i){
		visited[i] = false;
	}

	int index = find_index(key);
	show_path(index,visited);

}

void graph::show_path(int index,bool visited[]){

	visited[index] = true;
	cout<<adjacency_list[index].course<<" \n";

	for(int i = 0;i < size; ++i){

		if(!visited[i])
			show_path(i,visited);

	}
}

int graph::find_index(char * key){

	for(int i = 0; i < size; ++i){

		if(strcmp(adjacency_list[i].course,key) == 0)

			return i;

	}

}









