#include <stdio.h>

int main() {
   int i=0,len_ip=0,count;
   int len_op=0;
   int j=0,s=0,x=0,five=0;
   char ip[100],op[100],decode_op[100];
   char pre_post[]={'0','1','1','1','1','1','1','0'};
   
   printf("enter input bitsequence:\n");
   scanf("%s",ip);
   for(i=0;ip[i]!=0;i++)len_ip++;
   
   /*stuffing*/
   for(i=0;i<8;i++)op[i]=pre_post[i];
   count=i;
   do
   {
       if(ip[i]=='1')five++;
       else five=0;
       op[count]=ip[j];
       count++;
       j++;
       
       if(five==5)
       {
           op[count++]='0';
           five=0;
       }
   }
   while(j<len_ip);
   for(s=count,x=0;s<(count+8);s++,x++)
   {
       op[s]=pre_post[x];
   }
   printf("output\n");
   printf("---");
   printf("\nstuffedbitsequence is: ");
   op[s]=0;
   puts(op);
   /*destuffing*/
   j=0;
   five=0;
   len_op=count+8;
   i=8;
   do
   {
       decode_op[j++]=op[i];
       if(op[i]=='1')five++;
       else five=0;
       if(five==5)
       {
           i++;
           five=0;
       }
       len_op--;
       i++;
   }while((len_op-8)!=0);
   decode_op[len_ip]=0;
   printf("destuffed bitsequene is:");
   puts(decode_op);
    return 0;
}