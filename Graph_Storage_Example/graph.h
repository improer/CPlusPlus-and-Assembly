#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

struct vertex{

	char * course;
	struct node * head;
	
};


struct node{

	vertex * adjacent;

	node * next;
};


class graph{

	public:

		graph();
		~graph();
		
		int insert_vertex(char * course_name);
		int insert_edge(char * current_vertex, char * to_attach);
		int display_all(char * key_value);
		void depth_first(char * key);
	private:
		int remove_list(node *& head);
		void show_path(int index,bool visited []);
		int find_index(char * key);
		int size;
		vertex * adjacency_list;
		node * tail;
};
