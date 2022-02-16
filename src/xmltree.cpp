#include "../inc/xmltree.hpp"

Node::Node(std::string* tag, std::string* content) 
: m_tag(tag), m_content(content) {
    m_children = new std::vector<Node*>();
}

Node::~Node() {
    delete m_children;
}

void Node::insert(Node* child) {
    m_children->push_back(child);
}

std::vector<Node*>* Node::select(condfunc condition) {
    std::vector<Node*>* selected = new std::vector<Node*>();
    for (std::vector<Node*>::iterator child = m_children->begin(); child != m_children->end(); child++){
        if (condition(*child)) selected->push_back(*child);
    }
    return selected;
}

std::string* Node::tag() {
    return m_tag;
}

std::string* Node::content() {
    return m_content;
}

std::vector<Node*>* Node::children() {
    return m_children;
}