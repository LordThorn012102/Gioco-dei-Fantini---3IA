#include <iostream>
#include <windows.h>
#pragma comment(lib, "user32")
#include <time.h>
#include <cstdlib>
#define tempo1 50
#define tempo2 200          //Variabili globali per lo Sleep
#define tempo3 25
#define tempo4 15
#ifndef CURSORI_H_INCLUDED
#define CURSORI_H_INCLUDED
using namespace std;

void setColor(int bg, int fg)
{
int val;
if (bg<0)
bg=0;
if (fg>15)                                           //Funzione per settare il colore dello sfondo
fg=15;
val=bg*16+fg;
SetConsoleTextAttribute(
GetStdHandle(STD_OUTPUT_HANDLE),
val);
}
void gotoXY(int x, int y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);          //Funzione gotoXY per andare in una coordinata precisa
    SetConsoleCursorPosition(hConsole, CursorPos);
}
void stampaMenu(int &sce);
void impostazioni(int &lunghTab, int &nfan);
void stampatabellone_1_e_2_giocatori(int lunghTab);
void stampatabellone_3_giocatori(int lunghTab);
void stampatabellone_4_giocatori(int lunghTab);
int giocoIppico(int &nfan, int &lunghtab, int pos1, int pos2, int pos3, int pos4,int &cavallogicatore1,int &cavallogiocatore2,int &cavallogiocatore3, int &cavallogiocatore4,int classifica[],int posizione);      //tutti i sottoprogrammi utilizzati//
void stampaDadi(int &n1, int &n2);
void StampaGrafica();
int muoviCavallo(int pos1, int pos2, int pos3, int pos4, int &n1, int &n2, int &lunghTab, int &turno);
int main()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    srand((unsigned)time(NULL));
    int sce;                                //Scelte
    int nfan=1;                             //Numero dei Fantini
    int lunghTab=25;                        //Lunghezza del tabellone
    int pos1=0;
    int pos2=0;                             //Posizione cavalli
    int pos3=0;
    int pos4=0;
    int classifica[5]={0,1,2,3,4};
    int posizione=1;
    int cavallogiocatore1=0;
    int cavallogiocatore2=0;
    int cavallogiocatore3=0;
    int cavallogiocatore4=0;
    stampaMenu(sce);
    switch(sce)
    {
    case 1:
        {
            impostazioni(lunghTab, nfan);setColor(0,15);    //Non è presente il break perché dopop impostazioni non avrebbe eseguito il gioco
        }
    case 2:
        {
            giocoIppico(nfan, lunghTab , pos1, pos2, pos3, pos4,cavallogiocatore1,cavallogiocatore2,cavallogiocatore3,cavallogiocatore4,classifica,posizione);
            break;

        }
    case 3:
        {
            break;
        }
    default:
        {
            setColor(0,12);cout << "Scelta sbagliata, selezionane una valida:" << endl;setColor(0,15);
        }
    }
    return 0;
}
#endif  CURSORI_H_INCLUDED
void stampaMenu(int &sce)
{
    sce=0;
    system("cls");
    Sleep(tempo2);
    cout << endl << "                    ";

    setColor(0, 2);cout << R"(

         ___ ___ ___   ___ ___    ___  ___ ___   ___ _   _  _ _____ ___ _  _ ___ 
        / __|_ _/ _ \ / __/ _ \  |   \| __|_ _| | __/_\ | \| |_   _|_ _| \| |_ _|
       | (_ || | (_) | (_| (_) | | |) | _| | |  | _/ _ \| .` | | |  | || .` || | 
        \___|___\___/ \___\___/  |___/|___|___| |_/_/ \_\_|\_| |_| |___|_|\_|___|

        by Masini Mattia e Balli Tommaso                                                              
    )"<< endl;

        cout << R"(

                                   |\    /|
                                ___| \,,/_/
                             ---__/ \/    \
                            __--/     (D)  \
                            _ -/    (_      \
                           // /       \_ /  -\
     __-------_____--___--/           / \_ O o)
    /                                 /   \__/
    /                                 /
    ||          )                   \_/\
    ||         /              _      /  |
    | |      /--______      ___\    /\  :
    | /   __-  - _/   ------    |  |   \ \
    |   -  -   /                | |     \ )
    |  |   -  |                 | )     | |
    | |    | |                 | |    | |
    | |    < |                 | |   |_/
    < |    /__\                <  \
    /__\                       /___\


    )"<< endl;



    setColor(0,12); cout << "S C E L T A: " << endl;
    
    Sleep(tempo2);

     cout << "  ____________________ "   << endl;Sleep(tempo1);
     cout << " ()___________________)"   << endl;Sleep(tempo1);
     cout << " /                   /"     << endl;Sleep(tempo1);
     cout << " \\ 1: IMPOSTAZIONI   \\"   << endl;Sleep(tempo1);
     cout << " |                    |"   << endl;Sleep(tempo1);
     cout << " ( 2: AVVIA IL GIOCO  ("   << endl;Sleep(tempo1);
     cout << " /                    /"   << endl;Sleep(tempo1);
     cout << " \\ 3: ESCI           \\" << endl;Sleep(tempo1);
     cout << " \\____________________\\"  << endl;Sleep(tempo1);
     cout << " ()___________________)"    << endl;Sleep(tempo1);
     cout << endl << "              SCEGLI: ";

    do
    {
         setColor(0,10);cin >> sce;
         setColor(0,15);
         if(sce!=1 && sce!=2 && sce!=3)
         {
             setColor(0,12);cout << endl << "Scelta sbagliata, selezionane una valida: ";setColor(0,15);
         }

    }while(sce!=1 && sce!=2 && sce!=3);
}
void impostazioni(int &lunghTab, int &nfan)
{
    system("cls");
    setColor(0,11);cout << endl << "                IMPOSTAZIONI PER LA GARA: " << endl;
    cout << "          "; setColor(0,11); cout << "  _____________________    " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " ()____________________)   " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " /                    /    " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " \\  1: NUM FANTINI    \\  " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " |                     |   " << endl;Sleep(tempo1);                                         //Grafica per stampare le impostazioni e per far inserire all' utente il numero dei fantini(giocatori) e la lunghezza del percorso
    cout << "          "; setColor(0,11); cout << " (                     (   " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " /  2: LUNGHEZZA PISTA /   " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " \\                     \\ " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " \\_____________________\\ " << endl;Sleep(tempo1);
    cout << "          "; setColor(0,11); cout << " ()____________________)   " << endl;Sleep(tempo1);setColor(0,15);

    setColor(0,11); cout << endl << " Inserisci il numero dei fantini (da 1 a 4): ";
    cin >> nfan;
    while(nfan<1 || nfan>4)
    {
        setColor(0,12);cout << " Devi inserire un numero tra 1 e 4!: ";
        setColor(0,11);cin >> nfan;
    }
    setColor(0,11); cout << endl << " Inserisci la lunghezza del percorso (da 25 a 65): ";
    cin >> lunghTab;
    while(lunghTab<25 || lunghTab>65)
    {
        setColor(0,12);cout << " Devi inserire un numero tra 25 e 65!: ";
        setColor(0,11);cin >> lunghTab;setColor(0,15);
    }
}
void StampaGrafica()
{
    system("cls");
    cout << endl;
    setColor(0,2);cout << "TUTTI I GIOCATORI SI PREPARINO...." << endl;setColor(0,15);
}
void stampatabellone_1_e_2_giocatori(int lunghTab)
{
    for(int c=0;c<4;c++)
        {
            cout << "   ";
        }
    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";                                    //Ciclo utilizzato per la parte superiore del percorso
            Sleep(tempo3);
        }
    cout << endl;
    setColor(0,11);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,11);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;                           //Grafica per la stampa dei cavalli sul tabellone
    Sleep(tempo3);                                                                                          //Queste righe di codice si ripteranno anche nei successivi stampatabelloni
    setColor(0,11);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;setColor(0,15);
    Sleep(tempo3);
    for(int c=0;c<4;c++)
        {
            cout << "   ";
        }
    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";                             //Ciclo utilizzato per la parte inferiore del percorso
            Sleep(tempo3);
        }
}
void stampatabellone_3_giocatori(int lunghTab)
{
    for(int c=0;c<4;c++)
        {
            cout << "   ";
            Sleep(tempo3);
        }
    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";
            Sleep(tempo3);
        }
    cout << endl;
    setColor(0,11); cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,11);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,11);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,10);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,10);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,10);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;setColor(0,15);
    Sleep(tempo3);
    for(int c=0;c<4;c++)
        {
            cout << "   ";
            Sleep(tempo3);
        }

    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";
            Sleep(tempo3);
        }
}
void  stampatabellone_4_giocatori(int lunghTab)
{
    for(int c=0;c<4;c++)
        {
            cout << "   ";
        }
    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";
            Sleep(tempo3);
        }
    cout << endl;
    setColor(0,11);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,11);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,11);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,12);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,10); cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,10);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,10);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,14);cout << "      ____,;; ";setColor(0,15);cout << "|" << endl;
    Sleep(tempo3);
    setColor(0,14);cout << "    ~(_)__)\\| ";setColor(0,15);cout << "| " << endl;
    Sleep(tempo3);
    setColor(0,14);cout << "     /   \\    ";setColor(0,15);cout << "|" << endl;setColor(0,15);
    Sleep(tempo3);
    for(int c=0;c<4;c++)
        {
            cout << "   ";
        }

    for(int c=0;c<lunghTab;c++)
        {
            cout << "  |";
            Sleep(tempo3);
        }
}
int giocoIppico(int &nfan, int &lunghTab, int pos1, int pos2, int pos3, int pos4,int &cavallogiocatore1,int &cavallogiocatore2,int &cavallogiocatore3,int &cavallogiocatore4, int classifica[],int posizione)
{
    int arrivo1=0;
    int arrivo2=0;                                         //Variabili utilizzate per tenere conto la posizione dei cavalli all'arrivo 
    int arrivo3=0;
    int arrivo4=0;
    int n1;                                               //Variabili utilizzate per i numeri dei dadi casuali
    int n2;
    int sce;                                                //Scelta lancio dei dadi
    int turno=1;
    int x1=0;                                               //x g1 del gotoXY
    int x2=0;                                                //x cpu del gotoXY
    int x3=0;                                                                               //x g3 del gotoXY
    int x4=0;                                                                   //x g4 del gotoXY
    system("cls");

    if(nfan==1)                               //Condizione che fa cambiare il tabellone e i fantini in base al numero di fantini scelti 
    {
        sce=0;
        StampaGrafica();
        cout << endl;
        stampatabellone_1_e_2_giocatori(lunghTab);
        cout << endl;
        cout << endl;
        do
        {
            setColor(0,11);cout << "  CAVALLO DEL G 1: " << pos1 << " " << endl;
            cout << endl;
            setColor(0,12);cout << "  CAVALLO DEL COMPUTER : " << pos2 << " " << endl;setColor(0,15);
            cout << endl;
            turno=1;
            if(pos1<lunghTab)                                  //Condizione utilizzata per verificare che il cavallo non sia gia' arrivato all'arrivo
            {
                gotoXY(0,23);
                setColor(0,11);
                cout << "     VIA!" <<endl;
                setColor(0,11);cout << "  Il giocatore 1 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,23);
                    cin >> sce;
                }
                if(sce==1)
                    {
                        stampaDadi(n1, n2);
                        cout << endl;setColor(0,12);system("pause");

                    }

                pos1=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2,lunghTab, turno);             //Richiamo alla funzione muovi cavallo
                gotoXY(x1,4);
                cout << "              ";setColor(0,15);                                       //Righe di codice utilizzate per la cancellazione della grafica del cavallo nel punto precedente
                gotoXY(x1,5);
                cout << "              ";setColor(0,15);
                gotoXY(x1,6);
                cout << "              ";setColor(0,15);
                x1=pos1*3;
                if(pos1>lunghTab)
                {
                    x1=(lunghTab*3)+1;                                       //ciclo utilizzato per fare in modo che i cavalli si fermino all'arrivo
                }
                gotoXY(x1,4);
                setColor(0,11);cout << "      ____,;; ";setColor(0,15);
                gotoXY(x1,5);
                setColor(0,11);cout << "    ~(_)__)\\| ";setColor(0,15);                       //Righe utilizzzate per la stampa del cavallo nella nuova posizione
                gotoXY(x1,6);
                setColor(0,11);cout << "     /   \\    ";setColor(0,15);
            }
            if(pos1>lunghTab && arrivo1<1)                                                    //Condizione utilizzata per verificare se il cavallo è arrivato a destinazione
            {
                    cavallogiocatore1=classifica[posizione];                                  //Registra la posizione in un vettore
                    posizione++;                                                              
                    setColor(0,11);
                    gotoXY(17,12);
                    cout << endl;
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " << cavallogiocatore1<< endl;
                    arrivo1++;
            }
            turno=2;
            if(pos2<lunghTab)
                {
                    setColor(0,12);stampaDadi(n1,n2);
                    pos2=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                    gotoXY(x2,7);
                    cout << "              ";setColor(0,15);
                    gotoXY(x2,8);
                    cout << "              ";setColor(0,15);
                    gotoXY(x2,9);
                    cout << "              ";setColor(0,15);
                    x2=pos2*3;
                    if(pos2>lunghTab)
                    {
                        x2=(lunghTab*3)+1;
                    }
                    gotoXY(x2,7);
                    setColor(0,12);cout << "      ____,;; ";setColor(0,15);
                    gotoXY(x2,8);
                    setColor(0,12);cout << "    ~(_)__)\\| ";setColor(0,15);
                    gotoXY(x2,9);
                    setColor(0,12);cout << "     /   \\    ";setColor(0,15);
            }
              if(pos2>lunghTab&&arrivo2<1)
            {
                    cavallogiocatore2=classifica[posizione];
                    posizione++;
                    gotoXY(17,13);
                    setColor(0,12);
                    cout << endl;
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore2<< endl;
                    arrivo2++;
            }
            gotoXY(0,12);
        }while(pos1<lunghTab || pos2<lunghTab);
        gotoXY(0,40);
        system("pause");

    }
    if(nfan==2)
    {
        int arrivo1=0;
        int arrivo2=0;
        int arrivo3=0;
        int arrivo4=0;
        sce=0;
        StampaGrafica();
        cout << endl;
        stampatabellone_1_e_2_giocatori(lunghTab);
        cout << endl;
        cout << endl;
        do
        {
            cout << endl;
            setColor(0,11);cout << "  CAVALLO DEL G1: " << pos1 << " " << endl;
            cout << endl;
            setColor(0,12);cout << "  CAVALLO DEL G2: " << pos2 << " " << endl;setColor(0,15);
            cout << endl;
            turno=1;
            if(pos1<lunghTab)
                {
                    gotoXY(0,23);
                    cout << "VIA!" <<endl;
                    setColor(0,11);cout << "  Il giocatore 1 tira i dadi, premere 1 per farlo: ";
                    cin >> sce;
                    while(sce!=1)
                    {
                        gotoXY(46,23);
                        cin >> sce;
                    }
                    if(sce==1)
                    {
                        stampaDadi(n1, n2);
                    }
                    pos1=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2,lunghTab, turno);
                    gotoXY(x1,4);
                    cout << "              ";setColor(0,15);
                    gotoXY(x1,5);
                    cout << "              ";setColor(0,15);
                    gotoXY(x1,6);
                    cout << "              ";setColor(0,15);
                    x1=pos1*3;
                     if(pos1>lunghTab)
                {
                    x1=(lunghTab*3)+1;
                }
                    gotoXY(x1,4);
                    setColor(0,11);cout << "      ____,;;";setColor(0,15);
                    gotoXY(x1,5);
                    setColor(0,11);cout << "    ~(_)__)\\|";setColor(0,15);
                    gotoXY(x1,6);
                    setColor(0,11);cout << "     /   \\";setColor(0,15);
                }
         if(pos1>lunghTab)
            {
                if(arrivo1<1)
                {
                    cavallogiocatore1=classifica[posizione];
                    posizione++;
                    gotoXY(17,12);
                    setColor(0,11);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: "<<cavallogiocatore1<< endl;
                    arrivo1++;
                }
            }
                turno=2;
                if(pos2<lunghTab)
                {
                    gotoXY(0,24);
                    setColor(0,12);cout << "  Il giocatore 2 tira i dadi, premere 1 per farlo: ";
                    cin >> sce;
                    while(sce!=1)
                    {
                        gotoXY(46,24);
                        cin >> sce;
                    }
                    if(sce==1)
                    {
                        setColor(0,12);stampaDadi(n1, n2);
                    }

                    pos2=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                    gotoXY(x2,7);
                    cout << "              ";setColor(0,15);
                    gotoXY(x2,8);
                    cout << "              ";setColor(0,15);
                    gotoXY(x2,9);
                    cout << "              ";setColor(0,15);
                    x2=pos2*3;
                     if(pos2>lunghTab)
                    {
                        x2=(lunghTab*3)+1;
                    }
                    gotoXY(x2,7);
                    setColor(0,12);cout << "      ____,;;";setColor(0,15);
                    gotoXY(x2,8);
                    setColor(0,12);cout << "    ~(_)__)\\|";setColor(0,15);
                    gotoXY(x2,9);
                    setColor(0,12);cout << "     /   \\";setColor(0,15);
                }
              if(pos2>lunghTab)
            {
                if(arrivo2<1)
                {
                    cavallogiocatore2=classifica[posizione];
                    posizione++;
                    gotoXY(17,13);
                    setColor(0,12);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore2<< endl;
                    arrivo2++;
                }
            }
                gotoXY(0,12);
        }while(pos1<lunghTab || pos2<lunghTab);
        gotoXY(0,40);
        system("pause");
    }
    if(nfan==3)
    {
        sce=0;
        StampaGrafica();
        cout << endl;
        stampatabellone_3_giocatori(lunghTab);
        cout << endl;
        cout << endl;
        do
        {   
            cout << endl;
            setColor(0,11);cout << "CAVALLO DEL G1: " << pos1 << " " << endl;
            setColor(0,12);cout << "CAVALLO DEL G2: " << pos2 << " " << endl;
            setColor(0,10);cout << "CAVALLO DEL G3: " << pos3 << " " << endl;setColor(0,15);
            turno=1;
            if(pos1<lunghTab)
            {
                gotoXY(0,23);
                cout << "VIA!" <<endl;
                setColor(0,11);cout << "  Il giocatore 1 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,23);
                    cin >> sce;
                }
                if(sce==1)
                {
                    stampaDadi(n1, n2);
                }
                pos1=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2,lunghTab, turno);
                gotoXY(x1,4);
                cout << "              ";setColor(0,15);
                gotoXY(x1,5);
                cout << "              ";setColor(0,15);
                gotoXY(x1,6);
                cout << "              ";setColor(0,15);
                x1=pos1*3;
                  if(pos1>lunghTab)
                    {
                        x1=(lunghTab*3)+1;
                    }
                gotoXY(x1,4);
                setColor(0,11);cout << "      ____,;;";setColor(0,15);
                gotoXY(x1,5);
                setColor(0,11);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x1,6);
                setColor(0,11);cout << "     /   \\";setColor(0,15);
            }
             if(pos1>lunghTab)
            {
                if(arrivo1<1)
                {
                    cavallogiocatore1=classifica[posizione];
                    posizione++;
                    gotoXY(17,15);
                    setColor(0,11);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore1<< endl;
                    arrivo1++;
                }
            }
            turno=2;
            if(pos2<lunghTab)
            {
                gotoXY(0,24);
                setColor(0,12);cout << "  Il giocatore 2 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,24);
                    cin>> sce;
                }
                if(sce==1)
                {
                    setColor(0,12);stampaDadi(n1, n2);
                }
                pos2=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                gotoXY(x2,7);
                cout << "              ";setColor(0,15);
                gotoXY(x2,8);
                cout << "              ";setColor(0,15);
                gotoXY(x2,9);
                cout << "              ";setColor(0,15);
                x2=pos2*3;
                  if(pos2>lunghTab)
                    {
                        x2=(lunghTab*3)+1;
                    }
                gotoXY(x2,7);
                setColor(0,12);cout << "      ____,;;";setColor(0,15);
                gotoXY(x2,8);
                setColor(0,12);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x2,9);
                setColor(0,12);cout << "     /   \\";setColor(0,15);
            }
             if(pos2>lunghTab)
            {
                if(arrivo2<1)
                {
                    cavallogiocatore2=classifica[posizione];
                    posizione++;
                    gotoXY(17,16);
                    setColor(0,12);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore2<< endl;
                    arrivo2++;
                }
            }
            turno=3;
            if(pos3<lunghTab)
            {
                gotoXY(0,25);
                setColor(0,10);cout << "  Il giocatore 3 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,25);
                    cin>> sce;
                }
                if(sce==1)
                {
                    setColor(0,10);stampaDadi(n1, n2);
                }
                 pos3=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                gotoXY(x3,10);
                cout << "              ";setColor(0,15);
                gotoXY(x3,11);
                cout << "              ";setColor(0,15);
                gotoXY(x3,12);
                cout << "              ";setColor(0,15);
                x3=pos3*3;
                  if(pos3>lunghTab)
                    {
                        x3=(lunghTab*3)+1;
                    }
                gotoXY(x3,10);
                setColor(0,10);cout << "      ____,;;";setColor(0,15);
                gotoXY(x3,11);
                setColor(0,10);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x3,12);
                setColor(0,10);cout << "     /   \\";setColor(0,15);
            }
             if(pos3>lunghTab)
            {
                if(arrivo3<1)
                {
                    cavallogiocatore3=classifica[posizione];
                    posizione++;
                    gotoXY(17,17);
                    setColor(0,10);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore3<< endl;
                    arrivo3++;
                }
            }
            gotoXY(0,15);
        }while(pos1<lunghTab || pos2<lunghTab || pos3<lunghTab);
        gotoXY(0,40);
        system("pause");
    }
    if(nfan==4)
    {
        sce=0;
        StampaGrafica();
        cout << endl;
        stampatabellone_4_giocatori(lunghTab);
        cout << endl;
        cout << endl;
        do
        { 
            cout << endl;
            setColor(0,11);cout << "  CAVALLO DEL G1: " << pos1 << " " << endl;
            setColor(0,12);cout << "  CAVALLO DEL G2: " << pos2 << " " << endl;
            setColor(0,10);cout << "  CAVALLO DEL G3: " << pos3 << " " << endl;
            setColor(0,14);cout << "  CAVALLO DEL G4: " << pos4 << " " << endl;setColor(0,15);
            turno=1;
            if(pos1<lunghTab)
            {
                gotoXY(0,23);
                cout << "VIA!" <<endl;
                setColor(0,11);cout << "  Il giocatore 1 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,23);
                    cin >> sce;
                }
                if(sce==1)
                {
                    stampaDadi(n1, n2);
                }
                pos1=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2,lunghTab, turno);
                gotoXY(x1,4);
                cout << "              ";setColor(0,15);
                gotoXY(x1,5);
                cout << "              ";setColor(0,15);
                gotoXY(x1,6);
                cout << "              ";setColor(0,15);
                x1=pos1*3;
                  if(pos1>lunghTab)
                    {
                        x1=(lunghTab*3)+1;
                    }
                gotoXY(x1,4);
                setColor(0,11);cout << "      ____,;;";setColor(0,15);
                gotoXY(x1,5);
                setColor(0,11);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x1,6);
                setColor(0,11);cout << "     /   \\";setColor(0,15);
            }
             if(pos1>lunghTab)
            {
                if(arrivo1<1)
                {
                    cavallogiocatore1=classifica[posizione];
                    posizione++;
                    gotoXY(17,18);
                    setColor(0,11);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore1<< endl;
                    arrivo1++;
                }
            }
            turno=2;
            if(pos2<lunghTab)
            {
                gotoXY(0,24);
                setColor(0,12);cout << "  Il giocatore 2 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,24);
                    cin>> sce;
                }
                if(sce==1)
                {
                    setColor(0,12);stampaDadi(n1, n2);
                }
                pos2=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                gotoXY(x2,7);
                cout << "              ";setColor(0,15);
                gotoXY(x2,8);
                cout << "              ";setColor(0,15);
                gotoXY(x2,9);
                cout << "              ";setColor(0,15);
                x2=pos2*3;
                  if(pos2>lunghTab)
                    {
                        x2=(lunghTab*3)+1;
                    }
                gotoXY(x2,7);
                setColor(0,12);cout << "      ____,;;";setColor(0,15);
                gotoXY(x2,8);
                setColor(0,12);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x2,9);
                setColor(0,12);cout << "     /   \\";setColor(0,15);
            }
             if(pos2>lunghTab)
            {
                if(arrivo2<1)
                {
                    cavallogiocatore2=classifica[posizione];
                    posizione++;
                    gotoXY(17,19);
                    setColor(0,12);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore2<< endl;
                    arrivo2++;
                }
            }
            turno=3;
            if(pos3<lunghTab)
            {
                gotoXY(0,25);
                setColor(0,10);cout << "  Il giocatore 3 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,25);
                    cin>> sce;
                }
                if(sce==1)
                {
                    setColor(0,10);stampaDadi(n1, n2);
                }
                 pos3=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                gotoXY(x3,10);
                cout << "              ";setColor(0,15);
                gotoXY(x3,11);
                cout << "              ";setColor(0,15);
                gotoXY(x3,12);
                cout << "              ";setColor(0,15);
                x3=pos3*3;
                  if(pos3>lunghTab)
                    {
                        x3=(lunghTab*3)+1;
                    }
                gotoXY(x3,10);
                setColor(0,10);cout << "      ____,;;";setColor(0,15);
                gotoXY(x3,11);
                setColor(0,10);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x3,12);
                setColor(0,10);cout << "     /   \\";setColor(0,15);
            }
             if(pos3>lunghTab)
            {
                if(arrivo3<1)
                {
                    cavallogiocatore3=classifica[posizione];
                    posizione++;
                    gotoXY(17,20);
                    setColor(0,10);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore3<< endl;
                    arrivo3++;
                }
            }
            turno=4;
            if(pos4<lunghTab)
            {
                gotoXY(0,26);
                setColor(0,14);cout << "  Il giocatore 4 tira i dadi, premere 1 per farlo: ";
                cin >> sce;
                while(sce!=1)
                {
                    gotoXY(46,26);
                    cin>> sce;
                }
                if(sce==1)
                {
                    setColor(0,14);stampaDadi(n1, n2);
                }
                pos4=muoviCavallo(pos1, pos2, pos3, pos4, n1, n2, lunghTab, turno);
                gotoXY(x4,13);
                cout << "              ";setColor(0,15);
                gotoXY(x4,14);
                cout << "              ";setColor(0,15);
                gotoXY(x4,15);
                cout << "              ";setColor(0,15);
                x4=pos4*3;
                  if(pos4>lunghTab)
                    {
                        x4=(lunghTab*3)+1;
                    }
                gotoXY(x4,13);
                setColor(0,14);cout << "      ____,;;";setColor(0,15);
                gotoXY(x4,14);
                setColor(0,14);cout << "    ~(_)__)\\|";setColor(0,15);
                gotoXY(x4,15);
                setColor(0,14);cout << "     /   \\";setColor(0,15);
            }
             if(pos4>lunghTab)
            {
                if(arrivo4<1)
                {
                    cavallogiocatore4=classifica[posizione];
                    posizione++;
                    gotoXY(17,21);
                    setColor(0,14);
                    cout << "   CAVALLO ARRIVATO IN POSIZIONE NUMERO: " <<cavallogiocatore4<< endl;
                    arrivo4++;
                }
            }
            gotoXY(0,18);
        }while(pos1<lunghTab || pos2<lunghTab || pos3<lunghTab || pos4<lunghTab);
        gotoXY(0,40);
        system("pause");

    }
}
void stampaDadi(int &n1, int &n2)
{
    int somma;
    n1=rand()% 6+1;                                 //N casuale tra 1 e 12
    n2=rand()% 6+1;
    gotoXY(0,34);
    cout << "DADI" << endl;
    for(int i=0;i<5;i++)                        //Ciclo  utilizzato per la stampa dei dadi e animazioni varie
        {
            gotoXY(0,35);
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            cout << "                                                                                                  " << endl;
            gotoXY(0,35);
            cout << " _____ " << endl;
            cout << "|     |" << endl;
            cout << "|  o  |" << endl;
            cout << "|_____|" << endl;
            cout << " _____ " << endl;
            cout << "|     |" << endl;
            cout << "|  o  |" << endl;
            cout << "|_____|" << endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            gotoXY(0,35);
            cout << " _____ " << endl;
            cout << "|o    |" << endl;
            cout << "|     |" << endl;
            cout << "|____o|" << endl;
            cout << " _____ " << endl;
            cout << "|o    |" << endl;
            cout << "|     |" << endl;
            cout << "|____o|" << endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            gotoXY(0,35);
            cout << " _____ " << endl;
            cout << "|o    |" << endl;
            cout << "|  o  |" << endl;
            cout << "|____o|" << endl;
            cout << " _____ " << endl;
            cout << "|o    |" << endl;
            cout << "|  o  |" << endl;
            cout << "|____o|" << endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            gotoXY(0,35);
            cout << " _____ " <<endl;
            cout << "|o   o|" <<endl;
            cout << "|     |" <<endl;
            cout << "|o___o|" <<endl;
            cout << " _____ " <<endl;
            cout << "|o   o|" <<endl;
            cout << "|     |" <<endl;
            cout << "|o___o|" <<endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            gotoXY(0,35);
            cout << " _____ " << endl;
            cout << "|o   o|" << endl;
            cout << "|  o  |" << endl;
            cout << "|o___o|" << endl;
            cout << " _____ " << endl;
            cout << "|o   o|" << endl;
            cout << "|  o  |" << endl;
            cout << "|o___o|" << endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            gotoXY(0,35);
            cout << " _____ " << endl;
            cout << "|o   o|" << endl;
            cout << "|o   o|" << endl;
            cout << "|o___o|" << endl;
            cout << " _____ " << endl;
            cout << "|o   o|" << endl;
            cout << "|o   o|" << endl;
            cout << "|o___o|" << endl;Sleep(tempo4);
            gotoXY(0,35);
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
            cout << "       " << endl;
        }
    if(n1==1)                                         //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|     |" << endl;
            gotoXY(0,37);
            cout << "|  o  |" << endl;
            gotoXY(0,38);
            cout << "|_____|" << endl;Sleep(tempo4);
        }
    if(n1==2)                                        //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|o    |" << endl;
            gotoXY(0,37);
            cout << "|     |" << endl;
            gotoXY(0,38);
            cout << "|____o|" << endl;
        }
    if(n1==3)                                       //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|o    |" << endl;
            gotoXY(0,37);
            cout << "|  o  |" << endl;
            gotoXY(0,38);
            cout << "|____o|" << endl;
        }
    if(n1==4)                                       //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|o   o|" << endl;
            gotoXY(0,37);
            cout << "|     |" << endl;
            gotoXY(0,38);
            cout << "|o___o|" << endl;
        }
    if(n1==5)                                      //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|o   o|" << endl;
            gotoXY(0,37);
            cout << "|  o  |" << endl;
            gotoXY(0,38);
            cout << "|o___o|" << endl;
        }
    if(n1==6)                                       //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(0,35);
            cout << " _____ " << endl;
            gotoXY(0,36);
            cout << "|o   o|" << endl;
            gotoXY(0,37);
            cout << "|o   o|" << endl;
            gotoXY(0,38);
            cout << "|o___o|" << endl;
        }
    if(n2==1)                                        //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|     |" << endl;
            gotoXY(7,37);
            cout << "|  o  |" << endl;
            gotoXY(7,38);
            cout << "|_____|" << endl;Sleep(tempo4);
        }
    if(n2==2)                                        //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|o    |" << endl;
            gotoXY(7,37);
            cout << "|     |" << endl;
            gotoXY(7,38);
            cout << "|____o|" << endl;
        }
    if(n2==3)                                       //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|o    |" << endl;
            gotoXY(7,37);
            cout << "|  o  |" << endl;
            gotoXY(7,38);
            cout << "|____o|" << endl;
        }
    if(n2==4)                                     //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|o   o|" << endl;
            gotoXY(7,37);
            cout << "|     |" << endl;
            gotoXY(7,38);
            cout << "|o___o|" << endl;
        }
    if(n2==5)                                  //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|o   o|" << endl;
            gotoXY(7,37);
            cout << "|  o  |" << endl;
            gotoXY(7,38);
            cout << "|o___o|" << endl;
        }
    if(n2==6)                               //condizione per stampare la grafica adeguata al numero uscito//
        {
            gotoXY(7,35);
            cout << " _____ " << endl;
            gotoXY(7,36);
            cout << "|o   o|" << endl;
            gotoXY(7,37);
            cout << "|o   o|" << endl;
            gotoXY(7,38);
            cout << "|o___o|" << endl;
        }

    somma=n1+n2;
    gotoXY(0,39);
    cout << "Hai fatto " << somma;setColor(0,15);
}
int muoviCavallo(int pos1, int pos2, int pos3, int pos4, int &n1, int &n2, int &lunghTab, int &turno)
{
    int somma;
    if(turno==1)
    {
        if(n1==n2)                            //Condizione utilizzata per verificcare se i due numeri usciti sono uguali//
        {
             somma=((n1+n2)*1.30);
             pos1=pos1+somma;
             gotoXY(13,39);
             setColor(0,11);
             cout << " Complimenti! hai fatto doppio numero! il risultato sara' incrementato del 30%!" ;              //Messaggio che dichiara l'aumento del 30%//
        }
        if(n1!=n2)
        {
            somma=n1+n2;
            pos1=pos1+somma;

        }
        if(pos1%5==0)             //condizione  utilizzata per verificare se il cavallo si trova su una pedina che è multipla di 5//
        {
            pos1=pos1-6;
            gotoXY(13,39);
            setColor(0,11);
            cout << " Mi dispiace! sei costretto a tornare indietro di sei caselle!" ;  //messaggio che dichiara ch il cavalllo è costretto a tornare indietro//
            if(pos1<0)
            {
                pos1=0;
            }
        }
        return pos1;
    }
    if(turno==2)
    {
        if(n1==n2)
        {
             somma=((n1+n2)*1.30);
             pos2=pos2+somma;
             gotoXY(13,39);
             setColor(0,12);
             cout << " Complimenti! hai fatto doppio numero! il risultato sara' incrementato del 30%!" ;
        }
        if(n1!=n2)
        {
            somma=n1+n2;
            pos2=pos2+somma;
        }
        if(pos2%5==0)
        {
            pos2=pos2-6;
            gotoXY(13,39);
             setColor(0,12);
             cout << " Mi dispiace! sei costretto a tornare indietro di sei caselle!" ;
            if(pos2<0)
            {
                pos2=0;
            }
            return pos2;
        }
        return pos2;
    }
    if(turno==3)
    {
        if(n1==n2)
        {
             somma=((n1+n2)*1.30);
             pos3=pos3+somma;
             gotoXY(13,39);
             setColor(0,10);
             cout << " Complimenti! hai fatto doppio numero! il risultato sara' incrementato del 30%!" ;
        }
        if(n1!=n2)
        {
            somma=n1+n2;
            pos3=pos3+somma;
        }
        if(pos3%5==0)
        {
            pos3=pos3-6;
            gotoXY(13,39);
             setColor(0,10);
             cout << " Mi dispiace! sei costretto a tornare indietro di sei caselle!" ;
            if(pos3<0)
            {
                pos3=0;
            }
            return pos3;
        }
        return pos3;
    }
    if(turno==4)
    {
        if(n1==n2)
        {
             somma=((n1+n2)*1.30);
             pos4=pos4+somma;
             gotoXY(13,39);
             setColor(0,14);
             cout << " Complimenti! hai fatto doppio numero! il risultato sara' incrementato del 30%!" ;
        }
        if(n1!=n2)
        {
            somma=n1+n2;
            pos4=pos4+somma;
        }
        if(pos4%5==0)
        {
            pos4=pos4-6;
            gotoXY(13,39);
             setColor(0,14);
             cout << " Mi dispiace! sei costretto a tornare indietro di sei caselle!" ;
            if(pos4<0)
            {
                pos4=0;
            }
            return pos4;
        }
        return pos4;
    }

}