#include "../inc/folder.h"
#include "../inc/null_iterator.h"
//<-----Public methods----->
Folder::Folder(std::string filePath):Node(filePath){
    if(Folder::getFileType()!="folder")
    throw std::string("It is not Folder!");
}
//<-----Virtual public methods----->
void Folder::addChild(Node* child){
    _m[child->getFileName()] = child;
}
Node* Folder::getChild(std::string childName){
    
    Node* result ;
    Iterator* iter  = this->createIterator(); 
    for(iter->first(); !iter->isDone(); iter->next())
    {
      if(iter->currentItem()->getFileName() == childName)
      result = iter->currentItem();
    }
    delete iter;
    return result;
}
Iterator* Folder::createIterator(){
    return new FolderIterator(this);
}
void Folder::accept(Visitor* v){
    v->visitFolder(this);
}
int Folder::infoByte(){
    int total = 0;
    Iterator* iter  = this->createIterator(); 
    for(iter->first(); !iter->isDone(); iter->next())
    {
      total += iter->currentItem()->infoByte();
    }
    delete iter;
    return total;
}
//<-----Private methods----->