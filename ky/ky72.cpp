/*
描述
    The digital root of a positive integer is found by summing the digits of the integer. 
    If the resulting value is a single digit then that digit is the digital root. 
    If the resulting value contains two or more digits, those digits are summed and the process is repeated. 
    This is continued as long as necessary to obtain a single digit.     
    
    For example, consider the positive integer 24. Adding the 2 and the 4 yields a value of 6. 
    Since 6 is a single digit, 6 is the digital root of 24. 
    Now consider the positive integer 39. Adding the 3 and the 9 yields 12. 
    Since 12 is not a single digit, the process must be repeated. 
    Adding the 1 and the 2 yeilds 3, a single digit and also the digital root of 39.
输入描述：
    The input file will contain a list of positive integers, one per line. 
    The integer may consist of a large number of digits. (1 <= input value <= 10^9)
输出描述：
    For each integer in the input, output its digital root on a separate line of the output.
*/

#include<iostream>

using namespace std;

int main()
{
    freopen("./ky72.data","r",stdin);
	int n;
	while(cin >> n)
	{
		int x = n;
		while(x / 10 != 0)
		{
			int t = x, sum = 0;
			while(t != 0) {
				sum += t % 10;
				t /= 10;
			}
			x = sum;
		}
		cout << x << endl;
	}
	return 0;
}