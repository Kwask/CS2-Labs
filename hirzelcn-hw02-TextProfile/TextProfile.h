/*    @file TextProfile.h    
      @author Charles Hirzel
      @date 2014-09-02

			@description Returns text statistics for a string document.
*/

#include <iostream>
#include <vector>

using namespace std;

class TextProfile{
friend class TextProfileTest;
public:
	TextProfile( string text );
  
    /* getCharacterCount() returns the number of PRINTABLE characters
    given in the string.  This includes alphanumeric, plus numbers
    and punctuation. */
	int	getCharacterCount();
	
	  /* getLineCount() returns the number of lines in the given string.
	  Lines are delimited by the '\n' character */
	int getLineCount();
	
	  /* getWordCount() returns the number of words in the given string.
	  Words are groups of printable characters with whitespace before and
	  after. */
	int getWordCount();
	
	  /* getSentanceCount() return the number of sentences in the given string
	  A sentence is a sequence of 1. characters that ends (does not include)
	  the characters ! ? . or the end of the file. 2. whitespace on each end
	  and 3. is not empty.  */
	int getSentenceCount();

	
	  /* getAverageWordsPerSentance() returns a float of the average number
	  of words in a sentence, as defined in getSentanceCount above. */
	float getAverageWordsPerSentence();
	
	  /* getAverageWordLength() returns a float of the average number of 
	  alphanumeric characters in all words.  ie, remove punctuation. */
	float getAverageWordLength();
	
	  /* typeTokenRatio() returns a float of the ratio of the number of unique words to 
	  the total number of words.  Most documents contain repeated words.  
	  The numerator of this ratio does not contain any repeats, while 
	  the denominator does. */
	float typeTokenRatio();
	
	  /* returns a float of the Hapax Legomana Ratio.  Similar to the 
	  typeTokenRatio, but the numerator contains the count of words 
	  which are only used exactly ONCE in the text.  */
  float hapaxRatio();

    /* returns a bool of whether the given character is a letter */
  bool isLetter( char character );

    /* returns a bool of whether the given character is printable */
  bool isPrintable( char character );
    
    /* returns a bool of whether the given character is punctuation*/
  bool isPunctuation( char character );

private:
	TextProfile();

	string text;
  int text_length;
	
};
