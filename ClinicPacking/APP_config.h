#ifndef APP_CONFIG_H_INCLUDED
#define APP_CONFIG_H_INCLUDED

#define maxpakings          24
typedef struct body
{
    int ID;
    int time;
    char name[10];
    struct body * Next;
}LinkBody;

typedef struct
{
   LinkBody * Next ;
}LinkHead;



#endif // APP_CONFIG_H_INCLUDED
