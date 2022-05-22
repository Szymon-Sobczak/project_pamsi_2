/* WYKONAŁ: Szymon Sobczak 259275*/

#include "Production.hh"
#include "CSV_handling.hh"
#include "Sorting.hh"

/* Główna pętla programu - Driver */

int main(){
   RepairCSV();
   clock_t start, end;
   int NbrOfRecords[5] = {10, 10000, 100000, 500000, 1000000};
   std::cout << std::endl; 
   for (int i = 0 ; i < 5; i++){
      Production *Productions_array = new Production[NbrOfRecords[i]];
      
      /*MERGE SORT*/
      std::cout << "Sorting method: MERGE SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      LoadCSV(NbrOfRecords[i], Productions_array); 
      std::cout << std::endl;
      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of loaded movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }
      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      std::cout << std::endl;
      start = clock();
         MergeSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();
      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of sorted movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }
      std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;

      std::cout << std::endl << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "........................................................." << std::endl << std::endl;
      
      /*QUICK SORT*/
      std::cout << "Sorting method: QUICK SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      
      LoadCSV(NbrOfRecords[i], Productions_array);  
      
      std::cout << std::endl;
      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of loaded movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }

      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      std::cout << std::endl;
      start = clock();
         QuickSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();

      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of sorted movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }

      std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      std::cout << std::endl << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "........................................................." << std::endl << std::endl;
      
      /*BUCKET SORT*/
      std::cout << "Sorting method: BUCKET SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      LoadCSV(NbrOfRecords[i], Productions_array);
      std::cout << std::endl;
      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of loaded movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }
      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      std::cout << std::endl;
      start = clock();
         BucketSort(Productions_array,NbrOfRecords[i]);
      end = clock();

      if(NbrOfRecords[i] <= 100){
         std::cout << "Table of sorted movies:" << std::endl;
         for(int j = 0; j < NbrOfRecords[i]; j++)
            Productions_array[j].print_production();
      }
      std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      std::cout << std::endl;
      std::cout << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << "........................................................." << std::endl << std::endl;
      
      delete [] Productions_array;
   }
   return 0;
} 