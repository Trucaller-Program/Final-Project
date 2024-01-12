#ifndef CHAINING_H
#define CHAINING_H


#pragma once
#include <iostream>
#include<vector>

using namespace std;

class Chaining{
public:
    class Node {
    public:
        string name;
        string number;
        Node()
            :name(""),number("")
        {}
        Node(string name, string number)
            :name(name), number(number)
        {}
    };

    int tableSize = 50;
    vector<vector <Node>> table;
    int numberOfElements;
    int hashFunction(string n);

public:
    Chaining();

    ~Chaining();

    bool empty();

    void insert_chaining(string name, string number);

    string searchName_chaining(string name);

    void deleteName_chaining(string name);

    void display(ostream& out)const;
};


#endif // CHAINING_H
