#include <iostream>
#include <string>
using namespace std;
class Creature{
    private:
        string name;
        int hp;
        int maxhp;
        int atk;
    protected:
        virtual void die();
    public:
        Creature(string name,int maxhp,int atk);
        string getname(){
            return this -> name;
        }
        int gethp(){
            return this -> hp;
        }
        int getatk(){
            return this -> atk;
        }
        int getmaxhp(){
            return this -> maxhp;
        }
        
        void sethp(int hp){
            if(hp > this->maxhp){
                hp = this->maxhp;
            }else if(hp<=0){
                die();
            }
            this->hp = hp;
        }
        void setatk(int atk){
            this->atk = atk;
        }

};
Creature :: Creature(string name,int maxhp,int atk){
    this->name=name;
    this->maxhp=maxhp;
    this->atk=atk;
    this->hp=maxhp;
} 

class Traveler;
class Monster : public Creature{
    public:
        Monster(string name,int maxhp,int atk) : Creature(name,maxhp,atk){}
        void attack(Traveler* t);
        void die();
    
};
void Monster :: attack(Traveler* t){
    cout << (*t).getname() << "��" << this->getname() << "����" << this->getatk() <<"�̃_���[�W���������I\n";
    (*t).sethp((*t).gethp()-this->getatk());
}
void Monster :: die(){
    cout << this->getname() << "��|�����I\n";
}

class Monster;
class Traveler : public Creature{
    public:
        Traveler(string name,int maxhp, int atk) : Creature(name,maxhp, atk){}
        void attack(Monster* m);
        void die();
};
void Traveler :: attack(Monster* m){
    cout << this->getname() << "��" << (*m).getname() << "��" << this->getatk() <<"�̃_���[�W�����������I\n";
    (*m).sethp((*m).gethp()-this->getatk());
}
void Traveler :: die(){
    cout << this->getname() << "�͗͐s����\n";
}


class Healer : public Traveler{
    public:
        Healer(string name,int maxhp,int atk) : Traveler(name,maxhp,atk){}
        void heal(Traveler* ts);
};

void Healer::heal(Traveler* ts){
    for(int i=0;i<4;i++){
        if(ts[i].gethp()+10 <= ts[i].getmaxhp()){
            cout << ts[i].getname() << "�͏\���ɉ񕜂���Ă���悤��" << endl;
            i++;
            continue;
        }
        cout << ts[i].getname() << "�̗͑͂�10�񕜂���!" << endl;
        ts[i].sethp(ts[i].gethp()+10);
        i++;
    }
    
}
int main(){

    Healer h("�o�[�o��",2000,100);
    Monster m("�X���C��",1000,20);
    h.attack(&m);
    m.attack(&h);
    h.heal(&h);

    
    return 0;
}