#ifndef HASHTABLE_H
#define HASHTABLE_H
#pragma once
#include<iostream>
#include<vector>
using namespace std;

const float THRESHOLD = 0.75;

class HashTable {
private:
    class Node {
    public:
        int key;
        string name;
        string number;
        Node()
            :key(-1),number(""), name("")
        {}
        Node(string name, string number, int key)
            :name(name), number(number), key(key)
        {}
    };

    int tableSize = 50;
    vector <Node> table;
    int numberOfElements;

    bool isPrime(int num);
    int checkLargestPrime();
    int firstHashFunction(string n);
    int secondHashFunction(string n);
    int doubleHashFunction_insert(string n);
    int doubleHashing(string n);


public:
    HashTable();

    ~HashTable();

    bool empty();

    void rehashing(int size);

    void insert_double(string name, string number);

    string searchNumber_double(string number);

    void deleteNumber_double(string number);

    void display(ostream& out)const;

};


#endif // HASHTABLE_H
