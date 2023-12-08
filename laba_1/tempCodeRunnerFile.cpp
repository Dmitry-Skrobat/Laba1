#include <iostream>
using namespace std;
int main()
{  
   int num = 127;
   unsigned int order = 32;
   unsigned int mask = 1 << order-1;
   
   for (int i = 1; i<= order; i++){
      cout << (num & mask ? '1' : '0');
      mask = mask >> 1;
      if (i%8==0){
         cout << ' ';
      }
      if (i % order-1 == 0){
         cout << ' ';
      }