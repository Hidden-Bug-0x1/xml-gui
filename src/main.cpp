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

void print(Node* root, int tabs=0) {
    std::string tag = *root->tag();
    std::string content = *root->content();
    std::vector<Node*> children = *root->children();

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

bool bills(Node* root) {
    std::string tag = *root->tag();
    if (tag == "bill") return true;
    else {
        std::vector<Node*> children = *root->children();
        for(auto child : children) {
            return bills(child);
        }
    }
    return false;
}

bool frombank(Node* root) {
    std::string tag = *root->tag();
    if (tag == "bill") {
        std::vector<Node*> children = *root->children();
        for(auto child : children) {
            std::string childtag = *child->tag();
            std::string childcont = *child->content();
            if (childtag == "from" && childcont == "Bank") return true;
        }
        return false;
    }
    else {
        std::vector<Node*> children = *root->children();
        for(auto child : children) {
            return bills(child);
        }
    }
    return false;
}

Node* newbill(const char* sfrom) {
    Node* bill = new Node(str("bill"), str(""));
    Node* from =  new Node(str("from"), str(sfrom));
    Node* body = new Node(str("body"), str("You owe $100"));
    Node* address = new Node(str("address"), str("100 C St, Bank, USA"));
    
    body->insert(address);
    bill->insert(from);
    bill->insert(body);

    return bill;
}

int main() {
    Node* mail = new Node(str("mail"), str(""));

    Node* note = new Node(str("note"), str(""));
    Node* to = new Node(str("to"), str("John Doe"));
    Node* headline = new Node(str("headline"), str("Reminder"));
    Node* note_body = new Node(str("message"), str(""));
    Node* msg = new Node(str("message"), str("Please do your chores!"));
    Node* img = new Node(str("image"), str(""));
    Node* src = new Node(str("src"), str("kisses.jpg"));
    Node* alt = new Node(str("alt_text"), str("XOXOXOXO"));

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

    std::vector<Node*> allbills = *mail->select(bills);

    std::cout << "There are " << allbills.size() << " bills to pay." << std::endl;
    std::cout << "There are " << mail->select(frombank)->size() << " bills from the bank." << std::endl;
    return 0;
}