#include "Sorting.hh"

double ArithemticMean(Production *tab, int n){
	double sum = 0.0;
	for (int i = 0 ; i < n; i++)
		sum += tab[i].get_rating();
	sum /= double(n);
	return sum;
}

double Median(Production *tab, int n){
	double median;
	if (n % 2 == 0)
		median = (tab[n/2-1].get_rating() + tab[n/2].get_rating()) / 2;
	else
		median = (tab[(n+1)/2-1].get_rating());
	return median;
}

bool SortCheck(Production *arr, int lgth){
    for (int i=0; i < lgth - 1; i++){
        if(arr[i].get_rating() > arr[i+1].get_rating())
            return 0;
    }
    return 1;
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
 

void BucketSort(Production *tab, int n){
	Production MinimalRating, MaximalRating;
	MinimalRating = tab[0];
	MaximalRating = tab[0];
	
	for (int i = 0; i < n; i++){
		if (tab[i].get_rating() < MinimalRating.get_rating())
			MinimalRating = tab[i];
		if (tab[i].get_rating() > MaximalRating.get_rating())
			MaximalRating = tab[i];
	}

	int NbrOfBuckets = MaximalRating.get_rating() - MinimalRating.get_rating() +1;
	std::vector<Production> * buckets =  new std::vector<Production>[NbrOfBuckets];

	for (int i = 0; i < n; i++)
		buckets[int(tab[i].get_rating()-MinimalRating.get_rating())].push_back(tab[i]);
	
	int iterator = 0;
	
	for (int i = 0; i < NbrOfBuckets; i++){
		for (unsigned long int j = 0; j < buckets[i].size(); j++){
			tab[iterator++] = buckets[i][j];
		}
	}
}