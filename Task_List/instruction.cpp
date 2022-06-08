#include "instruction.h"

steps::steps()
{

   head = NULL; 
   pointer = NULL;

}

steps::~steps()
{

  while(head)
  {

    pointer = head -> next;
    delete [] head -> data;
    delete head;
    head = pointer;

  }


}

void steps::add_step1(char * array1, int size)
{
	add_step(head, array1, size);
}

void steps::add_step(node *& head,char * array1,int size)
{

  if(!head)
  {

    head = new node;
    head -> data = new char[size];
    strcpy(head -> data, array1);
    head -> next = NULL;
    return;

  }

  else if(head)
  {

    node * current = head;

    while(current -> next)
    {

      current = current -> next;

    }
    current -> next = new node;
    current -> next -> data = new char [size];
    strcpy(current -> next -> data, array1);
    current -> next -> next = NULL;
    return;


  }

}

void steps::search_step1(int key)
{

   search_step(head, key);
   

}

void steps::search_step(node * head,int key)
{
  node * current = head;
  int count;
  if(!head) 
    return;
 
  else{

    
     while(current ->next != NULL)
     {
       current = current -> next;
       count+=1;
       if(count == key)
       {
          cout<< current -> data <<endl;
          return;
       }
       
     }
     return;
   }     
}


void steps::display1()
{
  display(head);
}

void steps::display(node * head)
{

  if(!head) 
    return;

  else
  {

    cout<< head -> data <<endl;
    display(head -> next);

  }


}
