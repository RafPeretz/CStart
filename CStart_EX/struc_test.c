#include <stdio.h>
#include <string.h>

struct Client
{
    char firstname[50];
    char lastname[50];
    int m_id;

} client;

int main()
{
    struct Client client1;
    struct Client client2;

    // client 1 specification
    strcpy(client1.firstname, "Rafael");
    strcpy(client1.lastname, "Peretz");
    client1.m_id = 329875413;

    // client 2 specification
    strcpy(client2.firstname, "Moshe");
    strcpy(client2.lastname, "Atlani");
    client2.m_id = 123456789;

    // print client12 Info
    printf("Client 1 firstname : %s\n ", client1.firstname);
    printf("Client 1 lastname : %s\n ", client1.lastname);
    printf("Client 1 ID : %s\n ", client1.m_id);

    retur 0;    


}