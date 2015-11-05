#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in server;
    int sock;
    char buf[32];
    int n;

    // ソケット作成
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 接続先指定用構造体の準備
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // サーバに接続
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // サーバよりデータを受信
    memset(buf, 0, sizeof(buf));
    n = read(sock, buf, sizeof(buf));

    printf("%d, %s\n", n, buf);

    // ソケットの終了
    close(sock);

    return 0;
}
