// - 单行格式if语句
// - 多行格式if语句
// - 多条件的if语句
#include <iostream>

using namespace std;

int main(){
    int score = 0;
    cout << "intput score: " << endl;
    cin >> score;

    cout << "the score is: " << score << endl;

    if(score > 800 || score < 0) {//if嵌套
        if (score > 800){
            cout << "error,too big" << endl;
        }
        else{
            cout << "error,score must is a positive number" << endl;
        }
    }
    else if (score > 600){//多条件if
        cout << "the score is bigger than 600" << endl;
    }
    else if(score < 400){
        cout << "the score is smaller than 400" << endl;
    }
    else{
        cout << "the score is between 400 and 600" << endl;
    }

    return 0;
}