#include "../inc/link.h"
#include "../inc/null_iterator.h"
//<-----Public methods----->
Link::Link(std::string filePath):Node(filePath),_symLink(nullptr){
    if(Node::getFileType()!="link")
    throw std::string("It is not Link!");
}
Node* Link::getSource(){
    return _symLink;
}
void Link::addLink(Node* link){
    _symLink = link;
}
//<-----Virtual public methods----->
Iterator* Link::createIterator(){
    return new NullIterator();
}
void Link::accept(Visitor* v){
    v->visitLink(this);
}
//<-----Private methods----->
