#include "../inc/file.h"
#include "../inc/null_iterator.h"
//<-----Public methods----->
File::File(std::string filePath):Node(filePath){
    if(Node::getFileType()!="file")
    throw std::string("It is not File!");
}
//<-----Virtual public methods----->
Iterator* File::createIterator(){
    return new NullIterator();
}
void File::accept(Visitor* v){
    v->visitFile(this);
}
//<-----Private methods----->