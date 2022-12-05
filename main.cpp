#include <iostream>
#include "table.h"

int main() {
    HashTable<std::string, int> my_hash_table;
    my_hash_table.Insert("aaaa", 23);
    my_hash_table.Insert("bbbbeeee", 1236);
    std::cout << my_hash_table.Search("bbbbeeee") << std::endl;
    my_hash_table.Output();
    return 0;
}
