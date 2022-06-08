#include "instruction.h"

int main()
{

  steps tasks;

  char temp[100];
  int size;
  char response;
  char response1;
  char response2;
  int response3;

  do{
    cout<<"This program will help you build a task list of what you want to do."<<endl;
    cout<<" "<<endl;
  
    cout<<"What your you like to do (A) add in task (B) Display the task (C)Search for a task ?";
    cin>>response;
    cin.ignore(100,'\n');
 
    if(tolower(response) == 'a')
    {
      do
      {
        cout<<"What the task you want to add: "<<endl;
        cin.get(temp,100,'\n');
        cin.ignore(100,'\n');
        size = strlen(temp);
    
        tasks.add_step1(temp,size);
        cout<<"Do you want to continue(Y/N): ";
        cin>>response1;
        cin.ignore(100,'\n');
      }while(tolower(response1) != 'n');
    }

    else if(tolower(response) == 'b')
    {  

      tasks.display1();

    }

    else if(tolower(response) == 'c')
    {
       cout<<"Please enter in the task number: ";
       cin>>response3;
       cin.ignore(100,'\n');
       tasks.search_step1(response3);

    }

  cout<<"Would you like to continue the program(Y/N): ";
  cin>>response2;
  cin.ignore(100,'\n');
  }while(tolower(response2) != 'n');

  return 0;

}
