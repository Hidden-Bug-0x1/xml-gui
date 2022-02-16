#ifndef XMLTREE
#define XMLTREE

#include <string>
#include <vector>

class Node {
private:
    std::string* m_tag;              // the tag; ex <car></car> ; car is the tag
    std::string* m_content;          // can be null; ex <name>Jane</name> yields Jane
    std::vector<Node*>* m_children;  // all Nodes inside 

public:
    Node(std::string* tag, std::string* content);
    ~Node();
    void insert(Node* child); // add a child to my children
    std::vector<Node*>* select(bool (*condition)(Node*)); // select all children that fit the given condition
    std::string* tag(); // getter for m_tag
    std::string* content(); // getter for m_content
    std::vector<Node*>* children(); // getter for m_children
};

typedef bool (*condfunc)(Node*);

#endif//XMLTREE