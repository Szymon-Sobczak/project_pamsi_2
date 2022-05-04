#pragma once 
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>
#include "Production.hh"

/*MERGRESORT*/

void MergeSort(Production *arr, int l, int r);

void merge(Production *arr, int l, int m, int r);

bool SortCheck(Production *arr, int lgth);

/*QUICKSORT*/
void QuickSort(Production tab[], int indexLow, int indexHigh);

/*BUCKETSORT*/

void BucketSort(int *tab, int n, int yMin, int yMax);