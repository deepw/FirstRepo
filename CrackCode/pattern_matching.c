

#include<iostream>
using namespace std;


bool isMatch(char* pattern, char* text, int m, int n)
{
	if (m == 0 && n == 0)
		return true;
	else
	{
		if (m > 0)
		{
			if (pattern[m-1] == '*')
				return isMatch (pattern, text, m-1, n) || isMatch (pattern, text, m-2, n);
			if (pattern[m-1] == '.')
				return isMatch (pattern, text, m-1, n) || isMatch(pattern, text, m-1, n-1);
			if (n > 0)
				{
					if (pattern[m-1] == text[n-1])
						return true;
					else
						return false;
				}
		}
		else
			return false;
	}
}


int main()
{

	char* pattern;
	char* text;
	int m;
	int n;
	pattern=new char[7];
	text=new char[4];
	pattern="ab*c*d.";
	text="abdg";
	m=7;
	n=4;
	if(isMatch(pattern,text,m,n))
		cout<<"match"<<endl;
	else
		cout<<"not match"<<endl;

	return 0;
}
