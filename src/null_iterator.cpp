#include "../inc/null_iterator.h"
//<-----Public methods----->
//<-----Virtual public methods----->
bool NullIterator::isDone(){
    return true;
}
void NullIterator::first(){
    throw(std::string("no child member"));
}
void NullIterator::next(){
    throw(std::string("no child member"));
}
Node* NullIterator::currentItem(){
    throw(std::string("no child member"));
}
//<-----Private methods----->