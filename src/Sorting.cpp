#include "Sorting.hh"

bool SortCheck(Production *arr, int lgth){
    for (int i=0; i < lgth - 1; i++){
        if(arr[i].get_rating() > arr[i+1].get_rating()){
            std::cerr << "> Lista nie została posortowana poprawnie!!!" << std::endl;
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

void QuickSort(Production arr[], int p, int r){
	int q;
	if (p < r){  
		q = partition(arr,p,r); 
		QuickSort(arr, p, q); 
		QuickSort(arr, q+1, r); 
	}
}

int partition(Production arr[], int p, int r){
	int i = p, j = r; 
	Production w;
	double x = arr[p].get_rating();
	while (true){
		while (arr[j].get_rating() > x) 
			j--;
		while (arr[i].get_rating() < x) 
			i++;
		if (i < j){ 
			w = arr[i];
			arr[i] = arr[j];
			arr[j] = w;
			i++;
			j--;
		}
		else 
			return j;
	}
	
}
 

// void BucketSort(Production *tab, int n) {
// 	Production* minAndMax = new Production[2];
// 	double yMin, yMax;
	
// 	minAndMax[0] = tab[0]; 
// 	minAndMax[1] = tab[0];

// 	for (int x = 0; x < n; x++){
// 		if (tab[x].get_rating() < minAndMax[0].get_rating())
// 			minAndMax[0] = tab[x];
// 		if (tab[x].get_rating() > minAndMax[1].get_rating())
// 			minAndMax[1] = tab[x];
// 	}
	
// 	yMin = minAndMax[0].get_rating();
// 	yMax = minAndMax[1].get_rating();

// 	Production * buckets = new Production[int(yMax - yMin + 1)];
	
// 	for (int x = 0; x < int(yMax - yMin + 1); x++)
// 		buckets[x] = 0;
	
// 	for (int x = 0; x < n; x++)
// 		buckets[int(tab[x].get_rating() - yMin)]++;
	
// 	int lastIndex = 0;
	
// 	for (int x = 0; x < (yMax - yMin + 1); x++){
// 		int y;
// 		for (y = lastIndex; y < buckets[x].get_rating() + lastIndex; y++)
// 			tab[y] = x + yMin;
// 		lastIndex = y;
// 	}
// }