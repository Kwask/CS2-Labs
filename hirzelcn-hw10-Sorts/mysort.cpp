/*    @file mysort.cpp    
      @author Charles Hirzel
      @date 10-4-2014

			@description This program will sort line-by-line
			whatever is given on standard
			input, and print the result to the screen.  
			
			By default each line will be interpreted as a string, but if
			-n is given, each line will be converted to an int (using atoi)
			and sorted.
			
			By default merge sort should be used.  
			If -h, heapsort should be used.
			If -m, mergesort should be used.
			If -i, insertion sort should be used.
			
			The last sort command should be followed.
*/
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>

using namespace std;

template <class T>
void copyArray( vector<T> data, unsigned int begin,
                unsigned int end, vector<T> copy ){
  for( unsigned int i = begin; i < end; i++ ){
    copy[i] = data[i];
  cout << "Copying" << endl;
  }
}

template <class T>
void merge( vector<T> &data, unsigned int begin, unsigned int middle,
            unsigned int end, vector<T> &sorted ){
  unsigned int left_iterator = begin;
  unsigned int right_iterator = middle;

  // Sorts from begin to end, picking the smaller of the two sides for each slot
  for( unsigned int i = begin; i < end; i++ ){
    if( left_iterator < middle and
        ( right_iterator >= end or 
          data[left_iterator] <= data[right_iterator] )){
      sorted[i] = data[left_iterator];
      left_iterator++;
    }else{
      sorted[i] = data[right_iterator];
      right_iterator++;
    }
  }
}

template <class T>
void split( vector<T> &data, unsigned int begin, unsigned int end, vector<T> &sorted ){
  if( end-begin < 2 ){
    return;
  }

  unsigned int middle = ( begin+end )/2;

  // Fragmenting the data further
  split<T>( data, begin, middle, sorted );
  split<T>( data, middle, end, sorted );

  // Sorting the data
  merge<T>( data, begin, middle, end, sorted );
  copyArray<T>( sorted, begin, end, data );
}

// Function used by user
template <class T>
void mergeSort( vector<T> &data, vector<T> &sorted ){
  split<T>( data, 0, data.size(), sorted );
}

int main(int argc, char* argv[]){
  bool numerical_flag = false;
  int sort_type = 0;

  int c;

  while(( c = getopt( argc, argv, "nmih" )) != -1 ){
    switch( c ){
      case 'n':
        numerical_flag = true;
        break;
      case 'm':
        sort_type = 0;
        break;
      case 'i':
        sort_type = 1;
        break;
      case 'h':
        sort_type = 2;
        break;
      case '?':
        cout << "Unknown option\"" << (char)c << "\"" << endl;
        break;
    }
  }

  vector<int> data;
  vector<int> sorted;
  
  while( !cin.eof() ){
    string temp;
    getline( cin, temp );
    data.push_back( atoi( temp.c_str() ));
    sorted.push_back( atoi( temp.c_str() ));
  }

  mergeSort<int>( data, sorted );

  for( unsigned int i = 0; i < sorted.size(); i++ ){
    cout << data[i] << endl;
  }

  return 0;
}
