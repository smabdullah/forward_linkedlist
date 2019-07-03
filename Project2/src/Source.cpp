#include<iostream>
#include "linkedlist.h"

int main() {
	container::List<char> list;
	for (int i = 0; i < 26; ++i)
		list.append(i+65);

	list.search(66)? std::cout << "Item found\n": std::cout << "Item not found\n";

	list.print();
	std::cout << list.len() << std::endl;
	return 0;
}