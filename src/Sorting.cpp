#include "Sorting.hh"

/* 
	Funkcja wyznaczająca średnią arytmetyczną ocen dla tablicy Production o długości n.
*/

double ArithemticMean(Production *arr, int n){
	double sum = 0.0;
	for (int i = 0 ; i < n; i++)
		sum += arr[i].get_rating();
	sum /= double(n);
	return sum;
}

/* 
	Funkcja wyznaczająca mednianę ocen dla tablicy Production o długości n.
*/

double Median(Production *arr, int n){
	double median;
	if (n % 2 == 0)
		median = (arr[n/2-1].get_rating() + arr[n/2].get_rating()) / 2;
	else
		median = (arr[(n+1)/2-1].get_rating());
	return median;
}

/* 
	Funkcja sprawdzająca poprawnośc sortowania tablicy Production.
	Funkcja sprawdza, czy pozycje w tablicy są uszeregowane po ocenach krytyków w kolejności rosnącej.
*/

bool SortCheck(Production *arr, int lgth){
    for (int i=0; i < lgth - 1; i++){
        if(arr[i].get_rating() > arr[i+1].get_rating())
            return 0;
    }
    return 1;
}

/* 
    Funkcje realizujące sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania poprzez scalanie - Merge Sort. 
*/

void MergeSort(Production *arr, int left, int right){
	if (right > left){
		int m = (left + right) / 2;
		MergeSort(arr, left, m);
		MergeSort(arr, m + 1, right);
		merge(arr, left, m, right);
	}
}

void merge(Production *arr, int left, int middle, int right){
    int LeftSize = middle - left + 1;
	int RightSize = right - middle;
 
	Production * LeftArr = new Production[LeftSize];
	Production * RightArr = new Production[RightSize];
 
	for (int x = 0; x < LeftSize; x++)
		LeftArr[x] = arr[left + x];
	for (int y = 0; y < RightSize; y++)
		RightArr[y] = arr[middle + 1 + y];
 
	int LeftIndex = 0, RightIndex = 0, CurrIndex = 0; 

	for (CurrIndex = left; LeftIndex < LeftSize && RightIndex < RightSize; CurrIndex++){
		if (LeftArr[LeftIndex].get_rating() <= RightArr[RightIndex].get_rating())
			arr[CurrIndex] = LeftArr[LeftIndex++];
		else
			arr[CurrIndex] = RightArr[RightIndex++];
	}

	while (LeftIndex < LeftSize)
		arr[CurrIndex++] = LeftArr[LeftIndex++];

	while (RightIndex < RightSize)
		arr[CurrIndex++] = RightArr[RightIndex++];
 
	delete[] LeftArr;
    delete[] RightArr;
}

/* 
    Funkcje realizujące sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania szybkiego - Quick Sort. 
*/

void QuickSort(Production *arr, int p, int r){
	int q;
	if (p < r){  
		q = partition(arr,p,r); 
		QuickSort(arr, p, q); 
		QuickSort(arr, q+1, r); 
	}
}

int partition(Production *arr, int p, int r){
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

/* 
    Funkcja realizująca sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania kubełkowego - Bucket Sort. 
*/

void BucketSort(Production *arr, int n){
	Production MinimalRating, MaximalRating;
	MinimalRating = arr[0];
	MaximalRating = arr[0];

	for (int i = 0; i < n; i++){
		if (arr[i].get_rating() < MinimalRating.get_rating())
			MinimalRating = arr[i];
		if (arr[i].get_rating() > MaximalRating.get_rating())
			MaximalRating = arr[i];
	}

	int NbrOfBuckets = MaximalRating.get_rating() - MinimalRating.get_rating() +1;
	std::vector<Production> * buckets =  new std::vector<Production>[NbrOfBuckets];

	for (int i = 0; i < n; i++)
		buckets[int(arr[i].get_rating() - MinimalRating.get_rating())].push_back(arr[i]);
	
	int iterator = 0;
	
	for (int i = 0; i < NbrOfBuckets; i++){
		for (unsigned long int j = 0; j < buckets[i].size(); j++){
			arr[iterator++] = buckets[i][j];
		}
	}
}