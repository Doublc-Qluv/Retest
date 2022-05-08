#include <iostream>

using namespace std;

int main()
{
    int score;
    cout << "the score is " << endl;
    cin >> score;
    if (score > 10 || score < 0)
    {
        cout << "num error" << endl;
        return 0;
    }
    switch (score)
    {
    case 10:
    case 9:
        cout << "classical" << endl;
        break;
    case 8:
    case 7:
        cout << "good" << endl;
    case 6:
        cout << "normal" << endl;

    default:
        cout << "boom" << endl;
        break;
    }
    return 0;
}