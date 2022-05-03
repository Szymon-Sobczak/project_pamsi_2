#include "Production.hh"
#include "CSV_handling.hh"

int main(){
   int lgth = 10;
   
   Production *arr = new Production[lgth];
   
   fix_csv();
   read_record(lgth,arr);
   
   delete [] arr;
   return 0;
} 

