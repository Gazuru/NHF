#include <iostream>
#include <fstream>
#include "classes.h"
#include "string.h"
#include "tarolo.hpp"

int Team::letszam;

Team::Team(const char* c, int n): nev(c){ setLetszam(n); }

Team::Team(const Team& t){
    nev = t.nev;
    setLetszam(t.getLetszam());
}

const String& Team::getNev() const{ return nev; }

int Team::getLetszam() const{ return letszam; }

void Team::printName() const{ std::cout << nev << std::endl; }

footballTeam::footballTeam(const char* c, int n, const char* e1, const char* e2): Team(c, n){ edzok[0] = e1; edzok[1] = e2; }

footballTeam::footballTeam(const footballTeam& f){
    nev = f.nev;
    setLetszam(f.getLetszam());
    edzok[0] = f.edzok[0];
    edzok[1] = f.edzok[1];
}

void footballTeam::Print() const{
        std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
        std::cout << "Edzok nevei: " << edzok[0] << ", " << edzok[1] << std::endl;
}

basketballTeam::basketballTeam(const char* c, int n, int p): Team(c, n), pompom(p){}

void basketballTeam::setPom(int n){ pompom = n; }

int basketballTeam::getPom() const { return pompom; }

void basketballTeam::Print() const{
    std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
    std::cout << "Pompomlanyok szama: " << getPom() << std::endl;
}

handballTeam::handballTeam(const char* c, int n, double t): Team(c, n), tamogatas(t){}

void handballTeam::setTam(double n){ tamogatas = n; }

double handballTeam::getTam() const{ return tamogatas; }

void handballTeam::Print() const{
    std::cout << "Csapat neve: " << getNev() << std::endl << "Csapat letszama: " << getLetszam() << std::endl;
    std::cout << "Tamogatas osszege: " << getTam() << std::endl;
}

Egyesulet::Egyesulet(const Egyesulet& e){ csapatok = e.csapatok; }

void Egyesulet::list(){
    for(size_t i = 0; i < csapatok.size(); i++){
        csapatok[i]->printName();
    }
    std::cout << std::endl;
}

void Egyesulet::listAll(){
    for(size_t i = 0; i < csapatok.size(); i++){
        csapatok[i]->Print();
        std::cout << std::endl;
    }
}

void Egyesulet::addTeam(Team& t) {
    for(size_t i = 0; i < csapatok.size(); i++){
        if(csapatok[i] == &t)
            return;
    }
    csapatok.push_back(&t);
}

void Egyesulet::removeTeam(Team& t) { csapatok.remove(&t); }
