#include "Sorting.hh"

bool SortCheck(Production *arr, int lgth){
    for (int i=0; i < lgth - 1; i++){
        if(arr[i].get_rating() > arr[i+1].get_rating()){
            std::cerr << "> BLAD SORTOWANIA!!!" << std::endl;
            return 1;
        }
    }
    std::cerr << "> Sortowanie przebieglo poprawnie" << std::endl;
    return 0;
}

void MergeSort(Production *arr, int l, int r){
	if (r > l) {
		int m = (l + r) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(Production *arr, int l, int m, int r){
    
    int lSize = m - l + 1;
	int rSize = r - m;
 
	Production * tabL = new Production[lSize];
	Production * tabR = new Production[rSize];
 
	for (int x = 0; x < lSize; x++)
		tabL[x] = arr[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = arr[m + 1 + y];
 
	int indexL = 0; 
	int indexR = 0;
	int currIndex;

	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++){
		if (tabL[indexL].get_rating() <= tabR[indexR].get_rating())
			arr[currIndex] = tabL[indexL++];
		else
			arr[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize)
		arr[currIndex++] = tabL[indexL++];

	while (indexR < rSize)
		arr[currIndex++] = tabR[indexR++];
 
	delete[] tabL;
    delete[] tabR;
}


void QuickSort(Production tab[], int indexLow, int indexHigh) {
    Production tmp;
    if (indexLow >= indexHigh || indexLow < 0 || indexHigh < 0)
		return;
    
	double pivot = tab[indexLow].get_rating();
	int lowerNumbersEndIndex = indexLow + 1;

	for (int iterator = indexLow+1; iterator <= indexHigh; iterator++){
		if (tab[iterator].get_rating() <= pivot){
			
            tmp = tab[lowerNumbersEndIndex];
            tab[lowerNumbersEndIndex] = tab[iterator];
            tab[iterator] = tmp;
			
            lowerNumbersEndIndex++;
		}
	}

    tmp = tab[indexLow];
    tab[indexLow] = tab[lowerNumbersEndIndex - 1];
    tab[lowerNumbersEndIndex - 1] = tmp;

	QuickSort(tab, indexLow, lowerNumbersEndIndex-2);
	QuickSort(tab, lowerNumbersEndIndex, indexHigh);
}

void BucketSort(int *tab, int n, int yMin, int yMax) {
	int* buckets = new int[yMax - yMin + 1];
	for (int x = 0; x < (yMax - yMin + 1); x++)
		buckets[x] = 0;
	for (int x = 0; x < n; x++)
		buckets[tab[x] - yMin]++;
	int lastIndex = 0;
	for (int x = 0; x < (yMax - yMin + 1); x++){
		int y;
		for (y = lastIndex; y < buckets[x] + lastIndex; y++)
			tab[y] = x + yMin;
		lastIndex = y;
	}
}