#include <iostream>
using namespace std;
class Usya{
    public :
        int hp;
        int atk;
        int kogeki();
};
int Usya :: kogeki(){
    int damage=atk;
    return damage;
}
class Hirutyaru{
    public :
        int hp;

};

int main(){
    Usya hotaru;
    Hirutyaru kariberuto;
    hotaru.hp = 1000;
    hotaru.atk = 500;
    kariberuto.hp = 900;
    string sosa;
    while(kariberuto.hp > 0){
        cout << "何をする" << endl;
        cin >> sosa;
        if(sosa == "tatakau"){
            kariberuto.hp -= hotaru.kogeki();
            cout << "カリベルトは" << hotaru.kogeki() << "のダメージをうけた" <<endl;
        }    
    }
    cout << "カリベルトはしんだ" << endl;
    return 0;
}