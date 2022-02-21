#ifndef XMLTREE_HPP
#define XMLTREE_HPP

#include <string>
#include <vector>

typedef std::pair<std::string, std::string> Attribute;

class Element {
private:
    std::string* m_tag;              // the tag; ex <car></car> ; car is the tag
    std::string* m_content;          // can be null; ex <name>Jane</name> yields Jane
    std::vector<Element*>* m_children;  // all Elements inside 
    std::vector<Attribute*>* m_attributes; // all Attributes; ex: <car brand="Tesla"></car>, Attribute.first = "brand", Attribute.second = "Tesla"

public:
    Element(std::string* tag, std::string* content);
    ~Element();
    void insert(Element* child); // add a child to my children
    void attribute(std::string key, std::string val); // add an Attribute to m_attributes 
    std::vector<Element*>* select(bool (*condition)(Element*)); // select all children that fit the given condition
    std::string* tag(); // getter for m_tag
    std::string* content(); // getter for m_content
    std::vector<Element*>* children(); // getter for m_children
};

typedef bool (*condfunc)(Element*);

#endif//XMLTREE_HPP