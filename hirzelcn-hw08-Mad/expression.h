#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

ostream& operator<<( ostream& out, const Exp& to_print ){
  out << to_print.getString();
  return out;
}

class Exp{
public:
  Exp( string expression ){
    this->expression = expression;
  }
  
  virtual ~Exp(){}

  friend ostream& operator<<( ostream& out, const Exp& to_print );

  string getString(){
    return expression;
  }

private:
  string expression;
}

class Terminal{
public:
  Terminal( string input_exp );
private:
  Exp expression;
};

class Keyword{
public:
  Keyword( string input_exp );
private:
  Exp expression;
  map<string, Exp*> the_map;
};

class Choice{
public:
  Choice(){}

  Choice( string input_exp ){

  }

  virtual ~Choice(){}

  Terminal getKeyword(){
    return keyword;
  }

  Terminal getExpression( int position ){
    return expressions.at( position );
  }

  void addExpression( Exp expression ){
    expressions.push_back( expression );
  }

private:
  vector<Exp> expressions;
  Keyword keyword;
}

class Sequence: public Exp{
public:
  Sequence(){}

  Sequence( string input_exp ){

  }

  virtual ~Sequence(){}

private:
  vector<CExp> expression;
}
// Fill in all classes here!  Implement her
