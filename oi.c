#include <stdio.h>
#include <conio2.h>

typedef struct inim
{
    int vida;
    int x, y;
    char desenha1[4], desenha2[4];
}INIM;

void preenche_aliens(INIM *n, int x, int y)
{
	n->vida = 1;
	n->x = x;
	n->y = y;
	n->desenha1[0] = '@';
	n->desenha1[1] = ' ';
	n->desenha1[2] = '@';
	n->desenha1[3] = '\0';
	n->desenha2[0] = ' ';
	n->desenha2[1] = '@';
	n->desenha2[2] = ' ';
	n->desenha2[3] = '\0';
}

int main()
{
	int i, j, flag = 0;
	INIM aliens[5][5];

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			preenche_aliens(&aliens[i][j], i, j);
		}
	}
	textcolor(LIGHTCYAN);
	printf("%s\n", aliens[0][0].desenha1);
	printf("%s", aliens[0][0].desenha2);
	printf("%s\n", aliens[0][1].desenha1);
	printf("%s", aliens[0][1].desenha2);
	/*for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			gotoxy(10, -20);
			if(i % 2 == 0)
                printf("%s", aliens[i][j].desenha1);
            else
                printf("%s", aliens[i][j].desenha2);
		}
		printf("\n");
		/*if(flag == 0)
            if(i == 4)
        {
            i = 0;
            flag = 1;
        }*/
    //}*/

	return 0;
}
