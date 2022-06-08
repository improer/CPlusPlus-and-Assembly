#include "BST.h"

BST::BST(){

	root = NULL;	
}

BST::~BST(){

	remove_all(root);	

}

location::location(){
	
	name = NULL;
	country = NULL;
	summary = NULL;
	review = NULL;
	sites = NULL;
	rate = 0;
}


location::~location(){

	if(name){
		delete [] name;
		name = NULL;
	}
	if(country){
		delete [] country;
		country = NULL;
	}
	if(summary){
		delete [] summary;
		summary = NULL;
	}
	if(review){
		delete [] review;
		review = NULL;
	}
	if(sites){
		delete [] sites;
		sites = NULL;
	}

}
int location::copy(location to_add){

	name = new char[strlen(to_add.name) + 1];
	strcpy(name,to_add.name);

	
	country = new char[strlen(to_add.country) + 1];
	strcpy(country,to_add.country);


	summary = new char[strlen(to_add.summary) + 1];
	strcpy(summary,to_add.summary);

	review = new char[strlen(to_add.review) + 1];
	strcpy(review,to_add.review);

	sites = new char[strlen(to_add.sites) + 1];
	strcpy(sites,to_add.sites);

		
	rate = to_add.rate;
	
	return 1;

}
int BST::insert(location to_add){

	
	return insert(to_add,root);


}
int BST::insert(location to_add, node *& root){


	if(!root){

		root = new node; 

		root -> data.copy(to_add);

		root -> left = NULL;

		root -> right = NULL;

		return 1;

	}

	if(strcmp(to_add.name,root -> data.name) < 0)

		return insert(to_add, root -> left);

	
	return insert(to_add,root -> right);

}

int BST::height(){

	return height(root);

}

int BST::height(node * root){
	
	if(!root)
		return 0;

	
	int left = height(root -> left) + 1;
	int right = height(root -> right) + 1;
	
	
	if(left < right)
		return right;

	if(left > right)
		return left;
}

node * BST::retrieve(char * match){
	
	return retrieve(root,match);

}


node * BST::retrieve(node * root,char * match){

	if(!root)
		return NULL;

	if(strcmp(match,root -> data.name) == 0)

		return root;

	if(strcmp(match,root -> data.name) < 0)

		return retrieve(root -> left,match);

	if(strcmp(match,root -> data.name) > 0)

		return retrieve(root -> right,match);


}

int BST::remove_5(){

	return remove_5(root);

}

int BST::remove_5(node *& root){
	if(!root)
		return 0;

	int result = remove_5(root -> left) + remove_5(root -> right);

	if(root -> data.rate <= 5){
	
		if(root->right && root->left)
		{
			//
			node * temp = left_most(root -> right);
			temp -> left = root -> left;
			temp -> right = root -> right;
			delete root;
			root = temp;

		}
		
		else
		{
			node * temp;
			if(left)
			{
				temp = root->left;	
			}
			else
			{
				temp = root->right;	
			}
			delete root;
			root = temp;
		}
		result += 1;
	}
	return result;
}

int BST::remove(char * key){

	return remove(key,root);

}


int BST::remove(char * key, node *& root){

	if(!root)
		return 0;

	int result = remove(key, root -> left) + remove(key, root -> right);

	if(strcmp(key, root -> data.name) == 0){

	
		if(root->right && root->left)
		{
			
			node * temp = left_most(root -> right);
			temp -> left = root -> left;
			temp -> right = root -> right;
			delete root;
			root = temp;
			
		}
	
		else
		{
			node * temp;
			if(left)
			{
				temp = root->left;	
			}
			else
			{
				temp = root->right;	
			}
			delete root;
			root = temp;
		}
		result += 1;
	}
	return result;
}

node * BST::left_most(node *& root){
	
	if(!root)
		return NULL;
	
	if(!root -> left){
		
		node * temp = root;

		root = root -> right;

		temp -> left = NULL;

		temp -> right = NULL;
		
		return temp;

	}

	return left_most(root -> left);
	
	
}



int BST::remove_all(node *& root){

	if(!root)
		return 0;

	remove_all(root -> left);
	remove_all(root -> right);

	delete root;

	root = NULL;

}



int BST::display(){

	return display(root);

}

int BST::display(node * root){

	if(!root)
		return 0;
	display(root -> left);

	cout<<root -> data.name<<"\n";
	cout<<root -> data.country<<"\n";
	cout<<root -> data.summary<<"\n";
	cout<<root -> data.review<<"\n";
	cout<<root -> data.sites<<"\n";
	cout<<root -> data.rate<<"\n";
	cout<<" \n";
	display(root -> right);


}





















