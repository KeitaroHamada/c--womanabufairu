#include <iostream>
#include <string>
using namespace std;
class Creature{
    private:
        string name;
        int hp;
        int maxhp;
        int atk;
        bool isalive;
    protected:
        virtual void diemessage()=0;
        void die(){
            this -> isalive = false;
            diemessage();
        }
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
        bool getisalive(){
            return this -> isalive;
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
    this->isalive=true;
} 
class Traveler;
class Monster : public Creature{
    public:
        Monster(string name,int maxhp,int atk) : Creature(name,maxhp,atk){}
        void attack(Traveler* t);
    protected:
        void diemessage();
    
};
class Slime : public Monster{
    public:
        Slime(string name,int maxhp,int atk) : Monster(name,maxhp,atk){}
};
class Flime : public Monster{
    private:
        int attackedcount;
    public:
        int getattackedcount(){
            return this->attackedcount;
        }
        void setattackedcount(int attackedcount){
            this->attackedcount = attackedcount;
        }
        Flime(string name,int maxhp,int atk) : Monster(name,maxhp,atk){}
};
class Traveler : public Creature{
    public:
        Traveler(string name,int maxhp, int atk) : Creature(name,maxhp, atk){}
        void attack(Monster* m);
        void attack(Flime* f);
    protected:
        void diemessage();
};
void Monster :: attack(Traveler* t){
    if(!(this->getisalive())){
        return;
    }
    cout << t->getname() << "��" << this->getname() << "����" << this->getatk() <<"�̃_���[�W���������I\n";
    t->sethp(t->gethp()-this->getatk());
}
void Monster :: diemessage(){
    cout << this->getname() << "��|�����I\n";
}
void Traveler :: attack(Monster* m){
    if(!(this->getisalive())){
        return;
    }else if(!(m->getisalive())){
        return;
    }
    cout << this->getname() << "��" << m->getname() << "��" << this->getatk() <<"�̃_���[�W�����������I\n";
    m->sethp(m->gethp()-this->getatk());
}
void Traveler :: attack(Flime* f){
    f->setattackedcount(f->getattackedcount()+1);
    if(f->getattackedcount()%2 == 0){
        cout << this->getname() << "��" << f->getname() << "��" << this->getatk() <<"�̃_���[�W�����������I\n";
        f->sethp(f->gethp()-this->getatk());
    }else{
        cout << this->getname() << "��" << f->getname() << "��" << "�U�����悯���Ă��܂����I\n";
    }

}
void Traveler :: diemessage(){
    cout << this->getname() << "�͗͐s����\n";
}
class Healer : public Traveler{
    public:
        Healer(string name,int maxhp,int atk) : Traveler(name,maxhp,atk){}
        void heal(Traveler* ts);
};
void Healer::heal(Traveler* ts){
    if(!(this->getisalive())){
        return;
    }
    for(int i=0;i<4;i++){
        if(ts[i].gethp()+10 >= ts[i].getmaxhp()){
            cout << ts[i].getname() << "�͔��Ă��Ȃ��悤��" << endl;
            
            continue;
        }
        cout << ts[i].getname() << "�̗͑͂�10�񕜂���!" << endl;
        ts[i].sethp(ts[i].gethp()+10);
    }
}
int main(){
    Healer b("�o�[�o��",2000,100);
    Traveler h("�u",2000,200);
    Healer j("���U�[",2300,150);
    Traveler g("�K�C�A",1800,300);
    Traveler t[4] = {b,h,j,g};
    Slime s("�X���C��",1000,200);
    Flime f("�t���C��",2000,100);
    Monster m[2] = {s,f};
    string name;
    string action;
    string attackedmonster;
    while(true){
        cout << "���ꂪ���������H" << endl;
        for(int i=0;i<4;i++){
            if(t[i].getisalive()){
            cout << t[i].getname() << endl;
            }
        }
        cin >> name;
        for(int i=0;i<4;i++){
            if(t[i].getname() == name){
                cout << name << "�͂Ȃɂ�����H\n" << "�U��\n";
                if(i==0){
                    cout << "��\n";
                }
                cin >> action;
                if(action == "�U��"){
                    cout << "�ǂ̃����X�^�[���U������H\n";
                    for(int j=0;j<2;j++){
                        if(m[j].getisalive()){
                        cout << m[j].getname() << endl;
                        }
                    }   
                    cin >> attackedmonster;
                    for(int k=0;k<2;k++){
                        if(m[k].getname() == attackedmonster){
                            t[i].attack(&m[k]);
                        }
                    }
                }
                if(action == "��"){
                    b.heal(t);
                }
            }
        }
    }

    return 0;
}