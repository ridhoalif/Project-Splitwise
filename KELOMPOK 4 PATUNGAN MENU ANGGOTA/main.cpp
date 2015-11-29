#include <stdio.h>
#include <string.h>
#include "TUBES.h"

listelm l;
address p;
addressmenu q;
anggota a;
menu m;
string s,c;
int pil;

int main()
{
    cout<<" "<<endl;
    cout<<" "<<endl;
    char x[]="    .+.+.+.+.+.+.+.+.+.+.== SELAMAT DATANG ==+..+.+.+.+.+.+.+.+.+       ";
     int o,y,v,n;
      n=strlen(x);
      for(v=0; v<n; v++){
        for(o=0; o<9999;o++){
            for(y=0; y<500; y++){
                }
            }
                printf("%c",x[v]);
      }
    createlistmenu(l);
    do
    {
        tampilanmenu(pil);
        cin>>pil;
        switch (pil)
        {
        case 1:
            system("CLS");
            menumenu(m);
            q=alokasimenu(m);
            insertmenu(l,q);
            getch();
            system("CLS");
            break;
        case 2:
            system("CLS");
            menuanggota(a,c);
            q=findmenuanggota(l,c,a.ida);
            if(q==NULL)
            {
                p=alokasianggota(a);
                insertanggota(l,p,c);
            }
            else{
                cout<<"    3#############################################3    "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"                Data Menu Tidak Ditemukan              "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"    3#############################################3    "<<endl;
            }

            getch();
            system("CLS");
            break;
        case 3:
            system("CLS");
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"           Masukkan ID anggota: ";
            cin>>s;
            p=findanggota(l,s);
            if(p!=NULL){
            cout<<"           "<<p->info.nama<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            }
            else{
                cout<<"                Data Anggota Tidak Ditemukan              "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"    3#############################################3    "<<endl;
            }
            getch();
            system("CLS");
            break;
        case 4:
            system("CLS");
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout <<"         Masukkan ID menu : ";
            cin>>c;
            q=findmenu(l,c);
            if(q!=NULL){
            cout<<"          "<<q->info.namam;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            }
            else{
                cout<<"                Data Menu Tidak Ditemukan              "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"    3#############################################3    "<<endl;
            }
            getch();
            system("CLS");
            break;
        case 5:
            system("CLS");
            ubahanggota(l);
            getch();
            system("CLS");
            break;
        case 6:
            system("CLS");
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    Masukkan ID anggota yang akan dihapus: ";
            cin >>s;
            cout<<"    Masukkan ID menu yang di pesan anggota tersebut: ";
            cin >>c;
            q=findmenu(l,c);
            p=findanggota(l,s);
            deleteanggota(l,q,p);
            printmenu(l);
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            getch();
            system("CLS");
            break;
        case 7:
            system("CLS");
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"      Masukkan ID menu yang akan di hapus : ";
            cin>>s;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            q=findmenu(l,s);
            if(q!=NULL)
            {
                deleteanggotamenu(l,q);
            }
            else
            {
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"    3#############################################3    "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"                  DATA TIDAK DITEMUKAN!!!              "<<endl;
                cout<<"    3#                                           #3    "<<endl;
                cout<<"    3#############################################3    "<<endl;
            }
            printmenu(l);
            getch();
            system("CLS");
            break;
        case 8:
            system("CLS");
            printanggota(l);
            getch();
            system("CLS");
            break;
        case 9:
            system("CLS");
            printmenu(l);
            getch();
            system("CLS");
            break;
        case 10:
            system("CLS");
            q=menufavorit(l);
            if(q!=NULL){
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"            "<<q->info.namam<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            }
            else{
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"    3#############################################3    "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"                 DATA TIDAK DITEMUKAN!!!               "<<endl;
            cout<<"    3#                                           #3    "<<endl;
            cout<<"    3#############################################3    "<<endl;
            }
            getch();
            system("CLS");
            break;
        }
    }
    while(pil!=11);
}
