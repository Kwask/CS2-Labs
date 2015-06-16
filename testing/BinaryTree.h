template <class T>
class BinaryTree{
public:
  BinaryTree(){
    head = 0;
  }

  BinaryTree( T value ){
    head = new Node<T>( value );
  }

  virtual ~BinaryTree(){
    if( head != 0 ){
      delete head;
    }
  }

  bool insert( T value ){
    Node<T>* nearest = find( value );

    if( nearest == 0 ){
      head = new Node<T>( value );
      return true;
    }

    if( nearest->getValue() == value ){
      return false;
    }

    if( value < nearest->getValue() ){
      nearest->setLeft( new Node<T>( value ));
    }else if( value > nearest->getValue() ){
      nearest->setRight( new Node<T>( value ));
    }

    return true;
  }

  bool remove( T value ){
    Node<T>* nearest = find( value );

    if( nearest == 0 ){
      return false;
    }

    if( value == nearest->getValue() ){
      delete nearest;
      return true;
    }else{
      return false;
    }
  }

  Node<T>* find( T value ){
    if( head == 0 ){
      return 0;
    }

    Node<T>* current = head;

    while( current.getValue() != value ){
      if( value < current->getValue() ){
        current = current->getLeft();
      }else if( value > current->getValue(){
        current = current->getRight();
      }

      if( current == 0 ){
        break;
      }
    }

    return current;
  }

private:
  template <class G>
  class Node{
  public:
    Node(){
      value = 0;
      left = 0;
      right = 0;
    }

    Node( G value ){
      this->value = value;
      left = 0;
      right = 0;
    }

    Node( G value, Node* left, Node* right ){
      this->value = value;
      this->left = left;
      this->right = right;
    }

    virtual ~Node(){
      delete left;
      delete right;
    }

    Node* getLeft(){
      return left;
    }

    Node* getRight(){
      return right;
    }

    G getValue(){
      return value;
    }

    void setLeft( Node* left ){
      this->left = left;
    }

    void setRight( Node* right ){
      this->right = right;
    }

  private:
    G value;
    Node* left;
    Node* right;
  };

private:
  Node<T>* head;
};
