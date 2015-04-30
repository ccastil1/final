#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long int counter = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int i1 = 0; i1 < 26; i1++)
		{
			for(int i2 = 0; i2 < 26; i2++)
			{
				
				for(int i3 = 0; i3 < 26; i3++)
				{
					for(int i4 = 0; i4 < 26; i4++)
					{
						for(int i5 = 0; i5 < 26; i5++)
						{
							for(int i6 = 0; i6 < 26; i6++)
							{
								if( ( i == i1 && i1 = i2) )
								else if (i1 == i2 && i2 == i3)
								else if (i2 == i3 && i3 == i4)
								else if (i3 == i4 && i4 == i5)
								else if (i4 == i5 && i6 == i6)
								else counter++;
							}
						}
					}
				}
			}
		}
	}
	cout << counter << endl;
}