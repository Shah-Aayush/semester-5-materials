#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NOF_PACKETS 5
#define fullcap 200


int main()
{
    int token=0,packet_sz[10],i,p_sz_rm=0,op;
    for(int i = 0; i<NOF_PACKETS; ++i)
    {
        printf("Enter the %d packet size:",i);
        scanf("%d", &packet_sz[i]);
    }


    for( i=0;i<NOF_PACKETS;i++)
    {
        for(int clk=10;clk<=50;clk+=10)
        {
            if(token>=fullcap)
                token=fullcap;
            else
                token+=10;
        }
     if( (packet_sz[i] + p_sz_rm) > fullcap)
           if(packet_sz[i]>fullcap)

           {
               printf("\n\nIncoming packet size (%dbytes) is Greater than bucket capacity (%dbytes)-PACKET REJECTED", packet_sz[i], fullcap);
           }
           else
           {
               printf("\n\nBucket capacity exceeded-PACKETS REJECTED!!");
           }

        else
            p_sz_rm+=packet_sz[i];
            printf("\n\nIncoming Packet size: %d", packet_sz[i]);
            printf("\nBytes remaining to Transmit: %d", p_sz_rm);
            //for(clk = 10; clk <=30; clk += 10)
        //{
            sleep(1);
            printf("\nToken Count %d",token);
            if(p_sz_rm)
            {
                if(p_sz_rm<token)
                {
                    op=p_sz_rm;
                    token-=p_sz_rm;
                    p_sz_rm=0;
                    printf("\nPacket of size %d Transmitted",op);
                    printf("\nBytes Remaining to Transmit: %d", p_sz_rm);
                    printf("\nToken Count %d",token);

                }
                else
                {

                    op=token;
                    p_sz_rm-=op;
                    token=0;

                    printf("\nPacket of size %d Transmitted",op);
                    printf("\nBytes Remaining to Transmit: %d", p_sz_rm);
                    printf("\nTokens finished");
                     printf("\nToken Count %d",token);

                }
            }
        }
    }
