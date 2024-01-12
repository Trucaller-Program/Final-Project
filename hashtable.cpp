#include "HashTable.h"
#include <vector>
#include <Math.h>

HashTable::HashTable()
    :table(tableSize),numberOfElements(0)
{}

HashTable::~HashTable() {
    table.clear();
    tableSize = 0;
    numberOfElements = 0;
}

bool HashTable::empty() {
    return table.empty();
}

bool HashTable::isPrime(int num) {
    if (num == 1 || num == 0)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int HashTable::checkLargestPrime() {
    int prime = (int)tableSize - 1;
    while (!isPrime(prime) && tableSize != 0) {
        prime--;
    }
    return prime;
}

int HashTable::firstHashFunction(string n) {
    int sum = 0;
    for (size_t i = 0; i < n.length(); i++) {
        sum += n[i];
    }
    return sum % tableSize;
}

int HashTable::secondHashFunction(string n) {
    int prime = checkLargestPrime();
    int sum = 0;
    for (size_t i = 0; i < n.length(); i++) {
        sum += n[i];
    }
    return  prime - (sum % prime);
}

int HashTable::doubleHashFunction_insert(string n) {
    int hash1 = firstHashFunction(n);
    if (table[hash1].key == -1 || table[hash1].key == -2) {
        return hash1;
    }
    int hash2 = secondHashFunction(n);
    int hash1_2 = 0;
    int i = 1;
    while (i < tableSize) {
        hash1_2 = (hash1 + i * hash2) % tableSize;
        if (table[hash1_2].key == -1 || table[hash1_2].key == -2) {
            return hash1_2;
        }
        else i++;
    }
}

int HashTable::doubleHashing(string n) {
    bool found = false;
    int hash1 = firstHashFunction(n);
    if (table[hash1].number == n) {
        found = true;
        return hash1;
    }
    int hash2 = secondHashFunction(n);
    int hash1_2 = 0;
    int i = 1;
    while (i < tableSize) {
        hash1_2 = (hash1 + i * hash2) % tableSize;
        if (table[hash1_2].number == n) {
            found = true;
            return hash1_2;
        }
        else i++;
    }
    if (!found)
        return -3;
}

void HashTable::rehashing(int size) {
    for (int i = 0; i < size; i++) {
        if (table[i].key == -1 || table[i].key == -2) {
            continue;
        }
        else {
            int index = doubleHashFunction_insert(table[i].number);
            Node new_node(table[i].name, table[i].number, index);
            table[index] = new_node;
            table[i].name.erase();
            table[i].number.erase();
            table[i].key = -1;
        }
    }
}

void HashTable::insert_double(string name, string number) {
    float loadFactor = (float)numberOfElements / tableSize;
    if (loadFactor > THRESHOLD) {
        int size = tableSize;
        table.resize(tableSize + 10);
        tableSize = table.size();
        rehashing(size);
    }
    int index = doubleHashFunction_insert(number);
    Node new_node(name, number, index);
    table[index] = new_node;
    numberOfElements++;
}

string HashTable::searchNumber_double(string number) {
    int index = doubleHashing(number);
    if (index == -3) {
        return "Number is not found\n";
    }

    return table[index].name + "            " + table[index].number;
}

void HashTable::deleteNumber_double(string number) {
    int index = doubleHashing(number);
    if (index == -3) {
        cout << "Element doesn't exist\n";
        return;
    }
    table[index].name.erase();
    table[index].number.erase();
    table[index].key = -2;
}

void HashTable::display(ostream& out)const {
    for (size_t i = 0; i < table.size(); i++) {
        out << table[i].name << "  " << table[i].number << endl;
    }
}
