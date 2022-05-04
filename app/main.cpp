#include "Production.hh"
#include "CSV_handling.hh"
#include "Sorting.hh"
#include <bits/stdc++.h>

int main(){
   int lgth = 10;
   clock_t start, end;
   Production *Productions_array = new Production[lgth];
   fix_csv();

   read_record(lgth, Productions_array); // Wczytywanie 
   
   std::cout << ": Lista wczytana-nieposortowana :" << std::endl;
   
   for (int i = 0; i < lgth; i++)
      Productions_array[i].print_production();

   std::cout << std::endl << ": Sprawdzenie czy lista jest posortowana :" << std::endl;
   SortCheck(Productions_array, lgth);

   std::cout << std::endl;
   
   start = clock();
      QuickSort(Productions_array, 0, lgth-1);
   end = clock();
   
   std::cout << ": Lista posortowana :" << std::endl;
   for (int i = 0; i < lgth; i++)
      Productions_array[i].print_production();
   
   std::cout << std::endl << ": Sprawdzenie czy lista jest posortowana malejąco względem ocen :" << std::endl;
   SortCheck(Productions_array, lgth);

   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

   std::cout << "Czas sortowania to: " << std::setprecision(10) << std::fixed << time_taken << " sec." << std::endl;
  
   delete [] Productions_array;
   return 0;
} 
