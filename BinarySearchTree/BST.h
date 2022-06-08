#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

struct location{

	char * name; 
	char * country;
	char * summary;
	char * review;
	char * sites;
	int rate;

	location();
	~location();
	int copy(location to_add);
};

struct node{
	
	location data;
	node * left;
	node * right;

};


class BST{
	
	public:
		
		BST();
		~BST();
		int insert(location to_add);
		int display();
		int height();
		int remove_5();
		int remove(char * key);
		node * retrieve(char * match);
	private:
		
		node * root;
		int insert(location to_add,node *& root);
		int display(node * root);
		int height(node * root);	
		int remove_5(node *& root);
		int remove(char * key,node *& root);
		node * left_most(node *& root);
		int remove_all(node *& root);
		node * retrieve(node * root,char * match);

};
