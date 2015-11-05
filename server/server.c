#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

/**
 * main
 *
 * @return int
 */
int main() {
    //! ソケット
    int sock;

    //! ソケット
    int csock;

    //! アドレス構造体の長さ
    int len;

    //! サーバ側socketaddr_in構造体
    struct sockaddr_in server;

    //! クライアント側socketaddr_in構造体
    struct sockaddr_in client;

    // ソケットを作成
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // ソケットの設定
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    server.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (struct sockaddr *)&server, sizeof(server));

    // 接続要求待機
    listen(sock, 5);

    // 接続要求受付
    len = sizeof(client);
    csock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&len);

    // 文字列送信
    write(csock, "HELLO", 5);

    // TCPセッション終了
    close(csock);

    // listenするsocketの終了
    close(sock);
}
