#include "bataillenavale.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <time.h>
#include <windows.h>
#include<conio.h>
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
};
///
void logo() {
    //system("color 5");
    Color(3,0);
	printf(" ____        _        _ _ _                               _      \n");
	printf("| __ )  __ _| |_ __ _(_) | | ___   _ __   __ ___   ____ _| | ___ \n");
	printf("|  _ \\ / _` | __/ _` | | | |/ _ \\ | '_ \\ / _` \\ \\ / / _` | |/ _ \\\n");
	printf("| |_) | (_| | || (_| | | | |  __/ | | | | (_| |\\ V / (_| | |  __/\n");
	printf("|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| |_|\\__,_| \\_/ \\__,_|_|\\___|\n\n");
	//printf(ANSI_COLOR_BLUE"        _     _     _ " ANSI_COLOR_RESET "__-=-//__  __\\\\-=-__" ANSI_COLOR_BLUE " _     _     _        \n" ANSI_COLOR_RESET);
	//printf(ANSI_COLOR_BLUE".-.,.-'`(,.-'`(,.-'`(," ANSI_COLOR_RESET "\\_______/" ANSI_COLOR_BLUE ".." ANSI_COLOR_RESET "\\_______/" ANSI_COLOR_BLUE ",)`'-.,)`'-.,)`'-.,¸.-.\n\n" ANSI_COLOR_RESET);
	Color(15,0);
}

///

void o1(); //fonciont de choix 1
void o2(); //fonciont de choix 2
void o3(); //fonciont de choix 3
void o4(); //fonciont de choix 4
void arrow(); //foction de matipuler les choix

//=================================

void arrow(){
char ch;
int key=1;
o1();
do{

ch=getch();

if(ch==80)
    key++;
if(ch==72)
    key--;
    if(key==5)
        key=1;
    if(key==0)
        key=4;


if(key==1)
o1();
if(key==2)
o2();
if(key==3)
o3();
if(key==4)
o4();

}while(ch!=13);
if(key==1)
    AfficheSecondM();
if(key==2)
    readPartie();
if(key==3)
    afficherScore();
if(key==4)
    system("exit");
}
void o1(){
system("cls");
logo();
system("color 5");
printf("\n\n\n\n\n\n\n");
printf("\t\t\t\t\t  ");

Color(15,12);
printf(" 1-Nouvelle partie\n");
Color(15,0);
printf("\t\t\t\t\t2-Voir l'historique\n");
printf("\t\t\t\t\t3-afficher score\n");
printf("\t\t\t\t\t4-Quitter");
}
void o2(){
system("cls");
logo();
printf("\n\n\n\n\n\n\n");
Color(15,0);
printf("\t\t\t\t\t1-Nouvelle partie\n");
printf("\t\t\t\t\t  ");
Color(15,12);
printf(" 2-Voir l'historique\n");
Color(15,0);
printf("\t\t\t\t\t3-afficher score\n");
printf("\t\t\t\t\t4-Quitter");
}
void o3(){
system("cls");
logo();
printf("\n\n\n\n\n\n\n");
Color(15,0);
printf("\t\t\t\t\t1-Nouvelle partie\n");
printf("\t\t\t\t\t2-Voir l'historique\n");
printf("\t\t\t\t\t  ");
Color(15,12);
printf(" 3-afficher score\n");
Color(15,0);
printf("\t\t\t\t\t4-Quitter");
}
void o4(){
system("cls");
logo();
printf("\n\n\n\n\n\n\n");
Color(15,0);
printf("\t\t\t\t\t1-Nouvelle partie\n");
printf("\t\t\t\t\t2-Voir l'historique\n");
printf("\t\t\t\t\t3-afficher score\n");
printf("\t\t\t\t\t  ");
Color(15,12);
printf(" 3-Quitter");
Color(15,0);
}


///

void afficherScore()
{
    int * score;
    FILE *fp;
    fp = fopen("score.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }



    // Allocate memory for the 2D array
    score = (int*) malloc(2 * sizeof(int));


    // Read the array from the file
    for (int i = 0; i < 2; i++) {

            fscanf(fp, "%d", &score[i]);

    }
    fclose(fp);

    system("cls");
    printf("\n\t\t\t\tScore : %d vs %d\n\n\n", score[0], score[1]);



}

void writePartie(int **tab)
{
    FILE *fptr;
    fptr = fopen("partie.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fptr, "%d ", tab[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);

}

int * readScore()
{
    int * score;
    FILE *fp;
    fp = fopen("score.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }



    // Allocate memory for the 2D array
    score = (int*) malloc(2 * sizeof(int));


    // Read the array from the file
    for (int i = 0; i < 2; i++) {

            fscanf(fp, "%d", &score[i]);

    }
    fclose(fp);

    return score;



}
void readPartie()
{
    int** arr1;
    int ** arr2;
    FILE *fp;
    fp = fopen("partie.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }



    // Allocate memory for the 2D array
    arr1 = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr1[i] = (int*) malloc(n * sizeof(int));
    }
    arr2 = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr2[i] = (int*) malloc(n * sizeof(int));
    }

    // Read the array from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &arr2[i][j]);
        }
    }
    fclose(fp);

    int * score = readScore();



    if(score[0]>score[1])
    {
        printf("\nthe winner\n");
        Color(3,0);
        Afficher(arr1);
        Color(15,0);

        printf("\nthe loser\n");
        Color(4,0);
        Afficher(arr2);
        Color(15,0);
    }
    else
    {

        printf("\nthe loser\n");
        Color(15,12);
        Afficher(arr1);
        Color(15,0);

        printf("\nthe winner\n");
        Color(3,0);
        Afficher(arr2);
        Color(15,0);
    }




}
void writeScore(int me , int him)
{
    FILE *fptr;
    fptr = fopen("score.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");

    }
    fprintf(fptr, "%d %d\n",me,him);
    fclose(fptr);
}

/*void AffichageMenu(){
	int s;
	printf("0-Quiter le jeu.\n");
	printf("1-Nouvelle partie.\n");
	printf("2-Consulter une partie.\n");
	printf("3-Visualiser mon score.\n");
	printf("4-Les Regles du jeu.\n");
	printf("Qu'est-ce que tu veux? ");
	scanf("%d",&s);
	switch(s){
		case 0 : break;
		case 1 : AfficheSecondM(); break;
		case 2 :readPartie();break;
		case 3 :	afficherScore();break;
		case 4 : printf("\tLa bataille navale est un jeu de societe dans lequel deux joueurs tentent de couler tous les bateaux de leur adversaire.Dans un premier temps, les joueurs doivent placer leurs 'navires' respectifs sur une grille tenue secrete. Ensuite, chacun a son tour, ils essayent de trouver et couler les bateaux adverses en indiquant les coordonnees visees.\t\n");
		AffichageMenu();
	}
}*/
void AfficheSecondM(){
	system("cls" );
	logo();
	printf("\t\t ------- bataille navale ---------\n");
	int c;
	printf("0-Quiter le jeu.\n");
	printf("1-Joueur vs joueur.\n");
	printf("2-Joueur vs ordinateur.\n");
	printf("3-Revenir en arriere.\n");
	printf("choisissez-en un ? ");
	scanf("%d",&c);
	switch(c){
		case 0 : break;
		case 1 : JoueurVsJoueur();break;
		case 2 : JoueurVsOrdi();break;
		case 3 : 	system("cls" ); printf("\t\t ------- bataille navale ---------\n");arrow();break;
}}

int **init_jeuG(){
	int **tab;
	int i,ac,al,cc,cl,j,tl,tc,ctl,ctc;
	tab=calloc(sizeof(int(*)),n);
	for(i=0;i<n;i++){
		tab[i]=calloc(sizeof(int),n);
	}
	do{
		printf("Porte-avions(5 cases) L:");
		scanf("%d",&al);
	}while(al>=10 || al<0);
	do{
		printf("Porte-avions(5 cases) C:");
		scanf("%d",&ac);
	}while(ac>=6 || ac<0);

	for(i=ac;i<(ac+5);i++){
		tab[al][i]=1;
	}
	do{
	do{
		printf("Croiseur(4 cases) L:");
		scanf("%d",&cl);
    }while(cl<0 || cl>=10);
	do{
		printf("Croiseur(4 cases) C:");
		scanf("%d",&cc);
	}while( cc<0 || cc>=7 );
	}while(tab[cl][cc]==1);

	for(i=cl;i<(cl+4);i++){
		tab[i][cc]=1;
	}
	for(i=0;i<2;i++){
		do{
			do{
				printf(" Torpilleur %d(2 cases) L:",i+1);
				scanf("%d",&tl);
			}while(tl<0 || tl>=10);
			do{
				printf("Torpilleur %d(2 cases) C:",i+1);
				scanf("%d",&tc);
			}while(tc<0 || tc>=9);
		}while(tab[tl][tc]==1);
		for(j=tc;j<(tc+2);j++){
			tab[tl][j]=1;
		}
	}
	do{
		do{
		printf(" Contre-torpilleurs(3 cases)  L:");
		scanf("%d",&ctl);
		}while(ctl>=8 || ctl<0);
		do{
		printf(" Contre-torpilleurs(3 cases) C:");
		scanf("%d",&ctc);
		}while(ctc>=10 || ctc<0);
	}while(tab[ctl][ctc]==1);
	for(i=ctl;i<(ctl+3);i++){
		tab[i][ctc]=1;
	}
	return tab;
}
int **init_OrdiG(){
	int **tab;
	int i,ac,al,cc,cl,j,tl,tc,ctl,ctc;
	tab=calloc(sizeof(int(*)),n);
	for(i=0;i<n;i++){
		tab[i]=calloc(sizeof(int),n);
	}
		al=rand()%10;
	do{
		ac=rand()%10;
	}while(ac>=6 || ac<0);
	for(i=ac;i<(ac+5);i++){
		tab[al][i]=1;
	}
		do{
	do{
		cl=rand()%10;
    }while(cl<0 || cl>=10);
	do{
		cc=rand()%10;
	}while( cc<0 || cc>=7 );
	}while(tab[cl][cc]==1);
	for(i=cl;i<(cl+4);i++){
		tab[i][cc]=1;
	}
	for(i=0;i<2;i++){
		do{
			do{
				tl=rand()%10;
			}while(tl<0 || tl>=10);
			do{
				tc=rand()%10;
			}while(tc<0 || tc>=9);
		}while(tab[tl][tc]==1);
		for(j=tc;j<(tc+2);j++){
			tab[tl][j]=1;
		}
	}
	do{
		do{
		ctl=rand()%10;
		}while(ctl>=8 || ctl<0);
		do{
		ctc=rand()%10;
		}while(ctc>=10 || ctc<0);
	}while(tab[ctl][ctc]==1);
	for(i=ctl;i<(ctl+3);i++){
		tab[i][ctc]=1;
	}
	return tab;
}
void AfficherGrillFi(int **tab){
	int i,j;
	printf("    |0|1|2|3|4|5|6|7|8|9|\n");
	for(i=0;i<=9;i++){
		printf("%d   |",i);
		for(j=0;j<=9;j++){
		  if(tab[i][j]==2){
		  	printf("%d|",tab[i][j]);
		  }else{
		 printf("#|");
		 }
		}
		printf("\n");
		}
}

void Afficher(int **tab){
	int i,j;
	printf("    |0|1|2|3|4|5|6|7|8|9|\n");
	for(i=0;i<=9;i++){
		printf("%d   |",i);
		for(j=0;j<=9;j++){
		  if(tab[i][j]==1 || tab[i][j]==2 ){
		  	printf("%d|",tab[i][j]);
		  }else{
		 printf("#|");
		 }
		}
		printf("\n");
		}
}
void AfficherGrill(int **tab){
	int i,j;
	printf("    |0|1|2|3|4|5|6|7|8|9|\n");
	for(i=0;i<=9;i++){
		printf("%d   |",i);
		for(j=0;j<=9;j++){
		  if(tab[i][j]==1){
		  	printf("%d|",tab[i][j]);
		  }else{
		 printf("#|");
		 }
		}
		printf("\n");
		}
}
void replace(int **tab,int c,int l){
	tab[l][c]=2;
}
void timing(){
	SYSTEMTIME  now;
  GetLocalTime(&now);
  hour=now.wHour;
  minute=now.wMinute;
  sec=now.wSecond;
  millsec=now.wMilliseconds;
}

void StartGameO(int **tabG,int *p){
	int l,c;
	system("cls");
	printf("\t\t ------- bataille navale ---------\n");
	minute=0;
	timing();
	int m=minute;
	int endmin=minute+1;
	while(m!=endmin){
		l=rand()%10;
		c=rand()%10;
	 	if(tabG[l][c] == 1){
	 		replace(tabG,c,l);
	 		(*p)++;
		 }
	printf("Waiting..........\r");
	timing();
	m=minute;
	}
}
void StartGame(int **tabOr,int *g){
	int l,c;

	//printf("\t\t ------- bataille navale ---------\n");
	//minute=0;

	timing();
	int m=minute;
	int endmin=minute+1;
	while(m!=endmin){
	do{
	printf("\nL:");
	scanf("%d",&l);
	}while(l>=10 || l<0);
	do{
	printf("C:");
	scanf("%d",&c);
	}while(c>=10 || c<0);
	 	if(tabOr[l][c]==1){
	 		replace(tabOr,c,l);
	 		(*g)=(*g)+1;
	 		printf("Good\n");
	 		system("cls");
	 		AfficherGrillFi(tabOr);
		 }else{
		 	printf("try again\n");
		 }
	printf("the current time %02d:%02d:%02d\n",m,sec,millsec);
	Sleep(20);
	timing();
	m=minute;
	}
}

void thewinnergvsor(int **tabG,int**tabOr,int p,int g){
	if(g>p){
		printf("the winner is the gamer:");
	}else if(p>g){
		printf("the winner is the pc:");
	}else{
		printf("try again no gain");
	}
}
void thewinnergvsg(int **tabG,int**tabOr,int g1,int g2){
	if(g1>g2){
		printf("the winner is the gamer 1:)");
	}else if(g1>g2){
		printf("the winner is the gamer 2:)");
	}else{
		printf("try again no gain");
	}
}
void JoueurVsOrdi(){
	int g=0,p=0;
	int **tabG,**tabOr;
	tabG=init_jeuG();
	tabOr=init_OrdiG();
//	AfficherGrill(tabG);
//	sleep(20);
    system("cls");
    printf("\t\t ------- bataille navale ---------\n");
    printf("\nORDINATEUR\n");
	StartGame(tabOr,&g);
	system("cls");
    printf("\t\t ------- bataille navale ---------\n");
	printf("\nJOUEUR 1\n");
	StartGameO(tabG,&p);

	//sauv etat
	writePartie(tabG);
	writePartie(tabOr);
	writeScore(p,g);
	///

	if(g>p)
    {
        Color(3,0);
        printf("\nle joueur 1 a gagne\n");
        AfficherGrill(tabG);
        Color(15,0);
        printf("\n");

        Color(4,0);
        printf("\nl'odinateur a echoue\n");
        AfficherGrill(tabOr);
        Color(15,0);
    }
    else
    {
        Color(4,0);
        printf("\nle joueur 1 a echoue\n");
        AfficherGrill(tabG);
        Color(15,0);
        printf("\n");
        Color(3,0);
        printf("\nl'ordinateur a gagne\n");
        AfficherGrill(tabOr);
        Color(15,0);
    }

	///
	//AfficherGrill(tabG);
	printf("\n");
	//AfficherGrill(tabOr);
	printf("p=%d,g=%d",p,g);
	thewinnergvsor(tabG,tabOr,p,g);
}
void JoueurVsJoueur(){
	int g1=0,g2=0;
	int **tabG1,**tabG2;
	system("cls");
	printf("\n=========================Joueur 1 =========================\n");
	tabG1=init_jeuG();
	system("cls");
	printf("\n=========================Joueur 2 ==============================\n");
	tabG2=init_jeuG();
	system("cls");
    printf("\t\t ------- bataille navale ---------\n");
    printf("\nJOUEUR 2\n");
	StartGame(tabG2,&g1);
	system("cls");
	printf("\t\t ------- bataille navale ---------\n");
	printf("\nJOUEUR 1\n");
	StartGame(tabG1,&g2);


	///sauv
	writePartie(tabG1);
	writePartie(tabG2);
	writeScore(g1,g2);

	///
	if(g1>g2)
    {
        Color(3,0);
        printf("\nle joueur 1 a gagne\n");
        AfficherGrill(tabG1);
        Color(15,0);
        printf("\n");

        Color(4,0);
        printf("\nle joueur 2 a echoue\n");
        AfficherGrill(tabG2);
        Color(15,0);
    }
    else
    {
        Color(4,0);
        printf("\nle joueur 1 a echoue\n");
        AfficherGrill(tabG1);
        Color(15,0);
        printf("\n");
        Color(3,0);
        printf("\nle joueur 2 a gagne\n");
        AfficherGrill(tabG2);
        Color(15,0);
    }

	printf("g1=%d,g2=%d",g1,g2);
	thewinnergvsg(tabG1,tabG2,g1,g2);

}
