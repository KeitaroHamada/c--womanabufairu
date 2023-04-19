#include<iostream>
using namespace std;

class Dentaku {
    public:
        int x, y;
        int tasu();
        int hiku();
        int kakeru();
        int waru();
};

int Dentaku :: tasu() {
    return x+y;
}

int Dentaku :: hiku() {
    return x-y;
}
int Dentaku :: kakeru() {
    return x*y;
}
int Dentaku :: waru() {
    return x/y;
}
int main(){
    Dentaku d;
    cin >> d.x >> d.y;
    string enzan;
    cin >> enzan;
    if(enzan == "tasu"){
        cout << d.tasu() <<endl;
    }
    if(enzan == "hiku"){
        cout << d.hiku() <<endl;
    }
    if(enzan == "kakeru"){
        cout << d.kakeru() <<endl;
    }
    if(enzan == "waru"){
        cout << d.waru() <<endl;
    }

    return 0;
}