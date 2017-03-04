#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035 // server எந்த portல listen பண்ணுதோ அந்த port நம்பர்
int main()
{
int sockfd;
struct sockaddr_in serv_addr;
char r_buffer[20],w_buffer[20]; // user, terminalல டைப் பண்றது இந்த bufferல தான் store ஆகும் 
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET; // IPv4கான address family
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1"); // server client ரெண்டும் ஒரே machineல இருக்கு, அதனால loopback address use பண்றோம்
serv_addr.sin_port=htons(SERV_TCP_PORT); // host byteல இருந்து network byteக்கு convert பண்ணும்
printf("\nReady for connect...");
connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
printf("\nEnter the message to send\n");
printf("\nClient : ");
fgets(buffer,20,stdin); //user terminalல டைப் பண்றத bufferல store பண்ணும்
write(w_sockfd,buffer,20); // server dataவ bufferல இருந்து socketக்கு அனுப்பும்
read(sockfd,r_buffer,20)
printf("Server echoes : %s",r_buffer);
printf("\n");
close(sock_fd);  // socket close ஆகுது
return 0;
}
