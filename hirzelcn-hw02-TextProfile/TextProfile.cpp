/*    @file Analyzer.cpp   
      @author <fill me in>
      @date <fill me in>  

			@description Prints text statictics from a source docuemnt.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "TextProfile.h"


using namespace std;

TextProfile::TextProfile( string input ):text( input ){   
// :text(input) is the same as text = input
  
};

int TextProfile::getCharacterCount(){

  int character_count = 0;

  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isPrintable( text.at( i ))){

      character_count++;

    }
  }

  return character_count;
};

int TextProfile::getLineCount(){

  int line_count = 0;
  bool ignore = false;
  bool lonely_newline = false;  

  for( unsigned int i = 0; i < text.length(); i++ ){
    if( ignore == true and text.at( i ) == '\n' ){
      ignore = false;

      /*  If a newline symbol was found by itself on the previous line, 
          increase line_count */
      if( lonely_newline == true ){
        line_count++;
        lonely_newline = false;
      }
    }else if( ignore == false and text.at( i ) > 0 and text.at( i ) != '\n' ){
      /*  If there are non-newline characters, increase line_count and ignore 
          input until a newline character is reached */

      ignore = true;
      line_count++;
    
    }else if( ignore == false and text.at( i ) == '\n' ){
      lonely_newline = true;
    }
  }
  
  return line_count;
};

int TextProfile::getWordCount(){

  int word_count = 0;

  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isLetter( text.at( i ))){
      while( isPrintable( text.at( i )) and !isPunctuation( text.at( i ))){
        i++;

        if( i >= text.length()){
          break;
        }
      }

      word_count++;
    }
  }

  return word_count;
};

int TextProfile::getSentenceCount(){

  int sentence_count = 0;

  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isPrintable( text.at( i )) and !isPunctuation( text.at( i ))){
      while( !isPunctuation( text.at( i ))){
        i++;

        if( i >= text.length() ){
          break;
        }
      }

      sentence_count++;
    }
  }

  return sentence_count;
};

float TextProfile::getAverageWordsPerSentence(){ 

  if( getSentenceCount() != 0 ){
    return (float)getWordCount()/(float)getSentenceCount();
  }else{
    return 0;
  }
};

float TextProfile::getAverageWordLength(){

  float letter_count = 0;

  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isLetter( text.at( i ))){
      letter_count++;
    }
  }

  if( getSentenceCount() != 0 ){
    return (float)letter_count/(float)getWordCount();
  }else{
    return 0;
  }
};

float TextProfile::typeTokenRatio(){

  vector<string> words;

  // loading all words into the initial vector
  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isLetter( text.at( i ))){
      
      string word;
      word += tolower( text.at( i ));

      while( isPrintable( text.at( i )) and !isPunctuation( text.at( i ))){
        i++;

        if( i >= text.length()){
          break;
        }

        word += tolower( text.at( i ));
      }

      bool is_unique = true;

      for( vector<string>::iterator iterator_words = words.begin(); 
        iterator_words != words.end(); iterator_words++ ){

        if( *iterator_words == word ){
          is_unique = false;
        }
      }
      
      if( is_unique ){
        words.push_back( word ); 
      }
    }
  }

  return (float)words.size()/(float)getWordCount();
};

float TextProfile::hapaxRatio(){

  vector<string> words;

  // loading all words into the initial vector
  for( unsigned int i = 0; i < text.length(); i++ ){
    if( isLetter( text.at( i ))){
      
      string word;
      word += tolower( text.at( i ));

      while( isPrintable( text.at( i )) and !isPunctuation( text.at( i ))){
        i++;

        if( i >= text.length()){
          break;
        }

        word += tolower( text.at( i ));
      }

      bool is_unique = true;

      for( vector<string>::iterator iterator_words = words.begin(); 
        iterator_words != words.end(); iterator_words++ ){

        if( *iterator_words == word ){
          is_unique = false;
        }
      }
      
      if( is_unique ){
        words.push_back( word ); 
      }
    }
  }

  return 0.0;
};

bool TextProfile::isLetter( char character ){
  
  if(( character >= 65 and character <= 90 ) or ( character >= 97 and 
      character <= 122 )){
    return true;
  }

  return false;

}

bool TextProfile::isPrintable( char character ){

  if( character > 32 and character < 127  ){
    return true;
  }

  return false;

}

bool TextProfile::isPunctuation( char character ){

  if( character == '.' or character == '!' or character == '?' ){
    return true;
  }

  return false;

}

