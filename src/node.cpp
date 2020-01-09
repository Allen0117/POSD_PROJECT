#include "../inc/node.h"
#include "../inc/string_utility.h"
//<-----Public methods----->
Node::Node(std::string filePath):_filePath(filePath),_fileName(""){
    if(!isExistNode())
    throw std::string("Node is not exist!");
    parseFilePathGetName();
}
std::string Node::getFileName(){
    return _fileName;
}
std::string Node::getFilePath(){
    return _filePath;
}
std::string Node::getFileType(){
    return readNodeType();
}
int Node::getSize(){
    return _st.st_size;
}
void Node::renameNode(std::string newName){
     std::string newPath = newName;
     StringUtility su;
     if(getFileName() != getFilePath()){
          newPath = su.splitString(_filePath,"\\/") +"/"+newName;
     }
     _fileName = newName;
     std::rename(getFilePath().c_str(),newPath.c_str());
}
void Node::setPath(std::string newPath){
    _filePath = newPath;
}
//<-----Virtual public methods----->
int Node::infoByte(){
    return getSize();
}
void Node::addChild(Node* child){
    throw(std::string("Invalid add!"));
}
Node* Node::getChild(std::string childName){
    return nullptr;
}
//<-----Private methods----->
bool Node::isExistNode(){
    if(!(lstat(_filePath.c_str(), &_st))) return  true;
    return false;
}
void Node::parseFilePathGetName(){
    StringUtility su;
    _fileName = su.splitString(_filePath,"\\/","R");
}
std::string Node::readNodeType(){
    if(S_ISREG(_st.st_mode))
    return std::string("file");
    if(S_ISDIR(_st.st_mode))
    return std::string("folder");
    if(S_ISLNK(_st.st_mode))
    return std::string("link");
}