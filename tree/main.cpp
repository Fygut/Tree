#include "Tree.h"

int main(int argc, char **argv)
{ 
	try
	{
		/*if (argc != 5)throw "Input parametr error";
		if (argv[1][1] == 'i' && argv[3][1] == 'o')	{
			system("cls");
			Tree a(argv[2]);
			a.out_tree_on_console(a.get_root(), 0, vector< size_t >(0));
			a.output(argv[4]);
		}
		else
			if(argv[3][1] == 'i' && argv[1][1] == 'o') {
				system("cls");
				Tree a(argv[4]);
				a.out_tree_on_console(a.get_root(), 0, vector< size_t >(0));
				a.output(argv[2]);
			}
			else throw "Input parametr error";*/
			string input = "input.txt";
			string output = "output.txt";
			Tree a(input);
			a.out_tree_on_console(a.get_root(), 0, vector< size_t >(0));
			a.output(output);
	}
	catch (const char e[])
	{
		cout << e << endl;
	}
	return 0;
}