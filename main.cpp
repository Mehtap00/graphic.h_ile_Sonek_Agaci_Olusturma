#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>

struct dugumler{
int index_bas;
int index_son;
int cocukSayisi;
int sonekSayisi;
int tekrar;
int yukseklik;
int x;
int y;
struct dugumler *ebeveyn;
struct dugumler *cocuk[30];
};

struct dugumler *root=NULL;
struct dugumler *yer=NULL;
struct dugumler *yer_2=NULL;
struct dugumler *yer_3=NULL;
struct dugumler *kontrol=NULL;
struct dugumler *dugum=NULL;
struct dugumler *kontrol_2=NULL;
struct dugumler *ilk_konum=NULL;

int n,secim=5,c,katar_arama,f,ilk_index,index;

void dolasma(struct dugumler *dolas);
void sonekAgaciOlustur(char s[],int baslangic,int bitis);
void sonekAgaciCiz(struct dugumler *ciz,char c[],int uzunluk_p);
void sonekAgaciniYaz(struct dugumler *yaz,char c[],int uzunluk_p);
void pKatariArama(char s[],char p[],int uzunluk_p);
void enCokTekrarEdenAltkatar(char s[]);
void tekrarEdenEnUzunAltkatar(char s[]);
void sonekAgaciniSil(struct dugumler *sil);

void dolasma(struct dugumler *dolas)
{
    dolas->yukseklik++;

    int j;
    for(j=0;j<30;j++){
    if(dolas->cocuk[j]!=NULL)
    dolasma(dolas->cocuk[j]);}
}


void sonekAgaciOlustur(char s[],int baslangic,int bitis)
{
    int i,sayac,sayac_2,sayac_3,sayac_4,degisken,degisken_2,a;

    if(root==NULL)
    {
    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->index_bas=-5;
    dugum->index_son=-5;
    dugum->sonekSayisi=-5;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=0;

    root=dugum;
    }

    if(root!=NULL)
    {
    if(yer==NULL){
    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->index_bas=0;
    dugum->index_son=bitis;
    dugum->sonekSayisi=1;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=1;

    dugum->ebeveyn=root;
    root->cocuk[0]=dugum;
    root->cocukSayisi++;
    yer=root;
    }

    else{
    yer_3=yer->cocuk[0];
    yer_2=yer;
    sayac=0;
    sayac_4=0;
    sayac_3=0;

    while(yer_3!=NULL)
    {
    a=2;
    if(s[yer_3->index_bas]==s[baslangic+sayac]){

        for(i=0;i<=bitis-baslangic;i++){

        if(i==(yer_3->index_son)-(yer_3->index_bas)+1){
        yer_2=yer_3;
        sayac_4=0;
        yer_3=yer_3->cocuk[sayac_4];
        sayac=sayac+i;
        a=7;
        break;}

        if(s[(yer_3->index_bas)+i]!=s[baslangic+i+sayac]){
        sayac=baslangic+sayac+i;
        sayac_2=(yer_3->index_bas)+i-1;
        a=5;
        break;}
        }
        sayac_3++;

        if(a==5)
        break;

        if(a==7)
        continue;

        if(sayac_3==30)
        break;
    }

    else{
    sayac_2=-5;
    sayac_4++;

    if(yer_2->cocuk[sayac_4]!=NULL)
    yer_3=yer_2->cocuk[sayac_4];

    else
    break;}
    }

    if(sayac_2==-5){
    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->index_bas=baslangic+sayac;
    dugum->index_son=bitis;
    dugum->sonekSayisi=baslangic+1;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=0;

    dugum->ebeveyn=yer_2;
    yer_2->cocuk[sayac_4]=dugum;
    yer_2->cocukSayisi++;

    kontrol_2=yer_2;
    while(kontrol_2!=yer){
    kontrol_2->tekrar++;
    if(kontrol_2->ebeveyn!=yer)
    kontrol_2=kontrol_2->ebeveyn;
    else
    break;
    }

    yer_2->cocuk[sayac_4]->yukseklik=yer_2->yukseklik+1;
    }

    if(sayac_2!=-5){

    if(yer_3->cocuk[0]==NULL){
    degisken=yer_3->index_son;
    degisken_2=yer_3->sonekSayisi;

    yer_3->index_son=sayac_2;
    yer_3->sonekSayisi=-1;

    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->index_bas=sayac_2+1;
    dugum->index_son=degisken;
    dugum->sonekSayisi=degisken_2;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=0;

    dugum->ebeveyn=yer_3;
    yer_3->cocuk[0]=dugum;
    yer_3->cocukSayisi++;

    yer_3->cocuk[0]->yukseklik=yer_3->yukseklik+1;

    kontrol_2=yer_3;
    while(kontrol_2!=yer){
    kontrol_2->tekrar++;
    if(kontrol_2->ebeveyn!=yer)
    kontrol_2=kontrol_2->ebeveyn;
    else
    break;
    }

    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->index_bas=sayac;
    dugum->index_son=bitis;
    dugum->sonekSayisi=baslangic+1;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=0;

    dugum->ebeveyn=yer_3;
    yer_3->cocuk[1]=dugum;
    yer_3->cocukSayisi++;

    kontrol_2=yer_3;
    kontrol_2->tekrar++;
    yer_3->cocuk[1]->yukseklik=yer_3->yukseklik+1;
    }

    else{
    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    dugum->cocukSayisi=0;
    dugum->tekrar=0;
    dugum->yukseklik=0;

    yer_3=yer_2;

    dugum->cocuk[0]=yer_2->cocuk[sayac_4];
    dugum->cocukSayisi++;
    yer_2->cocuk[sayac_4]->ebeveyn=dugum;
    yer_2->cocuk[sayac_4]=dugum;
    dugum->ebeveyn=yer_2;

    yer_2->cocuk[sayac_4]->yukseklik=yer_2->yukseklik+1;

    kontrol_2=yer_2->cocuk[sayac_4]->cocuk[0];
    dolasma(kontrol_2);

    kontrol_2=yer_2;
    while(kontrol_2!=yer){
    kontrol_2->tekrar++;
    if(kontrol_2->ebeveyn!=yer)
    kontrol_2=kontrol_2->ebeveyn;
    else
    break;
    }

    yer_2->cocuk[sayac_4]->tekrar=yer_2->cocuk[sayac_4]->cocuk[0]->tekrar;

    yer_3=yer_2->cocuk[sayac_4]->cocuk[0];

    dugum->index_bas=yer_3->index_bas;
    dugum->index_son=sayac_2;
    dugum->sonekSayisi=-1;
    dugum->x=0;
    dugum->y=0;

    yer_3->index_bas=sayac_2+1;

    dugum=(struct dugumler*)malloc(sizeof(struct dugumler));
    for(i=0;i<30;i++)
    dugum->cocuk[i]=NULL;
    dugum->ebeveyn=NULL;

    yer_2->cocuk[sayac_4]->cocuk[1]=dugum;
    yer_2->cocuk[sayac_4]->cocukSayisi++;
    dugum->ebeveyn=yer_2->cocuk[sayac_4];

    dugum->index_bas=sayac;
    dugum->index_son=bitis;
    dugum->sonekSayisi=baslangic+1;
    dugum->cocukSayisi=0;
    dugum->x=0;
    dugum->y=0;
    dugum->tekrar=0;
    dugum->yukseklik=yer_2->cocuk[sayac_4]->yukseklik+1;

    kontrol_2=yer_2->cocuk[sayac_4];
    while(kontrol_2!=yer){
    kontrol_2->tekrar++;
    if(kontrol_2->ebeveyn!=yer)
    kontrol_2=kontrol_2->ebeveyn;
    else
    break;
    }}}
    }
    }

}

void sonekAgaciCiz(struct dugumler *ciz, char c[],int uzunluk_p)
{
    int b,sayi;
    if(ciz!=NULL && ciz->index_bas!=-5){

    if(ciz->ebeveyn->cocukSayisi%2==0){

    for(b=0;b< ciz->ebeveyn->cocukSayisi;b++){
    if(ciz->ebeveyn->cocuk[b]==ciz)
    break;}

    sayi=ciz->ebeveyn->cocukSayisi/2;

    ciz->x=ciz->ebeveyn->x+((b-sayi)*(n/ciz->yukseklik))+((n/ciz->yukseklik)/2);
    ciz->y=ciz->ebeveyn->y+100;
    }

    else if(ciz->ebeveyn->cocukSayisi%2==1){

    for(b=0;b< ciz->ebeveyn->cocukSayisi;b++){
    if(ciz->ebeveyn->cocuk[b]==ciz)
    break;}

    sayi=ciz->ebeveyn->cocukSayisi/2;

    ciz->x=ciz->ebeveyn->x+((b-sayi)*(n/ciz->yukseklik));
    ciz->y=ciz->ebeveyn->y+100;
    }

    printf("%d %d %d %d ----%d\n",ciz->index_bas,ciz->index_son,ciz->x,ciz->y,ciz->sonekSayisi);

     setcolor(WHITE);
    circle(ciz->x,ciz->y,12);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(ciz->x,ciz->y,WHITE);
    line(ciz->ebeveyn->x,ciz->ebeveyn->y,ciz->x,ciz->y);
    int ortax=(ciz->ebeveyn->x+ciz->x)/2;
    int ortay=(ciz->ebeveyn->y+ciz->y)/2;

    setcolor(LIGHTCYAN);
    settextstyle(DEFAULT_FONT,0,1);

    char k[ciz->index_son-ciz->index_bas+2];
    strcpy(k,"w");
    int t=ciz->index_bas;

    for(int l=0;l<=ciz->index_son-ciz->index_bas;l++){
    k[l]=c[t];
    t++;
    }
    k[ciz->index_son-ciz->index_bas+1]='\0';
    char* d = &k[0];
    outtextxy(ortax,ortay,d);
    int intetostr = ciz->sonekSayisi;
    char str[10];
    sprintf(str, "%d",intetostr);
    if(intetostr>0){
        outtextxy(ciz->x-5, ciz->y+15,str);
    }

    if(katar_arama==1){
    if(ciz==root->cocuk[index]){
    setcolor(BLUE);
    circle(ciz->x,ciz->y,12);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(ciz->x,ciz->y,BLUE);
    line(ciz->ebeveyn->x,ciz->ebeveyn->y,ciz->x,ciz->y);
    int ortax=(ciz->ebeveyn->x+ciz->x)/2;
    int ortay=(ciz->ebeveyn->y+ciz->y)/2;

    setcolor(BLUE);
    settextstyle(DEFAULT_FONT,0,1);

    char k[ciz->index_son-ciz->index_bas+2];
    strcpy(k,"w");
    int t=ciz->index_bas;

    for(int l=0;l<=ciz->index_son-ciz->index_bas;l++){
    k[l]=c[t];
    t++;
    }
    k[ciz->index_son-ciz->index_bas+1]='\0';
    char* d = &k[0];
    outtextxy(ortax,ortay,d);
    int intetostr = ciz->sonekSayisi;
    char str[10];
    sprintf(str, "%d",intetostr);
    if(intetostr>0){
        outtextxy(ciz->x-5, ciz->y+15,str);
    }}
    }

    else if(katar_arama==2){
    if(ciz==root->cocuk[f]){
    setcolor(MAGENTA);
    circle(ciz->x,ciz->y,12);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(ciz->x,ciz->y,MAGENTA);
    line(ciz->ebeveyn->x,ciz->ebeveyn->y,ciz->x,ciz->y);
    int ortax=(ciz->ebeveyn->x+ciz->x)/2;
    int ortay=(ciz->ebeveyn->y+ciz->y)/2;

    setcolor(MAGENTA);
    settextstyle(DEFAULT_FONT,0,1);

    char k[ciz->index_son-ciz->index_bas+2];
    strcpy(k,"w");
    int t=ciz->index_bas;

    for(int l=0;l<=ciz->index_son-ciz->index_bas;l++){
    k[l]=c[t];
    t++;
    }
    k[ciz->index_son-ciz->index_bas+1]='\0';
    char* d = &k[0];
    outtextxy(ortax,ortay,d);
    int intetostr = ciz->sonekSayisi;
    char str[10];
    sprintf(str, "%d",intetostr);
    if(intetostr>0){
        outtextxy(ciz->x-5, ciz->y+15,str);
    }}
    }


    else if(katar_arama==3 ){
    if(ciz==ilk_konum){
    setcolor(GREEN);
    circle(ciz->x,ciz->y,12);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(ciz->x,ciz->y,GREEN);
    line(ciz->ebeveyn->x,ciz->ebeveyn->y,ciz->x,ciz->y);
    int ortax=(ciz->ebeveyn->x+ciz->x)/2;
    int ortay=(ciz->ebeveyn->y+ciz->y)/2;

    setcolor(GREEN);
    settextstyle(DEFAULT_FONT,0,1);

    char k[ciz->index_son-ciz->index_bas+2];
    strcpy(k,"w");
    int t=ciz->index_bas;

    for(int l=0;l<=ciz->index_son-ciz->index_bas;l++){
    k[l]=c[t];
    t++;
    }
    k[ciz->index_son-ciz->index_bas+1]='\0';
    char* d = &k[0];
    outtextxy(ortax,ortay,d);
    int intetostr = ciz->sonekSayisi;
    char str[10];
    sprintf(str, "%d",intetostr);
    if(intetostr>0){
        outtextxy(ciz->x-5, ciz->y+15,str);
    }

    if(ilk_konum->index_son > ilk_index+uzunluk_p || ilk_konum->index_son == ilk_index+uzunluk_p){
    katar_arama=0;
    }

    if(ilk_konum->index_son < ilk_index+uzunluk_p){

    if(ilk_konum->cocuk[0]!=NULL)
    ilk_konum=ilk_konum->cocuk[0];

    else
    katar_arama=0;
    }
    }}




    }

    int j;
    for(j=0;j<30;j++){
    if(ciz->cocuk[j]!=NULL)
    sonekAgaciCiz(ciz->cocuk[j],c,uzunluk_p);
    }
}

void sonekAgaciniYaz(struct dugumler *yaz, char c[],int uzunluk_p)
{

    if(katar_arama!=2){
        initwindow(1570,850);
        yaz->x=getmaxx()/2;
        yaz->y=50;
        setbkcolor(DARKGRAY);
        cleardevice();
        setcolor(WHITE);
        circle(yaz->x,yaz->y,12);
        setfillstyle(SOLID_FILL,LIGHTRED);
        floodfill(yaz->x,yaz->y,WHITE);
        setcolor(LIGHTCYAN);
        settextstyle(DEFAULT_FONT,0,1);
        outtextxy(yaz->x-12, yaz->y-35, (char*)"kok");
        n=(yaz->x*2)/(yaz->cocukSayisi+1);
        sonekAgaciCiz(yaz,c,uzunluk_p);
        getch();
    }

    if(katar_arama==0)
        closegraph();

}

void pKatariArama(char s[],char p[],int uzunluk_p)
{
    int y,z,e,var;

    for(c=0;c<kontrol->cocukSayisi;c++){
        if(s[kontrol->cocuk[c]->index_bas]==p[0])
        break;
    }

    if(c==kontrol->cocukSayisi){
    printf("Aradiginiz '%s' katari '%s' katarinin icinde bulunmamaktadir.\n\n\n",p,s);

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }

    else{
    kontrol=kontrol->cocuk[c];

    z=0;
    y=0;
    var=0;
    e=0;

    while(kontrol!=NULL)
    {
        if(s[(kontrol->index_bas)+y]==p[z]){
        y++;
        z++;

        if(z==uzunluk_p+1){
        var++;
        z=0;}

        if(var==1 && z==0){
        ilk_index=(kontrol->index_bas)+y-1-uzunluk_p;

        kontrol_2=kontrol;
        while(kontrol_2!=root){
        if(kontrol_2->index_bas<=ilk_index){
        ilk_konum=kontrol_2;
        break;}

        else{
        if(kontrol_2->ebeveyn!=root)
        kontrol_2=kontrol_2->ebeveyn;}
        }
        }

        else if(s[(kontrol->index_bas)+y]!=p[z]){
        z=0;

        if(s[(kontrol->index_bas)+y]!=p[z])
        y++;

        if(s[(kontrol->index_bas)+y]==p[z]){
        z++;
        y++;}
        }

        if(y==(kontrol->index_son)-(kontrol->index_bas)+1){

        if(kontrol->cocuk[0]==NULL)
        break;

        if(kontrol->cocuk[0]!=NULL){
        kontrol=kontrol->cocuk[0];
        y=0;}
        }}

        e++;
        if(e==20)
        break;
    }

    if(var==0){
    printf("Aradiginiz '%s' katari '%s' katarinin icinde bulunmamaktadir.\n\n\n",p,s);

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }


    if(var>0){
    printf("Aradiginiz '%s' katari '%s' katarinin icinde %d kere bulunmaktadir.\n",p,s,var);
    printf("'%s' katarinin bulundugu ilk konum %d'dir.\n\n\n",p,ilk_index);

    katar_arama=3;
    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,uzunluk_p);
    }
    katar_arama=0;
    }

}


void enCokTekrarEdenAltkatar(char s[])
{
    int h,d,v;
    index=0;
    for(d=0;d<kontrol->cocukSayisi;d++){
        if(kontrol->cocuk[index]->tekrar < kontrol->cocuk[d]->tekrar)
        index=d;}

    if(kontrol->cocuk[index]->tekrar==0){
    printf("'%s' katarinda tekrar eden altkatar bulunmamaktadir.\n\n\n",s);

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }

    else{
    if((kontrol->cocuk[index]->index_son - kontrol->cocuk[index]->index_bas)>0){

    printf("'%s' katarinda en cok tekrar eden 1.altkatar '",s);
    for(v=kontrol->cocuk[index]->index_bas;v<=kontrol->cocuk[index]->index_son;v++)
    printf("%c",s[v]);
    printf("'dir ve %d kere tekrar etmektedir.\n",kontrol->cocuk[index]->tekrar);}
    printf("Ayrica bu katarin tum altkatarlari da ayni sayida tekrar etmektedir.\n\n");

    if((kontrol->cocuk[index]->index_son - kontrol->cocuk[index]->index_bas)==0){
    printf("'%s' katarinda en cok tekrar eden 1. altkatar '",s);
    for(v=kontrol->cocuk[index]->index_bas;v<=kontrol->cocuk[index]->index_son;v++)
    printf("%c",s[v]);
    printf("'dir ve %d kere tekrar etmektedir.\n\n",kontrol->cocuk[index]->tekrar);}

    h=1;
    for(f=index+1;f<kontrol->cocukSayisi;f++){
    if(kontrol->cocuk[f]->tekrar==kontrol->cocuk[index]->tekrar  &&  f!=index){

    printf("'%s' katarinda en cok tekrar eden %d.altkatar '",s,++h);
    for(v=kontrol->cocuk[f]->index_bas;v<=kontrol->cocuk[f]->index_son;v++)
    printf("%c",s[v]);
    printf("'dir ve %d kere tekrar etmektedir.\n\n\n",kontrol->cocuk[f]->tekrar);
    }}


    katar_arama=1;

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);


    for(f=index+1;f<kontrol->cocukSayisi;f++){
    if(kontrol->cocuk[f]->tekrar==kontrol->cocuk[index]->tekrar  &&  f!=index){
    katar_arama=2;

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }}

    katar_arama=0;
    }
}


void tekrarEdenEnUzunAltkatar(char s[])
{
    int d,f,v;

    for(d=0;d<kontrol->cocukSayisi;d++){
        if(kontrol->cocuk[d]->tekrar>0){
        index=d;
        break;}
    }

    if(d==kontrol->cocukSayisi){
    printf("'%s' katarinda tekrar eden altkatar bulunmamaktadir.\n\n\n",s);

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }

    else{
    for(d=0;d<kontrol->cocukSayisi;d++){
        if(kontrol->cocuk[d]->tekrar >0){
        if((kontrol->cocuk[index]->index_son) - (kontrol->cocuk[index]->index_bas) < (kontrol->cocuk[d]->index_son) -(kontrol->cocuk[d]->index_bas) )
        index=d;}}

    printf("'%s' katarinda tekrar eden en uzun altkatar '",s);
    for(v=kontrol->cocuk[index]->index_bas;v<=kontrol->cocuk[index]->index_son;v++)
    printf("%c",s[v]);
    printf("'dir ve uzunlugu %d'dir.\n\n",kontrol->cocuk[index]->index_son-kontrol->cocuk[index]->index_bas+1);


    for(f=index+1;f<kontrol->cocukSayisi;f++){
        if(kontrol->cocuk[f]->tekrar > 0){
        if((kontrol->cocuk[f]->index_son) - (kontrol->cocuk[f]->index_bas) == (kontrol->cocuk[index]->index_son) - (kontrol->cocuk[index]->index_bas) &&  f!=index){

        printf("'%s' katarinda tekrar eden en uzun altkatar '",s);
        for(v=kontrol->cocuk[f]->index_bas;v<=kontrol->cocuk[f]->index_son;v++)
        printf("%c",s[v]);
        printf("'dir ve uzunlugu %d'dir.\n\n\n",kontrol->cocuk[f]->index_son-kontrol->cocuk[f]->index_bas+1);
        }}}

    katar_arama=1;

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);

    for(f=index+1;f<kontrol->cocukSayisi;f++){
    if(kontrol->cocuk[f]->tekrar==kontrol->cocuk[index]->tekrar  &&  f!=index){
    katar_arama=2;

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);
    }}

    katar_arama=0;

    }
}


void sonekAgaciniSil(struct dugumler *sil)
{
    int k;
    for(k=0;k<30;k++){
    if(sil->cocuk[k]!=NULL)
    sonekAgaciniSil(sil->cocuk[k]);
    }

    if(sil!=NULL)
    free(sil);
}


int main()
{
    int uzunluk,j,uzunluk_p;
    char s[60];
    printf("Lutfen dosya ismini giriniz.");
    char dosyaAdi[20];
    gets(dosyaAdi);
    FILE* f=fopen(dosyaAdi,"r");
    fgets(s,60,f);

    strcat(s,"$");

    uzunluk=strlen(s);

    for(j=0;j<uzunluk;j++){
    sonekAgaciOlustur(s,j,uzunluk-1);
    }

    while(secim!=0){
    printf("\n0--Cikis\n");
    printf("1--s katari icin sonek agaci oluturulabilir mi?\n");
    printf("2--Sonek agaci olusturulan bir s katari icinde p katari geciyor mu,geciyorsa ilk bulundugu yerin baslangic pozisyonu    nedir,kac kez tekrar etmektedir?\n");
    printf("3--Sonek agaci olusturulan bir s katari icinde tekrar eden en uzun altkatar nedir,kac kez tekrar etmektedir?\n");
    printf("4--Sonek agaci olusturulan bir s katari icinde en cok tekrar eden altkatar nedir,kac kez tekrar etmektedir?\n\n");

    printf("Yapmak istediginiz islemi giriniz:");
    scanf("%d",&secim);
    printf("\n");

    if(secim==1){
    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniYaz(kontrol,s,5);}

    if(secim==2){
    char p[30]="bc";
    uzunluk_p=strlen(p);
    if(kontrol!=root)
    kontrol=root;
    pKatariArama(s,p,uzunluk_p-1);}

    if(secim==3){
    if(kontrol!=root)
    kontrol=root;
    tekrarEdenEnUzunAltkatar(s);}

    if(secim==4){
    if(kontrol!=root)
    kontrol=root;
    enCokTekrarEdenAltkatar(s);}

    if(secim==0)
    break;
    }

    if(kontrol!=root)
    kontrol=root;
    sonekAgaciniSil(kontrol);

    return 0;

}
