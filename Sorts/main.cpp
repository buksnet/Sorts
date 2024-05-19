#include <iostream>
#include <vector>
#include <chrono>
#include "Merge_sort.h"
#include "Quick_Sort.h"
#include "count_sort.h"
#include "Bucket_sort.h"
#include "Bucket_Adapted.h"
#include "Shell_sort.h"
#include "Hoare_sort.h"

using namespace std;

const int n = 25;

void print(int* arr);
void init_arr(int* arr);
void init_arr_cnt(int* arr);
void init_vector(vector<int>& vect);
void print_vector(vector<int>& vect);
void hends_arr_init(int* arr);

int main()
{
    srand(time(0));
    int* arr = new int[n];
    vector <int> vect(25);

    int k = 0;
    printf("Pick a sorting alghorythm: \n 1: Merge\n 2: Quick sort \n");
    printf(" 3: Counting sort \n 4: Block sort\n 5: Shell's algorythm \n 6: Hoare's algorythm \n");
    cin >> k;

    switch (k) {
    case 1: {
        auto start_time_recursive = chrono::steady_clock::now();
        init_arr(arr);
        printf("New array\n");
        print(arr);
        Merge_sort(arr, 0, n - 1);
        printf("Sorted array (Merge): \n");
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break; }
    case 2: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("New array:\n");
        init_arr(arr);
        print(arr);
        Quick_Sort(arr, 0, n - 1);
        printf("Sorted array (Quick): \n");
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break; }
    case 3: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("New array\n");
        init_arr_cnt(arr);
        print(arr);
        printf("Sorted array (Counting): \n");
        count_sort(arr, 0, 10);
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 4: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("New array\n");
        init_vector(vect);
        print_vector(vect);
        printf("Sorted array (Block sort): \n");
        Bucket_sort(vect);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 5: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("New array\n");
        init_vector(vect);
        print_vector(vect);
        printf("Sorted array (Shell's algorythm): \n");
        Shell_sort(vect);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 6: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("New array\n");
        init_vector(vect);
        print_vector(vect);
        printf("Sorted array (Hoare's algorythm): \n");
        Hoare_Sort(vect, 0, n - 1);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Sorting finished in " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    }
}


void init_arr(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50;
    }
}
void init_arr_cnt(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9 + 1;
    }
}
void hends_arr_init(int* arr) {
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i] = t;
    }
}
void init_vector(vector<int>& vect) {
    for (int i = 0; i < n; i++)
        vect[i] = rand() % 50;
}
void print_vector(vector<int>& vect) {
    for (int i = 0; i < 25; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
void print(int* arr) {
    cout << arr[0];
    for (int i = 1; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << "\n";
}