#include <bits/stdc++.h>
using namespace std;

struct Material {
    string name;
    int cnt;
};
struct Monster{
    string name;
    int health;
    int damage;
};map<string, Monster> monsters;
struct Weapon {
    string name;
    int damage;
    int durable;
};
struct Armour {
    string name;
    int antiDamage;
    int durable;
};
struct Player{
    int liveDay,nowWeek;

    string name;
    int health;
    int damage,antiDamage;

    int initialDamage,initialAntiDamage;

    Weapon weapon;
    map<string,Weapon>weapons;

    map<string, Material> materials;

    Armour armour;
    map<string,Armour> armours;
}my;

void flush() {
    my.damage = my.initialDamage+my.weapon.damage;
    my.antiDamage = my.initialAntiDamage+my.armour.antiDamage;


    if (my.liveDay<8) {
        my.nowWeek = my.liveDay;
    }else {
        my.nowWeek = my.liveDay%8;
        my.nowWeek++;
    }

}
void coutFlushUp() {
    int cnt=100;
    while (cnt--)cout<<endl;

    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
}
void coutFlushDown() {
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
}
void delaySomeTime() {
    cout<<"系统加载";
    int cnt=1e9;
    int tmp=1e8;
    while (cnt) {
        cnt--;
        if (cnt%tmp==0)cout<<".";
    }
}
void coutStartChoose(string s) {
    coutFlushDown();
    cout<<s;
    coutFlushDown();
}
void coutLoadState(string s) {
    coutFlushUp();
    cout<<s<<endl;
    coutFlushDown();
    delaySomeTime();
}
void playerChangeWeapon() {
    coutFlushUp();
    cout<<endl;

    if (my.weapons.size()==0) {
        coutLoadState("bro以为自己有武器");
        return;
    }

    if (my.weapon.name=="") {
        cout<<"当前未装备武器"<<endl;
    }else {
        cout<<"当前装备武器："<<my.weapon.name<<endl;
        cout<<"攻击力："<<my.weapon.damage<<endl;
        cout<<"剩余耐久："<<my.weapon.durable<<endl;
    }
    coutFlushDown();

    cout<<"除此之外还拥有的武器："<<endl;
    int cnt=1;
    for (auto tmp:my.weapons) {
        Weapon val=tmp.second;
        if (val.name==my.weapon.name) {
            continue;
        }else {
            cout<<cnt++<<"、"<<val.name<<endl;
            cout<<"攻击力："<<val.damage<<endl;
            cout<<"耐久："<<val.durable<<endl;
            cout<<endl;
        }
    }
    coutFlushDown();
    cout<<"选择你要切换的武器（键入武器名字）"<<endl;
    cout<<"在此处输入:";

    string stringtmp;
    cin>>stringtmp;
    if (my.weapons.find(stringtmp)==my.weapons.end()) {
        coutLoadState("请输入正确的武器名");
        playerChangeWeapon();
    }else if (stringtmp==my.weapon.name){
        coutLoadState("你选择了目前持有的武器，未切换新武器");
    }else {
        string s="\""+my.weapon.name+"\"被变更为\""+stringtmp+"\"";
        coutLoadState("武器:"+s);
        my.weapon=my.weapons[stringtmp];
    }
}
void playerChangeArmour() {
    coutFlushUp();
    cout<<endl;

    if (my.armours.size()==0) {
        coutLoadState("bro以为自己有护甲");
        return;
    }

    if (my.armour.name=="") {
        cout<<"当前未装备护甲"<<endl;
    }else {
        cout<<"当前装备护甲："<<my.armour.name<<endl;
        cout<<"防御值："<<my.armour.antiDamage<<endl;
        cout<<"剩余耐久："<<my.armour.durable<<endl;
    }
    coutFlushDown();

    cout<<"除此之外还拥有的护甲："<<endl;
    int cnt=1;
    for (auto tmp:my.armours) {
        Armour val=tmp.second;
        if (val.name==my.armour.name) {
            continue;
        }else {
            cout<<cnt++<<"、"<<val.name<<endl;
            cout<<"防御值："<<val.antiDamage<<endl;
            cout<<"耐久："<<val.durable<<endl;
            cout<<endl;
        }
    }
    coutFlushDown();
    cout<<"选择你要切换的护甲（键入护甲名字）"<<endl;
    cout<<"在此处输入:";

    string stringtmp;
    cin>>stringtmp;
    if (my.armours.find(stringtmp)==my.armours.end()) {
        coutLoadState("请输入正确的护甲名");
        playerChangeArmour();
    }else if (stringtmp==my.armour.name){
        coutLoadState("你选择了目前持有的护甲，未切换新护甲");
    }else {
        string s="\""+my.armour.name+"\"被变更为\""+stringtmp+"\"";
        coutLoadState("护甲:"+s);
        my.armour=my.armours[stringtmp];
    }
}
void getWeapon(string name,int damage,int durable) {
    my.weapons[name]={name,damage,durable};
}
void getArmour(string name,int antiDamage,int durable) {
    my.armours[name]={name,antiDamage,durable};
}
void initMonster() {
    monsters["E型感染者"]={"E型感染者",10,1};
    monsters["D型感染者"]={"D型感染者",20,2};
    monsters["C型感染者"]={"C型感染者",30,3};
    monsters["B型感染者"]={"B型感染者",50,12};
    monsters["A型感染者"]={"A型感染者",120,33};
}
void initPlayer() {
    my.health=100;
    my.liveDay=1;
    my.initialDamage = 1;
    my.initialAntiDamage = 1;
}
void init() {
    initMonster();
    initPlayer();
}
bool checkInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        coutLoadState("请输入合法内容");
        return false;
    }else {
        return true;
    }
}
void showPlayerInfo() {
    coutFlushUp();
    cout<<"星期"<<my.nowWeek<<"   存活天数"<<my.liveDay<<endl;
    cout<<"武器["<<my.weapon.name<<"]耐久"<<my.weapon.durable<<"   防具["<<my.armour.name<<"]耐久"<<my.armour.durable<<endl;
    cout<<"血量"<<my.health<<"   攻击"<<my.damage<<"   防御"<<my.antiDamage<<endl;
    coutFlushDown();
}
void showMenu() {//注意写上check Input
    showPlayerInfo();
    cout<<"1、更换武器   2、防具"<<endl;

    int inttmp;
    cin>>inttmp;;
    if (inttmp==1)playerChangeWeapon();
    else playerChangeArmour();
}

int main() {
    init();


    getArmour("测试",1,1);
    while (true) {
        flush();

        showMenu();
    }
    return 0;
}
