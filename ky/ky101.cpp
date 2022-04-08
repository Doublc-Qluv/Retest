/*
描述
    Today, facing the rapid development of business, SJTU recognizes that more powerful calculator should be studied, 
    developed and appeared in future market shortly. SJTU now invites you attending such amazing research and development work.     
    
    In most business applications, the top three useful calculation operators are Addition (+), Subtraction (-) and Multiplication (×) between two given integers. 
    Normally, you may think it is just a piece of cake. However, since some integers for calculation in business application may be very big, 
    such as the GDP of the whole world, the calculator becomes harder to develop.     
    
    For example, if we have two integers 20 000 000 000 000 000 and 4 000 000 000 000 000, the exact results of addition, 
    subtraction and multiplication are:     
    20000000000000000 + 4000000000000000 = 24 000 000 000 000 000     
    20000000000000000 - 4000000000000000 = 16 000 000 000 000 000     
    20000000000000000 × 4000000000000000 = 80 000 000 000 000 000 000 000 000 000 000     
    Note: SJTU prefers the exact format of the results rather than the float format or scientific remark format. 
    For instance, we need "24000000000000000" rather than 2.4×10^16.     
    As a programmer in SJTU, your current task is to develop a program to obtain the exact results of the addition (a + b), subtraction (a - b) and multiplication (a × b) between two given integers a and b.
输入描述：
   Each case consists of two separate lines where the first line gives the integer a and the second gives b (|a| <10^400 and |b| < 10^400).
输出描述：
    For each case, output three separate lines showing the exact results of addition (a + b), subtraction (a - b) and multiplication (a × b) of that case, one result per lines.
*/
//大数运算

// xxxxx
//说实话代码量有点多...
#include <iostream>
using namespace std;
#include <vector>
#include<string>

class BigNum {
	int a[1000];
	const int MAX = 10;
	const int size = 1000;
public:
	BigNum() { fill(a, a + size, 0); }
	BigNum(string s) {
		fill(a, a + size, 0);
		for (int j = 0, i = s.size() - 1;i >= 0;i--, j++) {
			a[j] = s[i] - '0';
		}
	}
	void operator+(BigNum& B) {
		BigNum C;
		int carry = 0;
		for (int i = 0;i<size;i++) {
			C.a[i] = a[i] + B.a[i] + carry;
			carry = C.a[i] / MAX;
			C.a[i] = C.a[i] % MAX;
		}
		C.print();
	}
	void operator-(BigNum& B) {
        int pos = size - 1;
		while (a[pos] == B.a[pos])pos--;
        if(a[pos] < B.a[pos]){
            for (int i = 0,t;i<size;i++){
                t=a[i];
                a[i]=B.a[i];
                B.a[i]=t;
            } 
            cout<<'-';
        }
        
		BigNum C;
		int carry = 0;
		for (int i = 0;i<size;i++) {

			C.a[i] = a[i] - B.a[i] - carry;
			if (C.a[i] < 0) {
				carry = 1;
				C.a[i] = C.a[i] + MAX;
			}

			else {
				carry = 0;
				C.a[i] = C.a[i] % MAX;
			}
		}
		C.print();
	}

	void operator*(BigNum& B) {
		BigNum C;
		for (int i = 0;i<500;i++) {
			int carry = 0;
			for (int j = 0;j<500;j++) {
				C.a[i + j] = a[i] * B.a[j] + C.a[i + j] + carry;
				carry = C.a[i + j] / MAX;
				C.a[i + j] = C.a[i + j] % MAX;
			}
		}
		C.print();
	}

	void print() {
		int i = size - 1;
		while (a[i] == 0)i--;
		for (;i >= 0;i--) {
			cout << a[i];
		}
		cout << endl;
	}

};
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		BigNum a(s1), b(s2);
		a + b;
		a - b;
		a * b;
	}
}