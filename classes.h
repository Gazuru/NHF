#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <iostream>
#include <fstream>
#include "string.h"

typedef enum fajta{
    foci,
    kosar,
    kezi
}fajta;

class Ember{
protected:
    String neve;
public:
    Ember(const char* c): neve(c){};
    Ember(const Ember& e){ neve = e.neve; }
    ~Ember();
};

class Team{
protected:
    String nev;
    static int letszam;

public:
    Team(const char* c = "", int n = 0): nev(c){ setLetszam(n); }
    Team(const Team& t){
        nev = t.nev;
        setLetszam(t.getLetszam());
    }
    static void setLetszam(int n){ letszam = n; }
    const String& getNev() const { return nev; }
    int getLetszam() const { return letszam; }
    virtual void Print() const = 0;
    void printName() const{ std::cout << nev << std::endl; }
    virtual ~Team(){}
};

int Team::letszam;

class footballTeam: public Team{
    String edzok[2];
public:
    footballTeam(const char* c, int n, const char* e1, const char* e2): Team(c, n){ edzok[0] = e1; edzok[1] = e2; }
    footballTeam(const footballTeam& f){
        nev = f.nev;
        setLetszam(f.getLetszam());
        edzok[0] = f.edzok[0];
        edzok[1] = f.edzok[1];
    }
    virtual void Print() const{
        std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
        std::cout << "Edzok nevei: " << edzok[0] << ", " << edzok[1] << std::endl;
    }
    ~footballTeam(){}
};

class basketballTeam: public Team{
    int pompom;
public:
    basketballTeam(const char* c, int n, int p): Team(c, n), pompom(p){}
    void setPom(int n){ pompom = n; }
    int getPom() const { return pompom; }
    virtual void Print() const{
        std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
        std::cout << "Pompomlanyok szama: " << getPom() << std::endl;
    };
    ~basketballTeam(){}
};

class handballTeam: public Team{
    double tamogatas;
    const fajta f = kezi;
public:
    handballTeam(const char* c, int n, double t): Team(c, n), tamogatas(t){}
    void setTam(double n){ tamogatas = n; }
    double getTam() const{ return tamogatas; }
    virtual void Print() const{
        std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
        std::cout << "Tamogatas osszege: " << getTam() << std::endl;
    }
    ~handballTeam(){}
};

template <typename T>
class tarolo {
    T* adat;
    size_t meret;
public:
    tarolo(size_t meret = 0): adat(new T[meret]), meret(meret){}
    tarolo(const tarolo& t){
        meret = t.meret;
        for(size_t i = 0; i < meret; i++)
            adat[i] = t.adat[i];
    }
    tarolo& operator=(const tarolo& t){
        if(this != &t){
            delete[] adat;
            meret = t.meret;
            for(size_t i = 0; i < meret; i++)
                adat[i] = t.adat[i];
        }
        return *this;
    }
    ~tarolo(){ delete[] adat; }

    size_t size() const { return meret; }
    T& operator[](size_t i){
        if(i < meret && i >= 0)
            return adat[i];
        throw("Tulindexelve");
    }
    T& operator[](size_t i) const{
        if(i < meret && i >= 0)
            return adat[i];
        throw("Tulindexelve");
    }
    void push_back(const T& uj){
        T* ujAdat = new T[meret+1];
        for(size_t i = 0; i < meret; i++)
            ujAdat[i] = adat[i];
        ujAdat[meret] = uj;
        delete[] adat;
        adat = ujAdat;
        meret++;
    }
    void remove(const T& t){
        for(size_t i = 0; i < meret; i++){
            if(t == adat[i]){
                for(size_t j = i; j+1 < meret; j++)
                    adat[j] = adat[j+1];
                meret--;
            }
        }
    }
};

class Egyesulet{
    tarolo<Team*> csapatok;
public:
    Egyesulet(){}
    Egyesulet(const Egyesulet& e){ csapatok = e.csapatok; }
    ~Egyesulet(){}
    void list(){
        for(size_t i = 0; i < csapatok.size(); i++){
            csapatok[i]->printName();
            std::cout << std::endl;
        }
    }
    void listAll(){
        for(size_t i = 0; i < csapatok.size(); i++){
            csapatok[i]->Print();
            std::cout << std::endl;
        }
    }
    void addTeam(Team& t) {
        for(size_t i = 0; i < csapatok.size(); i++){
            if(csapatok[i] == &t)
                return;
        }
        csapatok.push_back(&t);
    }
    void removeTeam(Team& t) { csapatok.remove(&t); }

    void writeEgyesulet(){
        std::ofstream file;
        file.open("NHF.txt");
        for(size_t i = 0; i < csapatok.size(); i++){
            switch(csapatok[i]->f){
                case foci:
                    file << "F, " << csapatok[i]->getNev() << ", " << csapatok[i]->letszam << ", " << csapatok[i]->edzok[0] << ", " << csapatok[i]->edzok[1] << std::endl;
                    break;
                case kosar:
                    file << "B, " << csapatok[i]->getNev() << ", " << csapatok[i]->letszam << ", " << csapatok[i]->pompom << std::endl;
                    break;
                case kezi;
                    file << "H, " << csapatok[i]->getNev() << ", " << csapatok[i]->letszam << ", " << csapatok[i]->tamogatas << std::endl;
            }
        }
    }
};
#endif // CLASSES_H_INCLUDED
