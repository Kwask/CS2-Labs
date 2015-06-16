/*    @file printstats.cpp    
      @author <fill me in>
      @date <fill me in>  

			@description Prints statistics about a given text file
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <string>

#include "TextProfile.h"

using namespace std;

int main(int argc, char* argv[]){

  int options;
  const char* input_file_name = 0;

  while(( options = getopt( argc, argv, "i:" )) != -1 ){
    switch( options ){
      case 'i':
        input_file_name = optarg;
        break;
      case '?':
        cout << "Option -" << optopt << " requires an argument." << endl;
        break;
      default:
        break;
    }
  }
  
  if( input_file_name == 0 ){

    cout << "ERROR: FILENAME NOT SPECIFIED" << endl;
    return -1; // If no file was provided, exit

  }

	ifstream file;  // The following lines reads an entire text file and saves
	file.open( input_file_name,  iostream::in); // it to a string.

	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	char *buffer = new char[length];
	file.read(buffer, length);
	file.close();

	string sfile(buffer);
	delete[] buffer;
	
	TextProfile prof( sfile );
	cout << "Printable char count: " << prof.getCharacterCount() << endl
       << "Line Count: " << prof.getLineCount() << endl
       << "Word Count: " << prof.getWordCount() << endl
       << "Sentence Count: " << prof.getSentenceCount() << endl
       << "Avg words per sentence: " << prof.getAverageWordsPerSentence()
          << endl
       << "Avg word length: " << prof.getAverageWordLength() << endl
       << "TypeToken Ratio: " << prof.typeTokenRatio() << endl
       << "Hapax Ratio: " << prof.hapaxRatio() << endl;


	return 0;
}
