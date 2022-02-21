#include "../inc/xmltree.hpp"

Element::Element(std::string* tag, std::string* content) 
: m_tag(tag), m_content(content) 
{
    m_children = new std::vector<Element*>();
}

Element::~Element() 
{
    delete m_children;
    delete m_attributes;
}

void Element::insert(Element* child) 
{
    m_children->push_back(child);
}

void Element::attribute(std::string key, std::string val) 
{
    Attribute* attr = new Attribute(key, val);
    m_attributes->push_back(attr);
}

std::vector<Element*>* Element::select(condfunc condition) 
{
    std::vector<Element*>* selected = new std::vector<Element*>();
    for (std::vector<Element*>::iterator child = m_children->begin(); child != m_children->end(); child++)
    {
        if (condition(*child)) selected->push_back(*child);
    }
    return selected;
}

std::string* Element::tag() 
{
    return m_tag;
}

std::string* Element::content() 
{
    return m_content;
}

std::vector<Element*>* Element::children() 
{
    return m_children;
}