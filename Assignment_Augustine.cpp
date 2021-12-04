#include<iostream>     //header files
#include<conio.h> //header files
#include<stdlib.h>      //header files
#include<stdio.h>     //header files
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
/*declaration of global variables*/
/* front will show first index of array, initiated with -1 that shows that nothing is present at first position in queue*/
int front=-1;  
/* rear will show first last index of array, initiated with -1 that shows that nothing is present at last position in queue*/
int rear=-1;
int index=0;          // index will represent that how long is queue
int *queue=new int[index];      // for dynamical creation of queue
//////////////////////////////////////////////////////////////////////////////////////
/*declaration of functions*/
//The functions below are named in such a way that they will clearly reveal what they are meant for ?
void createqueue();
void enqueue(int a);
int dequeue();
void deletequeue();
void clearqueue();
int isfull();
int isempty();
void find();
void display();
void menu();

/////////////////////////////////////////////////////////////////////////////////////
//The function below is the first function that would be called when code is executed. It will display a menu having different functionalities. Just select the number corresponding to operation you want to perform and then you will be on your way to go ?
////////////////////////////////////////////////////////////////////////////////////
void menu()
{
     system("pause");     /*built in function supported by dev c++ to pause a screen until “enter” or any key is entered to proceed further.*/
     system("cls");   /*It will remove any garbage value that may appear on screen*/
     int option;
     cout<<"****welcome to queue application****\n";
     cout<<"press 1 to create queue\n";
     cout<<"press 2 to display queue\n";
     cout<<"press 3 to delete queue\n";
     cout<<"press 4 to clear queue\n";
     cout<<"press 5 to find number in queue\n";
     cout<<"press 6 to enqueue\n";
     cout<<"press 7 to dequeue\n";
     cout<<"press 8 to check if queue is full\n";
     cout<<"press 9 to check if queue is empty\n";
     cout<<"press 0 to exit\n";
     cout<<"enter option\n";
     cin>>option;
//////////////////////////////////////////////////////////////////////////////////////
//Below I have used a switch to call various functions. If you are a beginner and don’t have any idea about “switch” you can go ahead with if-else statements but their drawback is they mess up everything, make confusions as code gets lengthy.
/////////////////////////////////////////////////////////////////////////////////////    
     switch(option)
     {
     case 1:   // this case will simply call create queue function and will create it.
          createqueue();
          menu();
          break;
         
     case 2:   // this case will call display function and will display queue items
          display();
          menu();
          break;
     
     case 3:  // this function will delete whole queue by calling delete queue function
          deletequeue();
          menu();
          break;
     
     case 4:     // it will only clear items in queue but empty queue will still exist
          clearqueue();
          menu();
          break;
     
     case 5:   // it will search for required item in queue
          find();
          menu();
          break;
     
     case 6:    //
          {
          int a;
/*the check below will be used throughout the code to check if queue is created or not. Note the point that whenever front and rear will have negative value it means that array does not exist because array’s index can never be negative*/
          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else  
          if(isfull()==1)
         
          cout<<"queue is already full\n";
                     
          else
          {
          cout<<"enter element to enqueue\n";
          cin>>a;
          enqueue(a);
          }
          menu();
          }
          break;
     
     case 7:
          {
          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else
          if(isempty()==1)
          {
          cout<<"queue is already empty\n";
          }
          else
          {
          cout<<"element dequeued is :"<<dequeue();
          cout<<endl;                
          }
          menu();
          }
          break;
     
     case 8:
          {    
          int a;    
          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else  
          isfull();
          if(a==1)
          cout<<"queue is full\n";
          else
          cout<<"queue is not full\n";
          }
          menu();
          break;
     
     case 9:
          {
          int a;    
          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else  
          isempty();
          if(a==1)
          cout<<"queue is empty\n";
          else
          {
          cout<<"queue is not empty\n";  
          }
          menu();
          }
          break;
         
     case 0:
          exit(0);
          break;
   
    default:
          cout<<"invalid input\n";
          break;
          }
          }
//////////////////////////////////////////////////////////////
         
void createqueue()
{
/*The loop below will continue till you enter correct size of queue that must be greater than zero*/
     do
     {
     cout<<"enter size of queue:";
     cin>>index;
     }
     while(index<=0);
//////////////////////////////////////////////////////////////////////////////////////
//Suppose you entered 10 then, queue will be like that
//Front/rear
//queue input value
//enter queue value = 10

//Dequeue/ Enqueue        
//////////////////////////////////////////////////////////////////////////////////////  

/*The loop below will continue till you enter accurate current size that must be positive and less then index value. The “rear” here is pointing last index. */
     do
     {
     cout<<"enter current size of queue:";
     cin>>rear;
     }
     while(rear>index||rear<0);

     front=0;   // front always start from zero it could be 1 also.
     cout<<"enter elements\n";    
     for(int i=front;i<rear;i++)// loop will start from ‘0’ and continue till “rear” value
     {
        cin>>queue[i];
     }
 cout<<"queue is successfully created\n";
}


void display()
{
     if(front==-1&&rear==-1)
     cout<<"queue not created\n";
     else
     if(front<rear)
     {
     cout<<"total number of elements in queue are:";
     cout<<rear-front<<endl;                             // rear=5 , front=0 so 5-0=5 elements
     cout<<"elements are\n";
     for(int i=front;i<rear;i++)                        
     cout<<queue[i]<<endl;
     }
     else
     {
     int length;
     length=(index-front)+rear;
     cout<<"total number of elements in queue are:";
     cout<<length<<endl;
     cout<<"elements are\n";
     for(int i=front;i<index;i++)
     for(int j=0;j<rear;j++)
     cout<<queue[1]<<endl;
     }    
}



void deletequeue()
{
     if(front==-1&&rear==-1)
     cout<<"queue not created\n";
     else
     front=-1;
     rear=-1;
     cout<<"queue is successfully deleted\n";
}


void clearqueue()
{
     if(front==-1&&rear==-1)
     cout<<"queue not created\n";
     else
     front=0;
     rear=0;
     cout<<"queue is successfully cleared\n";
}


void find()
{
     int temp=0;
     int number;
     int i;
     if(front==-1&&rear==-1)
     cout<<"queue not created\n";  
     else
     cout<<"enter number to find in queue\n";
     cin>>number;
     for(i=front;i<rear;i++)
     {
     if(queue[i]==number)
     {
     cout<<"number found at position"<<i<<endl;
     temp=1;
     
     }
     }
     
     if(temp==0)
     cout<<"number not found\n";
     
     }


void enqueue(int a)
{
     queue[rear]=a;
     rear=(rear+1)%index;
     cout<<"element is successfully enqueued\n";
}


int dequeue()
{
    int a=queue[front];
    front=(front+1)%index;
    return a;
}

int isfull()
{
    if(rear-front==rear)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(front==rear)
    return 1;
    else
    return 0;
}       
int main()
{
    menu();
    return 0;
}
