#include <thread>
#include <iostream>
#include <string>
class Test {
public:
	Test(std::string text) {
		std::thread printtest(&Test::print, this,text);
		printtest.join();
	}
	Test() {

	}
	void display(std::string text) {
		std::cout << text << std::endl;
	}
private:
	void print(std::string text) {
		std::cout << text << std::endl;
	}
};

class Pass {
public:
	Pass() {
		Test t;
		std::thread displaypass(&Test::display, t, "Pass executed"); //You must pass the classes object as a parameter
		displaypass.join();
	}
};
void print() {
	std::cout << "Hello World" << std::endl;
}

int main() {
	//Create a thread in the main function
	std::thread hello(print);
	hello.join();  //Wait for the thread to finish executing

	//Create a thread in a class
	Test test("Test passed");

	//create a thread using a function from another class
	Pass pass;

	return 0;
}