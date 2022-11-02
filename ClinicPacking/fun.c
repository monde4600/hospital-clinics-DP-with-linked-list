 #include "app_config.h"

void Link_init(LinkHead** HeadAddres)   //this fun used to create the first heat this head pointing to null
{
     *HeadAddres = ( LinkHead * ) malloc(sizeof(LinkHead));
     (*HeadAddres)->Next=(void*)0;
}
void LinkCreatNode(LinkHead* HeadAddres, LinkBody ** NewNode) // this fun used to create new node
{

    *NewNode = (LinkBody *)calloc(1,sizeof(LinkBody));
    // check if the head if it pointing to null then we will create the new bode then let the head point to this node (body)
    if(HeadAddres->Next==(void*)0)
    {
        HeadAddres->Next=*NewNode;
        (*NewNode)->Next=(void*)0;
        return;
    }
    //then if the head already pointing to node then we start to search continuously move to next address till we reach the null
    //add then we let that null add point to the new add.
    LinkBody * current =  HeadAddres->Next;
    while(current->Next)        current = current->Next;
    current->Next = *NewNode;
    (*NewNode)->Next=(void*)0;
}
//this node used to search for the desired id and return the address for the node have this ID
char Link_POP_FromTime(LinkHead * HeadAddres ,int time,LinkBody** DesiredNode)
{
    LinkBody* current = HeadAddres->Next;
    //this loop search for the desired ID break in null case or founded id the fun will return 1.
    while(current)
    {
        if(time==current->time)
        {
           // printf("data = %d\n",current->data);
            *DesiredNode = current;
            return 1;
        }
        current = current->Next;

    }
    printf("\ndata no exist\n");
    //if not found it will return 0
    return 0;
}
char Link_POP_FromID(LinkHead * HeadAddres ,int ID,LinkBody** DesiredNode)
{
    LinkBody* current = HeadAddres->Next;
    //this loop search for the desired ID break in null case or founded id the fun will return 1.
    while(current)
    {
        if(ID==current->ID)
        {
           // printf("data = %d\n",current->data);
            *DesiredNode = current;
            return 1;
        }
        current = current->Next;

    }
    printf("\ndata no exist\n");
    //if not found it will return 0
    return 0;
}
char NodeDelet(LinkHead * HeadAddres,int ID)
{
    //check if the linked lest have data or embity
    if(!HeadAddres || !HeadAddres->Next )
    {
        printf("\nList is embity\n");
        return 0;
    }
    LinkBody * Current = HeadAddres->Next;
    //start searching by two pointer one pointing to previous and the other point to the current if the current have the targeted id
    // let the previous point to the next to the current then free the current
    if(ID==Current->ID)
    {
        HeadAddres->Next=Current->Next;
        free(Current);
        return 1;
    }

    LinkBody *Brevios = Current ;
    Current = Current->Next;
    while(Current)
    {
        if(ID==Current->ID)
        {
            Brevios->Next=Current->Next;
            free(Current);
            return 1;
        }
        LinkBody *Brevios = Current ;
        Current = Current->Next;
    }
    printf("this name not exist in the list");
    return 0;
}

