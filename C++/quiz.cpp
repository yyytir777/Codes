#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class Player{
    string name;
public:
    Player(string name=""){
        this->name = name;
    }
    
    void setName(string name){
        this->name = name;
    }

    string getName(){
        return name;
    }
 
    void getEnterKey(){
        char buf[100];
        cin.getline(buf, 99);
    }
};

class GameblingGame{
    Player p[2];
    int num[3];
    bool matchAll();

public:
    GameblingGame();
    void run();
};

bool GameblingGame::matchAll(){
    if(num[0] == num[1] && num[1] == num[2]) return true; //��� ������ true ��ȯ
    return false; //�ٸ��� false ��ȯ
}

GameblingGame::GameblingGame(){
    for(int i = 0; i < 3; i++){
        num[i] = 0;
    }

}

void GameblingGame::run(){
    string tmp1, tmp2;
    cout << "***** ㅁㄴㅇ람ㄴㅇ람ㄴ. *****" << '\n';

    cout << "ù��° ���� �̸� >> ";
    cin >> tmp1;

    cout << "�ι�° ���� �̸� >> ";
    cin >> tmp2;

    p[0].setName(tmp1);
    p[1].setName(tmp2);

    while(true){
        cout << p[0].getName();
        p[0].getEnterKey();
        for(int i = 0; i < 3; i++){
            num[i] = (rand() % 3);
        }

        if(matchAll() == true){ //��ȣ�� �� ������
            cout << num[0] << '\t' << num[1]<<'\t' << num[2]<<'\t' << p[0].getName() << "�� �¸�!!";
            return;
        }  
        else{
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[0].getName() << "�ƽ�����!";
        }

        cout << p[1].getName();
        p[1].getEnterKey();
        for(int i = 0; i < 3; i++){
            num[i] = (rand() % 3);
        }

        if(matchAll()){
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[1].getName() << "�� �¸�!!";
            return;
        }
        else{
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[1].getName() << "�ƽ�����!";
        }
    } 
}

int main(){
    GameblingGame game;
    game.run();
}