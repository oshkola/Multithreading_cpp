#include <chrono>
#include <iostream>
#include <thread>

void changeInput(int &a)
{
	std::cout << "******CHANGEINPUT STARTED******" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	a *= 2;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "******CHANGEINPUT FINISHED******" << std::endl;
}

int main()
{
	int a = 7;

	std::cout << "1 main(): a = " << a << std::endl;

	std::thread th1(changeInput, std::ref(a));

	th1.join();

	std::cout << "2 main(): a = " << a << std::endl;
}
