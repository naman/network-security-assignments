# rudiIRC
An encrypted rudimentary IRC system for - CSE550 Network Security. The client-server software emulates an elementary IRC system which handles multiple clients. The clients can chat with another client or send a file easily. Additionally, all the conversations are encrypted using Needam Schroeder Model.

To install or test the software, see Install and Test section.

See the screenshot provided!

## Libraries
Posix threads library, fork()/exec(), socket io, OpenSSL

## Working Commands
`/msg`, `/msg_reply`, `/auth`, `/auth_reply`  


## Install and Test
Compile using the Makefile provided.

1. `make`
2. run `./server`
3. run multiple clients in different terminal windows/tabs using `./client`


## Assumptions

//ENCRYPTED VERSION

13. Server doesn't store client's long term shared secret key when the client registers for the first time. Everytime
14. /auth to retrieve session key, /msg will use session key to encrypt data. 
15. the client can not distinguish a correct message from a corrupted one, and cannot know if it the messages are encrypted with a wrong session key. 
16. Client cannot send messages without establishing a session key.
17. Assumes that this is just POC, and many small loopholes might be there.
18. Session keys are stored "just in case" for manual verification purpose. Note that no file i/o is being used anywhere.
19. Clients converse/authenticat each other using the server which acts as an intermediary.

 //NON ENCRYPTED VERSION

1. Initially, we have a list of allowed users which can be found in ![.allowed_users](.allowed_users). To allow another user, simply edit this file.
2. Linux supports filenames upto 256 characters, the software abides by the rule. (and various other limits mentioned below).
3. Path length has to be < 4096 bytes long. 
4. one client can log in using only one terminal tab/window. client is rejected if it tries to open another connection.
5. Closing the server resets the logged in users list, removes all groups and messages stored.
6. logout is not part of the assignment, to logout remove the username from .logged_in file
7. Not more than X clients can connect simultaneously due to the limitations of the CPU. It is advisable to run $(nproc) number of threads. nproc = number of processors. X can range upto 50 for a 4 core processors, but the PC may hang.
8. leave group is not part of the assignment, to leave a group remove the username from .groups/<groupname> file
9. Server and client shares a synchronized memory (just used for sending/receiving messages part).
10. You have to press enter to receive a msg on client. If the client is not connected, it receives the message on connection.
11. File size should be greater than BYTES_READ (512 bytes). There is no limit on maximum file size.
12. Assuming that the destination client to which the file is being sent, knows the name of the file. 


## Attacks/Bugs/Errors
//ENCRYPTED VERSION
8. Prevents against reflection attack as it follows Needam Schroeder Model with CBC mode (reflection attack only works in ECB mode).
9. Prevents impersonation of clients.  Any adversary can't bruteforce or send fake packets.
10. Prevents impersonation of KDC.  Any adversary can't bruteforce or send fake packets to act as the intermediary server.

//NON ENCRYPTED VERSION

1. < 256 character naming convention for file is followed everywhere, < 4096 characters for path is followed and <32 characters for usernames.
2. Handles Ctrl-C and Ctrl-\ for preventing killing the server.
3. The software defends against possible loopholes in client login when and if the server is disconnected when client is entering their username. This is prevented by trapping signals and sending them to the child threads, when required.
4. Once a group is created, no one can overwrite the member list of the group. 
5. if already in group, user is not joined again.
6. Every client can only access the file to which it has access to (sent by another client). All the files are stored in Downloads/username folder. Previous downloads are overwritten by the new ones.
7. Password authentication is also implemented. If the password is wrong, the client is disconnected.