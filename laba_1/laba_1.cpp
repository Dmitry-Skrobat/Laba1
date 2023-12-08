#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{  
   
   bool flag=true;
   int num;
   float fl;
   double db;
   cout << "int:" << sizeof(int) <<  '\n'
   << "short int:" << sizeof(short int) << '\n'
   << "long int:" << sizeof (long int) << '\n'
   << "float:" << sizeof(float) << '\n'
   << "long double:" << sizeof (long double) << '\n'
   << "double:" << sizeof (double) << '\n'
   << "char:" << sizeof(char) << '\n'
   << "bool:" << sizeof (bool) << '\n';

   while (flag==true)
   {  
      unsigned int order = 32;
      unsigned int mask = 1 << order-1;
      unsigned int mask2 = 1 << order-1;
      int idz;
      cout << "If you want to shift all bits, specify the following command: 1 otherwise 0: ";
      cin >> idz;

      if (idz==0){
         cout << "Enter the number of type int: ";
         cin >> num;
         for (int i = 1; i<= order; i++){
            cout << (num & mask ? '1' : '0');
            mask = mask >> 1;
            if (i%8==0){
               cout << ' ';
            }
            if (i % order-1 == 0){
               cout << ' ';
            }
         }
         cout << endl;
         
         cout << "Enter the number of type float: ";

         union{
            int tool;
            float fl;
         };

         cin >> fl;
      
         for (int i = 1; i<= order; i++){
            cout << (tool & mask2 ? '1' : '0');
            mask2 = mask2 >> 1;
            if (i==9 || i==1 || i == 16 || i==24){
               cout << ' ';
            }
         }
         cout << endl;


         cout << "Enter the number of type double: ";

         union{
            int array[2];
            double db;
         };

         cin >> db;
         
         for (int j = 1; j>=0; j--){
            int unsigned mask3 = 1<<order-1;
            for (int i = 1; i<= order; i++){
               cout << ((array[j] & mask3) ? '1' : '0');
               mask3 >>= 1;
               if (i==12 && j==1 ){
                  cout << ' ';
               }
               if (i == 1 && j==1){
                  cout << ' ';
               }
            }
         }
         cout << endl;
      }

      else{
         cout << "Enter the number of type int: ";
         cin >> num;
         cout << "Enter how much you want to shift all 1 to the left: ";
         int countInt;
         cin >> countInt;
         for (int i = 1; i<=order; i++){
            cout << ((num*int(pow(2,countInt))) & mask ? '1' : '0');
            mask = mask >> 1;
            if (i%8==0){
               cout << ' ';
            }
            if (i % order-1 == 0){
               cout << ' ';
            }
         }
         cout << endl;
         
         cout << "Enter the number of type float: ";

         union{
            int tool;
            float fl;
         };

         cin >> fl;
         int countFloat;
         cout << "Enter how much you want to shift all 1 to the left ";
         cin >> countFloat;
         mask2 = mask2 >> countFloat;
         for (int i = 1; i<= order; i++){
            cout << (tool & mask2 ? '1' : '0');
            mask2 = mask2 >> 1;
            if (i==9 || i==1 || i == 16 || i==24){
               cout << ' ';
            }
         }
         cout << endl;


         cout << "Enter the number of type double: ";

         union{
            int array[2];
            double db;
         };

         cin >> db;
         int countDouble;
         cout << "Enter how much you want to shift all 1 to the left ";
         cin >> countDouble;
         for (int j = 1; j>=0; j--){
            int unsigned mask3 = 1<<order-1;
            mask3 = mask3 >> countDouble;
            for (int i = 1; i<= order; i++){
               cout << ((array[j] & mask3) ? '1' : '0');
               mask3 >>= 1;
               if (i==12 && j==1 ){
                  cout << ' ';
               }
               if (i == 1 && j==1){
                  cout << ' ';
               }
            }
         }
      }
      cout << endl; 
   }     
}