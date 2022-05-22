#pragma once 
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>
#include "Production.hh"
#include <vector>

/* 
    Funkcje realizujące sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania poprzez scalanie - Merge Sort. 
*/
void MergeSort(Production *arr, int left, int right);
void Merge(Production *arr, int left, int middle, int right);

/* 
    Funkcje realizujące sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania szybkiego - Quick Sort. 
*/
void QuickSort(Production *arr, int p, int r);
int Partition(Production *arr, int p, int r);

/* 
    Funkcja realizująca sortowanie tablicy produkcji - Productions, 
    z użyciem algorytmu sortowania kubełkowego - Bucket Sort. 
*/
void BucketSort(Production *arr, int n);

/* 
    Funkcje realizujące analizę zebranych danych.
*/
bool SortCheck(Production *arr, int n); /* Funkcja sprawdzająca poprawność sortowania tablicy produkcji */
double ArithemticMean(Production *arr, int n); /* Funkcja wyliczająca średnią arytmetyczna ocen z tablicy produkcji */
double Median(Production *arr, int n); /* Funkcja wyliczająca medianę ocen z tablicy produkcji */

