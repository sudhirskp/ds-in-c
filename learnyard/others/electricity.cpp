// Write a C++ program to input electricity unit charge and calculate the total electricity bill according to the given condition:
// For first 50 units Rs. 0.50/unit
// For next 100 units Rs. 0.75/unit
// For next 100 units Rs. 1.20/unit
// For unit above 250 Rs. 1.50/unit
// An additional surcharge of 20% is added to the bill.

#include<iostream>
using namespace std;

int main(){
   int units;
   float bill=0;

   cout<<"Enter the Units : ";
   cin>>units;

   if(units<=50){
    bill = 50*0.5;

   }
   if(units >50 && units<=150){
    bill = 50*0.5 + (units-50)*0.75;
    
   }
   if(units > 50 && units > 150 && units <= 250){
    bill = 50*0.5 + 100*0.75 + (units-150)*1.20;
   }
   if(units > 250){
    bill = 50*0.5 + 100*0.75 + 100*1.20 + (units-250)*1.50;
   }

   float total = bill + (bill*0.20);

   cout<<"Total bill is of units : "<<units<< " is Rs."<<total;
}