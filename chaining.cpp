#include "chaining.h"

Chaining::Chaining()
    :table(tableSize),numberOfElements(0)
{}

Chaining::~Chaining(){
    for (size_t i = 0; i < table.size(); i++) {
        table[i].clear();
    }
    numberOfElements = 0;
    tableSize = 0;
}

bool Chaining::empty(){
    return table.empty();
}

int Chaining::hashFunction(string n) {
    int sum = 0;
    for (size_t i = 0; i < n.length(); i++) {
        sum += n[i];
    }
    return sum % tableSize;
}

void Chaining::insert_chaining(string name, string number) {
    int index = hashFunction(name);
    Node new_node(name, number);
    table[index].push_back(new_node);
    numberOfElements++;
}

string Chaining::searchName_chaining(string name) {
    int index = hashFunction(name);
    for (size_t col = 0; col < table[index].size(); col++) {
        if (table[index][col].name == name) {
            return table[index][col].name + "            " + table[index][col].number;
        }
    }
    return "Name is not found";
}

void Chaining::deleteName_chaining(string name) {
    bool found = false;
    int index = hashFunction(name);
    for (size_t col = 0; col < table[index].size(); col++) {
        vector<Node>::iterator it = table[index].begin() + col;
        if (table[index][col].name == name) {
            found = true;
            table[index].erase(it);
            numberOfElements--;
        }
    }
    if (!found)
        cout << "Element doesn't exist";
}

void Chaining::display(ostream& out)const{
    for (size_t i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            out << table[i][j].name << "  " << table[i][j].number << endl;
        }
    }
}
