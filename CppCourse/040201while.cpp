#include <iostream>

using namespace std;

int main()
{
    char choose = 'Y';
    cout << "GAME START" << endl;
    while (choose == 'Y')
    {
        cout << "Choose : Y : New a turn" << endl;
        cout << "Choose : N : Exit the game" << endl;
        cout << "Please choose: Y/N" << endl;
        cin >> choose;
        if (choose == 'Y')
        {
            int num = rand() % 100;//随机生成一个两位数,让玩家猜
            cout << num << endl;

            int guess;

            while (cin >> guess)
            {
                if (guess == num)
                {
                    cout << "right,this turn is over" << endl;
                    break;
                }
                else if (guess > num)
                {
                    cout << "you guess is big" << endl;
                }
                else
                {
                    cout << "you guess is small" << endl;
                }
            }
        }
        if (choose == 'N')
        {
            return 0;
        }
    }
}