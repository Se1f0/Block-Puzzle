#include<stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include<time.h>
#include <SDL/SDL_ttf.h>
#include "fonctio.h"

void copiepile(pile **p,pile **q){
pile *r=initpile(r);
(*q)=initpile(*q);
cordo z;

while(!pilevide(*p)){desempiler(p,&z);empiler(&r,z);}
while(!pilevide(r)){desempiler(&r,&z);empiler(p,z);empiler(q,z);}
}

int verifier3(int a[100][100],int b[100][100]){
int i,j,k;
cordo z;
pile *p;
for(i=1;i<=10;i++){
    for(j=1;j<=10;j++){
            z.x=j;z.y=i;
            k=moh(a,10,10,b,5,5,z,&p);
        if(k==1){return 1;}
    }
}
return 0;
}

int cordone(int b[100][100],int n,int m){
int x,y,i,j,v;
i=1;v=1;

while(i<=n && v==1){
        j=1;
    while(j<=m && v==1){

        if(b[i][j]!=0){
            y=j;v=0;
        }
        j++;
    }
    i++;
}
i=1;v=0;
while(i<=m && v==0){
        j=1;
    while(j<=n && v==0){
        if(b[j][i]!=0){
            x=i;v=1;
        }
        j++;
    }
    i++;
}
y=y-x;
return y;
}

void calculemax(int a[100][100],cordo y,int *max2,int *max3,int e,cordo *cmax){
int i,j,nb,cpt,n,m;
cordo z;
z.x=y.x;z.y=y.y;y.x=y.x-e;
nb=0;
n=y.y+1;if(n>10){n=10;}
m=y.x+1;if(m>10){m=10;}

for(i=y.y;i<=n;i++){
    for(j=y.x;j<=m;j++){
        if(a[i][j]!=0){nb++;}
    }
}
n=y.y+2;if(n>10){n=10;}
m=y.x+2;if(m>10){m=10;}
cpt=0;

for(i=y.y;i<=n;i++){
    for(j=y.x;j<=m;j++){
        if(a[i][j]!=0){cpt++;}
    }
}
i=(*max2)+(*max3);
if(nb>(*max2)){(*max2)=nb;}
if(cpt>(*max3)){(*max3)=cpt;}
j=(*max2)+(*max3);
if(j>i){(*cmax).y=z.y;(*cmax).x=z.x;}
}

int nombre(int b[100][100]){
int i,j;

for(i=1;i<=5;i++){
    for(j=1;j<=5;j++){
        if(b[i][j]!=0){return b[i][j];}
    }
}
}

void rempliepile(int a[100][100],pile *p,int x,pile **q){
cordo y;
(*q)=initpile(*q);

while(!pilevide(p)){desempiler(&p,&y);a[y.y][y.x]=x;empiler(q,y);}
}

cordo verifier4(int a[100][100],int b[100][100],int *k2,int *k3){
pile *p,*q;
int i,j,r,vr,e,max2,max3,n,nf=0;
cordo y,cmax,cfin;
cmax.x=-1;cmax.y=-1;
cfin.x=-1;cfin.y=-1;
max2=0;max3=0;
e=cordone(b,5,5);
r=nombre(b);
for(i=1;i<=10;i++){
    for(j=1;j<=10;j++){
             y.y=i; y.x=j;
vr=moh(a,10,10,b,5,5,y,&p);
if(vr==1){
    rempliepile(a,p,r,&q);
    calculemax(a,y,&max2,&max3,e,&cmax);
    n=verifier2(a);
    if(n>nf){nf=n;cfin=y;}
    rempliepile(a,q,0,&p);
}
    }
}
(*k2)=max2;
(*k3)=max3;
if(nf>0){return cfin;}
return cmax;
}

cordo verifier(int a[100][100],int b[100][100]){
pile *p,*q;
int i,j,r,vr,e,max2,max3,n,nf=0;
cordo y,cmax,cfin;
max2=0;max3=0;
e=cordone(b,5,5);
r=nombre(b);
for(i=1;i<=10;i++){
    for(j=1;j<=10;j++){
             y.y=i; y.x=j;
vr=moh(a,10,10,b,5,5,y,&p);
if(vr==1){
    rempliepile(a,p,r,&q);
    calculemax(a,y,&max2,&max3,e,&cmax);
    n=verifier2(a);
    if(n>nf){nf=n;cfin=y;}
    rempliepile(a,q,0,&p);
}
    }
}
if(nf>0){return cfin;}
return cmax;
}

void ligne_et_col(int a[100][100],int *score){
pile *r=initpile(r),*q=initpile(q);
int i,j,cpt1,cpt2,cpt0=0,bonus;
cordo e,v;
for(i=1;i<=10;i++){
    cpt1=0;cpt2=0;
   for(j=1;j<=10;j++){
        if(a[i][j]==0){cpt1++;}
        if(a[j][i]==0){cpt2++;}
    }
    if(cpt2==0){
            e.x=i;
        empiler(&q,e);
    }
    if(cpt1==0){
        v.x=i;
        empiler(&r,v);
    }
}
while(pilevide(q)==0){
    desempiler(&q,&v);
    cpt0++;
    for(j=1;j<=10;j++){
        a[j][v.x]=0;
    }
}
while(pilevide(r)==0){
    desempiler(&r,&v);
    cpt0++;
    for(j=1;j<=10;j++){
        a[v.x][j]=0;
    }
}
bonus=0;
for(i=1;i<cpt0;i++){
    bonus=bonus+100*i;
}
bonus=bonus+cpt0*100;
*score=*score+bonus;
}

int verifier2(int a[100][100]){
int i,j,cpt1,cpt2,cpt0=0;
for(i=1;i<=10;i++){
    cpt1=0;cpt2=0;
   for(j=1;j<=10;j++){
        if(a[i][j]==0){cpt1++;}
        if(a[j][i]==0){cpt2++;}
    }
    if(cpt1==0){cpt0++;}
      if(cpt2==0){cpt0++;}
}
return cpt0;
}

void pcdetectepos(int a[100][100],int b[100][100],int *score){
cordo h,z;
int i,x,nb1=0;
pile *p;
z=verifier(a,b);
i=moh(a,10,10,b,5,5,z,&p);
x=nombre(b);
if(x==6){nb1=3;}
if(i==1){(*score)=(*score)+(x+nb1)*10;}
while(!pilevide(p)){desempiler(&p,&h);a[h.y][h.x]=x;}
}

int tempo(int a[100][100],pile **f,int *r){
    int b[100][100],i,j,nb,max2,max3,cpt,sc;
    cordo h,z;
    pile *p=initpile(p),*q=initpile(q);
    sc=0;
    int nb1=0;
    rempliematrice(sommetdepile(*f).x,b);
    if(verifier3(a,b)==1){
        z=verifier4(a,b,&max2,&max3);
        (*r)=max2+max3;
        i=moh(a,10,10,b,5,5,z,&p);
        nb=nombre(b);
        if(nb==6){nb1=3;}
        if(i==1){sc=sc+10*(nb+nb1);}
        while(!pilevide(p)){desempiler(&p,&h);empiler(&q,h);a[h.y][h.x]=nb;}
        cpt=verifier2(a);
        for(j=1;j<cpt;j++){
            sc=sc+j*100;
        }
        sc=sc+cpt*100;
        while(!pilevide(q)){desempiler(&q,&h);a[h.y][h.x]=0;}
    }
     return sc;
}

void finaly(int a[100][100],pile **f1,pile **f2,pile **f3,int *vf,int *score,int *l,int *k){
int sc1,sc2,sc3,sc,vs=0,p1,p2,p3,pf,vp=0,b[100][100],c[100][100],d[100][100],f=0,c2=0,c1=0;
cordo z;
initmatrice(b,5,5,0);initmatrice(c,5,5,0);initmatrice(d,5,5,0);
sc1=tempo(a,f1,&p1);
sc2=tempo(a,f2,&p2);
sc3=tempo(a,f3,&p3);
if((sc1+sc2+sc3)==0){(*vf)=0;}else{
    if(sc1>sc2){
        sc=sc1;vs=1;
    }else{sc=sc2;vs=2;}
    if(sc3>sc){sc=sc3;vs=3;}
    if(p1>p2){
        pf=p1;vp=1;
    }else{pf=p2;vp=2;}
    if(p3>pf){pf=p3;vp=3;}
    if(sc>100){(*l)=vs;
    if(vs==1){desempiler(f1,&z);}else{
            if(vs==2){desempiler(f2,&z);}else{desempiler(f3,&z);}
    }
    }else{(*l)=vp;
    if(vp==1){desempiler(f1,&z);}else{
            if(vp==2){desempiler(f2,&z);}else{desempiler(f3,&z);}
    }
    }
(*k)=z.x;
rempliematrice(z.x,b);
f=(*l);
if(verifier3(a,b)){
    pcdetectepos(a,b,score);
}else{
if(f==1){empiler(f1,z);rempliematrice(sommetdepile(*f2).x,c);rempliematrice(sommetdepile(*f3).x,d);c1=p2;c2=p3;}
if(f==2){empiler(f2,z);rempliematrice(sommetdepile(*f1).x,c);rempliematrice(sommetdepile(*f3).x,d);c1=p1;c2=p3;}
if(f==3){empiler(f3,z);rempliematrice(sommetdepile(*f1).x,c);rempliematrice(sommetdepile(*f2).x,d);c1=p1;c2=p2;}
if(!verifier3(a,c) || !verifier3(a,d)){
    if(!verifier3(a,d)){
        pcdetectepos(a,c,score);
if(f==1){desempiler(f2,&z);(*l)=2;(*k)=z.x;}
if(f==2){desempiler(f1,&z);(*l)=1;(*k)=z.x;}
if(f==3){desempiler(f1,&z);(*l)=1;(*k)=z.x;}
    }
    if(!verifier3(a,c)){
        pcdetectepos(a,d,score);
if(f==1){desempiler(f3,&z);(*l)=3;(*k)=z.x;}
if(f==2){desempiler(f3,&z);(*l)=3;(*k)=z.x;}
if(f==3){desempiler(f2,&z);(*l)=2;(*k)=z.x;}
    }
}else{
if(c1>=c2){
pcdetectepos(a,c,score);
if(f==1){desempiler(f2,&z);(*l)=2;(*k)=z.x;}
if(f==2){desempiler(f1,&z);(*l)=1;(*k)=z.x;}
if(f==3){desempiler(f1,&z);(*l)=1;(*k)=z.x;}
}
if(c2>c1){
pcdetectepos(a,d,score);
if(f==1){desempiler(f3,&z);(*l)=3;(*k)=z.x;}
if(f==2){desempiler(f3,&z);(*l)=3;(*k)=z.x;}
if(f==3){desempiler(f2,&z);(*l)=2;(*k)=z.x;}
}
}
   }
}
}

void savescore(int score,int a){
    FILE *fichier=NULL;
    scor x;
x.sc=score;
if(a==3){fichier=fopen("file/score/save2.score","w");}
if(a==1){fichier=fopen("file/score/save1.score","w");}
if(a==8){fichier=fopen("file/score/save3.score","w");}
fwrite(&x,sizeof(scor),1,fichier);
     fclose(fichier);
}

void inittab(toplayer t[100]){
int i;
for(i=1;i<=5;i++){
    t[i].score=-1;
}
}

int position(toplayer x,toplayer t[100]){
int y=x.score,i;
for(i=1;i<=5;i++){
 if((t[i].score)<y){return i;}
}
return -1;
}

void insert(toplayer t[100],int k,toplayer x){
int i=5;
if(k!=-1){
while(i>=k){
 t[i+1]=t[i];
    i--;
}
t[k]=x;
}
}

void create(toplayer t[100],toplayer x){
int u;
u=position(x,t);
 insert(t,u,x);
}

void standard(SDL_Surface *ecran,int score,int *vr,int scorepc,int j){
int meilleur,r=0,q=0;
listewinner a;
  SDL_Rect pos;
  SDL_Color chiffre = {0, 0,0 },chiffre1 = {255, 150,15 },surf= {192, 192, 192},chiffre4 = {0, 0,128 };
SDL_Surface *texte=NULL,*init=NULL,*image=NULL,*home=NULL,*replay=NULL,*liste=NULL;
TTF_Font *police=NULL;
 char temp[50],temppc[100],temp1[100];
  cordo z;
FILE *fichier=NULL;
if(j==1){fichier=fopen("file/score/save.topscore","r");}
if(j==3){fichier=fopen("file/score/savepc.topscore","r");}
fread(&a,sizeof(listewinner),1,fichier);
  fclose(fichier);
image=SDL_LoadBMP("file/images/others/400.bmp");
replay=SDL_LoadBMP("file/images/others/replay.bmp");
home=SDL_LoadBMP("file/images/others/home.bmp");
liste=SDL_LoadBMP("file/images/others/save.bmp");
 init=SDL_CreateRGBSurface(SDL_HWSURFACE,330,170,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 192, 192,192));
meilleur=a.t[1].score;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 192, 192, 192));
if(scorepc<score && scorepc!=0){r=400;}
    pos.x=r;
 pos.y=0;
 SDL_BlitSurface(image, NULL, ecran, &pos);
    pos.x=0;
 pos.y=450;
 SDL_BlitSurface(init, NULL, ecran, &pos);
    pos.x=70;
 pos.y=519;
 SDL_BlitSurface(home, NULL, ecran, &pos);
    pos.x=200;
 pos.y=519;
 SDL_BlitSurface(replay, NULL, ecran, &pos);
 TTF_Init();
police = TTF_OpenFont("font/3.ttf", 50);
 sprintf(temp, "Best:%d",meilleur);
 sprintf(temp1, "Score:%d",score);
 sprintf(temppc, "Scorepc:%d",scorepc);
  texte = TTF_RenderText_Shaded(police, temp1, chiffre,surf);
 if(j==2){q=50; texte = TTF_RenderText_Shaded(police, temp1, chiffre4,surf);}
  pos.x=15;
  pos.y=290+q;
      SDL_BlitSurface(texte, NULL, ecran, &pos);
      pos.x=25;
  pos.y=370;
  if(j!=2){
  texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf);
      SDL_BlitSurface(texte, NULL, ecran, &pos);
  }
if(scorepc!=0){
    pos.x=400;
  pos.y=330;
  texte = TTF_RenderText_Shaded(police, temppc, chiffre,surf);
      SDL_BlitSurface(texte, NULL, ecran, &pos);
}
TTF_Quit();
SDL_Flip(ecran);
SDL_Event event;
int conto=1;
while(conto){

        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:conto=0;(*vr)=2;
            break;
        case SDL_MOUSEBUTTONDOWN:
 z.x=event.button.x;
  z.y=event.button.y;
    if(z.x>200 && z.x<=260 && z.y>=519 && z.y <=579){
        (*vr)=1;
        conto=0;
    }
if(z.x>70 && z.x<=130 && z.y>=519 && z.y <=579){
        (*vr)=2;
        conto=0;
    }
            break;
}
}
}

void classer(int score,int scorepc,SDL_Surface *ecran,int *u,int game){
toplayer x;
date y;
int i,v,r;
listewinner a;
  char moh[50];
FILE *fichier=NULL;
if(game==3){fichier=fopen("file/score/savepc.topscore","r");}else{fichier=fopen("file/score/save.topscore","r");}
fread(&a,sizeof(listewinner),1,fichier);
  fclose(fichier);
if( a.t[5].score<score ){
        if(a.t[1].score<=score){
            v=1;
        }
        else{v=0;}
    name(ecran,moh,v);
        x.score=score;
timee(&y);
x.playdate.annee = y.annee;
x.playdate.jour = y.jour;
x.playdate.mois = y.mois;
   i=0;
   while(moh[i]!='\0'){
    x.username[i]=moh[i];
    i++;
   }
   x.username[i]='\0';
    create(a.t,x);
if(game==3){fichier=fopen("file/score/savepc.topscore","w");}else{fichier=fopen("file/score/save.topscore","w");}
fwrite(&a,sizeof(listewinner),1,fichier);
  fclose(fichier);
}
standard(ecran,score,&r,scorepc,game);
    (*u)=r;
}

void retournerscore(int *score,int *meilleur,int a){
    FILE *fichier=NULL;
  scor x;
  listewinner z;
    if(a==3){fichier=fopen("file/score/save2.score","r");}
    if(a==1){fichier=fopen("file/score/save1.score","r");}
    if(a==8){fichier=fopen("file/score/save3.score","r");}
fread(&x,sizeof(scor),1,fichier);
(*score)=x.sc;
     fclose(fichier);
      if(a!=1){fichier=fopen("file/score/savepc.topscore","r");}else{fichier=fopen("file/score/save.topscore","r");}
fread(&z,sizeof(listewinner),1,fichier);
(*meilleur)=z.t[1].score;
     fclose(fichier);
}

void timee(date *x){
     time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
   x->mois=(s[1]-48)+(s[0]-48)*10;
   x->jour=(s[4]-48)+(s[3]-48)*10;
    x->annee=(s[7]-48)+(s[6]-48)*10 +2000;
}

cordo recherche(int a[100][100],int n,int m){
int i=1,j;
cordo z;
z.x=-1;
z.y=-1;
while(i<=n){
        j=1;
    while(j<=m){
        if(a[i][j]!=0){
                z.x=j;
                z.y=i;
            return z ;
        }else{j++;}
    }
    i++;
}
return z;
}

pile*initpile(pile *p){
return NULL;
}

int pilevide(pile *p){
if(p==NULL){return 1;}else{return 0;}
}

cordo sommetdepile(pile *p){
return p->info;
}

void empiler(pile **p, cordo x){
       pile *q;
       q=malloc(sizeof(*q));
       (q->info).x=x.x;
       (q->info).y=x.y;
       q->svt=*p;
       *p=q;
}

void empiler1(pile **p, int x){
       pile *q;
       q=malloc(sizeof(*q));
       (q->info).x=x;
       q->svt=*p;
       *p=q;
}

 void desempiler(pile **a,cordo *x){
     pile *q,*p;
     p=*a;
     (*x).x=(p->info).x;
     (*x).y=(p->info).y;
     q=p;
     p=p->svt;
     free(q);
     *a=p;
 }

 void empilertrie(pile **p,cordo z){
    pile *q=initpile(q);
    cordo a;
    while(!pilevide(*p) && sommetdepile(*p).x>z.x){
        desempiler(p,&a);
        empiler(&q,a);
    }
    empiler(p,z);
    while(!pilevide(q)){
        desempiler(&q,&a);
        empiler(p,a);
    }
}

void dessinpause(SDL_Surface *ecran,int game){
int a=0,b=0,i;
listewinner z;
FILE *fichier=NULL;
if(game==3){fichier=fopen("file/score/savepc.topscore","r");a=215;b=5;}else{fichier=fopen("file/score/save.topscore","r");}
fread(&z,sizeof(listewinner),1,fichier);
fclose(fichier);
TTF_Font *police = NULL;
SDL_Surface *texte=NULL;
SDL_Color chiffre1 = {0, 0,255 },chiffre2= {0, 0,0 },surf= {192,192,192},surf2= {192, 192, 192};
    SDL_Rect pos;
    char temp[50];
TTF_Init();
police = TTF_OpenFont("font/3.ttf", 20);
sprintf(temp, "NAME");
 texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf2);
pos.x=35+a;
 pos.y=315+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
 sprintf(temp, "SCORE");
 texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf2);
pos.x=130+a;
 pos.y=315+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
 sprintf(temp, "DATE");
 texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf2);
pos.x=220+a;
 pos.y=315+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
    for(i=1;i<=5;i++){
 sprintf(temp, "%d-%s",i,z.t[i].username);
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=35+a;
 pos.y=320+28*(i)+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
    }
    for(i=1;i<=5;i++){
 sprintf(temp, "%d",z.t[i].score);
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=140+a;
 pos.y=320+28*(i)+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
    }
     for(i=1;i<=5;i++){
 sprintf(temp, "%d/%d/%d",z.t[i].playdate.jour,z.t[i].playdate.mois,z.t[i].playdate.annee-2000);
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=220+a;
 pos.y=320+28*(i)+b;
 SDL_BlitSurface(texte, NULL, ecran, &pos);
    }
TTF_Quit();
}

int moh(int a[100][100],int n,int m ,int b[100][100],int l,int c,cordo s,pile **p){
int i,j,e,f;
cordo z,k;
*p=initpile(*p);
z=recherche(b,l,c);
i=z.y;
while(i<=l){
    j=1;
    while(j<=c){
        if(b[i][j]!=0){
         e=i-z.y+s.y;
         f=j-z.x+s.x;
         if(e<=n && f<=m){
            if(a[e][f]!=0){
                return 0;
            }else{
            k.x=f;k.y=e;           empiler(p,k);
            }
         }else{
         return 0;
         }
        }
        j++;
    }
    i++;
}
return 1;
}

int converte(int x,int cpt1,int cpt2,float y){

float c,d=cpt1;
int b;
	c=((x-cpt2)/d);
	b=((x-cpt2)/cpt1);
	if(( c-b )> y){
	 b++;
	}
	return b;
}

void initmatrice(int a[100][100],int n,int m,int val){
int i,j;
for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        a[i][j]=val;
    }
}
for(j=0;j<=m;j++){
        a[0][j]=1;
    }
for(i=0;i<=n;i++){
        a[i][0]=1;
    }
}

void rempliematrice(int k,int m[100][100]){
int i,j;
 const int    t[27][6][6]={
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//1

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,2,0,0},{0,0,0,2,0,0},{0,0,0,0,0,0}},//2
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,2,2,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//3

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,0,0},{0,0,0,3,0,0},{0,0,0,3,0,0},{0,0,0,0,0,0}},//4
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,3,3,3,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//5
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,3,0},{0,0,0,3,0,0},{0,0,0,0,0,0}},//6
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,0,0},{0,0,0,3,3,0},{0,0,0,0,0,0}},//7
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,3,0},{0,0,0,3,3,0},{0,0,0,0,0,0}},//8
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,3,0},{0,0,0,0,3,0},{0,0,0,0,0,0}},//9

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,4,0},{0,0,0,4,4,0},{0,0,0,0,0,0}},//10
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0}},//11
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,4,4,4,4},{0,0,0,0,0,0},{0,0,0,0,0,0}},//12
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,4,4,4,0},{0,0,0,0,0,0}},//13
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,4,4,0,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//14
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,4,4,4,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//15
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,0,4,4,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//16

                    {{0,0,0,0,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0}},//17
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,5,5,5,5,5},{0,0,0,0,0,0},{0,0,0,0,0,0}},//18
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,0,5,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//19
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,5,0,5,0},{0,0,0,0,0,0}},//20
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,0,0,5,0},{0,0,0,0,5,0},{0,0,0,0,0,0}},//21
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,5,0,0,0},{0,0,5,0,0,0},{0,0,0,0,0,0}},//22
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,0,0,0},{0,0,5,0,0,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//23
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,5,0},{0,0,0,0,5,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//24
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,5,5,0},{0,0,0,0,5,0},{0,0,0,5,5,0},{0,0,0,0,0,0}},//25
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,5,5,0},{0,0,0,5,0,0},{0,0,0,5,5,0},{0,0,0,0,0,0}},//26

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,6,6,6,0},{0,0,6,6,6,0},{0,0,6,6,6,0},{0,0,0,0,0,0}}};//27


for(i=1;i<=5;i++){
for(j=1;j<=5;j++){
m[i][j]=t[k][i][j];
}}
}

void dessinmatrice (SDL_Surface *ecran,int a,int u){
 SDL_Surface *ligne=NULL,*col=NULL,*high=NULL,*highscore=NULL,*currentscore=NULL,*pause=NULL;
SDL_Rect pos;
int i,z=0,b=0,c=255,depl=0;
if(a==3){z=430;c=0;b=255;}
    ligne=SDL_CreateRGBSurface(SDL_HWSURFACE,322,2,32,0,0,0,0);
    SDL_FillRect(ligne, NULL, SDL_MapRGB(ecran->format, b, 0,c));
   col=SDL_CreateRGBSurface(SDL_HWSURFACE,2,320,32,0,0,0,0);
    SDL_FillRect(col, NULL, SDL_MapRGB(ecran->format, b, 0,c));
    high=SDL_LoadBMP("file/images/others/high.bmp");
pause=SDL_LoadBMP("file/images/others/pause.bmp");
highscore=SDL_LoadBMP("file/images/others/highscore.bmp");
currentscore=SDL_LoadBMP("file/images/others/currentscore.bmp");
if(a==2){
     pause=SDL_LoadBMP("file/images/others/replay2.bmp");
high=SDL_LoadBMP("file/images/others/home2.bmp");
depl=10;
}
if(a!=3 && u==1){
pos.x=150;
pos.y=15;
SDL_BlitSurface(high, NULL, ecran, &pos);
pos.x=259;
pos.y=25-depl;
SDL_BlitSurface(pause, NULL, ecran, &pos);
}
if(u==0){
    pos.x=345;
pos.y=32*1+70;
SDL_BlitSurface(high, NULL, ecran, &pos);
pos.x=355;
pos.y=32*5+70;
SDL_BlitSurface(pause, NULL, ecran, &pos);
}
    for(i=4;i<=325;i=i+32){
            pos.x=i+z;pos.y=100;
        SDL_BlitSurface(col, NULL, ecran, &pos);
    }
    for(i=100;i<=420;i=i+32){
            pos.x=4+z;pos.y=i;
        SDL_BlitSurface(ligne, NULL, ecran, &pos);
    }
}

void dessinblock(int m[100][100],int trans,int x,SDL_Surface *image,SDL_Surface *image0, SDL_Surface *ecran){
SDL_Rect pos;
int i,j;
for(i=1;i<=5;i++){
    for(j=1;j<=5;j++){
            pos.x=17*j+x;
pos.y=17*i+452;
SDL_BlitSurface(image0, NULL, ecran, &pos);
        if(m[i][j]!=0){
 SDL_SetAlpha(image, SDL_SRCALPHA, trans);
SDL_BlitSurface(image, NULL, ecran, &pos);
        }
    }
}
}

SDL_Surface *couleurimage(SDL_Surface *image,int x){
switch(x){
case 1:image=SDL_LoadBMP("file/images/block/1.1.bmp");
break;
case 2:image=SDL_LoadBMP("file/images/block/2.1.bmp");
break;
case 3:image=SDL_LoadBMP("file/images/block/3.1.bmp");
break;
case 4:image=SDL_LoadBMP("file/images/block/4.1.bmp");
break;
case 5:image=SDL_LoadBMP("file/images/block/5.1.bmp");
break;
case 6:image=SDL_LoadBMP("file/images/block/6.1.bmp");
break;
}
return image;
}

SDL_Surface *couleurimage2(SDL_Surface *image,int x){
switch(x){
case 1:image=SDL_LoadBMP("file/images/block/1.2.bmp");
break;
case 2:image=SDL_LoadBMP("file/images/block/2.2.bmp");
break;
case 3:image=SDL_LoadBMP("file/images/block/3.2.bmp");
break;
case 4:image=SDL_LoadBMP("file/images/block/4.2.bmp");
break;
case 5:image=SDL_LoadBMP("file/images/block/5.2.bmp");
break;
case 6:image=SDL_LoadBMP("file/images/block/6.2.bmp");
break;
}
return image;
}

void eliminerligne_et_col(int a[100][100],SDL_Surface *init, SDL_Surface *ecran,int *score){
pile *r=initpile(r),*q=initpile(q),*r1=initpile(r1),*q1=initpile(q1);
SDL_Surface *blanc=NULL;
int i,j,cpt1,cpt2,cpt0=0,bonus;
SDL_Rect pos;
cordo e,v;
blanc=SDL_CreateRGBSurface(SDL_HWSURFACE,30,30,32,0,0,0,0);
    SDL_FillRect(blanc, NULL, SDL_MapRGB(blanc->format, 255, 255,255));
for(i=1;i<=10;i++){
    cpt1=0;cpt2=0;
   for(j=1;j<=10;j++){
        if(a[i][j]==0){cpt1++;}
        if(a[j][i]==0){cpt2++;}
    }
    if(cpt2==0){
            e.x=i;
        empiler(&q,e);
    }
    if(cpt1==0){
        v.x=i;
        empiler(&r,v);
    }

}
while(pilevide(q)==0){
    desempiler(&q,&v);
    empiler(&q1,v);
    cpt0++;
    for(j=1;j<=10;j++){
        pos.y=j*32+70;
        pos.x=v.x*32-26;
        SDL_BlitSurface(blanc, NULL, ecran, &pos);
    }
}
while(pilevide(r)==0){
    desempiler(&r,&v);
    empiler(&r1,v);
    cpt0++;
    for(j=1;j<=10;j++){
        pos.y=v.x*32+70;
        pos.x=j*32-26;
        SDL_BlitSurface(blanc, NULL, ecran, &pos);
    }
}
SDL_Flip(ecran);
if(verifier2(a)>0){SDL_Delay(500);}
while(pilevide(q1)==0){
    desempiler(&q1,&v);
    for(j=1;j<=10;j++){
        a[j][v.x]=0;
        pos.y=j*32+70;
        pos.x=v.x*32-26;
        SDL_BlitSurface(init, NULL, ecran, &pos);
    }
}
while(pilevide(r1)==0){
    desempiler(&r1,&v);
    for(j=1;j<=10;j++){
        a[v.x][j]=0;
        pos.y=v.x*32+70;
        pos.x=j*32-26;
        SDL_BlitSurface(init, NULL, ecran, &pos);
    }
}
bonus=0;
for(i=1;i<cpt0;i++){
    bonus=bonus+100*i;
}
bonus=bonus+cpt0*100;
*score=*score+bonus;
}

void colorergrille(int a[100][100],int x,char y,SDL_Surface *init,SDL_Surface *ecran){
SDL_Rect pos;
SDL_Surface *image=NULL;
int z=0,i,j;
if(x==3){z=430;}
if(y=='n'){
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
                 pos.x=32*j-26+z;
       pos.y=32*i+70;
if(a[i][j]==0){
            SDL_BlitSurface(init, NULL, ecran, &pos);
            }
        }
}
}else{
for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
                 pos.x=32*j-26+z;
       pos.y=32*i+70;
if(a[i][j]!=0){
switch(a[i][j]){
case 1:image=SDL_LoadBMP("file/images/block/1.2.bmp");
break;
case 2:image=SDL_LoadBMP("file/images/block/2.2.bmp");
break;
case 3:image=SDL_LoadBMP("file/images/block/3.2.bmp");
break;
case 4:image=SDL_LoadBMP("file/images/block/4.2.bmp");
break;
case 5:image=SDL_LoadBMP("file/images/block/5.2.bmp");
break;
case 6:image=SDL_LoadBMP("file/images/block/6.2.bmp");
break;
}
            SDL_BlitSurface(image, NULL, ecran, &pos);
        }
        }
}
}
}

void eliminerligne_et_col_pc(int a[100][100], SDL_Surface *ecran,int b){
pile *r=initpile(r);
pile *q=initpile(q);
int i,j,cpt1,cpt2,cpt0=0,z=0;
SDL_Rect pos;
cordo e,v;
SDL_Surface *init=NULL;
init=SDL_CreateRGBSurface(SDL_HWSURFACE,30,30,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 255, 255,255));
if(b==3){z=430;}
for(i=1;i<=10;i++){
    cpt1=0;cpt2=0;
   for(j=1;j<=10;j++){
        if(a[i][j]==0){cpt1++;}
        if(a[j][i]==0){cpt2++;}
    }
    if(cpt2==0){
            e.x=i;
        empiler(&q,e);
    }
    if(cpt1==0){
        v.x=i;
        empiler(&r,v);
    }
}
while(pilevide(q)==0){
    desempiler(&q,&v);
    cpt0++;
    for(j=1;j<=10;j++){
        pos.y=j*32+70;
        pos.x=v.x*32-26+z;
        SDL_BlitSurface(init, NULL, ecran, &pos);
    }
}
while(pilevide(r)==0){
    desempiler(&r,&v);
    cpt0++;
    for(j=1;j<=10;j++){
        pos.y=v.x*32+70;
        pos.x=j*32-26+z;
        SDL_BlitSurface(init, NULL, ecran, &pos);
    }
}
}

void pausemenu(SDL_Surface *ecran,int game){
   SDL_Surface *save=NULL,*replay=NULL,*continuegame=NULL,*pausescreen=NULL,*home=NULL;
   SDL_Rect pos;
   int a=0,b=0;
   if(game==3){a=215;b=5;}
pausescreen=SDL_LoadBMP("file/images/others/pausescreen.bmp");
save=SDL_LoadBMP("file/images/others/save.bmp");
replay=SDL_LoadBMP("file/images/others/replay.bmp");
continuegame=SDL_LoadBMP("file/images/others/continuegame.bmp");
home=SDL_LoadBMP("file/images/others/home.bmp");
pos.x=15+a;
pos.y=110+b;
SDL_BlitSurface(pausescreen, NULL, ecran, &pos);
pos.x=12+15+a;
pos.y=225+b;
SDL_BlitSurface(save, NULL, ecran, &pos);
pos.x=84+15+a;
pos.y=225+b;
SDL_BlitSurface(home, NULL, ecran, &pos);
pos.x=156+15+a;
pos.y=225+b;
SDL_BlitSurface(continuegame, NULL, ecran, &pos);
pos.x=228+15+a;
pos.y=225+b;
SDL_BlitSurface(replay, NULL, ecran, &pos);
}

void ecrire(SDL_Surface *ecran,int v){
SDL_Surface *texte=NULL;
TTF_Font *police=NULL,*police1=NULL,*police2=NULL;
 char temp[50],temp1[100];
  int z=0;
 TTF_Init();
police = TTF_OpenFont("font/3.ttf", 25);
police1= TTF_OpenFont("font/3.ttf", 30);
police2= TTF_OpenFont("font/face2.ttf", 50);
if(v!=1){
sprintf(temp, "Congratulations");
sprintf(temp1, " You made it to the top 5");
}else{
    z=40;
sprintf(temp, "Wonderful");
sprintf(temp1, "You got the highest score");
    }
  SDL_Rect pos;
  SDL_Color surf= {192, 192, 192};
  SDL_Color chiffre3 = {255, 150,15 },chiffre4 = {163, 73,164 },chiffre5 = {34, 177,76 },chiffre6 = {0, 162,232 };
  pos.x=45+z;
  pos.y=300;
  texte = TTF_RenderText_Shaded(police1, temp, chiffre3,surf);
      SDL_BlitSurface(texte, NULL, ecran, &pos);
      pos.x=12;
  pos.y=350;
  texte = TTF_RenderText_Shaded(police, temp1, chiffre5,surf);
      SDL_BlitSurface(texte, NULL, ecran, &pos);
      sprintf(temp1, "m");
          pos.x=0;
  pos.y=310;
  texte = TTF_RenderText_Shaded(police2, temp1, chiffre4,surf);
      SDL_BlitSurface(texte, NULL, ecran, &pos);
pos.x=290;
  pos.y=310;
SDL_BlitSurface(texte, NULL, ecran, &pos);
police2= TTF_OpenFont("font/face2.ttf", 100);
sprintf(temp1, "& L");
 texte = TTF_RenderText_Shaded(police2, temp1, chiffre6,surf);
pos.x=70;
  pos.y=400;
SDL_BlitSurface(texte, NULL, ecran, &pos);
TTF_Quit();
}

void calscore(int score ,int *meilleur,SDL_Surface *ecran,int a,int game){
TTF_Font *police = NULL,*police1=NULL;
SDL_Surface *texte=NULL;
int z=0,dpl=0,c=0,b1=0,b2=0,b3=0,b4=0,b5=0,c1=0;
SDL_Color chiffre1 = {255, 255,255 },chiffre2= {255, 201,14 },surf= {0, 0, 0};
    SDL_Rect pos;
    char temp[50],temp2[50];
        if(score > (*meilleur)){
            (*meilleur)=score;
        }
TTF_Init();
police = TTF_OpenFont("font/comicbd.ttf", 20);
  sprintf(temp, "%d",(*meilleur));
sprintf(temp2, "%d",score);
if(game==3){police = TTF_OpenFont("font/comicbd.ttf", 50);police1 = TTF_OpenFont("font/comicbd.ttf", 20);c1=50;c=32*3-26;b1=326;b2=0;b3=-15;b4=-25;b5=-5;}
if(a==3){z=430;}
if(a==2){police = TTF_OpenFont("font/comicbd.ttf", 30);dpl=-5;}
if(a==1){
     pos.x=20+b1;
     pos.y=10+b2+c1;
     if(game==3){texte = TTF_RenderText_Shaded(police1, temp, chiffre2,surf);}else{texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);}
      SDL_BlitSurface(texte, NULL, ecran, &pos);
      texte = TTF_RenderText_Shaded(police, temp2, chiffre1,surf);
      pos.x=20+c;
     pos.y=50+b2+b3+b4;
  SDL_BlitSurface(texte, NULL, ecran, &pos);
}else{
texte = TTF_RenderText_Shaded(police, temp2, chiffre1,surf);
      pos.x=20+z+c;
     pos.y=30+dpl+b2+b3+b5;
  SDL_BlitSurface(texte, NULL, ecran, &pos);
}
TTF_Quit();
}

void affscorepause(int score ,int meilleur ,SDL_Surface *ecran,int game){
TTF_Font *police = NULL;
SDL_Surface *texte=NULL;
SDL_Color chiffre1 = {0, 0,0 },chiffre2= {255, 150,15 },surf= {192, 192, 192};
    SDL_Rect pos;
int a=0,b=0;
if(game==3){a=215;b=5;}
char temp[50],temp2[50];
TTF_Init();
police = TTF_OpenFont("font/3.ttf", 35);
sprintf(temp, "best:%d",meilleur);sprintf(temp2, "score:%d",score);
pos.x=25+a;pos.y=113+b;
texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);SDL_BlitSurface(texte, NULL, ecran, &pos);
texte = TTF_RenderText_Shaded(police, temp2, chiffre1,surf);
pos.x=25+a;pos.y=165+b;SDL_BlitSurface(texte, NULL, ecran, &pos);
TTF_Quit();
}

void essie(char ch[20],SDL_Surface *ecran,int k,int v){
TTF_Font *police = NULL;
SDL_Surface *texte=NULL,*image=NULL;
SDL_Rect pos2,pos;
SDL_Color chiffre1 = {0, 0,128 },chiffre2= {255, 0,0 },surf= {192, 192,192};
int j;
  image=SDL_LoadBMP("file/images/others/400.bmp");
    pos2.x=0;pos2.y=0;SDL_BlitSurface(image, NULL, ecran, &pos2);
char temp[50],sch[20]="";
for(j=0;j<k;j++){sch[j]=ch[j];}
ecrire(ecran,v);
TTF_Init();
police = TTF_OpenFont("font/3.ttf", 30);
  sprintf(temp, "Set your name");
  texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=60;pos.y=490;SDL_BlitSurface(texte, NULL, ecran, &pos);
sprintf(temp, "Username:%s",sch);
texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf);
 pos.x=60;pos.y=550;SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);
TTF_Quit();
}

void name(SDL_Surface *ecran,char fch[20],int v){

SDL_Event event;
int continuer=1,j,i,frg=4;
char ch[50]="";
i=0;
   while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
        case SDLK_q:if(i<frg){ch[i]='a';i++;}
        break;
           case SDLK_b:if(i<frg){ch[i]='b';i++;}
        break;
           case SDLK_c:if(i<frg){ch[i]='c';i++;}
        break;
           case SDLK_d:if(i<frg){ch[i]='d';i++;}
        break;
           case SDLK_e:if(i<frg){ch[i]='e';i++;}
        break;
            case SDLK_f:if(i<frg){ch[i]='f';i++;}
        break;
            case SDLK_g:if(i<frg){ch[i]='g';i++;}
        break;
            case SDLK_h:if(i<frg){ch[i]='h';i++;}
        break;
            case SDLK_i:if(i<frg){ch[i]='i';i++;}
        break;
            case SDLK_j:if(i<frg){ch[i]='j';i++;}
        break;
            case SDLK_k:if(i<frg){ch[i]='k';i++;}
        break;
            case SDLK_l:if(i<frg){ch[i]='l';i++;}
        break;
            case SDLK_SEMICOLON:if(i<frg){ch[i]='m';i++;}
        break;
            case SDLK_n:if(i<frg){ch[i]='n';i++;}
        break;
            case SDLK_o:if(i<frg){ch[i]='o';i++;}
        break;
            case SDLK_p:if(i<frg){ch[i]='p';i++;}
        break;
            case SDLK_a:if(i<frg){ch[i]='q';i++;}
        break;
            case SDLK_r:if(i<frg){ch[i]='r';i++;}
        break;
            case SDLK_s:if(i<frg){ch[i]='s';i++;}
        break;
            case SDLK_t:if(i<frg){ch[i]='t';i++;}
        break;
        case SDLK_u:if(i<frg){ch[i]='u';i++;}
        break;
        case SDLK_v:if(i<frg){ch[i]='v';i++;}
        break;
        case SDLK_z:if(i<frg){ch[i]='w';i++;}
        break;
        case SDLK_x:if(i<frg){ch[i]='x';i++;}
        break;
        case SDLK_y:if(i<frg){ch[i]='y';i++;}
        break;
        case SDLK_w:if(i<frg){ch[i]='z';i++;}
        break;
        case SDLK_SPACE:if(i<frg){ch[i]=32;i++;}
        break;

        case SDLK_KP0:if(i<frg){ch[i]='0';i++;}
        break;
        case SDLK_KP1:if(i<frg){ch[i]='1';i++;}
        break;
         case SDLK_KP2:if(i<frg){ch[i]='2';i++;}
        break;
        case SDLK_KP3:if(i<frg){ch[i]='3';i++;}
        break;
        case SDLK_KP4:if(i<frg){ch[i]='4';i++;}
        break;
        case SDLK_KP5:if(i<frg){ch[i]='5';i++;}
        break;
        case SDLK_KP6:if(i<frg){ch[i]='6';i++;}
        break;
        case SDLK_KP7:if(i<frg){ch[i]='7';i++;}
        break;
        case SDLK_KP8:if(i<frg){ch[i]='8';i++;}
        break;
        case SDLK_KP9:if(i<frg){ch[i]='9';i++;}
        break;
        case SDLK_BACKSPACE:

        if(i!=0){i--;}
break;

        case SDLK_RETURN:continuer=0;
        break;
        }
        break;
                }
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 192, 192, 192));
essie(ch,ecran,i,v);
SDL_Flip(ecran);
   }
for(j=0;j<i;j++){fch[j]=ch[j];}
fch[i]='\0';
    }

void savingpile(pile *p,int y){
FILE *fichier=NULL;
cordo z;
int k;
pile *q=initpile(q);
if(y==1){fichier=fopen("file/pile/savepile1.txt","w");}
if(y==2){fichier=fopen("file/pile/savepile2.txt","w");}
if(y==3){fichier=fopen("file/pile/savepile3.txt","w");}
if(y==4){fichier=fopen("file/pile/savepile4.txt","w");}
if(y==5){fichier=fopen("file/pile/savepile5.txt","w");}
if(y==6){fichier=fopen("file/pile/savepile6.txt","w");}
while(!pilevide(p)){desempiler(&p,&z);empiler(&q,z);}
while(!pilevide(q)){desempiler(&q,&z);empiler(&p,z);k=z.x+65;fwrite(&k,1,1,fichier);}
fclose(fichier);
}
void retournepile(pile **p,int y){
FILE *fichier=NULL;
cordo z;
char k;
 (*p)=initpile(*p);
if(y==1){fichier=fopen("file/pile/savepile1.txt","r");}
if(y==2){fichier=fopen("file/pile/savepile2.txt","r");}
if(y==3){fichier=fopen("file/pile/savepile3.txt","r");}
if(y==4){fichier=fopen("file/pile/savepile4.txt","r");}
if(y==5){fichier=fopen("file/pile/savepile5.txt","r");}
if(y==6){fichier=fopen("file/pile/savepile6.txt","r");}

fread(&k,1,1,fichier);
while(!feof(fichier)){z.x=k-65;empiler(p,z);fread(&k,1,1,fichier);}
fclose(fichier);

}

int detec(int b[100][100]){
int i,j,k,cpt,v;
v=-5;
 const int    t[27][6][6]={
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//1

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,2,0,0},{0,0,0,2,0,0},{0,0,0,0,0,0}},//2
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,2,2,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//3

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,0,0},{0,0,0,3,0,0},{0,0,0,3,0,0},{0,0,0,0,0,0}},//4
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,3,3,3,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},//5
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,3,0},{0,0,0,3,0,0},{0,0,0,0,0,0}},//6
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,0,0},{0,0,0,3,3,0},{0,0,0,0,0,0}},//7
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,3,0},{0,0,0,3,3,0},{0,0,0,0,0,0}},//8
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,3,3,0},{0,0,0,0,3,0},{0,0,0,0,0,0}},//9

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,4,0},{0,0,0,4,4,0},{0,0,0,0,0,0}},//10
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0},{0,0,0,4,0,0}},//11
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,4,4,4,4},{0,0,0,0,0,0},{0,0,0,0,0,0}},//12
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,4,4,4,0},{0,0,0,0,0,0}},//13
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,4,4,0,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//14
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,4,4,4,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//15
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,4,0,0},{0,0,0,4,4,0},{0,0,0,4,0,0},{0,0,0,0,0,0}},//16

                    {{0,0,0,0,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0},{0,0,0,5,0,0}},//17
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,5,5,5,5,5},{0,0,0,0,0,0},{0,0,0,0,0,0}},//18
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,0,5,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//19
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,5,0,5,0},{0,0,0,0,0,0}},//20
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,0,0,5,0},{0,0,0,0,5,0},{0,0,0,0,0,0}},//21
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,5,5,0},{0,0,5,0,0,0},{0,0,5,0,0,0},{0,0,0,0,0,0}},//22
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,5,0,0,0},{0,0,5,0,0,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//23
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,5,0},{0,0,0,0,5,0},{0,0,5,5,5,0},{0,0,0,0,0,0}},//24
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,5,5,0},{0,0,0,0,5,0},{0,0,0,5,5,0},{0,0,0,0,0,0}},//25
                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,5,5,0},{0,0,0,5,0,0},{0,0,0,5,5,0},{0,0,0,0,0,0}},//26

                    {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,6,6,6,0},{0,0,6,6,6,0},{0,0,6,6,6,0},{0,0,0,0,0,0}}};//27


for(k=0;k<27;k++){
        cpt=0;
for(i=1;i<=5;i++) {
    for(j=1;j<=5;j++){
            if(b[i][j]==t[k][i][j]){
              cpt++;
            }


    }
}

if(cpt==25){
return k;
}
}
return -5;
}

void eliminer(SDL_Surface *ecran,int a[100][100],int *score,int nb,int l,int f,int b,int k){
SDL_Surface *init=NULL,*image=NULL,*imagep=NULL,*init0=NULL;
init=SDL_CreateRGBSurface(SDL_HWSURFACE,30,30,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 0, 0,0));
init0=SDL_CreateRGBSurface(SDL_HWSURFACE,15,15,32,0,0,0,0);
    SDL_FillRect(init0, NULL, SDL_MapRGB(init0->format, 0, 0,0));

int meilleur=0,abc=500,c[100][100],cp[100][100];
    rempliematrice(f,c);image=couleurimage(image,nombre(c));
rempliematrice(k,cp);imagep=couleurimage(imagep,nombre(cp));
dessinblock(cp,120,b,imagep,init0,ecran);SDL_Flip(ecran);
SDL_Delay(abc);
colorergrille(a,nb,'c',init,ecran);calscore((*score),&meilleur,ecran,nb,nb);SDL_Flip(ecran);
SDL_Delay(abc);
if(verifier2(a)>0){eliminerligne_et_col_pc(a,ecran,nb);SDL_Flip(ecran);SDL_Delay(abc);}
ligne_et_col(a,score);calscore((*score),&meilleur,ecran,nb,nb);
colorergrille(a,nb,'n',init,ecran);dessinblock(c,255,b,image,init0,ecran);SDL_Flip(ecran);
}

void mtab(int M[100][100],int x,int y,int t[200]){
	int i,j,k1,k2;
		for(i=1;i<=x;i++){k1=y*(i-1);
		       for(j=1;j<=y;j++){k2=k1+j;t[k2]=M[i][j];
			   }
}
 }

void savematrice(int m[100][100],int p){
    FILE *fichier=NULL;
   int x,y,t[200],k,i;
y=25;x=5;
if(p==11){fichier=fopen("file/matrice/savea.txt","w");x=10;}
if(p==13){fichier=fopen("file/matrice/savea1.txt","w");x=10;}
if(p==21){fichier=fopen("file/matrice/saveb.txt","w");}
if(p==23){fichier=fopen("file/matrice/saveb1.txt","w");}
if(p==31){fichier=fopen("file/matrice/savec.txt","w");}
if(p==33){fichier=fopen("file/matrice/savec1.txt","w");}
if(p==41){fichier=fopen("file/matrice/saved.txt","w");}
if(p==43){fichier=fopen("file/matrice/saved1.txt","w");}
if(p==5){fichier=fopen("file/matrice/savepc.txt","w");x=10;}
 if(x==10){y=100;}
 mtab(m,x,x,t);
 for(i=1;i<=y;i++){k=t[i]+65;fwrite(&k,1,1,fichier);}
     fclose(fichier);
}

void returnermatrice(int m[100][100],int p){
    FILE *fichier=NULL;
   int i,j,x;
    char k;
x=5;
if(p==11){fichier=fopen("file/matrice/savea.txt","r"); x=10;}
if(p==13){fichier=fopen("file/matrice/savea1.txt","r"); x=10;}
if(p==21){fichier=fopen("file/matrice/saveb.txt","r");}
if(p==23){fichier=fopen("file/matrice/saveb1.txt","r");}
if(p==31){fichier=fopen("file/matrice/savec.txt","r");}
if(p==33){fichier=fopen("file/matrice/savec1.txt","r");}
if(p==41){fichier=fopen("file/matrice/saved.txt","r");}
if(p==43){fichier=fopen("file/matrice/saved1.txt","r");}
if(p==5){fichier=fopen("file/matrice/savepc.txt","r");x=10;}
 initmatrice(m,x,x,0);
 for(i=1;i<=x;i++){for(j=1;j<=x;j++){fread(&k,1,1,fichier);m[i][j]=k-65;}}
}

void jeux(int game){
    int pc=0;
    if(game==3){pc=430;}
    int a[100][100],b[100][100],c[100][100],d[100][100],apc[100][100],jh[100][100];
    int continuer=1,vr=0,vb=1,vc=1,vd=1,vp=1,verpc=1,vs=15;
    int i=0,j=0,vgo=0,kd,kb,kc,vmoh,w,score=0,scorepc=0,meilleur=50,n1,n2,n3=0,n4=0;
    readsavebool(&vs,game);
    if(game==3){returnermatrice(a,13);}else{returnermatrice(a,11);}
    if(game==3){returnermatrice(b,23);}else{returnermatrice(b,21);}
    if(game==3){returnermatrice(c,33);}else{returnermatrice(c,31);}
    if(game==3){returnermatrice(d,43);}else{returnermatrice(d,41);}
    if(game==3){retournerscore(&score,&meilleur,8);}else{retournerscore(&score,&meilleur,1);}
    if(game==3){retournerscore(&scorepc,&meilleur,3);returnermatrice(apc,5);}
    cordo z,s,e,h,x,y,ef;
    srand(time(NULL));
pile *p,*pred=initpile(pred),*nop,*f1=initpile(f1),*f2=initpile(f2),*f3=initpile(f3),*p3=initpile(p3),*p1=initpile(p1),*p2=initpile(p2);
if(vs==1){retournepile(&p1,1);retournepile(&p2,2);retournepile(&p3,3);retournepile(&f1,4);retournepile(&f2,5);retournepile(&f3,6);}
if(vs==0){initpiles(&f1,&f2,&f3,&p1,&p2,&p3);}
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(330+pc,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetIcon(SDL_LoadBMP("file/images/others/7.bmp"),NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_WM_SetCaption("block puzzle", NULL);
    SDL_Surface *imagea=NULL,*init=NULL,*init2=NULL,*ecran2=NULL,*save=NULL,*save0=NULL,*imaged=NULL,*image0=NULL,*image=NULL,*imagec=NULL,*imageb=NULL;
    SDL_Rect posb,posc,posgr,pos;
    SDL_Event event,event2;
     save=SDL_LoadBMP("file/images/others/save.bmp");
    image0=SDL_CreateRGBSurface(SDL_HWSURFACE,15,15,32,0,0,0,0);
    SDL_FillRect(image0, NULL, SDL_MapRGB(image0->format, 0, 0,0));
    init=SDL_CreateRGBSurface(SDL_HWSURFACE,30,30,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 0, 0,0));
init2=SDL_CreateRGBSurface(SDL_HWSURFACE,15,15,32,0,0,0,0);
    SDL_FillRect(init2, NULL, SDL_MapRGB(init2->format, 192, 192,192));
save0=SDL_CreateRGBSurface(SDL_HWSURFACE,60,60,32,0,0,0,0);
    SDL_FillRect(save0, NULL, SDL_MapRGB(save0->format, 192, 192,192));
ecran2=SDL_CreateRGBSurface(SDL_HWSURFACE,330,630,32,0,0,0,0);
    SDL_FillRect(ecran2, NULL, SDL_MapRGB(ecran2->format, 192, 192, 192));
    if(game==3){dessinmatrice(ecran,1,0);}else{dessinmatrice(ecran,1,1);}
if(game==3){dessinmatrice(ecran,3,1);rempliematrice(sommetdepile(p1).x,jh);image=couleurimage(image,nombre(jh));
dessinblock(jh,255,4+430,image,image0,ecran);rempliematrice(sommetdepile(p2).x,jh);image=couleurimage(image,nombre(jh));dessinblock(jh,255,106+430,image,image0,ecran);
rempliematrice(sommetdepile(p3).x,jh);image=couleurimage(image,nombre(jh));dessinblock(jh,255,208+430,image,image0,ecran);
calscore(scorepc,&meilleur,ecran,3,game);SDL_Flip(ecran);}
kb=detec(b);if(kb==-5){desempiler(&f1,&ef);kb=ef.x;rempliematrice(kb,b);}
kc=detec(c);if(kc==-5){desempiler(&f2,&ef);kc=ef.x;rempliematrice(kc,c);}
kd=detec(d);if(kd==-5){desempiler(&f3,&ef);kd=ef.x;rempliematrice(kd,d);}
imageb=couleurimage(imageb,nombre(b));imagec=couleurimage(imagec,nombre(c));imaged=couleurimage(imaged,nombre(d));
colorergrille(a,1,'c',init,ecran);colorergrille(apc,3,'c',init,ecran);
dessinblock(c,255,106,imagec,image0, ecran);dessinblock(b,255,4,imageb,image0, ecran);dessinblock(d,255,208,imaged,image0, ecran);
calscore(score,&meilleur,ecran,1,game);
existepos(ecran,imageb,image0,a,b,&vb,4);existepos(ecran,imagec,image0,a,c,&vc,106);existepos(ecran,imaged,image0,a,d,&vd,208);
while(continuer){
if(vp==1){
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:continuer=0;
        break;
        case SDL_MOUSEBUTTONDOWN:
vr=0;y.x=event.button.x;y.y=event.button.y;n1=259;n2=25;
if(game==3){n1=355;n2=32*5+70;}
z.x=converte(y.x,17,4,0.88);z.y=converte(y.y,17,452,0.88);
if(z.x>=1 && z.x<=5 && z.y<=5 && z.y >=1 ){
if(b[z.y][z.x]!=0 && vb!=0){vr=1;vmoh=10;dessinblock(b,120,4,imageb,image0, ecran);}
}else{
if(z.x>=7 && z.x<=11 && z.y<=5 && z.y >=1){
if(c[z.y][z.x-6]!=0 &&  vc!=0){
vr=2;vmoh=10;dessinblock(c,120,106,imagec,image0, ecran);}
}else{
if(z.x>=13 && z.x<=17 && z.y<=5 && z.y >=1){
if(d[z.y][z.x-12]!=0 && vd!=0){vr=3;vmoh=10;dessinblock(d,120,208,imaged,image0, ecran);}
}}}
if(y.x>n1 && y.x<n1+60 && y.y >n2 && y.y<n2+60 ){
pausemenu(ecran,game);affscorepause( score ,meilleur,ecran,game);dessinpause(ecran,game);vp=0;}
break;


          case SDL_MOUSEBUTTONUP:
vmoh=0;
if(vr==1){
    if(event.button.y <420-(30)/2 && event.button.x <325-(30)/2 && event.button.y > 100){
s.x= converte(event.button.x,32,-26,0.5);s.y=converte(event.button.y,32,70,0.5);
w=moh(a,10,10,b,5,5,s,&p);
if(w==1){
imagea=couleurimage2(imagea,nombre(b));
while(pilevide(p)==0){desempiler(&p,&h);a[h.y][h.x]=nombre(b);score=score+10;
posgr.x=h.x*32-26;posgr.y=h.y*32+70;SDL_BlitSurface(imagea, NULL, ecran, &posgr);}
pred=initpile(pred);
eliminerligne_et_col(a,init, ecran,&score);calscore(score,&meilleur,ecran,1,game);
desempiler(&f1,&ef);kb=ef.x;rempliematrice(kb,b);imageb=couleurimage(imageb,nombre(b));dessinblock(b,255,4,imageb,image0, ecran);
existepos(ecran,imageb,image0,a,b,&vb,4);existepos(ecran,imagec,image0,a,c,&vc,106);existepos(ecran,imaged,image0,a,d,&vd,208);
pcplayone(apc,ecran,&p1,&p2,&p3,&verpc,&scorepc,game,kb);SDL_Flip(ecran);
}else{
dessinblock(b,255,4,imageb,image0, ecran);
}
        }else{
 dessinblock(b,255,4,imageb,image0, ecran);
}

}
if(vr==2){
    if(event.button.y <420-(30)/2 && event.button.x <325-(30)/2 && event.button.y > 100){
         s.x= converte(event.button.x,32,-26,0.5);s.y=converte(event.button.y,32,70,0.5);
            w=moh(a,10,10,c,5,5,s,&p);
if(w==1){
imagea=couleurimage2(imagea,nombre(c));
while(pilevide(p)==0){desempiler(&p,&h);a[h.y][h.x]=nombre(c);score=score+10;
posgr.x=h.x*32-26;posgr.y=h.y*32+70;SDL_BlitSurface(imagea, NULL, ecran, &posgr);}
pred=initpile(pred);
eliminerligne_et_col(a,init, ecran,&score);calscore(score,&meilleur,ecran,1,game);
desempiler(&f2,&ef);kc=ef.x;rempliematrice(kc,c);imagec=couleurimage(imagec,nombre(c));dessinblock(c,255,106,imagec,image0, ecran);
existepos(ecran,imageb,image0,a,b,&vb,4);existepos(ecran,imagec,image0,a,c,&vc,106);existepos(ecran,imaged,image0,a,d,&vd,208);
pcplayone(apc,ecran,&p1,&p2,&p3,&verpc,&scorepc,game,kc);
}else{
dessinblock(c,255,106,imagec,image0, ecran);
}
        }else{
 dessinblock(c,255,106,imagec,image0, ecran);
}

}
if(vr==3){
    if(event.button.y <420-(30)/2 && event.button.x <325-(30)/2 && event.button.y > 100){
         s.x= converte(event.button.x,32,-26,0.5);s.y=converte(event.button.y,32,70,0.5);
         w=moh(a,10,10,d,5,5,s,&p);
if(w==1){
imagea=couleurimage2(imagea,nombre(d));
while(pilevide(p)==0){desempiler(&p,&h);a[h.y][h.x]=nombre(d);score=score+10;
posgr.x=h.x*32-26;posgr.y=h.y*32+70;SDL_BlitSurface(imagea, NULL, ecran, &posgr);}
pred=initpile(pred);
eliminerligne_et_col(a,init, ecran,&score);calscore(score,&meilleur,ecran,1,game);
desempiler(&f3,&ef);kd=ef.x;rempliematrice(kd,d);imaged=couleurimage(imaged,nombre(d));dessinblock(d,255,208,imaged,image0, ecran);
existepos(ecran,imageb,image0,a,b,&vb,4);existepos(ecran,imagec,image0,a,c,&vc,106);existepos(ecran,imaged,image0,a,d,&vd,208);
pcplayone(apc,ecran,&p1,&p2,&p3,&verpc,&scorepc,game,kd);
}else{
dessinblock(d,255,208,imaged,image0, ecran);
}
        }else{
 dessinblock(d,255,208,imaged,image0, ecran);
}

}
        break;

          case SDL_MOUSEMOTION:
              if(event.button.y <420 && event.button.x <325 && event.button.x >4 && event.button.y > 100){
x.x= converte(event.button.x,32,-26,0.5);x.y=converte(event.button.y,32,70,0.5);

               if(vmoh==10){
               if(a[x.y][x.x]==0 ){
while(pilevide(pred)==0){desempiler(&pred,&e);posgr.x=e.x*32-26;posgr.y=e.y*32+70;SDL_BlitSurface(init, NULL, ecran, &posgr);}
posb.x= x.x*32-26;posb.y=x.y*32+70;
z.x=converte(posb.x,32,-26,0.5);z.y=converte(posb.y,32,70,0.5);
if(vr==1){i=moh(a,10,10,b,5,5,z,&nop);  image=couleurimage2(image,nombre(b));}
if(vr==2){i=moh(a,10,10,c,5,5,z,&nop);  image=couleurimage2(image,nombre(c));}
if(vr==3){i=moh(a,10,10,d,5,5,z,&nop);  image=couleurimage2(image,nombre(d));}

              if(i==0){
                SDL_BlitSurface(init, NULL, ecran, &posb);
              }else{
                  pred=initpile(pred);
while(pilevide(nop)==0){desempiler(&nop,&h);empiler(&pred,h);
posgr.x=h.x*32-26;posgr.y=h.y*32+70;SDL_SetAlpha(image, SDL_SRCALPHA, 255);SDL_BlitSurface(image, NULL, ecran, &posgr);}
              }
posc.x=posb.x;posc.y=posb.y;
              }else{

while(pilevide(pred)==0){desempiler(&pred,&e);posgr.x=e.x*32-26;posgr.y=e.y*32+70;SDL_BlitSurface(init, NULL, ecran, &posgr);}
              }
              }}else{

while(pilevide(pred)==0){desempiler(&pred,&e);
posgr.x=e.x*32-26;posgr.y=e.y*32+70;SDL_BlitSurface(init, NULL, ecran, &posgr);}
              }
               break;
    }
}

if(vp==0){
    SDL_WaitEvent(&event2);
    switch(event2.type)
    {
case SDL_QUIT:continuer=0;
        break;
    case SDL_MOUSEBUTTONDOWN :
        if(game==3){n3=215;n4=5;}
x.x=event2.button.x;x.y=event2.button.y;

if(x.x>99+n3 && x.x<159+n3 && x.y >225+n4 && x.y<285+n4 ){continuer=0;}
if(x.x>243+n3 && x.x<303+n3 && x.y >225+n4 && x.y<285+n4 ){
score=0;clearsave(game);

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

  if(game==3){
initmatrice(apc,10,10,0);savematrice(apc,5);initpiles(&f1,&f2,&f3,&p1,&p2,&p3);
dessinmatrice(ecran,3,1);initmatrice(apc,10,10,0);scorepc=0;verpc=1;colorergrille(apc,3,'n',init,ecran);savescore(scorepc,3);
rempliematrice(sommetdepile(p1).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,4+430,image,image0,ecran);
rempliematrice(sommetdepile(p2).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,106+430,image,image0,ecran);
rempliematrice(sommetdepile(p3).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,208+430,image,image0,ecran);
calscore(scorepc,&meilleur,ecran,3,game);}
  if(game==3){dessinmatrice(ecran,1,0);}else{dessinmatrice(ecran,1,1);}
  calscore(score,&meilleur,ecran,1,game);
  if(game==3){savescore(score,8);}else{savescore(score,1);}
initmatrice(a,10,10,0);initmatrice(b,5,5,0);initmatrice(c,5,5,0);initmatrice(d,5,5,0);
if(game==3){savematrice(a,13);}else{savematrice(a,11);}
    if(game==3){savematrice(b,23);}else{savematrice(b,21);}
    if(game==3){savematrice(c,33);}else{savematrice(c,31);}
    if(game==3){savematrice(d,43);}else{savematrice(d,41);}

desempiler(&f1,&ef);kb=ef.x;
rempliematrice(kb,b);
imageb=couleurimage(imageb,nombre(b));
desempiler(&f2,&ef);kc=ef.x;
rempliematrice(kc,c);
imagec=couleurimage(imagec,nombre(c));
desempiler(&f3,&ef);kd=ef.x;
rempliematrice(kd,d);
imaged=couleurimage(imaged,nombre(d));
for(i=1;i<=10;i++){
for(j=1;j<=10;j++){
       pos.x=32*j-26;
       pos.y=32*i+70;
       SDL_BlitSurface(init, NULL, ecran, &pos);

        }
}
dessinblock(b,255,4,imageb,image0, ecran);dessinblock(c,255,106,imagec,image0, ecran);dessinblock(d,255,208,imaged,image0, ecran);
 SDL_Flip(ecran);
vp=1;vb=1;vc=1;vd=1;
}

if(x.x>171+n3 && x.x<231+n3 && x.y >225+n4 && x.y<285+n4){
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
   if(game==3){dessinmatrice(ecran,1,0);}else{dessinmatrice(ecran,1,1);}
   calscore(score,&meilleur,ecran,1,game);
if(vb==0){dessinblock(b,120,4,imageb,image0, ecran);}else{dessinblock(b,255,4,imageb,image0, ecran);}
if(vc==0){dessinblock(c,120,106,imagec,image0, ecran);}else{dessinblock(c,255,106,imagec,image0, ecran);}
if(vd==0){dessinblock(d,120,208,imaged,image0, ecran);}else{dessinblock(d,255,208,imaged,image0, ecran);}
colorergrille(a,1,'c',init,ecran);
if(game==3){
     dessinmatrice(ecran,3,1);
    colorergrille(apc,3,'n',init,ecran);
colorergrille(apc,3,'c',init,ecran);
rempliematrice(sommetdepile(p1).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,4+430,image,image0,ecran);
rempliematrice(sommetdepile(p2).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,106+430,image,image0,ecran);
rempliematrice(sommetdepile(p3).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,208+430,image,image0,ecran);
calscore(scorepc,&meilleur,ecran,3,game);}
 SDL_Flip(ecran);
vp=1;
}
if(x.x>27+n3 && x.x<87+n3 && x.y >225+n4 && x.y<285+n4){
if(game==3){savematrice(a,13);}else{savematrice(a,11);}
if(game==3){savematrice(b,23);}else{savematrice(b,21);}
if(game==3){savematrice(c,33);}else{savematrice(c,31);}
if(game==3){savematrice(d,43);}else{savematrice(d,41);}
if(game==3){savescore(score,8);}else{savescore(score,1);}
savingpile(f1,4);
savingpile(f2,5);
savingpile(f3,6);
if(game==3){
savingpile(p1,1);
savingpile(p2,2);
savingpile(p3,3);
}
if(game==3){savescore(scorepc,3);savematrice(apc,5);}
setsave(game);
pos.x=27+n3;
pos.y=225+n4;
SDL_BlitSurface(save0, NULL, ecran, &pos);
SDL_SetAlpha(save, SDL_SRCALPHA, 120);
SDL_BlitSurface(save, NULL, ecran, &pos);
}
break;

    case  SDL_MOUSEBUTTONUP:
        if(x.x>27+n3 && x.x<87+n3 && x.y >225+n4 && x.y<285+n4){
pos.x=27+n3;
pos.y=225+n4;
SDL_BlitSurface(save0, NULL, ecran, &pos);
SDL_SetAlpha(save, SDL_SRCALPHA, 255);
SDL_BlitSurface(save, NULL, ecran, &pos);
        }
        break;
    }
}

if(vb+vc+vd==0){
        SDL_Delay(1000);
classer(score,scorepc,ecran,&vgo,game);
if(game==3){initmatrice(apc,10,10,0);savematrice(apc,5);}
if(game==3){ scorepc=0;savescore(scorepc,3);initmatrice(apc,10,10,0);savematrice(apc,5);}
initpiles(&f1,&f2,&f3,&p1,&p2,&p3);
initmatrice(a,10,10,0);initmatrice(b,5,5,0);initmatrice(c,5,5,0);initmatrice(d,5,5,0);
    if(game==3){savematrice(a,13);}else{savematrice(a,11);}
    if(game==3){savematrice(b,23);}else{savematrice(b,21);}
    if(game==3){savematrice(c,33);}else{savematrice(c,31);}
    if(game==3){savematrice(d,43);}else{savematrice(d,41);}
clearsave(game);
if(vgo==1){
score=0;
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
  if(game==3){
     dessinmatrice(ecran,3,1);
     initmatrice(apc,10,10,0);savematrice(apc,5);
     scorepc=0;verpc=1;colorergrille(apc,3,'n',init,ecran);
      rempliematrice(sommetdepile(p1).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,4+430,image,image0,ecran);
rempliematrice(sommetdepile(p2).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,106+430,image,image0,ecran);
rempliematrice(sommetdepile(p3).x,jh);
image=couleurimage(image,nombre(jh));
dessinblock(jh,255,208+430,image,image0,ecran);
calscore(scorepc,&meilleur,ecran,3,game);
}
  if(game==3){dessinmatrice(ecran,1,0);}else{dessinmatrice(ecran,1,1);}
  calscore(score,&meilleur,ecran,1,game);
  if(game==3){savescore(score,8);}else{savescore(score,1);}
desempiler(&f1,&ef);kb=ef.x;
rempliematrice(kb,b);
imageb=couleurimage(imageb,nombre(b));
desempiler(&f2,&ef);kc=ef.x;
rempliematrice(kc,c);
imagec=couleurimage(imagec,nombre(c));
desempiler(&f3,&ef);kd=ef.x;
rempliematrice(kd,d);
imaged=couleurimage(imaged,nombre(d));
for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
       pos.x=32*j-26;
       pos.y=32*i+70;
       SDL_BlitSurface(init, NULL, ecran, &pos);

        }
}
dessinblock(b,255,4,imageb,image0, ecran);
dessinblock(c,255,106,imagec,image0, ecran);
dessinblock(d,255,208,imaged,image0, ecran);
 SDL_Flip(ecran);
vgo=0;vb=1;vc=1;vd=1;
}
if(vgo==2){continuer=0;}
    score=0;
if(game==3){savescore(score,8);}else{savescore(score,1);}
}
 SDL_Flip(ecran);
}
}

void existepos(SDL_Surface *ecran,SDL_Surface *imageb,SDL_Surface *image0,int a[100][100],int b[100][100],int *e,int y){
     int l,i,j,v;
     pile *p;
     cordo z;

     l=0;
  for(i=1;i<=10;i++){
    for(j=1;j<=10;j++){
        z.x=j;
      z.y=i;
      v=moh(a,10,10,b,5,5,z,&p);
            if(v==0){l++;}
  }
}

if(l!=100 && (*e)==0){dessinblock(b,255,y,imageb,image0,ecran);(*e)=1;}
if(l==100 && (*e)==1){dessinblock(b,120,y,imageb,image0,ecran);(*e)=0;}

}

void pcplayone(int a[100][100],SDL_Surface *ecran,pile **f1,pile**f2,pile **f3,int *vf,int *score,int nb,int kb){
       int l=0,f=0,b=208,z=0,k=0;
if(nb!=1){
    if((*vf)!=0){
    finaly(a,f1,f2,f3,vf,score,&l,&k);
    if(l==3){if(nb==3){empiler1(f3,kb);}f=sommetdepile(*f3).x;}
    if(l==1){b=4;   if(nb==3){empiler1(f1,kb);}f=sommetdepile(*f1).x;}
    if(l==2){b=106;if(nb==3){empiler1(f2,kb);}   f=sommetdepile(*f2).x;}
    if(nb==3){z=430;}
b=b+z;
if( (*vf)!=0){
eliminer(ecran,a,score,nb,l,f,b,k);
}

}
}
}

void pc(){
SDL_Surface *ecran = NULL;
 SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("file/images/others/1.bmp"),NULL);
   ecran = SDL_SetVideoMode(330,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_WM_SetCaption("block puzzle", NULL);
SDL_Surface *image=NULL,*init=NULL;
SDL_Event   event;
init=SDL_CreateRGBSurface(SDL_HWSURFACE,30,30,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 0, 0,0));
int continuer=1,vf=1 ,a[100][100],b[100][100],i,meilluer,score=0,vp=0,tyu=0;
cordo z;
dessinmatrice(ecran,2,1);
initmatrice(a,10,10,0);
initmatrice(b,5,5,0);
srand(time(NULL));
score=0;
pile *f1=initpile(f1),*f2=initpile(f2),*f3=initpile(f3);
for(i=1;i<=1000;i++){empiler1(&f1,rand()%27);}
for(i=1;i<=1000;i++){empiler1(&f2,rand()%27);}
for(i=1;i<=1000;i++){empiler1(&f3,rand()%27);}
 rempliematrice(sommetdepile(f1).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,4,image,init,ecran);
rempliematrice(sommetdepile(f2).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,106,image,init,ecran);
rempliematrice(sommetdepile(f3).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,208,image,init,ecran);
SDL_Flip(ecran);
SDL_Delay(500);
    while(continuer){
    SDL_PollEvent(&event);
        switch(event.type){
        case SDL_QUIT:continuer=0;
        break;
        case SDL_MOUSEBUTTONDOWN:
          z.x=event.button.x;
          z.y=event.button.y;
          if(z.x>150 && z.x <210 && z.y >15 && z.y<75){continuer=0;}
          if(z.x>259 && z.x <319 && z.y >15 && z.y<75){
           score=0;
           calscore(score,&meilluer,ecran,2,2);
            initmatrice(a,10,10,0);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                dessinmatrice(ecran,2,1);
f1=initpile(f1);f2=initpile(f2);f3=initpile(f3);
for(i=1;i<=100000;i++){empiler1(&f1,rand()%27);}
for(i=1;i<=100000;i++){empiler1(&f2,rand()%27);}
for(i=1;i<=100000;i++){empiler1(&f3,rand()%27);}
 rempliematrice(sommetdepile(f1).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,4,image,init,ecran);
rempliematrice(sommetdepile(f2).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,106,image,init,ecran);
rempliematrice(sommetdepile(f3).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,208,image,init,ecran);
SDL_Flip(ecran);
SDL_Delay(500);
          }
       break;

        }
if(!vp && continuer==1){pcplayone(a,ecran,&f1,&f2,&f3,&vf,&score,2,0);}

if(vf==0){
SDL_Delay(2000);
    standard(ecran,score,&tyu,0,2);
                if(tyu==1){
                score=0;initmatrice(a,10,10,0);
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                dessinmatrice(ecran,2,1);calscore(score,&meilluer,ecran,2,2);
                initmatrice(a,10,10,0);
colorergrille(a,2,'n',init,ecran);
f1=initpile(f1);f2=initpile(f2);f3=initpile(f3);
for(i=1;i<=100000;i++){empiler1(&f1,rand()%27);}
for(i=1;i<=100000;i++){empiler1(&f2,rand()%27);}
for(i=1;i<=100000;i++){empiler1(&f3,rand()%27);}
 rempliematrice(sommetdepile(f1).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,4,image,init,ecran);
rempliematrice(sommetdepile(f2).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,106,image,init,ecran);
rempliematrice(sommetdepile(f3).x,b);image=couleurimage(image,nombre(b));dessinblock(b,255,208,image,init,ecran);
SDL_Flip(ecran);
SDL_Delay(500);
vf=1;

                }
                if(tyu==2){
                    continuer=0;
                }
}

        }

}

void resetfiles(SDL_Surface *ecran){
SDL_Rect pos;
SDL_Surface *image=NULL;
image=SDL_LoadBMP("file/images/others/resetmsg.bmp");
SDL_Event event;
cordo z;
FILE *fichier=NULL;
listewinner a1;
toplayer y;

int continuer=1,m[100][100],i,score;
 inittab(a1.t);
 for(i=1;i<=5;i++){
        y.score=0;
        y.username[0]='\0';
        y.playdate.annee=2019;
        y.playdate.jour=1;
        y.playdate.mois=1;

 create(a1.t,y);
        }
pile *p=initpile(p);
srand(time(NULL));
SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
pos.x=130;pos.y=165;SDL_BlitSurface(image, NULL, ecran, &pos);
SDL_Flip(ecran);
while(continuer){
    SDL_WaitEvent(&event);
    switch(event.type){
case SDL_QUIT:continuer=0;
break;
case SDL_MOUSEBUTTONDOWN:
   z.x=event.button.x;z.y=event.button.y;
   if(z.x > 130 && z.x <250+130 && z.y >195+165 && z.y <300+165 ){
 fichier=fopen("file/score/save.topscore","w");
  fwrite(&a1,sizeof(listewinner),1,fichier);
    fclose(fichier);
            fichier=fopen("file/score/savepc.topscore","w");
  fwrite(&a1,sizeof(listewinner),1,fichier);
    fclose(fichier);
    continuer=0;
   initmatrice(m,10,10,0);
   savematrice(m,11);savematrice(m,13);savematrice(m,5);
   initmatrice(m,5,5,0);
   savematrice(m,21);savematrice(m,23);savematrice(m,31);savematrice(m,33);savematrice(m,41);savematrice(m,43);
   score=0;savescore(score,1);savescore(score,3);savescore(score,8);
    for(i=1;i<=1000;i++){empiler1(&p,rand()%27);}
    savingpile(p,4);savingpile(p,1);p=initpile(p);
    for(i=1;i<=1000;i++){empiler1(&p,rand()%27);}
    savingpile(p,5);savingpile(p,2);p=initpile(p);
    for(i=1;i<=1000;i++){empiler1(&p,rand()%27);}
    savingpile(p,6);savingpile(p,3);p=initpile(p);
    clearsave(1);
    clearsave(3);
   }
    if(z.x > 130+250 && z.x <500+130 && z.y >195+165 && z.y <300+165 ){
    continuer=0;
   }
break;
}
}

}

void topscoremain2(SDL_Surface *ecran){
    SDL_Event event;
    int continuer=1;
    cordo w;
    topscoremain(ecran);
while(continuer){
    SDL_WaitEvent(&event);
    switch(event.type){
case SDL_QUIT:continuer=0;
case SDL_MOUSEBUTTONDOWN:
    w.x=event.button.x;w.y=event.button.y;
    if(w.x>365 && w.x<425 && w.y >28 && w.y < 88){
        continuer=0;
    }
    if(w.x>365 && w.x<425 && w.y >543 && w.y <603 ){
        resetfiles(ecran);topscoremain(ecran);SDL_Flip(ecran);

    }
    break;
    }


}

}

void topscoremain(SDL_Surface *ecran){

    SDL_Surface *init=NULL,*image=NULL;
    SDL_Rect pos;
    SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    init=SDL_CreateRGBSurface(SDL_HWSURFACE,305,400,32,0,0,0,0);
    SDL_FillRect(init, NULL, SDL_MapRGB(init->format, 192, 192,192));
    int i,b=150;
    pos.x=50;pos.y=115;SDL_BlitSurface(init, NULL, ecran, &pos);
    pos.x=405;pos.y=115;SDL_BlitSurface(init, NULL, ecran, &pos);
    pos.x=350;pos.y=28;image=SDL_LoadBMP("file/images/others/Home2.bmp");SDL_BlitSurface(image, NULL, ecran, &pos);
    pos.x=350;pos.y=543;image=SDL_LoadBMP("file/images/others/Cloud.bmp");SDL_BlitSurface(image, NULL, ecran, &pos);
    SDL_Flip(ecran);
FILE *fichier=NULL;
listewinner a,z;
fichier=fopen("file/score/save.topscore","r");fread(&z,sizeof(listewinner),1,fichier);fclose(fichier);
fichier=fopen("file/score/savepc.topscore","r");fread(&a,sizeof(listewinner),1,fichier);fclose(fichier);
char temp[50]="\0";
TTF_Init();
TTF_Font *police = NULL;
SDL_Surface *texte=NULL;
SDL_Color chiffre1 = {255, 0,0 },chiffre4= {0, 0,255 },chiffre3= {255, 155,15 },chiffre2= {0, 0,0 };
SDL_Color surf= {192,192,192};
police = TTF_OpenFont("font/3.ttf", 50);
sprintf(temp, "Top 5");
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=57;pos.y=115;SDL_BlitSurface(texte, NULL, ecran, &pos);
 sprintf(temp, "(solo)");
 texte = TTF_RenderText_Shaded(police, temp, chiffre4,surf);
pos.x=210;pos.y=115;SDL_BlitSurface(texte, NULL, ecran, &pos);
police = TTF_OpenFont("font/3.ttf", 35);
for(i=1;i<=5;i++){
 sprintf(temp, "%d-%s",i,z.t[i].username);
 if(i==1){texte = TTF_RenderText_Shaded(police, temp, chiffre3,surf);}else{texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);}
pos.x=60;pos.y=b+55*(i);SDL_BlitSurface(texte, NULL, ecran, &pos);
    }
    for(i=1;i<=5;i++){
 sprintf(temp,"%d",z.t[i].score);
 if(i==1){texte = TTF_RenderText_Shaded(police, temp, chiffre3,surf);}else{texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);}
pos.x=175+50;pos.y=b+55*(i);
 SDL_BlitSurface(texte, NULL, ecran, &pos);
    }



    police = TTF_OpenFont("font/3.ttf", 30);
sprintf(temp, "Top 5");
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=410;pos.y=135;SDL_BlitSurface(texte, NULL, ecran, &pos);
 sprintf(temp, "(player ");
 texte = TTF_RenderText_Shaded(police, temp, chiffre4,surf);
pos.x=500;pos.y=135;SDL_BlitSurface(texte, NULL, ecran, &pos);
sprintf(temp, "vs ");
 texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);
pos.x=615;pos.y=135;SDL_BlitSurface(texte, NULL, ecran, &pos);
sprintf(temp, "pc)");
 texte = TTF_RenderText_Shaded(police, temp, chiffre1,surf);
pos.x=660;pos.y=135;SDL_BlitSurface(texte, NULL, ecran, &pos);

police = TTF_OpenFont("font/3.ttf", 35);

for(i=1;i<=5;i++){
 sprintf(temp, "%d-%s",i,a.t[i].username);
 if(i==1){texte = TTF_RenderText_Shaded(police, temp, chiffre3,surf);}else{texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);}
pos.x=413;pos.y=b+55*(i);SDL_BlitSurface(texte, NULL, ecran, &pos);
    }
    for(i=1;i<=5;i++){
 sprintf(temp, "%d",a.t[i].score);
 if(i==1){texte = TTF_RenderText_Shaded(police, temp, chiffre3,surf);}else{texte = TTF_RenderText_Shaded(police, temp, chiffre2,surf);}
pos.x=175+405;pos.y=b+55*(i);SDL_BlitSurface(texte, NULL, ecran, &pos);
    }

    TTF_Quit();
    SDL_Flip(ecran);
}

void clearsave(int a){
FILE *f=NULL;
int x=65;
if(a==1){f=fopen("file/pile/controlsave.txt","w");}else{f=fopen("file/pile/controlsave3.txt","w");}
fwrite(&x,sizeof(char),1,f);
fclose(f);
}

void setsave(int a){
FILE *f=NULL;
int x=66;
if(a==1){f=fopen("file/pile/controlsave.txt","w");}else{f=fopen("file/pile/controlsave3.txt","w");}
fwrite(&x,sizeof(char),1,f);
fclose(f);
}

void readsavebool(int *x,int a){
FILE *f=NULL;
char y;
if(a==1){f=fopen("file/pile/controlsave.txt","r");}else{f=fopen("file/pile/controlsave3.txt","r");}
fread(&y,sizeof(char),1,f);
(*x)=y-65;
fclose(f);
}

void initpiles(pile **f1,pile **f2,pile **f3,pile **p1,pile **p2,pile **p3 ){
int i;
srand(time(NULL));
(*f1)=initpile(*f1);(*f2)=initpile(*f2);(*f3)=initpile(*f3);
for(i=1;i<=1000;i++){empiler1(f1,rand()%27);}
for(i=1;i<=1000;i++){empiler1(f2,rand()%27);}
for(i=1;i<=1000;i++){empiler1(f3,rand()%27);}
copiepile(f1,p1);copiepile(f2,p2);copiepile(f3,p3);
}

void help(SDL_Surface *ecran){
SDL_Event event;
SDL_Rect pos;
int continuer=1;
SDL_Surface *image=NULL;
SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
pos.x=(760-550)/2;pos.y=(630-600)/2;image=SDL_LoadBMP("file/images/others/Help.bmp");SDL_BlitSurface(image, NULL, ecran, &pos);SDL_Flip(ecran);
image=SDL_LoadBMP("file/images/others/Home2.bmp");
pos.x=(105-60)/2;pos.y=(630-60)/2;SDL_BlitSurface(image, NULL, ecran, &pos);
SDL_Flip(ecran);
cordo z;
while(continuer){
    SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:continuer=0;
            break;
             case SDL_MOUSEBUTTONDOWN:
                z.x=event.button.x;z.y=event.button.y;
                if(z.x >22 && z.y >265 && z.x <82 && z.y <325){continuer=0;}
        }
}
}
