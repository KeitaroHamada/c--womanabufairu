#include <iostream>
#include <string>
using namespace std;
class Creature{
    private:
        string name:
        int hp;
        int maxhp;
        int atk;
        string die();
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
        
        void sethp(int hp){
            if(hp>this->maxhp){
                hp=this->maxhp;
            }else if(hp<0){
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
class Monster : public Creature{
    public:
        Monster(string name;int maxhp,int atk) : Creature(name,maxhp,atk){}
        int attack(Traveler t);
};
int Monster :: attack(Traveler t){
    cout << t->name << 'は' << this->name << 'から' << this->atk <<"のダメージをうけた！\n";
    t.sethp(t.gethp()-this->getatk());
}
class Traveler : public Creature{
    public:
        Traveler(string name,int maxhp, int atk) : Creature(name,maxhp, atk){}
        void attack(Monster m);
};
int Traveler :: attack(Monster m){
    cout << this->name << 'は' << m->name << 'に' << this->atk <<"のダメージをあたえた！\n";
    m.sethp(m.gethp()-this->getatk());
    
}
class Healer : public Traveler{
    public:
        Healer(string name,int maxhp,int atk) : Traveler(name,maxhp,atk){}
        void heal(Traveler* ts);
}
void heal(Traveler* ts){
    Traveler ts[5];
    int i=0;
    while(i<5){
        if(Traveler[i]->hp+10 <= Traveler[i]->maxhp){
            brake;
        }
        cout << 
        Traveler[i]->hp += 10;
        i++;
    }
    
}
int main(){
    Traveler hamada(2000,100);
    cout << hamada.show() << endl;
    return 0;
}