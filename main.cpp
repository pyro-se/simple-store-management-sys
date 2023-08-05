#include <iostream>
#include <fstream>
#include <iomanip>
//#include <vector>
#include <map>
#include <cstdlib>
//#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>

#define N 50
#define U 6
#define T 200
#define S 18

//Lukasz Rogowski 109520
using namespace std;

class Dane{
public:
    virtual ~Dane(){};
    virtual void show()=0;
    virtual int getCNT()=0;
    virtual void setCNT()=0;
};

class User: public Dane{
private:
    int id;//, kod;
    char *login,*pass;
    double score, token;
public:
    static int cnt;
    User(int,char *,char *,double,double);
    User(char*);
    User(){id=-1;}
    ~User();
    int getID(){return id;}
    virtual int getCNT(){return this->cnt;}
    virtual void setCNT(){cnt=0;}
    char* getLog(){return login;}
    void token_Boost(double tok){
        token+=tok;
        if(tok>0){
            score+=tok*10;
        }
    }
    bool id_check(int id){
        if(this->id==id){return true;}
        else{return false;}
    }
    bool active(){
        if(id<0){return false;}
        else{return true;}
    }
    void show(){
        if(active()){
            //cout<<"-----------------------------"<<endl;
            cout<<"["<<setw(3)<<setfill('0')<<id<<"]-"<<login<<" | score: "<<score<<" | "<<token<<" $"<<endl;
            cout<<"-----------------------------"<<endl;
        }
    }
    friend ostream& operator<<(ostream&, User&);
    friend istream& operator>>(istream&, User&);
};
ostream& operator<<(ostream& os, User& a)
    {
        //const User& a;
        //for(int i=0;i<M;i++){
            //os << a[i].id<<"   "<<a[i].login<<"   "<<a[i].pass<<"    "<<a[i].score<<"   "<<a[i].token<<endl;
            //os << a.id<<"   "<<a.login<<"   "<<a.pass<<"    "<<a.score<<"   "<<a.token;
        //}
        //os << a.id<<"   "<<a.login<<"   "<<a.pass<<"    "<<a.score<<"   "<<a.token;
        if(a.active()){os << a.id<<"   "<<a.login<<"   "<<a.pass<<"    "<<a.score<<"   "<<a.token;}
        return os;
    }
istream& operator>>(istream& is, User& a)
    {
        if(a.active()){
            is>>a.id;
            is>>a.login;
            is>>a.pass;
            is>>a.score;
            is>>a.token;
        }
        return is;
    }

User::User(int i,char *l, char *p, double pkt, double t){
    login = new char[strlen(l)+1];
    pass = new char[strlen(p)+1];
    strcpy(login,l);
    strcpy(pass,p);
    token=t;
    score=pkt;
    id=i;
    cnt++;
}
User::User(char *l){
    login = new char[strlen(l)+1];
    strcpy(login,l);
}
User::~User(){
    //delete [] login;
    //delete [] pass;
}

class Zadanie{
private:
    char Komunikat[60];
    double nagroda;
public:

};

class Sklep: public Dane{
private:
    int sub_id;
    char *nazwa;
    double cena;
public:
    static int cnt;
    Sklep(int,char*,double);
    Sklep(){sub_id=-1;}
    ~Sklep();
    int getSID(){return sub_id;}
    int getCNT(){return this->cnt;}
    virtual void setCNT(){cnt=0;}
    char* getNaz(){return nazwa;}
    double getCena(){return cena;}
    bool active(){
        if(sub_id<0){return false;}
        else{return true;}
    }
    bool id_check(int id){
        if(sub_id==id){return true;}
        else{return false;}
    }
    void show(){
        if(active()){
            //cout<<"-----------------------------"<<endl;
            cout<<"["<<setw(3)<<setfill('0')<<sub_id<<"] "<<nazwa<<" -> "<<cena<<" $"<<endl;
            cout<<"-----------------------------"<<endl;
        }
    }
    friend ostream& operator<<(ostream&, Sklep&);
    friend istream& operator>>(istream&, Sklep&);
};
ostream& operator<<(ostream& os, Sklep& a)
    {
        if(a.active()){os<<a.sub_id<<"   "<<a.nazwa<<"   "<<a.cena;}
        return os;
    }
istream& operator>>(istream& is, Sklep& a)
    {
        if(a.active()){
            is>>a.sub_id;
            is>>a.nazwa;
            is>>a.cena;
        }
        return is;
    }

Sklep::Sklep(int i, char *n, double c){
    nazwa = new char[strlen(n)+1];
    strcpy(nazwa,n);
    cena=c;
    sub_id=i;
    cnt++;
}
Sklep::~Sklep(){
    //delete [] nazwa;
}

class Transakcja : public User, public Sklep{
private:
    int t_id;
public:
    Transakcja(int,char*,int,char*,int);
    Transakcja(){t_id=-1;}
    bool active(){
        if(t_id<0){return false;}
        else{return true;}
    }
    ~Transakcja(){};
    void show(){
        cout<<"["<<setw(3)<<setfill('0')<<t_id<<"] "<<getLog()<<" kupil/a ["<<Sklep::getSID()<<"]"<<getNaz()<<" -> "<<getCena()<<endl;
        cout<<"-----------------------------"<<endl;
    }
    friend ostream& operator<<(ostream&, Transakcja&);
    //friend istream& operator>>(istream&, Transakcja&);
};
Transakcja::Transakcja(int ti, char *l, int si, char *n, int c):Sklep(si,n,c),User(l)
{
    t_id=ti;
    Sklep::cnt--;
}
ostream& operator<<(ostream& os, Transakcja& t){
    if(t.active()){
        os<<"["<<setw(3)<<setfill('0')<<t.t_id<<"] "<<t.getLog()<<" kupil/a ["<<t.getSID()<<"]"<<t.getNaz()<<" -> "<<t.getCena()<<endl;
    }
    //cout<<"-----------------------------"<<endl;
    //os<<t.t_id<<t.getLog()<<t.getSID()<<t.getNaz<<t.getCena;
    return os;
}
istream& operator>>(istream& is, Transakcja& t){
/*
    is>>;t.t_id;
    is>>t.getLog();
    is>>t.getSID();
    is>>t.getNaz;
    is>>t.getCena;
*/
    return is;
}
int User::cnt=0;
int Sklep::cnt=0;

////////////////////////////////////////////////////////////////////////
int main(){
    //vector<User> u;
    //int *sav=new int[3]; //0 -> ID | 1 -> SUB_ID | 2 -> T_ID
    char a[20],b[20],menu; //dodawanie uzytkownika
    int uu=0, ss=0,tt=0, id;
    double tok,sc;
    bool war=false, pow=false;
    string log, pas,line;
    User* u = new User[U];
    Sklep* s = new Sklep[S];
    Transakcja* t = new Transakcja[T];
    //Transakcja t[T];
    int cnt=0;

    map<char,int> sav;
    map<char,int>::iterator pos;

    ifstream odc("TXT/sav.txt");
    odc>>sav['u']>>sav['s']>>sav['t'];
    odc.close();

/////////////////////////////////////////////////
    try{
        ifstream pU("TXT/user.txt");
        ifstream pS("TXT/sklep.txt");
        ifstream pT("TXT/transakcje.txt");
        if (!pT){
            //cerr << "ERROR! " << endl;
            throw 101;
            system("pause");
            //exit(1);
        }
        for(int i=0;i<T;i++){
            pT>>tt>>a>>id>>b>>tok;
            if(!pT.eof()){
                t[i]=Transakcja(tt,a,id,b,tok);
            }
        }
        if (!pU || !pS){
            //cerr << "ERROR! " << endl;
            throw 101;
            system("pause");
            //exit(1);
        }
        for(int i=0;i<S;i++){
            pS>>id>>a>>tok;
            if(!pS.eof()){
                s[i]=Sklep(id,a,tok);
                ss++;
            }
        }
        for(int i=0;i<U;i++){
            pU>>id>>a>>b>>sc>>tok;
            if(!pU.eof()){
                u[i]=User(id,a,b,sc,tok);
                uu++;
            }
        }
        pU.close();
        pS.close();

    }
    catch(int b)
    {
        if(b==101){cout << "Blad odczytu z pliku! error: 101 \n";}
        else if(b==102){cout << "Blad zapisu do pliku! error: 102 \n";}
        else if(b==103){cout << "Blad identyfikatorow! error: 103 \n";}
    }
    catch(...)
    {
        std::cout << "B��d nieznanego pochodzenia \n";
    }


///////////////////////////////////////////////////

    do{
        system("cls");
        cout<<"------------------------------"<<endl;
        if(pow){cout<<"Bledny login lub haslo!!!"<<endl;}
        cout<<">    login: ";
        cin>>log;
        cout<<"> password: ";
        cin>>pas;
        if(log=="admin" && pas=="admin"){war=true;}
        else{pow=true;}
    }while(war==false);
    system("cls");
    pow=false;
    do{
    system("cls");

    //cout<<sav['u']<<"|"<<sav['s']<<"|"<<sav['t']<<endl;
    //Dane * wsk = new User, * ds = new Sklep;
    //delete du, ds;
    cout<<"---------user: "<</*log*/"admin"<<"---------"<<endl;
    cout<<"---------ver. 1.0.5----------"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"o--Sklep---:["<<s->getCNT()<<"]"<<endl;
    cout<<"     [1] Wyswietlanie bazy."<<endl;
    cout<<"     [2] Dodawanie produktu."<<endl;
    cout<<"     [3] Usuwanie produktu."<<endl;
    cout<<"     [4] Historia transakcji."<<endl;
    cout<<"o--User---:["<<u->getCNT()<<"]"<<endl;
    cout<<"     [5] Ranking uzytkownikow."<<endl;
    cout<<"     [6] Dodawanie/usuwanie token'ow."<<endl;
    cout<<"     [7] Dodaj uzytkownika."<<endl;
    cout<<"     [8] Usun uzytkownika."<<endl;
    cout<<"o--Zadania---"<<endl;
    cout<<"     [9] Wyswietl liste.   - LOCKED"<<endl;
    cout<<"     [e] Dodaj zadanie.    - LOCKED"<<endl;
    cout<<"     [r] Usun zadanie.     - LOCKED"<<endl;
    cout<<"o--Etc---"<<endl;
    cout<<"     [w] Reload/Refresh"<<endl;
    cout<<"     [q] Wyjscie."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<" > Choose: ";
    cin>>menu;
    switch(menu){
        case '1':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---ZAWARTOSC SKLEPU"<<endl;
            cout<<"-----------------------------"<<endl;
            for(int i=0; i<S; i++){
                s[i].show();
            }
            system("pause");
            break;
        case '2':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---DODAWANIE PRODUKTU"<<endl;
            cout<<"-----------------------------"<<endl;
            if(Sklep::cnt<S){
                cout<<"Nazwa: ";
                cin>>a;
                cout<<"Cena: ";
                cin>>tok;
                ss=Sklep::cnt;
                sav.find('s');//pos->second
                s[ss]=Sklep(sav['s'],a,tok);ss++;
                sav['s']++;
            }
            else{
                cout<<"PRZEKROCZONO LIMIT "<<S<<" PRODUKTOW"<<endl;
            }
            system("pause");
            break;
        case '3':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---USUWANIE PRODUKTU"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Podaj <id> produktu do usuniecia: "; //DO POPRAWIENIA
            cin>>id;
            for(int i=0;i<S;i++){
                if(s[i].id_check(id)){
                    s[i]=Sklep();
                    pow=true;
                }
            }
            if(!pow){
                cout<<"Nie ma produktu o takim <id>"<<endl;
            }
            pow=false;
            system("pause");
            break;
        case '4':{
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---HISTORIA TRANSAKCJI"<<endl;
            cout<<"-----------------------------"<<endl;

            //pT.close();
            for(int i=0; i<T; i++){
                cout<<t[i];//.show();
            }

            system("pause");
            break;}
        case '5':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---LISTA UZYTKOWNIKOW"<<endl;
            cout<<"-----------------------------"<<endl;
            for(int i=0; i<U; i++){
                u[i].show();
            }
            system("pause");
            break;
        case '6':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---EDYCJA TOKENOW"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Dla jakiego uzytkownika zmienic liczbe tokenow? [ID]: ";
            cin>>id;
            cout<<"Podaj liczbe tokenow o jaka ma sie zmienic wartosc: ";
            cin>>tok;
            for(int i=0; i<U; i++){
                if(u[i].id_check(id)){
                    u[i].token_Boost(tok);
                }
            }
            system("pause");
            break;
        case '7':{
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---DODAWANIE UZYTKOWNIKA"<<endl;
            cout<<"-----------------------------"<<endl;
            if(User::cnt<U){
                cout<<"Nazwa uzytkownika: ";
                cin>>a;
                cout<<"Haslo: ";
                cin>>b;
                sav.find('u');//w
                u[uu]=User(sav['u'],a,b,0,0);
                sav['u']++;
                uu++;
            }
            else{
                cout<<"PRZEKROCZONO LIMIT "<<U<<" UZYTKOWNIKOW"<<endl;
            }
            system("pause");
            break;}
        case '8':
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---USUWANIE UZYTKOWNIKA"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Podaj <id> uzytkownika do usuniecia: "; //DO POPRAWIENIA
            cin>>id;
            for(int i=0;i<U;i++){
                if(u[i].id_check(id)){
                    u[i]=User();
                    pow=true;
                }
                if(!pow){
                    cout<<"Nie ma uzytkownika o takim <id>"<<endl;
                }
            }
            pow=false;
            system("pause");
            break;
        case '9':
            system("cls");
            system("pause");
            break;
        case 'w':{
            system("cls");
            cout<<"-----------------------------"<<endl;
            cout<<"O---RELOAD"<<endl;
            cout<<"-----------------------------"<<endl;
            system("pause");
            break;}
        case 'q':
            system("cls");
            break;
    }

    try
    {
        ifstream pT2("TXT/transakcje.txt");
        if(!pT2){
            //cerr << "ERROR! " << endl;
            system("pause");
            throw 101;
            //exit(1);
        }
        for(int i=0;i<T;i++){
            pT2>>tt>>a>>id>>b>>tok;
            if(!pT2.eof()){
                t[i]=Transakcja(tt,a,id,b,tok);
            }
        }
        pT2.close();

        ofstream pU2("TXT/user.txt");
        ofstream pS2("TXT/sklep.txt");
        if (!pU2 || !pS2){
            //cerr << "ERROR! " << endl;
            system("pause");
            throw 102;
            //exit(1);
        }

        for(int i=0;i<U;i++){
            if(u[i].active()){
                pU2<<u[i]<<endl;
            }
        }cout<<"USER.TXT saved!!!"<<endl;
        for(int i=0;i<S;i++){
            if(s[i].active()){
                pS2<<s[i]<<endl;
            }
        }cout<<"SKLEP.TXT saved!!!"<<endl;
        pU2.close();
        pS2.close();
        User::cnt=0;
        uu=0;
        Sklep::cnt=0;
        ss=0;
        ifstream pU("TXT/user.txt");
        ifstream pS("TXT/sklep.txt");

        if (!pU || !pS){
            //cerr << "ERROR! " << endl;
            //system("pause");
            throw 101;
            //exit(1);
        }
        for(int i=0;i<S;i++){
            pS>>id>>a>>tok;
            if(!pS.eof()){
                s[i]=Sklep(id,a,tok);
                ss++;
            }
        }
        for(int i=0;i<U;i++){
            pU>>id>>a>>b>>sc>>tok;
            if(!pU.eof()){
                u[i]=User(id,a,b,sc,tok);
                uu++;
            }
        }

        pU.close();
        pS.close();
        ofstream zap("TXT/sav.txt");
        if (!zap){
            //cerr << "ERROR! " << endl;
            //system("pause");
            throw 103;
            //exit(1);
        }
        zap<<sav['u']<<"  "<<sav['s']<<"    "<<sav['t'];
        zap.close();
    }
    catch(int b)
    {
        if(b==101){cout << "Blad odczytu z pliku! error: 101 \n";}
        else if(b==102){cout << "Blad zapisu do pliku! error: 102 \n";}
        else if(b==103){cout << "Blad identyfikatorow! error: 103 \n";}
    }
    catch(...)
    {
        std::cout << "B��d nieznanego pochodzenia \n";
    }
    }while(menu!='q');
    return 0;
}
