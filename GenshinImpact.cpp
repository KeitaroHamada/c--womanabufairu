#include <iostream>
#include <string>
#include <typeinfo>
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
        int attackedcount=0;
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
    cout << t->getname() << "は" << this->getname() << "から" << this->getatk() <<"のダメージをうけた！\n";
    t->sethp(t->gethp()-this->getatk());
}
void Monster :: diemessage(){
    cout << this->getname() << "を倒した！\n";
}
void Traveler :: attack(Monster* m){
    if(!(this->getisalive())){
        return;
    }else if(!(m->getisalive())){
        return;
    }
    cout << this->getname() << "は" << m->getname() << "に" << this->getatk() <<"のダメージをあたえた！\n";
    m->sethp(m->gethp()-this->getatk());
}
void Traveler :: attack(Flime* f){
    f->setattackedcount(f->getattackedcount()+1);
    if(f->getattackedcount()%2 == 0){
        cout << this->getname() << "は" << f->getname() << "に" << this->getatk() <<"のダメージをあたえた！\n";
        f->sethp(f->gethp()-this->getatk());
    }else{
        cout << this->getname() << "は" << f->getname() << "に" << "攻撃をよけられてしまった！\n";
    }

}
void Traveler :: diemessage(){
    cout << this->getname() << "は力尽きた\n";
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
            cout << ts[i].getname() << "は疲れていないようだ" << endl;
            
            continue;
        }
        cout << ts[i].getname() << "は体力が10回復した!" << endl;
        ts[i].sethp(ts[i].gethp()+10);
    }
}
int main(){
    Healer b("バーバラ",2000,100);
    Traveler h("蛍",2000,200);
    Healer j("レザー",2300,150);
    Traveler g("ガイア",1800,300);
    Traveler t[4] = {b,h,j,g};
    Slime s("スライム",1000,200);
    Flime f("フライム",2000,100);
    Monster m[2] = {s,f};
    string name;
    string action;
    string attackedmonster;
    while(true){
        Healer x[4];
        cout << "だれがたたかう？" << endl;
        for(int i=0;i<4;i++){
            if(t[i].getisalive()){
            cout << t[i].getname() << endl;
            }
        }
        cin >> name;
        for(int i=0;i<4;i++){
            if(t[i].getname() == name){
                cout << name << "はなにをする？\n" << "攻撃\n";
                if(typeid(t[i]) == typeid(Healer)){
                    x[i] = (Healer)t[i];
                    cout << "回復\n";
                }
                cin >> action;
                if(action == "攻撃"){
                    cout << "どのモンスターを攻撃する？\n";
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
                if(action == "回復"){
                    x[i].heal(t);
                }
            }
        }
    }

    return 0;
}

