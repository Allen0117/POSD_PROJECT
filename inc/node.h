#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include "./iterator.h"
#include "./visitor.h"
class Node{
public:
    Node(std::string); 
    std::string getFileName();
    std::string getFilePath();
    std::string getFileType();
    int getSize();
    void renameNode(std::string );
    void setPath(std::string );
    virtual int infoByte();
    virtual void addChild(Node*);
    virtual Node* getChild(std::string);
    virtual Iterator* createIterator() = 0;
    virtual void accept(Visitor *) = 0;
private:
    bool isExistNode();
    void parseFilePathGetName();
    std::string readNodeType();
    std::string _filePath;
    std::string _fileName;
    struct stat _st;//using c api get file states 
};
#endif