#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>

int menu_inicial()
{
    int x, y, opcao;

    const int LIN = 50;
    const int COL = 75;

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
    cputsxy (30, 10, "* SPACE INVADERS *");
    textcolor(LIGHTCYAN);
    cputsxy (34, 15, "- Menu -");
    cputsxy (26, 22, "1. Novo Jogo");
    cputsxy (26, 24, "2. Carregar Jogo");
    cputsxy (26, 26, "3. High Scores");
    cputsxy (26, 28, "4. Sair");
    cputsxy (26, 32, "Digite: ");
    scanf("%d", &opcao);
    gotoxy(41, 32);
    textcolor(YELLOW);
    cputsxy (24, 53, "<> Mover");
    cputsxy (24, 55, "S Salvar");
    putchxy(36,53,'|');
    putchxy(36,54,'|');
    putchxy(36,55,'|');
    cputsxy (40, 53, "|_| Atira");
    cputsxy (40, 55, "P Pausar");

    return opcao;
}

void ex_jogo()
{
    char nave1[4] = {" @ "}, nave2[4] = {"@@@"};
    int i, j, cont = 1;
    const int LIN = 50;
    const int COL = 75;

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
        gotoxy(41, 32);
        textcolor(YELLOW);
        cputsxy (24, 53, "<> Mover");
        cputsxy (24, 55, "S Salvar");
        putchxy(36,53,'|');
        putchxy(36,54,'|');
        putchxy(36,55,'|');
        cputsxy (40, 53, "|_| Atira");
        cputsxy (40, 55, "P Pausar");

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
