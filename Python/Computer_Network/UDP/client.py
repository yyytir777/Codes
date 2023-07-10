from socket import *

message1 = "GET URL HTTP/0.1\r\n"
message2 = "POST URL HTTP/0.1\r\n"
message3 = "DELETE URL HTTP/0.1\r\n"
message_set = [message1, message2, message3]

for temp in message_set:
    serverName = '127.0.0.1'
    serverPort = 12000
    clientSocket = socket(AF_INET, SOCK_DGRAM)

    clientSocket.sendto(temp.encode(), (serverName, serverPort))
    recv_message, serverAddress = clientSocket.recvfrom(2048)
    print(recv_message.decode())
    clientSocket.close()
