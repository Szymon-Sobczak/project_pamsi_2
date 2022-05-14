#include "Production.hh"
#include "CSV_handling.hh"
#include "Sorting.hh"
#include <bits/stdc++.h>

int main(){
   fix_csv();
   clock_t start, end;
   int NbrOfRecords[4] = {10000, 100000, 500000, 1000000};
   
   std::cout << ": MERGE SORT :" << std::endl;
   for (int i = 0 ; i < 4; i++){
      std::cout << std::endl << ": NUMBER OF RECORDS IN THE ARRAY : " << NbrOfRecords[i] << std::endl;
      Production *Productions_array = new Production[NbrOfRecords[i]];
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      std::cout << ": LIST READ NOT SORTED :" << std::endl;

      std::cout << std::endl << "? IS THE LIST SORTED ?" << std::endl;
      SortCheck(Productions_array, NbrOfRecords[i]);

      std::cout << std::endl;
   
      start = clock();
         MergeSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();
   
      std::cout << ": SORTED LIST :" << std::endl;
   
      std::cout << std::endl << ": ? IS THE LIST SORTED IN ASCENDING ORDER OF RATINGS ? :" << std::endl;
    
      SortCheck(Productions_array, NbrOfRecords[i]);

      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

      std::cout << "SORTING TIME: " << std::setprecision(10) << std::fixed << time_taken << " sec." << std::endl;
      std::cout << "ARITHMETIC MEAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "MEDIAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
   
      delete [] Productions_array;
   }

   std::cout << ": QUICK SORT :" << std::endl;
   for (int i = 0 ; i < 4; i++){
      std::cout << ": NUMBER OF RECORDS IN THE ARRAY : " << NbrOfRecords[i] << std::endl;
      Production *Productions_array = new Production[NbrOfRecords[i]];
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      std::cout << ": LIST READ NOT SORTED :" << std::endl;

      std::cout << std::endl << "? IS THE LIST SORTED ?" << std::endl;
      SortCheck(Productions_array, NbrOfRecords[i]);

      std::cout << std::endl;
   
      start = clock();
         QuickSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();
   
      std::cout << ": SORTED LIST :" << std::endl;
   
      std::cout << std::endl << ": ? IS THE LIST SORTED IN ASCENDING ORDER OF RATINGS ? :" << std::endl;
    
      SortCheck(Productions_array, NbrOfRecords[i]);

      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

      std::cout << "SORTING TIME: " << std::setprecision(10) << std::fixed << time_taken << " sec." << std::endl;
      std::cout << "ARITHMETIC MEAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "MEDIAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
   
      delete [] Productions_array;
   }

   std::cout << ": BUCKET SORT :" << std::endl;
   for (int i = 0 ; i < 4; i++){
      std::cout << ": NUMBER OF RECORDS IN THE ARRAY : " << NbrOfRecords[i] << std::endl;
      Production *Productions_array = new Production[NbrOfRecords[i]];
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      std::cout << ": LIST READ NOT SORTED :" << std::endl;

      std::cout << std::endl << "? IS THE LIST SORTED ?" << std::endl;
      SortCheck(Productions_array, NbrOfRecords[i]);

      std::cout << std::endl;
   
      start = clock();
         BucketSort(Productions_array,NbrOfRecords[i]);
      end = clock();
   
      std::cout << ": SORTED LIST :" << std::endl;
   
      std::cout << std::endl << ": ? IS THE LIST SORTED IN ASCENDING ORDER OF RATINGS ? :" << std::endl;
    
      SortCheck(Productions_array, NbrOfRecords[i]);

      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

      std::cout << "SORTING TIME: " << std::setprecision(10) << std::fixed << time_taken << " sec." << std::endl;
      std::cout << "ARITHMETIC MEAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "MEDIAN WITHIN THE RANGE: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
   
      delete [] Productions_array;
   }

   return 0;
} 
