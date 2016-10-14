#include<stdio.h>

int sender(int send[], int len)
{
    int sum = 0, checksum;
    int i;
    for(i = 0; i < len; i++)
    {
       sum += send[i];
    }
    checksum = ~sum;
    printf("\nSender's checksum is : %x", checksum);
    return checksum;
}

int receiver(int rec[], int len, int csum)
{
    int sum = 0, checksum;
    int i;
    for(i = 0; i < len; i++)
    {
        sum += rec[i];
    }
    printf("\nReceiver's sum is : %x", sum);
    sum = sum + csum;
    checksum = ~sum;
    printf("\nReceiver's checksum is : %x", checksum);
    return checksum;
}

int main()
{
    int count, checksum;
    printf("How many decimal numbers are there in the address: \n");
    scanf("%d", &count);
    int send[count];
    int rec[count];
    int result;
    int flag = 0;
    printf("Enter the sender decimal numbers of the address: \n");
    while(flag<count)
    {
        scanf("%x", &send[flag]);
        flag++;
    }
    flag = 0;
    printf("Enter the receiver decimal numbers of the address: \n");
    while(flag<count)
    {
        scanf("%x", &rec[flag]);
        flag++;
    }
    checksum = sender(send, count);
    result = receiver(rec, count, checksum);
    if(result == 0)
    {
        printf("\nThere is no error.");
    }
    else
    {
        printf("\nThere is error.");
    }
    return 0;
}
