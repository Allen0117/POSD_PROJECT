#ifndef FILE_H 
#define FILE_H
#include "./node.h"
class File : public Node{
public:
    File(std::string);
    Iterator* createIterator();
    void accept(Visitor *);
};
#endif