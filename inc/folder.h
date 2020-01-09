#ifndef FOLDER_H
#define FOLDER_H
#include "./node.h"
#include <map>
class Folder : public Node{
public:
class FolderIterator : public Iterator{
public:
    FolderIterator(Folder * f): _f(f){}
    void first()
    {
         _current = _f->_m.begin();
    }
    Node* currentItem()
    {
        // if iterator is to the end that it should throw string "No current item!"
        // if iterator is not to the end that it should return current node
        if(!isDone())
        return _current->second;
        else
        throw(std::string("No current item!"));
    }
    void next()
    {
        // if iterator is to the end that it should throw string "Moving past the end!"
        // if iterator is not to the end that it should add 1
        if(!isDone())
        ++_current;
        else
        throw(std::string("Moving past the end!"));
    }
    bool isDone()
    {
        if(_current == _f->_m.end())
        return true;
        return false;
    }
private:
    Folder * _f;
    std::map<std::string, Node*>::iterator _current;
};
public:
    Folder(std::string);
    void addChild(Node*);
    Node* getChild(std::string);
    Iterator* createIterator();
    void accept(Visitor *);
    int infoByte();
private:
    std::map<std::string , Node*> _m;
};
#endif
