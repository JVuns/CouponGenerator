# include <iostream>
# include <thread>
# include<time.h>
using namespace std;


string genCode()
{
	string code = "xxxxx-xxxxx-xxxxx";
	for(int i = 0; i < 18; i++)
	{
		if (i != 5 && i != 11)
		{
			int numorlet = (rand() % 2) + 0;
			if (numorlet == 0)
			{
				char val = rand()%26 + 65;
				code[i] = val;
			}
			else
			{
				char val = rand()%10 + 48;
				code[i] = val;
			}
		}
	}	
	return code;
}

int main()
{
	srand(time(0));
	cout << genCode();
}
