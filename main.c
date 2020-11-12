#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>
void imprime_inimigos()
{
    int i, j;
    char aliens[10][15] = {'@',' ','@','@',' ','@','@',' ','@','@',' ','@','@',' ','@',
                          ' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',
                          '@',' ','@','@',' ','@','@',' ','@','@',' ','@','@',' ','@',
                          ' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',
                           '@',' ','@','@',' ','@','@',' ','@','@',' ','@','@',' ','@',
                           ' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',
                           '@',' ','@','@',' ','@','@',' ','@','@',' ','@','@',' ','@',
                           ' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',
                           '@',' ','@','@',' ','@','@',' ','@','@',' ','@','@',' ','@',
                           ' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' ',' ','@',' '};

    textcolor(LIGHTCYAN);
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 15; j++)
        {
            printf("%c", aliens[i][j]);
        }
        printf("\n");
    }
}
int menu_inicial()
{
    int x, y, opcao;

    const int LIN = 30;
    const int COL = 40;

    textcolor(GREEN);
    x = 1;
    for (y = 1; y <= COL; y++)
        putchxy(y,x,'_');
    x = LIN;
    for(y = 1; y <= COL; y++)
        putchxy(y,x,'_');
    y = 1;
    for (x = 1; x <= LIN; x++)
        if(x > 1)
            putchxy(y,x,'|');
    y = COL;
    for (x = 1; x <= LIN; x++)
        if(x > 1)
            putchxy(y,x,'|');
    cputsxy (11, 8, "* SPACE INVADERS *");
    textcolor(LIGHTCYAN);
    cputsxy (15, 12, "- Menu -");
    cputsxy (11, 15, "1. Novo Jogo");
    cputsxy (11, 16, "2. Carregar Jogo");
    cputsxy (11, 17, "3. High Scores");
    cputsxy (11, 18, "4. Sair");
    cputsxy (11, 20, "Digite: ");
    textcolor(YELLOW);
    cputsxy (9, 31, "<> Mover");
    cputsxy (9, 32, "S Salvar");
    putchxy(18,31,'|');
    putchxy(18,32,'|');
    cputsxy (20, 31, "|_| Atira");
    cputsxy (20, 32, "P Pausar");
    gotoxy(18, 20);
    scanf("%d", &opcao);

    return opcao;
}

void ex_jogo()
{
    char nave1[4] = {" @ "}, nave2[4] = {"@@@"};
    int i, j, cont = 1;
    const int LIN = 20;
    const int COL = 30;

    clrscr();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        textbackground(BLACK);
        textcolor(GREEN);
        i = 1;
        for(j = 1; j<= COL; j++)
            putchxy(j,i,'_');
        i = LIN;
        for(j = 1; j <= COL; j++)
            putchxy(j, i, '_');
        j = 1;
        for(i = 1; i <= LIN; i++)
            if(i > 1)
                putchxy(j, i, '|');
        j = COL;
        for(i = 1; i <= LIN; i++)
            if(i > 1)
                putchxy(j, i, '|');
        gotoxy(1, 2);
        imprime_inimigos();
        gotoxy(41, 32);
        textcolor(YELLOW);
        cputsxy (24, 23, "<> Mover");
        cputsxy (24, 25, "S Salvar");
        putchxy(36,23,'|');
        putchxy(36,24,'|');
        putchxy(36,25,'|');
        cputsxy (40, 23, "|_| Atira");
        cputsxy (40, 25, "P Pausar");

        j = 38;
        i = 12;
        while(1)
        {
            int aux = j;
            int auy = i;
            if (GetKeyState(VK_RIGHT) & 0x80)
            {
                j += 1;
                cont = 1;
            }
            if (GetKeyState(VK_LEFT) & 0x80)
            {
                j -= 1;
                cont = 1;
            }
            if (GetKeyState(VK_UP) & 0x80)
            {
                i -= 1;
                cont = 1;
            }
            if (GetKeyState(VK_DOWN) & 0x80)
            {
                i += 1;
                cont = 1;
            }
            if (GetKeyState(VK_ESCAPE) & 0x80)
                break;

            if(j > COL - 3)
                j = COL - 3;
            if(j < 2)
                j = 2;
            if(i > LIN - 2)
                i = LIN - 2;
            if(i < 2)
                i = 2;

            if(cont)
            {
                textbackground(BLACK);
                putchxy((aux + 1),auy,' ');
                putchxy((aux + 1),(auy + 1),' ');
                putchxy(aux,(auy + 1),' ');
                putchxy((aux + 2),(auy + 1),' ');
                textcolor(GREEN);
                cputsxy (j, i, nave1);
                cputsxy (j, (i + 1), nave2);
            }
            Sleep(90);
            cont = 0;
        }
    }
    clrscr();
}


int main()
{
    int op;

    op = menu_inicial();
    switch(op)
    {
    case 1:
        ex_jogo();
        break;
    case 2:
        clrscr();
        printf("Oi2\n");
        break;
    case 3:
        clrscr();
        printf("Oi3\n");
    case 4:
        clrscr();
        return 0;
        break;
    }

    return 0;
}
