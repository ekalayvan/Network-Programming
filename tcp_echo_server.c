#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035   //server எந்த portல listen பண்ணுதோ அந்த port நம்பர்
int main()
{
int listen_sd,conn_sd; 
socklen_t clength; 
struct sockaddr_in serv_addr,cli_addr;
char buffer[20]; //user terminalல டைப் பண்றது இந்த bufferல தான் store ஆகும் 
listen_sd=socket(AF_INET,SOCK_STREAM,0);  // TCP socket create பண்ண use பண்ற function
serv_addr.sin_family=AF_INET;  
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(SERV_TCP_PORT);  
printf("\nStart");
bind(listen_sd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
printf("\n");
listen(listen_sd,5); //server listen stateல இருக்கு,5 client கூட communicate பண்ணலாம்
printf("\nListening...");
clength=sizeof(cli_addr);
conn_sd=accept(listen_sd,(struct sockaddr*)&cli_addr,&clength); 
printf("\nAccepted");
printf("\n");
read(conn_sd,buffer,20); //client dataவ bufferல இருந்து socketக்கு அனுப்பும்
printf("\nClient message:%s",buffer);
write(conn_sd,buffer,20); //server dataவ socketல இருந்து bufferக்கு அனுப்பும்
printf("\n");
close(listen_sd); //socket close ஆகுது
return 0;
}
