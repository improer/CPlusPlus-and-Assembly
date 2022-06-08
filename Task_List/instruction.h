/*Andrew Lee
program 5*/

//include the library
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

struct node{

  char * data;
  node * next;

};


class steps
{

  public:
    steps();
    ~steps();
    void display1();
    void display(node * head);
    void add_step1(char * array1,int size);
    void add_step(node *& head, char * array1, int size);
    void search_step1(int key);
    void search_step(node * head,int key);
  private:  

    node * head;
    node * pointer;
};
