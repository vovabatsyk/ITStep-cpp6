#include"Tree.h"
#include"ListViolations.h";
#include"Data.h"
#include<fstream>
#include<Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	tree<int, ViolationsList> list_tree;
	ViolationsList current_car;
	database db("database.bin", std::ios_base::binary);

	// load database(binary)
	db.load_data<int, ViolationsList>(list_tree);
	std::cout<<"\tБаза правопорушень" <<std::endl;

	// print database
	db.print(list_tree);

	// find by number
	std::cout << "\tПошук т/з за номером \nВведіть номер: ";
	int number;
	std::cin >> number;
	if (list_tree.find(number))
	{
		std::cout << "\tт/з знайдено" << std::endl;
		std::cout << *(list_tree.find(number)) << std::endl;
	}
	else
		std::cout << "\tт/з не знайдено" << std::endl;

	// add to list_tree
	std::cout << "Ведіть номер т/з та порушення. Для виходу натисніть \"ctrl+z\"" << std::endl;
	while (std::cin >> current_car)
	{
		list_tree.add(current_car.key(), current_car);
	}

	// save to database(binary)
	db.save_data(list_tree);

	// print database
	db.print(list_tree);

	return 0;

}