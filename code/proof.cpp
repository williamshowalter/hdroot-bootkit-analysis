#include <iostream>
#include <fstream>

int main () {	
	std::ofstream output1;
	output1.open("C:\\proof.txt");
	output1 << "file_ran\n";
	output1.close();
	std::cout << "Completed\n";
	return 0;
}