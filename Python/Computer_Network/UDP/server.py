from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")

cnt = 0
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode().upper()
    sorted_message = modifiedMessage.split(' ')

    if(sorted_message[0] == "GET"):
        response = "HTTP/0.1 200 ok"
    elif(sorted_message[0] == "POST"):
        response = "HTTP/0.1 404 Not Found"
    else:
        response = "HTTP/0.1 400 Bad Request"
        serverSocket.sendto(response.encode(), clientAddress)
        serverSocket.close()
        break
    cnt += 1
    serverSocket.sendto(response.encode(), clientAddress)
    if cnt == 3:
        serverSocket.close()
