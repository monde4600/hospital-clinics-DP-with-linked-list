#include <stdio.h>
#include <stdlib.h>
#include "app_config.h"
#include "fun.h"

int main()
{
    LinkHead * headadd = (void*)0;
    LinkBody * CurrNodeadd = (void*)0;
    Link_init(&headadd);

    for(int i=1;i<=maxpakings;i++)
    {
        LinkCreatNode(headadd,&CurrNodeadd);
        CurrNodeadd->time=i;
    }
    /*for(int i=1;i<=maxpakings;i++)
    {
        Link_POP_FromTime(headadd,i,&CurrNodeadd);
        printf("ID = %d,,Time = %d\n",CurrNodeadd->ID,CurrNodeadd->time);
    }*/
    int selection;

    while(1)
    {
        printf("\n1_for display all free times :\n");
        printf("\n2_for cancel packing :\n");
        printf("\n3_for edit packing time:\n");
        printf("\n4_for for packing :\n");
        scanf("%d",&selection);
        int P_ID;
        switch(selection)
        {
        case 1:
            for(int i=1;i<=maxpakings;i++)
            {
                Link_POP_FromTime(headadd,i,&CurrNodeadd);
                if(!CurrNodeadd->ID)
                    printf("%d\n",CurrNodeadd->time);
            }
            break;
        case 2:
            printf("enter patient ID: ");
            scanf("%d",&P_ID);
            if(Link_POP_FromID(headadd,P_ID,&CurrNodeadd))
            {
                CurrNodeadd->ID = 0;
                CurrNodeadd->name[0]='\0';
            }
            break;
        case 3:
            printf("enter patient ID: ");
            scanf("%d",&P_ID);
            if(!P_ID)
            {
                printf("not available ID.\n");
                break;
            }
            if(Link_POP_FromID(headadd,P_ID,&CurrNodeadd))
            {
                printf("enter packing Time: ");
                int T;
                scanf("%d",&T);
                if(T>0 && T<=maxpakings)
                {
                    LinkBody * bree=CurrNodeadd;
                    Link_POP_FromTime(headadd,T,&CurrNodeadd);
                    if(!CurrNodeadd->ID)
                    {
                        CurrNodeadd->time=bree->time;
                        bree->time=T;
                    }
                    else printf("this Time is already packed.\n");
                }
                else printf("the entered Time is not exist. \n");
            }
            /*printf("enter student ID: ");
            scanf("%d",&sID);
            NodeDelet(headadd,sID);*/
            break;
        case 4:
            printf("enter packing Time: ");
            int T;
            scanf("%d",&T);
            if(T>0 && T<=maxpakings)
            {
                Link_POP_FromTime(headadd,T,&CurrNodeadd);
                if(!CurrNodeadd->ID)
                {
                    printf("enter patient Name: ");
                    do{
                        fgets(CurrNodeadd->name,10,stdin);
                    }while('\n'==CurrNodeadd->name[0]);
                    printf("enter patient ID: ");
                    scanf("%d",&CurrNodeadd->ID);
                }
                else printf("this Time is already packed.\n");
            }
            else printf("the entered Time is not exist. \n");
            break;
        default :
            printf("not available selection\n");
            break;
        }
    }

}

/*do{
        fgets(CurrNodeadd->name,10,stdin);
    }while('\n'==CurrNodeadd->name[0]);
*/
