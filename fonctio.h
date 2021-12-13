#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int jour;
    int mois;
    int annee;

}date;

typedef struct
{
    char cha[20];
    int taille;
}chaine;

typedef struct
{
    char username[50];
    date playdate;
    int score;

}toplayer;

typedef struct
{
	toplayer t[100];

}listewinner;

typedef  struct
{

    int x,y;
}cordo;

typedef struct
{
int M[100][100];

}matrice;

typedef struct
{
    int sc,msc;

}scor;

typedef struct celulle pile;
struct celulle
{
   cordo info;
   pile *svt;
};

///les fonctions de dessin:
void standard(SDL_Surface *ecran,int score,int *vr,int scorepc,int j);
void classer(int score,int scorepc,SDL_Surface *ecran,int *u,int game);///retourner votre classement
void dessinpause(SDL_Surface *ecran,int game);///dessiner les icons dans le pause
void dessinmatrice (SDL_Surface *ecran,int a,int u);///dessiner la matrice dans les 3 parties
void dessinblock(int m[100][100],int trans,int x,SDL_Surface *image,SDL_Surface *image0, SDL_Surface *ecran);///dessiner les pieces dans les 3 parties
void colorergrille(int a[100][100],int x,char y,SDL_Surface *init,SDL_Surface *ecran);///colorer la grille dans les 3 parties
void pausemenu(SDL_Surface *ecran,int game);///dessiner le menu de pause
void ecrire(SDL_Surface *ecran,int v);
void calscore(int score ,int *meilleur,SDL_Surface *ecran,int a,int game);///dessiner le score dans les 3 parties
void affscorepause(int score ,int meilleur ,SDL_Surface *ecran,int game);///dessiner le score dans le menu de pause
void essie(char ch[20],SDL_Surface *ecran,int k,int v);///dessiner le message quand vous avez le meilleur score ou parmi les TOP 5
void eliminer(SDL_Surface *ecran,int a[100][100],int *score,int nb,int l,int f,int b,int k);///remplir les lignes et les colones eliminer avec le noir
void existepos(SDL_Surface *ecran,SDL_Surface *imageb,SDL_Surface *image0,int a[100][100],int b[100][100],int *e,int y);///verifier les blocks possible a jouer et les colorer avec le transparent
void topscoremain2(SDL_Surface *ecran);///dessiner la liste de TOP 5 dans le menu principale
void topscoremain(SDL_Surface *ecran);///dessiner les icons et remplir les deux listes de TOP5
void help(SDL_Surface *ecran);///dessiner l'information du jeu dans le menu principale
void pcdetectepos(int a[100][100],int b[100][100],int *score);///dessiner le blocks dans la meilleur position sur la grille
SDL_Surface *couleurimage(SDL_Surface *image,int x);
SDL_Surface *couleurimage2(SDL_Surface *image,int x);
void eliminerligne_et_col(int a[100][100],SDL_Surface *init, SDL_Surface *ecran,int *score);
void eliminerligne_et_col_pc(int a[100][100], SDL_Surface *ecran,int b);

///les piles:
void copiepile(pile **p,pile **q);
void rempliepile(int a[100][100],pile *p,int x,pile **q);
pile*initpile(pile *p);
int pilevide(pile *p);
cordo sommetdepile(pile *p);
void empiler(pile **p, cordo x);
void empiler1(pile **p, int x);
void desempiler(pile **a,cordo *x);
void empilertrie(pile **p,cordo z);
void initpiles(pile **f1,pile **f2,pile **f3,pile **p1,pile **p2,pile **p3 );

///les tableaux:
int position(toplayer x,toplayer t[100]);///retourner la position du top score dans le tableau
void insert(toplayer t[100],int k,toplayer x);///inserer vos information dans la position
void create(toplayer t[100],toplayer x);///fait l'appele au deux fonction precedente
void inittab(toplayer t[100]);
void initmatrice(int a[100][100],int n,int m,int val);
void mtab(int M[100][100],int x,int y,int t[200]);///copier matrice dans u tableau

///les fonctions de verification:
int verifier3(int a[100][100],int b[100][100]);///verifier si un block est jouable dans la grille
cordo verifier4(int a[100][100],int b[100][100],int *k2,int *k3);///retourner la meuilleur posistion dans la matrice
cordo verifier(int a[100][100],int b[100][100]);
int moh(int a[100][100],int n,int m ,int b[100][100],int l,int c,cordo s,pile **p);///verifer si le block selectioner peut etre placer dans la position de la sourie
int verifier2(int a[100][100]);///retourner le nombre de ligne/colone qui serait eleminer

///les fonctions de sauvgarde et chargement:
void savescore(int score,int a);///sauvgarder le score
void retournerscore(int *score,int *meilleur,int a);///charger le score
void savingpile(pile *p,int y);///sauvgarder les piles qui contenant les pieces
void retournepile(pile **p,int y);///charger les pieces
void resetfiles(SDL_Surface *ecran);///reinitialiser les fichiers
void clearsave(int a);///supprimer le sauvgarde
void setsave(int a);///sauvgarder
void readsavebool(int *x,int a);///charger un bool qui verifier si il exist un sauvgarde ou non
void savematrice(int m[100][100],int p);///sauvgarder les matrices
void returnermatrice(int m[100][100],int p);///charger les matrices

///les fonctions de detection:
int cordone(int b[100][100],int n,int m);
void calculemax(int a[100][100],cordo y,int *max2,int *max3,int e,cordo *cmax);///retourner la meilleur position
int nombre(int b[100][100]);///detecter les pieces
void ligne_et_col(int a[100][100],int *score);///detecter les lignes/colones qui peut l'eleminer
int tempo(int a[100][100],pile **f,int *r);///retourner le score d'une piece dans une position
void finaly(int a[100][100],pile **f1,pile **f2,pile **f3,int *vf,int *score,int *l,int *k);
void rempliematrice(int k,int m[100][100]);
cordo recherche(int a[100][100],int n,int m);
int converte(int x,int cpt1,int cpt2,float y);///converte de cordo vers des indices da la matrice
int detec(int b[100][100]);///detecter la piece
void timee(date *x);///retourner une chiane contenat la date
void name(SDL_Surface *ecran,char fch[20],int v);///retourner une chaine contenat le nom

///fonction principale
void jeux(int game);///partie 1 et 3
void pcplayone(int a[100][100],SDL_Surface *ecran,pile **f1,pile**f2,pile **f3,int *vf,int *score,int nb,int kb);///Pc jouer une seul fois
void pc();///partie 2
