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

void QuickSort(Production tab[], int p, int r);

int partition(Production arr[], int p, int r);

/*BUCKETSORT*/

void BucketSort(Production *tab, int n);

