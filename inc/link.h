#ifndef LINK_H
#define LINK_H
#include "./node.h"
class Link : public Node{
public:
    Link(std::string);
    Iterator* createIterator();
    Node* getSource();
    void addLink(Node*);
    void accept(Visitor *);
private:
    Node* _symLink;
};
#endif