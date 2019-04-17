#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <iostream>
#include <fstream>
#include "string.h"
#include "tarolo.hpp"

class Team{
protected:
    String nev;
    static int letszam;

public:
    Team(const char* c = "", int n = 0);
    Team(const Team& t);
    static void setLetszam(int n){ letszam = n; }
    const String& getNev() const;
    int getLetszam() const;
    virtual void Print() const = 0;
    void printName() const;
    virtual ~Team(){}
};

int Team::letszam;

class footballTeam: public Team{
    String edzok[2];
public:
    footballTeam(const char* c, int n, const char* e1, const char* e2);
    footballTeam(const footballTeam& f);
    virtual void Print() const;
    ~footballTeam(){}
};

class basketballTeam: public Team{
    int pompom;
public:
    basketballTeam(const char* c, int n, int p);
    void setPom(int n);
    int getPom() const;
    virtual void Print() const;
    ~basketballTeam(){}
};

class handballTeam: public Team{
    double tamogatas;
public:
    handballTeam(const char* c, int n, double t);
    void setTam(double n);
    double getTam() const;
    virtual void Print() const;
    ~handballTeam(){}
};

class Egyesulet{
    tarolo<Team*> csapatok;
public:
    Egyesulet(){}
    Egyesulet(const Egyesulet& e);
    ~Egyesulet(){}
    void list();
    void listAll();
    void addTeam(Team& t);
    void removeTeam(Team& t);
};
#endif // CLASSES_H_INCLUDED
