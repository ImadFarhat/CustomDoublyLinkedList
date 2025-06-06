//Name: Imad Farhat
#include "DoublyLinkedList.h"

int main() {
	 DoublyLinkedList a;
	 a.pop_front(); //does nothing since list is empty

	 a.push_front(3);
	 a.push_front(5);
	 std::cout << "List a is: " << a << std::endl;
	 
	std::cout << "Index of 3 is at: " << a.find(3) << std::endl;
	std::cout << "Size is: " << a.size() << std::endl;
	DoublyLinkedList b;
	 b.insert(0, 1);
	 b.insert(1, 2);
	 b.insert(2, 3);
	 std::cout << "List b is: " << b << std::endl;
	 std::cout << "Size is: " << b.size() << std::endl;
	

	 std::cout << "Index of 2 is at: " << b.find(2) << std::endl;

	 b.erase(0);
	 b.push_front(0);
	 b.pop_front();
	 std::cout <<"The head was just erased. List b is: " << b << std::endl;
	 std::cout << "Index of 3 is at: " << b.find(3) << std::endl;
	 std::cout << "Size is: " << b.size() << std::endl;
	 std::cout << "New head is: " << b[0] << std::endl;
	 std::cout << "Is b empty? 0 means no and 1 means yes: " << b.empty() << std::endl;
	 
	 b.erase(1);
	 std::cout << "Index 1 is erased. List b is: " << b << std::endl;
	 std::cout << "Size is: " << b.size() << std::endl;
	 std::cout << "Is b empty? 0 means no and 1 means yes: " << b.empty() << std::endl;
	 b.insert(5, 10);
	 b.insert(1, 7);
	 b.insert(1, 4);
	 std::cout << "New values are added. List b is: " << b << std::endl;
	 std::cout << "Searching for index of value 11: " << b.find(11) << std::endl;

	 //statements to test each method using custom lists
}