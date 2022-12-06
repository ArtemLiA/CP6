#include <iostream>
#include "table.h"

int main() {
    HashTable<std::string, int> my_hash_table;
    my_hash_table.Insert("Mikhail", 23);
    my_hash_table.Insert("Nikolay", 1236);
    my_hash_table.Insert("Andrei", 1236);
    my_hash_table.Insert("Artem", 10);
    my_hash_table.Insert("Artem", 123456);
    my_hash_table.Insert("Konstantin", -18);
    my_hash_table.Insert("Mikhail", 10);
    my_hash_table.Output();
    std::cout << std::endl;

    std::cout << my_hash_table.Search("Andrei") << std::endl;
    std::cout << std::endl;
    my_hash_table.Delete(23);
    my_hash_table.Delete(10);
    my_hash_table.Output();
    std::cout << my_hash_table["Nikolay"];
    return 0;
}
