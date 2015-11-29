#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct menu
{
    string jenis;
    string idm;
    string namam;
    int harga;
};

struct anggota
{
    string nama;
    string ida;
    string alamat;
};

typedef struct elma *address;

struct elma
{
    anggota info;
    address next;
    address prev;
};

typedef struct elm *addressmenu;

struct elm
{
    menu info;
    addressmenu next;
    addressmenu prev;
    address anggota;
};

struct listelm
{
    addressmenu first;
    addressmenu last;
};

void createlistmenu(listelm &l);

address alokasianggota(anggota a);
addressmenu alokasimenu(menu m);
address findanggota(listelm l,string s);
addressmenu findmenu(listelm l, string c);
addressmenu findmenuanggota(listelm l, string s,string c);
void insertanggota(listelm &l, address p,string s);
void insertmenu(listelm &l,addressmenu q);
void printanggota(listelm l);
void printmenu(listelm l);
void ubahanggota(listelm &l);
void deleteanggota(listelm &l,addressmenu &q, address &p);
void deleteanggotamenu(listelm &l,addressmenu &q);
addressmenu menufavorit(listelm &l);


void tampilanmenu(int pil);
void menuanggota(anggota &a,string &c);
void menumenu(menu &m);

#endif // TUBES_H_INCLUDED
