//½èÖústrtokÊµÏÖsplit
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	char s[] = "Golden Global      View,disk * desk";
	const char* d = " ,*";
	char* p;
	p = strtok(s, d);
	while (p)
	{
		printf("%s\n", p);
		p = strtok(NULL, d);
	}
	//while(_getch()!=27)
	int wait;
	cin >> wait;
	return 0;
}