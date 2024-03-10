/* Online C++ Compiler and Editor */
#include <iostream>

using namespace std;

#define WIDTH 5;

typedef unsigned short int distance_t;
typedef enum {RED, BLUE, GREEN} primary_color_t;

char a = 'A';
int feet[10]; 
int *feet_p;
//primary_color_t primary_color[];


int test_func()
{
    return 1;
    
}

int main()
{
    //primary_color = new[10];
   for (int i = 0; i < 10; i++){
    feet[i] = i;
    // primary_color[i] = (primary_color_t)(rand()%3);
    // cout << primary_color[i] << endl; 
   }
   //feet = 10;
   feet_p =  feet;
   //cout << "Size of distance " << (feet) << "\n";
   cout << "Hello World " << feet_p << endl; 
   
   for(int i =0; i < 10; i++) {
       cout << *(feet_p +i)<<"\n";
   }
   
   cout << test_func() << endl;

   
   return 0;
}
