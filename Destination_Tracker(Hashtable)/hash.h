#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>
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
	int copy(const location to_add);
	int display();
};

struct node{
	
	location place;

	node * next;

};

class hash{

	public:

		hash();
		~hash();
		
		int insert(location to_add);

		node * retrieve(node * head, char * country, char * place);
		int review(char * country, char * place);
		int display_country(char * key_name);
		int display_country(node * head);
		int read_in();


	private:

		node ** hash_table;
		int hash_index(char * key);
		int hash_table_size;

};
