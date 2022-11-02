#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED


void Link_init(LinkHead** HeadAddres);
void LinkCreatNode(LinkHead* HeadAddres, LinkBody ** NewNode);
char Link_POP_FromID(LinkHead * HeadAddres ,int ID,LinkBody** DesiredNode);
char Link_POP_FromTime(LinkHead * HeadAddres ,int time,LinkBody** DesiredNode);
char NodeDelet(LinkHead * HeadAddres,int ID);



#endif // FUN_H_INCLUDED
