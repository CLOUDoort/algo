#include <iostream>

class Marine {
    int hp;                 // 마린 체력
    int coord_x, coord_y;   // 마린 위치
    int damage;             // 공격력
    bool is_dead;
    char* name; // 마린 이름

    public:
        Marine();           // 기본 생성자
        Marine(int x, int y, const char* marine_name); // x, y 좌표에 마린 생성
        Marine(int x, int y);
        ~Marine();

        int attack(); // 데미지 리턴
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y);

        void show_status(); // 상태를 보여준다.
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name=NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name)+1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출! " << std::endl;
    if(name != NULL) {
        delete[] name;
    }
}

int main(void) {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 1");
    marines[1] = new Marine(3, 5, "Marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

}