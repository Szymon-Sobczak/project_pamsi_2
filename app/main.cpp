#include "Production.hh"
#include "CSV_handling.hh"

int main(){
   int lgth = 50;
   Production arr[50];

   read_record(lgth,arr);
   //
   arr[0].print_production();

   return 0;
} 

