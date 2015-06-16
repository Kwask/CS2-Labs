/*    @file TextProfile_test.h  
      @author <your name
      @date 08-16-2013  
      @version 0.01   
      Copyright 2014 your name

			Unit tests for TextProfile class.
*/

#include <TextProfile.h>

#include <cxxtest/TestSuite.h>

class TextProfileTest : public CxxTest::TestSuite {
public:

/* --  getCharCount ----------------------------------*/
	void testCharCount0(){
		TextProfile a("");
		TS_ASSERT_EQUALS(a.getCharacterCount(), 0 );
	}
	
	void testCharCount1(){
		TextProfile a("a");
		TS_ASSERT_EQUALS(a.getCharacterCount(), 1 );
	}
	
	
/* --  getLineCount ----------------------------------*/
  //Mine
  void testLineCount0(){
    TextProfile a( "\n" );
    TS_ASSERT_EQUALS( a.getLineCount(), 0 );
  }

  void testLineCount1(){
		TextProfile a( "abcd" );
		TS_ASSERT_EQUALS( a.getLineCount(), 1 );
	}

  // Mine
  void testLineCount2(){
    TextProfile a( "a\n\n" );
    TS_ASSERT_EQUALS( a.getLineCount(), 1 );
  }
  
  // Mine
  void testLineCount4(){
    TextProfile a( "\na\nb\nc\n" );
    TS_ASSERT_EQUALS( a.getLineCount(), 4 );
  }
	
/* --  getWordCount ----------------------------------*/
	void testWordCount1(){
		TextProfile a("boy");
		TS_ASSERT_EQUALS( a.getWordCount(), 1 );
	}

  // Mine
  void testWordCount2(){
    TextProfile a( "this is a sentence ." );
    TS_ASSERT_EQUALS( a.getWordCount(), 4 );
	}

  // Mine
  void testWordCount3(){
    TextProfile a( " word " );
    TS_ASSERT_EQUALS( a.getWordCount(), 1 );
	}

  // Mine
  void testWordCount4(){
    TextProfile a( ".still.words." );
    TS_ASSERT_EQUALS( a.getWordCount(), 2 );
	}

  // Mine
  void testWordCount5(){
    TextProfile a( " humonguous ungodly. vocables" );
    TS_ASSERT_EQUALS( a.getWordCount(), 3 );
	}

  


/* --  getSentenceCount ----------------------------------*/
  void testGetSentenceCount0(){
		TextProfile a( "This is a sentence." );
		TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
	}

  // Mine
  void testGetSentenceCount1(){
    TextProfile a( "this is also a sentence." );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
	}

  // Mine
  void testGetSentenceCount3(){
    TextProfile a( "This is still a sentence ." );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }
  
  // Mine
  void testGetSentenceCount4(){
    TextProfile a( " This is still a sentence." );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }

  // Mine
  void testGetSentenceCount5(){
    TextProfile a( "This is still a sentence" );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }

  // Mine
  void testGetSentenceCount6(){
    TextProfile a( "This is still a sentence!" );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }

  // Mine
  void testGetSentenceCount7(){
    TextProfile a( "This is still a sentence?" );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }
  
  // Mine
  void testGetSentenceCount8(){
    TextProfile a( "This is still a sentence!?!" );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }

  // Mine
  void testGetSentenceCount9(){
    TextProfile a( "" );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 0 );
  }

  // Mine
  void testGetSentenceCount10(){
    TextProfile a( " This is still a sentence. " );
    TS_ASSERT_EQUALS( a.getSentenceCount(), 1 );
  }


/* --  getAverageWordsPerSentence ----------------------------------*/
  void testGetAverageWordsPerSentence0(){
		TextProfile a("This is a sentence.");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}

  // Mine
  void testGetAverageWordsPerSentence1(){
		TextProfile a("This too is a sentence.");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 5, 0.01);
	}

  // Mine
  void testGetAverageWordsPerSentence2(){
		TextProfile a("Why are these sentences?");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}

  // Mine
  void testGetAverageWordsPerSentence3(){
		TextProfile a("Too many sentences!.");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}



/* --  getAverageWordLength ----------------------------------*/
  void testGetAverageWordLength0(){
		TextProfile a("This");
		TS_ASSERT_DELTA(a.getAverageWordLength(), 4, 0.01);
	}

  // Mine
  void testGetAverageWordLength2(){
		TextProfile a("This is longer word");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}

  // Mine
  void testGetAverageWordLength(){
		TextProfile a("To many wordss here");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}
	
/* --  typeTokenRatio ----------------------------------*/
	void testTypeTokenRatio2(){
		TextProfile a("this is a big big sentance this is a big sentance");
		TS_ASSERT_DELTA(a.typeTokenRatio(), 0.5, 0.1);
	}

/* --  hypaxRatio ----------------------------------*/
  void testHapaxRatio2(){
		TextProfile a("this is a sentance? of a sentance is ");
		TS_ASSERT_DELTA(a.hapaxRatio(), 0.25, 0.01);
	}

	
/* -- White Box Tests ------------------------------------------------- */

};
