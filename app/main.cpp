#include "Production.hh"
#include "CSV_handling.hh"
#include "Sorting.hh"
#include <bits/stdc++.h>

int main(){
   int lgth = 100000;
   clock_t start, end;
   
   Production *arr = new Production[lgth];
   
   fix_csv();

   read_record(lgth,arr);

   //  for (int i = 0; i < lgth; i++){
   //    arr[i].print_production();
   // }

   SortCheck(arr, lgth);

   std::cout << std::endl;
   
   start = clock();
      QuickSort(arr, 0, lgth-1);
   end = clock();

   // for (int i = 0; i < lgth; i++){
   //    arr[i].print_production();
   // }

   SortCheck(arr, lgth);

   
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

   std::cout << "Czas sortowania to: " << std::setprecision(10) << std::fixed << time_taken << " sec." << std::endl;
  
   delete [] arr;
   return 0;
} 
