/*    @file benchmark.cpp    
      @author <fill me in>
      @date <fill me in>  

			@description benchmark evaluates the speed of various implementations of
			              queues and stacks and prints the results to the screen
			              via tab-delimed values.
			              
			              If no paramters are set, or -h, print usage to the screen.
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#include <stack>
#include <queue>

#include "MyStack.h"
#include "MyQueue.h"
#include "AStack.h"
#include "AQueue.h"

using namespace std;

int main(int argc, char* argv[]){
  int start_size = 0;
  int step_size = 1;
  int max_size = 100;
  int class_choice = 0; // Values: 0 == stack, 1 == queue
  int action_choice = 0; // Values: 0 == grow, 1 == shrink, 2 == access

  int c;
  opterr = 0;
  while(( c = getopt( argc, argv, "m:s:x:c:a:h" )) != -1 ){
    switch( c ){
      case 'm':
        start_size = atoi( optarg );
        break;
      case 's':
        step_size = atoi( optarg );
        break;
      case 'x':
        max_size = atoi( optarg );
        break;
      case 'c':
        class_choice = atoi( optarg );
        break;
      case 'a':
        action_choice = atoi( optarg );
        break;
      case 'h':
        cout << "Compares the perfomance of MyStack, AStack, and the STL Stack, as well as their queue counterparts. Use command-line options to change output of program. Output is in this form:" << endl
             << "size   my_time   a_time   stl_time" << endl
             << "-m: Start size" << endl
             << "-s: Step size" << endl
             << "-x: Max size" << endl
             << "-c: Class choice. Values: 0 == stack, 1 == queue " << endl
             << "-a: Action choice. Values: 0 == grow, 1 == shrink, 2 == access" << endl
             << "-h: Print usage" << endl;
        return 1;
      case '?':
        if( c == 's' or c == 'x' or c == 'c' or c == 'a' or c == 'm' ){
          cout << "Option " << (char)c << " requires an argument." << endl;
        }else{
          cout << "Unknown option character \'" << (char)c << "\'" << endl;
        }
        return 1;
      default:
        cout << "Program requires 'c' and 'a' arguments to be filled." << endl;
        return 1;
    }
  }

  for( int i = start_size; i < max_size; i += step_size ){
    MyStack<int> my_stack;
    MyQueue<int> my_queue;

    AStack<int> a_stack;
    AQueue<int> a_queue;

    stack<int> stl_stack;
    queue<int> stl_queue;

    for( int j = 0; j < i; j++ ){
      if( class_choice == 0 ){
        my_stack.push( j );
        a_stack.push( j );
        stl_stack.push( j );
      }else if( class_choice == 1 ){
        my_queue.enqueue( j );
        a_queue.enqueue( j );
        stl_queue.push( j );
      }
    }

    clock_t start = clock();
    for( int j = start_size; j < i; j++ ){
      if( action_choice == 0 ){
        if( class_choice == 0 ){
          my_stack.push( j );
        }else if( class_choice == 1 ){
          my_queue.enqueue( j );
        }
      }else if( action_choice == 1 ){
        if( class_choice == 0 ){
          my_stack.pop();
        }else if( class_choice == 1 ){
          my_queue.dequeue();
        }
      }else if( action_choice == 2 ){
        if( class_choice == 0 ){
          my_stack.peek();
        }else if( class_choice == 1 ){
          my_queue.peek();
        }
      }
    }
    clock_t stop = clock();
    float my_time = (float)(stop - start) * 1000.0 / (float) CLOCKS_PER_SEC;

    start = clock();
    for( int j = start_size; j < i; j++ ){
      if( action_choice == 0 ){
        if( class_choice == 0 ){
          a_stack.push( j );
        }else if( class_choice == 1 ){
          a_queue.enqueue( j );
        }
      }else if( action_choice == 1 ){
        if( class_choice == 0 ){
          a_stack.pop();
        }else if( class_choice == 1 ){
          a_queue.dequeue();
        }
      }else if( action_choice == 2 ){
        if( class_choice == 0 ){
          a_stack.peek();
        }else if( class_choice == 1 ){
          a_queue.peek();
        }
      }
    }
    stop = clock();
    float a_time = (float)(stop - start) * 1000.0 / (float) CLOCKS_PER_SEC;

    start = clock();
    for( int j = start_size; j < i; j++ ){
      if( action_choice == 0 ){
        if( class_choice == 0 ){
          stl_stack.push( j );
        }else if( class_choice == 1 ){
          stl_queue.push( j );
        }
      }else if( action_choice == 1 ){
        if( class_choice == 0 ){
          stl_stack.pop();
        }else if( class_choice == 1 ){
          stl_queue.pop();
        }
      }else if( action_choice == 2 ){
        if( class_choice == 0 ){
          stl_stack.top();
        }else if( class_choice == 1 ){
          stl_queue.front();
        }
      }
    }
    stop = clock();
    float stl_time = (float)(stop - start) * 1000.0 / (float) CLOCKS_PER_SEC;

    cout << i << "\t" << my_time << "\t" << a_time << "\t" << stl_time << endl;
  }

  return 0;
}
