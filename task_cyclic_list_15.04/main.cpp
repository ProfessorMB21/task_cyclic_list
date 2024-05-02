#include "main.h"

using namespace std;

int main()
{
	list_t numbers;

	ifstream file("num2.txt");
	if (file)
	{
		int i;
		while (!file.eof())
		{
			file >> i;
			numbers.add(i);
		}
		file.close();
	}
	else {
		cout << "file not found!" << endl;
	}

	cout << "----------LIST TESTING-----------\n";
	//numbers.tail->next = numbers.head; // making list cyclic for testing
	cout << "Number sequence is, ";
	numbers.toHead(); // take the pointer back to head

	bool loop_result = numbers.is_cyclic();
	if (loop_result == true)
		cout << "CYCLIC" << endl;
	else
		cout << "NOT CYCLIC" << endl;
	cout << "---------------------------------\n";

	return 0;
}
