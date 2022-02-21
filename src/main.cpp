#include <iostream>
#include <string>
#include <vector>
#include "../inc/xml.hpp"

std::string* str(const char* c) {
    return new std::string(c);
}

void indent(int tabs) {
    std::string ending = "";
    if (tabs > 0) {
        ending = "|-->";
    }
    while (--tabs > 0) std::cout << "|   ";
    std::cout << ending;
}

void print(Element* root, int tabs=0) {
    std::string tag = *root->tag();
    std::string content = *root->content();
    std::vector<Element*> children = *root->children();

    indent(tabs);

    std::cout << tag << "\n";

    if (content.length() > 0) {
        indent(tabs+1);
        std::cout << content << "\n";
    }

    for(auto child : children) {
        print(child, tabs+1);
    }
}

bool bills(Element* root) {
    std::string tag = *root->tag();
    if (tag == "bill") return true;
    else {
        std::vector<Element*> children = *root->children();
        for(auto child : children) {
            return bills(child);
        }
    }
    return false;
}

bool frombank(Element* root) {
    std::string tag = *root->tag();
    if (tag == "bill") {
        std::vector<Element*> children = *root->children();
        for(auto child : children) {
            std::string childtag = *child->tag();
            std::string childcont = *child->content();
            if (childtag == "from" && childcont == "Bank") return true;
        }
        return false;
    }
    else {
        std::vector<Element*> children = *root->children();
        for(auto child : children) {
            return bills(child);
        }
    }
    return false;
}

Element* newbill(const char* sfrom) {
    Element* bill = new Element(str("bill"), str(""));
    Element* from =  new Element(str("from"), str(sfrom));
    Element* body = new Element(str("body"), str("You owe $100"));
    Element* address = new Element(str("address"), str("100 C St, Bank, USA"));
    
    body->insert(address);
    bill->insert(from);
    bill->insert(body);

    return bill;
}

int main() {
    Element* mail = new Element(str("mail"), str(""));

    Element* note = new Element(str("note"), str(""));
    Element* to = new Element(str("to"), str("John Doe"));
    Element* headline = new Element(str("headline"), str("Reminder"));
    Element* note_body = new Element(str("message"), str(""));
    Element* msg = new Element(str("message"), str("Please do your chores!"));
    Element* img = new Element(str("image"), str(""));
    Element* src = new Element(str("src"), str("kisses.jpg"));
    Element* alt = new Element(str("alt_text"), str("XOXOXOXO"));

    img->insert(src);
    img->insert(alt);

    note_body->insert(msg);
    note_body->insert(img);

    note->insert(to);
    note->insert(headline);
    note->insert(note_body);

    mail->insert(note);
    mail->insert(newbill("Bank"));

    mail->insert(newbill("Hospital"));


    mail->insert(note);
    mail->insert(newbill("Library"));

    mail->insert(note);
    mail->insert(newbill("Bank"));


    mail->insert(newbill("School"));

    // 5 bills; 2 from the bank
    // 3 notes

    print(mail);

    std::vector<Element*> allbills = *mail->select(bills);

    std::cout << "There are " << allbills.size() << " bills to pay." << std::endl;
    std::cout << "There are " << mail->select(frombank)->size() << " bills from the bank." << std::endl;
    return 0;
}