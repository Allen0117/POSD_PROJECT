#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H
#include "node.h"
class NullIterator: public Iterator{
public:
      bool isDone();
      void first();
      void next();
      Node* currentItem();
};
#endif