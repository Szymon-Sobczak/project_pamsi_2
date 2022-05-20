#include "Production.hh"
#include "CSV_handling.hh"
#include "Sorting.hh"

int main(){
   fix_csv();
   clock_t start, end;
   int NbrOfRecords[4] = {10000, 100000, 500000, 1000000};
   
   std::cout << std::endl;

   for (int i = 0 ; i < 4; i++){
      /*MERGE SORT*/
      std::cout << "Sorting method: MERGE SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      Production *Productions_array = new Production[NbrOfRecords[i]];
      
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      
      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      start = clock();
         MergeSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();

       std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      std::cout << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl << std::endl;
      
      /*QUICK SORT*/

      std::cout << "Sorting method: QUICK SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      
      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      start = clock();
         QuickSort(Productions_array, 0, NbrOfRecords[i]-1);
      end = clock();

       std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      std::cout << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl << std::endl;
      
      /*BUCKET SORT*/
   
      std::cout << "Sorting method: BUCKET SORT" << std::endl;
      std::cout << "* Number of read records: " << NbrOfRecords[i] << std::endl;
      
      read_record(NbrOfRecords[i], Productions_array); // Wczytywanie 
      
      std::cout << "* Checking order before sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      start = clock();
         BucketSort(Productions_array,NbrOfRecords[i]);
      end = clock();

       std::cout << "* Checking order after sorting > ";
      if(SortCheck(Productions_array, NbrOfRecords[i]))
         std::cout << "Data sorted successfully" << std::endl;
      else 
         std::cout << "Data not sorted" << std::endl;
      
      std::cout << "Statistics gathered:" << std::endl;
      std::cout << " - Sorting time: " << std::setprecision(10) << std::fixed << double(end - start) / double(CLOCKS_PER_SEC) << " sec." << std::endl;
      std::cout << " - Arithmetic mean of ratings: " << std::setprecision(2) << std::fixed << ArithemticMean(Productions_array, NbrOfRecords[i]) << std::endl;
      std::cout << " - Median of ratings: " << std::setprecision(2) << std::fixed << Median(Productions_array, NbrOfRecords[i]) << std::endl << std::endl;
      
      delete [] Productions_array;
   }
   return 0;
} 
