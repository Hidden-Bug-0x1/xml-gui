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
    void insert(Node* child);
    std::vector<Node*>* select(bool (*condition)(Node*));
    std::string* tag();
    std::string* content();
    std::vector<Node*>* children();
    void clear();
};

typedef bool (*condfunc)(Node*);

#endif//XMLTREE