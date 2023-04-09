#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; // 선수를 추상화한 클래스


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
    if(num[0] == num[1] && num[1] == num[2]) return true; //모두 같을때 true 반환
    return false; //다를때 false 반환
}

GameblingGame::GameblingGame(){
    for(int i = 0; i < 3; i++){
        num[i] = 0;
    }

}

void GameblingGame::run(){
    string tmp;
    cout << "***** 갬블링 게임을 시작합니다. *****" << '\n';

    cout << "첫번째 선수 이름 >> ";
    cin >> tmp;
    p[0].getName(tmp);

    cout << "두번째 선수 이름 >> ";
    cin >> tmp;
    p[1].getName(tmp);

    while(true){
        cout << p[0].getName();
        p[0].getEnterKey();
        for(int i = 0; i < 3; i++){
            num[i] = (rand() % 3);
        }

        if(matchAll() == true){ //번호가 다 같을때
            cout << num[0] << '\t' << num[1]<<'\t' << num[2]<<'\t' << p[0].getName() << "님 승리!!";
            return;
        }  
        else{
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[0].getName() << "아쉽군요!";
        }

        cout << p[1].getName();
        p[1].getEnterKey();
        for(int i = 0; i < 3; i++){
            num[i] = (rand() % 3);
        }

        if(matchAll()){
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[1].getName() << "님 승리!!";
            return;
        }
        else{
            cout << num[0]<<'\t' << num[1]<<'\t' << num[2]<<'\t' << p[1].getName() << "아쉽군요!";
        }

    } 
}

int main(){
    GameblingGame game;
    game.run();
}