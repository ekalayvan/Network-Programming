#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035   // server எந்த portல listen பண்ணுதோ அந்த port நம்பர்
int main()
{
int listen_sd,conn_sd; // listen பண்றதுக்கு ஒரு socket, accept பண்றதுக்கு ஒரு socket
struct sockaddr_in serv_addr,cli_addr;
socklen_t clength=sizeof(cli_addr); 
char buffer[20]; // user, terminalல டைப் பண்றது இந்த bufferல தான் store ஆகும் 
listen_sd=socket(AF_INET,SOCK_STREAM,0);  // TCP socket create பண்ண use பண்ற function
serv_addr.sin_family=AF_INET; // IPv4கான address family
serv_addr.sin_addr.s_addr=INADDR_ANY; // இந்த serverல இருக்கும் எல்லா IP கூடவும் bind பண்ணும்
serv_addr.sin_port=htons(SERV_TCP_PORT);  // host byteல இருந்து network byteக்கு convert பண்ணும்
printf("\nStart");
bind(listen_sd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)); // local protocol addressஅ socketக்கு assign பண்ணும்
printf("\n");
listen(listen_sd,5); // server listen stateல இருக்கு,5 client கூட communicate பண்ணலாம்
printf("\nServer is listening...");
//clength=sizeof(cli_addr);
conn_sd=accept(listen_sd,(struct sockaddr*)&cli_addr,&clength); // clientல இருந்து வர்ர connectionஅ accept பண்ணும்
printf("\nClient is connected");
printf("\n");
read(conn_sd,buffer,20); // client dataவ bufferல இருந்து socketக்கு அனுப்பும்
printf("\nClient says : %s",buffer);
write(conn_sd,buffer,20); // server dataவ socketல இருந்து bufferக்கு அனுப்பும்
printf("\n");
close(listen_sd); // socket close ஆகுது
return 0;
}
