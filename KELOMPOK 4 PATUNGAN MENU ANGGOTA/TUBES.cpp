#include <iostream>
#include <conio.h>
#include <windows.h>
#include "TUBES.h"

void createlistmenu(listelm &l)
{
    l.first=NULL;
    l.last=NULL;
};

address alokasianggota(anggota a)
{
    address ang= new elma;
    ang->info=a;
    ang->next=NULL;
    ang->prev=NULL;
    return ang;
};
addressmenu alokasimenu(menu m)
{
    addressmenu a= new elm;
    a->info=m;
    a->next=NULL;
    a->prev=NULL;
    a->anggota=NULL;;
    return a;
};
address findanggota(listelm l, string s)
{
    addressmenu it=l.first;
    while (it!=0)
    {
        address q=it->anggota;
        while(q!=NULL)
        {
            if(q->info.ida==s)
            {
                return q;
            }
            q=q->next;
        }
        it=it->next;
    }
}
addressmenu findmenu(listelm l, string c)
{
    addressmenu it=l.first;
    if(it==NULL)
    {
        return 0;
    }
    while (it!=0)
    {
        if(it->info.idm==c)
        {
            return it;
        }
        it=it->next;
    }
    return 0;
};

addressmenu findmenuanggota(listelm l, string s,string c)
{

    addressmenu it=l.first;
    while (it!=0)
    {
        if(it->info.namam==s)
        {
            address q=it->anggota;
            while(q!=NULL)
            {
                if(q->info.ida==c)
                {
                    return it;
                }
                q=q->next;
            }
        }
        it=it->next;
    }
}

void insertanggota(listelm &l, address p,string s)
{
    addressmenu c;
    c=findmenu(l,s);
    if(c!=NULL)
    {
        if(c->anggota==NULL)
            c->anggota=p;
        else
        {
            address q=c->anggota;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
            p->prev=q;
            p->next=NULL;
        }
    }
    else{
        cout << "           Menu tidak ada"<< endl;
    }
}

void insertmenu(listelm &l,addressmenu q)
{
    addressmenu a;
    a=findmenu(l,q->info.idm);
    if (a==NULL)
    {
        if (l.first==0)
            l.first=q;
        else
        {
            q->next=l.first;
            l.first->prev=q;
            l.first=q;
        }
    }
    else
        {
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"                    Maaf Id Sudah Ada                  "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
        }
}

void printanggota(listelm l)
{
    addressmenu it=l.first;
    while (it!=0)
    {
        address q=it->anggota;
        while(q!=NULL)
        {
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"           Nama : "<<q->info.nama<<endl;
            cout<<"           ID : "<<q->info.ida<<endl;
            cout<<"           Alamat : "<<q->info.alamat<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            q=q->next;
        }
        it=it->next;
        cout<<endl;
    }
}

void printmenu(listelm l)
{
    addressmenu it=l.first;
    while (it!=0)
    {
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"    3#############################################3    "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"        Nama menu: "<<it->info.namam<<endl;
        cout<<"        ID menu: "<<it->info.idm<<endl;
        cout<<"        Harga menu: "<<it->info.harga<<endl;
        cout<<"        Jenis menu: "<<it->info.jenis<<endl;
        address a=it->anggota;
        while(a!=NULL)
        {
            cout<<"        Anggota yang memesan : "<<a->info.nama<<endl;
            a=a->next;
        }
        it=it->next;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"    3#############################################3    "<<endl;
        cout<<endl;
    }
}

void ubahanggota(listelm &l)
{
    string x;
    address p;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"    3#############################################3    "<<endl;
    cout<<"    3#                                           #3    "<<endl;
    cout<<"      Masukkan ID Anggota yang akan diubah : ";
    cin>>x;
    p=findanggota(l,x);
    if(p!=NULL){
    cout<<"      Masukkan Nama baru: ";
    cin>>p->info.nama;
    cout<<"      Masukkan ID baru: ";
    cin>>p->info.ida;
    cout<<"      Masukkan Alamat baru: ";
    cin>>p->info.alamat;
    cout<<"    3#                                           #3    "<<endl;
    cout<<"    3#############################################3    "<<endl;
    }
    else{
        cout << "Data Tidak Ditemukan" << endl;
    }
}

void deleteanggota(listelm &l,addressmenu &q, address &p)
{
    if (q==NULL)
    {
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"    3#############################################3    "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"                      Data Kosong                      "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"    3#############################################3    "<<endl;
    }

    else if(p->next!=NULL&&p->prev==NULL)
    {
        q->anggota=p->next;
        q->anggota->prev=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else if(p->next==NULL&&p->prev==NULL)
    {
        p=NULL;
        q->anggota=NULL;
    }
    else if (p->next==NULL&&p->prev!=NULL)
    {
        p->prev->next=NULL;
        p->prev=NULL;
        p->next=NULL;
    }
    else
    {
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->next=NULL;
        p->prev=NULL;
    }
};

void deleteanggotamenu(listelm &l,addressmenu &q)
{
    if (q==NULL)
    {
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"    3#############################################3    "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"                      Data Kosong                      "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"    3#############################################3    "<<endl;
    }
    else if(q==l.first&&q->next!=NULL)
    {
        l.first=q->next;
        q->next->prev=l.first;
        l.first->prev=q;
        q->next=NULL;
        q->prev=NULL;
    }
    else if(q==l.first&&q->next==NULL)
    {
        l.first=NULL;
    }
    else if (q->next==NULL&&q->prev!=NULL)
    {
        q->prev->next=NULL;
        q->next=NULL;
        q->prev=NULL;
    }
      else
    {
        q->prev->next=q->next;
        q->next->prev=q->prev;
        q->next=NULL;
        q->prev=NULL;
    }

}
addressmenu menufavorit(listelm &l)
{
    int i=0;
    int tmp=0;
    addressmenu tempe;
    addressmenu it=l.first;
    if (it==NULL)
        return NULL;
    else
    {
        while (it!=0)
        {
            address q=it->anggota;
            if(q==NULL){
                return NULL;
            }
            while(q!=NULL)
            {
                i=i+1;
                if(i>tmp)
                {
                    tmp=i;
                    tempe=it;
                }

                q=q->next;
            }
            i=0;
            it=it->next;
        }
        return tempe;
    }
};

void tampilanmenu(int pil)
{
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"    33#########################################################33    "<<endl;
    cout<<"    33#**********************            *********************#33    "<<endl;
    cout<<"    33#3                      ===MENU===                     3#33    "<<endl;
    cout<<"    33#33                                                   33#33    "<<endl;
    cout<<"    33#333                  1. Input Menu                  333#33    "<<endl
        <<"    33#3333                 2. Input Anggota              3333#33    "<<endl
        <<"    33#33333                3. Cari Anggota              33333#33    "<<endl
        <<"    33#333333               4. Cari Menu                333333#33    "<<endl
        <<"    33#3333333              5. Ubah Anggota            3333333#33    "<<endl
        <<"    33#333333               6. Hapus Anggota            333333#33    "<<endl
        <<"    33#33333                7. Hapus Menu & Anggota      33333#33    "<<endl
        <<"    33#3333                 8. Print Anggota              3333#33    "<<endl
        <<"    33#333                  9. Print Menu                  333#33    "<<endl
        <<"    33#33                   10. Menu Favorit                33#33    "<<endl
        <<"    33#3                    11. Exit                         3#33    "<<endl;
    cout<<"    33################||              ||#######################33    "<<endl;
    cout<<"                      Pilih Menu :  ";

}
    void menumenu(menu &m)
    {
        cin.ignore();
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"    3#############################################3    "<<endl;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"        Masukkan nama menu: ";
        getline(cin,m.namam);
        cout<<"        Masukkan ID menu: ";
        cin>>m.idm;
        cin.ignore();
        cout<<"        Masukkan harga menu: ";
        cin>>m.harga;
        cout<<"        Masukkan jenis menu: ";
        cin>>m.jenis;
        cout<<"    3#                                           #3    "<<endl;
        cout<<"    3#############################################3    "<<endl;
    }

void menuanggota(anggota &a,string &c)
{
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"         Masukkan nama anggota: ";
            cin>>a.nama;
            cout<<"         Masukkan ID anggota: ";
            cin>>a.ida;
            cout<<"         Masukkan Alamat anggota: ";
            cin>>a.alamat;
            cout<<"         Masukkan menu yang dipesan: ";
            cin>>c;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
}

