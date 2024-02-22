#include <iostream>
#include <fstream>

using namespace std;

void elabora(string a)
{
	int i = 0;
	while(a[i])
		cout << a[i++];
	cout << endl;
}

int main(int argn, char **args)
{
	fstream input, output;
	input.open(args[1], ios::in);
	output.open(args[2], ios::out | ios::app);
	if (input.fail())
	{
		cout << "Problemi col file di lettura\n";
		return 0;
	}
	if (output.fail())
	{
		cout << "Problemi col file di scrittura\n";
		return 0;
	}
	char temp;
	string str = "";
	int i = 0;
	while(input.get(temp))
	{
		//cout << temp;
		if(temp == ';') //condizione di fine stringa
		{
			output << str + ' ';
			str += '\0';
			elabora(str);
			str = "";
		}
		else if (temp != '\n')
		{
			str += temp;
		}
	}
	input.close();
	output.close();
}