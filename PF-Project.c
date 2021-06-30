#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int wkts=0;
int player=0;
int result=0;

void start();
void instructions();
void ascore();
void innings();

struct game
{
	int balls;
	int overs;
	int runs;
	int wickets;
}g[2];

int main()
{
	system("color F6");
	int i;
	while(1)
	{
		printf("\t\tMAIN MENU");
		printf("\n 1. Start\n 2. Instructions\n 3. Score Records\n 4. Exit\n");
		scanf("%d", &i);
		
		switch(i)
		{
			case 1:
				start();
				break;
				
			case 2:
				instructions();
				break;
			
			case 3:
				ascore();
				break;
			case 4:
				exit(1);
			
			default:
				system("cls");
				printf("Invalid Entry!");
		}
	}
}

void start()
{
	system("cls");
	
	int l;	//for loops
	int i=0,j=0,timing,toss,choose=0,a,o,ht;
	int no_of_overs;
	
	for(l = 0;l<2;l++)
	{
		g[l].runs=0;
		g[l].wickets=0;
		g[l].balls=0;
		g[l].overs=0;
	}
	
	printf("Select number of overs: ");
	printf("\n 1. 1 over\n 2. 5 overs\n 3. 10 overs\n 4. 15 overs\n 5. 20 overs\n 6. 30 overs\n 7. 50 overs\n");
	scanf("%d", &o);
	switch(o)
	{
		case 1:
			no_of_overs = 1;
			wkts=2;
			break;
		case 2:
			no_of_overs = 5;
			wkts=3;
			break;
		case 3:
			no_of_overs = 10;
			wkts=5;
			break;
		case 4:
			no_of_overs = 15;
			wkts=7;
			break;
		case 5:
			no_of_overs = 20;
			wkts=10;
			break;
		case 6:
			no_of_overs = 30;
			wkts=10;
			break;
		case 7:
			no_of_overs = 50;
			wkts=10;
			break;
		default:
			printf("Invalid Entry!");
			start();			
	}
	
	system("cls");
	
	printf("Match is of %d over(s)", no_of_overs);
	printf("\nPress any key to continue\n");
	getch();
	system("cls");
	
	printf("Choose Heads or Tails for toss\n");
	
	while(1)
	{
		printf("Player 1: \n");
		printf(" 1. Heads\n 2. Tails\n");
		scanf("%d", &ht);
		system("cls");
		if(ht==1)
		{
			printf("\nPlayer 1 is Heads\n");
			printf("\nPlayer 2 is Tails\n");
			break;
		}
		else if(ht==2)
		{
			printf("\nPlayer 1 is Tails\n");
			printf("\nPlayer 2 is Heads\n");
			break;
		}
		else
		{
			system("cls");
			printf("Invalid Entry! Choose again\n");
		}
	}
	
	printf("\nPress any key to proceed for the toss");
	getch();
	system("cls");
	
	for(l=0;l<30;l++)
	{
		if((l%2)==0)
		{
			printf("\tHeads");
		}
		if((l%2)!=0)
		{
			printf("\tTails");
		}
		system("cls");
	}
	
	srand(time(0));
	a=rand()%2;
	toss=a;
	
	if(toss==0 && ht==1)	//heads
	{
		printf("Heads! Player 1 won the toss\n");
		printf("\nChoose Bat or Ball: ");
		printf("\n 1. Bat\n 2. Bowl\n");
		scanf("%d", &choose);
		if(choose==1)
			player = 1;
		else
			player = 2;
	}
	else if(toss==0 && ht==2)	//heads
	{
		printf("Heads! Player 2 won the toss\n");
		printf("\nChoose Bat or Ball: ");
		printf("\n 1. Bat\n 2. Bowl\n");
		scanf("%d", &choose);
		if(choose==2)
			player = 1;
		else
			player = 2;
	}
	else if(toss==1 && ht==2)	//tails
	{
		printf("Tails! Player 1 won the toss\n");
		printf("\nChoose Bat or Ball: ");
		printf("\n 1. Bat\n 2. Bowl\n");
		scanf("%d", &choose);
		if(choose==1)
			player = 1;
		else
			player = 2;
	}
	else if(toss==1 && ht==1)	//tails
	{
		printf("Tails! Player 2 won the toss\n");
		printf("\nChoose Bat or Ball: ");
		printf("\n 1. Bat\n 2. Bowl\n");
		scanf("%d", &choose);
		if(choose==2)
			player = 1;
		else
			player = 2;
	}
	system("cls");
	//batting
	for(l=0;l<2;l++)
	{
		printf("\n\tPlayer %d is batting", player);
		printf("\n\n\n\nPress any key to continue");
		getch();
		innings(l,no_of_overs);
		printf("\t\t\tPlayer %d Score\n", player);
		printf("\tRUNS : %d\t", g[l].runs);
		printf("WICKETS : %d\t", g[l].wickets);
		printf("OVERS : %d\n", g[l].overs);
		
		printf("\nPress any key to continue");
		getch();
		system("cls");
		
		FILE *fptr;
		fptr=fopen("project.txt","a");
		if(fptr==NULL)
		{
			printf ("\nFile could not be opened!");
			exit(1);
		}
		
		if(l==1)
		{
			if(player==1)
			{
				printf("\n\t\t\t\tFINAL SCORE\n\n");
				fprintf(fptr,"\n\t\t\t\tFINAL SCORE\n\n");
				printf(" -------------------------------------------------------------------------------\n");
				fprintf(fptr," -------------------------------------------------------------------------------\n");
				printf("|   Player\t|   Runs\t|   Wickets     |   Overs\t|   Result\t|\n");
				printf(" -------------------------------------------------------------------------------\n");
				fprintf(fptr,"|   Player\t|   Runs\t|   Wickets     |   Overs\t|   Result\t|\n");
				fprintf(fptr," -------------------------------------------------------------------------------\n");
				printf("|\t1\t|\t%d\t|\t%d\t|\t%d\t|\t \t|\n", g[1].runs,g[1].wickets,g[1].overs+1);
				fprintf(fptr,"|\t1\t|\t%d\t|\t%d\t|\t%d\t|\t \t|\n", g[1].runs,g[1].wickets,g[1].overs+1);
				printf("|\t2\t|\t%d\t|\t%d\t|\t%d\t|", g[0].runs,g[0].wickets,g[0].overs+1);
				fprintf(fptr,"|\t2\t|\t%d\t|\t%d\t|\t%d\t|", g[0].runs,g[0].wickets,g[0].overs+1);
				
				if(result==0)
				{
					printf("Game Draw\t|\n");
					fprintf(fptr,"Game Draw\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
				else if(result==1)
				{
					printf("Player 1 Won\t|\n");
					fprintf(fptr,"Player 1 Won\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
				else if(result==2)
				{
					printf("Player 2 Won\t|\n");
					fprintf(fptr,"Player 2 Won\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
				
			}
			if(player==2)
			{
			
				printf("\n\t\t\t\tFINAL SCORE\n\n");
				fprintf(fptr,"\n\t\t\t\tFINAL SCORE\n\n");
				printf(" -------------------------------------------------------------------------------\n");
				fprintf(fptr," -------------------------------------------------------------------------------\n");
				printf("|   Player\t|   Runs\t|   Wickets     |   Overs\t|   Result\t|\n");
				printf(" -------------------------------------------------------------------------------\n");
				fprintf(fptr,"|   Player\t|   Runs\t|   Wickets     |   Overs\t|   Result\t|\n");
				fprintf(fptr," -------------------------------------------------------------------------------\n");
				printf("|\t1\t|\t%d\t|\t%d\t|\t%d\t|\t \t|\n", g[0].runs,g[0].wickets,g[0].overs);
				fprintf(fptr,"|\t1\t|\t%d\t|\t%d\t|\t%d\t|\t \t|\n", g[0].runs,g[0].wickets,g[0].overs);
				printf("|\t2\t|\t%d\t|\t%d\t|\t%d\t|", g[1].runs,g[1].wickets,g[1].overs);
				fprintf(fptr,"|\t2\t|\t%d\t|\t%d\t|\t%d\t|", g[1].runs,g[1].wickets,g[1].overs);
				
				if(result==0)
				{
					printf("Game Draw\t|\n");
					fprintf(fptr,"Game Draw\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
				else if(result==1)
				{
					printf("Player 1 Won\t|\n");
					fprintf(fptr,"Player 1 Won\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
				else if(result==2)
				{
					printf("Player 2 Won\t|\n");
					fprintf(fptr,"Player 2 Won\t|\n");
					printf(" -------------------------------------------------------------------------------\n");
					fprintf(fptr," -------------------------------------------------------------------------------\n");
				}
			}
		
			printf("\nPress any key to continue");
			getch();		
			system("cls");
		
		}
		
		fclose(fptr);
		
		if(player==1)
		{
			player = 2;
		}
		else if(player==2)
		{
			player = 1;
		}
	}
	
	printf("\nMatch Ended!\n");
	printf("Press any key to continue");
	getch();
	system("cls");
	
	while(1)
	{
		printf("\n 1. Back to main menu\n 2. Exit\n");
	
		scanf("%d", &j);
	
		switch(j)
		{
			case 1:
				system("cls");
				return;
				
			case 2:
				exit(1);
				
			default:
				system("cls");
				printf("Invalid Entry!\n");
				
		}
	}
}

void instructions()
{
	int i;
	
	system("cls");
	printf("How To Play? \n");
	printf("Until a player won the toss follow the output and give whatever it asks you to give. Player 1 is always asked to choose heads or tails \n");
	printf("then player 2 gets the other. The Player who won the toss chooses either to Bat or to Bowl. The Player who chose batting and bowling has \n");
	printf("to proceed by pressing any key one by one when asked. Scoring is based on the timing of batting and bowling for both players. The player \n");
	printf("on the bowling side delivers the ball by pressing any key and the player batting will play the ball also by pressing any key. \n\n");
	printf("There will be two innings for each player and in the second inning the batting player will chase the target of the other player. There \n");
	printf("will be 2 wickets for each player in 1 over and 3 wickets for 5 overs matches and 5 wickets for each in 10 overs match and 7 wickets for \n");
	printf("15 overs match and 10 wickets for each in 20 overs, 30 overs and 50 overs match. If the second player chases the target score of the first \n");
	printf("player, the second player wins else the first player wins.\n\n");
	
	while(1)
	{
		printf(" 1. Back to main menu\n 2. Exit\n");
		scanf("%d", &i);
		
		switch(i)
		{	
			case 1:
				system("cls");
				return;
				
			case 2:
				exit(1);
			
			default:
				system("cls");
				printf("Invalid Entry!\n");
		}
	}
}

void ascore()
{
	int i;
	char ch;
	system ("cls");
	
	FILE *fptr; 	//retriving from file 
	
	if ((fptr=fopen("project.txt","r"))==NULL)
	{
		printf ("\n\t\t ERROR!!!");
		exit(1);
	}
	
	printf("\n\n");
	
	while (ch!=EOF)
	{
		ch=fgetc(fptr);
		printf ("%c",ch);
	}

	printf("\n\n");
	
	fclose (fptr);

	printf(" 1. Back to main menu\n 2. Exit\n");
	scanf("%d", &i);
	
	switch(i)
	{	
		case 1:
			system("cls");
			return;
		case 2:
			exit(1);
	}
}

void innings(int p,int no_of_overs)
{
	int timing;
	
	while(1)
	{	
		system("cls");
		
		printf("Ball %d of over %d \n", g[p].balls+1,g[p].overs+1);
		
		printf("\t\tSCORE BOARD \n");
		printf("RUNS : %d\t", g[p].runs);
		printf("WICKETS : %d\t", g[p].wickets);
		printf("OVER : %d\t", g[p].overs+1);
		if(p==1)
		{
			printf("TARGET : %d", g[p-1].runs+1);
		}
		printf("\n\nPress any key to deliver the ball \n");
		getch();
		printf("\t\nBowling...\n");
		sleep(1);
		fflush(stdin);
		clock_t before = clock();
		printf("\nPress any key to play \n\n");
		getch();
		clock_t after = clock();
		timing = after - before;
		
		if((timing>=1900) && (timing<=2100))
		{
			printf("\t6 RUNS!\t\n");
			printf("\a");
			g[p].runs = g[p].runs+6;
		}
		else if((timing>=1810) && (timing<1850) || (timing>2250) && (timing<=2290))
		{
			printf("\tCatch Out!\t\n");
			printf("\a");
			g[p].wickets = g[p].wickets+1;
		}
		else if((timing>=1600) && (timing<1900) || (timing>2100) && (timing<=2400))
		{
			printf("\t4 RUNS!\t\n");
			g[p].runs = g[p].runs+4;
		}
		else if((timing>=1510) && (timing<1550) || (timing>2550) && (timing<=2590))
		{
			printf("\tRun Out!\t\n");
			printf("\a");
			g[p].wickets = g[p].wickets+1;
		}
		else if((timing>=1200) && (timing<1600) || (timing>2400) && (timing<=2800))
		{
			printf("\t2 RUNS!\t\n");
			g[p].runs = g[p].runs+2;
		}
		else if((timing>=800) && (timing<1200)||(timing>2800) && (timing<=3000))
		{
			printf("\t1 RUN!\t\n");
			g[p].runs = g[p].runs+1;
		}
		else if((timing<800) || (timing>3000))
		{
			printf("\tOUT!\t\n");
			printf("\a");
			g[p].wickets = g[p].wickets+1;
		}
	
		printf("\n");
		g[p].balls++;

		if(g[p].balls==6)
		{
			g[p].balls = 0;
			g[p].overs++;
		}
		
		if(p==1)
		{
			if(g[p].runs>g[p-1].runs)
			{
				if(player==1)
				{
					printf("Player 1 Won!");	
					printf("\a");
					result = 1;
					printf("\n\nPress any key to continue\n");
					getch();
					system("cls");
					return;
				}
				else if(player==2)
				{
					printf("Player 2 Won!");	
					printf("\a");
					result = 2;
					printf("\n\nPress any key to continue\n");
					getch();
					system("cls");
					return;
				}
			}
			else
			{
				printf("Press any key to continue");
				getch();
				system("cls");
			}
		}
		else
		{
			printf("Press any key to continue");
			getch();
			system("cls");
		}
		
		if(g[p].wickets==wkts || g[p].overs==no_of_overs)
		{
			
			if(g[p].wickets==wkts)
			{
				printf("\n\tALL OUT!\n");
				printf("\a");
			}
			if(g[p].overs==no_of_overs)
			{
				printf("\n\tOVERS ENDED!\n");
				printf("\a");
			}
			
			printf("\nPress any key to continue");
			getch();
			system("cls");
			break;
		}
	}	//while loop ends
	
	if(p==1)
	{	
		if(g[p].runs<g[p-1].runs)
		{
			if(player==1)
			{
				printf("Player 2 Won!");
				printf("\a");
				result = 2;
				printf("\nPress any key to continue\n");
				getch();
				system("cls");
				return;
			}
			else if(player==2)
			{
				printf("Player 1 Won!");
				result = 1;
				printf("\a");
				printf("\nPress any key to continue\n");
				getch();
				system("cls");
				return;
			}
		}
		else if(g[p].runs==g[p-1].runs)
		{
			printf("Game Draw!");
			result = 0;
			printf("\a");
			printf("\n\nPress any key to continue\n");
			getch();
			system("cls");
			return;
		}
	}
}
