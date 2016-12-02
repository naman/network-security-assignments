#include <arpa/inet.h>
#include <asm-generic/errno.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <limits.h>clude <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BYTES_READ
#define BYTES_READ 128
#endif

#ifndef ALLOWED_CHAR_LENGTH
#define ALLOWED_CHAR_LENGTH 4096
#endif

#ifndef PORT_X
#define PORT_X 8000
#endif

#ifndef PORT_Y
#define PORT_Y 8001
#endif

typedef int bool;
#define true 1
#define false 0

pthread_t worker_threads[2];
char username[ALLOWED_CHAR_LENGTH];

int listenFlag = 0;

void check_username_length(char* username) {
	if (strlen(username) >= 32) {
		errno = E2BIG;
		perror("Username has to be less than 32 bytes!");
	}
}

void check_path_length(char* path) {
	if (strlen(path) >= PATH_MAX) //4096 bytes
	{
		errno = E2BIG;
		perror("Path has to be less than 4096 bytes!");
	}
}

void check_file_length(char* filename) {
	if (strlen(filename) >= NAME_MAX) {
		errno = E2BIG;
		perror("Path has to be less than 255 bytes!");
	}
}

char** splitline(char *line, char* delimiter) {
	int buffer = 64;
	int pos = 0;
	char **args = malloc(buffer * sizeof(char*));
	char *token;

	token = strtok(line, delimiter);
	while (token != NULL) {
		args[pos] = token;
		pos += 1;

		if (pos >= buffer) {
			buffer += buffer;
			args = realloc(args, buffer * sizeof(char*));
		}

		token = strtok(NULL, delimiter);
	}
	args[pos] = NULL;
	return args;
}

void sigproc()

{
	signal(SIGQUIT, sigproc);
	printf(" Trap. Quitting.\n");
	//	pthread_exit(-1);
	raise(SIGINT);
	// kill(getpid(), SIGINT);
	exit(-1);
}

int file_exists(char *path) {
	struct stat st;
	int result = stat(path, &st);
	return result;
}

int file_size(char *path) {
	struct stat st;
	stat(path, &st);
	int size = st.st_size;
	return size;
}

void strip_line_endings(char* input) {
	/* strip of /r and /n chars to take care of Windows, Unix, OSx line endings. */
	input[strcspn(input, "\r\n")] = 0;
}

void resolve_path(char* path) {
	char resolved_path[ALLOWED_CHAR_LENGTH];
	realpath(path, resolved_path);
	strcpy(path, resolved_path);
}

void init(char* username) {
	printf("\n\n================== Authenticating.... ==================\n");

	sleep(1);

	system("clear");

	printf("================== Welcome to rudiIRC! ==================\n\n");

	char *wd = NULL;
	wd = getcwd(wd, ALLOWED_CHAR_LENGTH);
	check_path_length(wd);

	printf("Hello! You are at Usage %s, [options] ... \n\n", wd);
}

void save_file(int socket) {
	while (0) {
		/* code */
	}
}

int read_dstmsg(char* msg) {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "r");

	if (file_pointer == NULL) {
		return -1;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	int line_number = 0;

	int val = 0;
	while ((read = getline(&line, &len, file_pointer)) != -1) {
		strip_line_endings(line);
		if (line_number == 0) {
			val = atoi(line);
		} else if (line_number == 1) {
			strcpy(msg, line);
//			printf("#include <arpa/inet.h>
#include <asm-generic/errno.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <limits.h>clude <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BYTES_READ
#define BYTES_READ 128
#endif

#ifndef ALLOWED_CHAR_LENGTH
#define ALLOWED_CHAR_LENGTH 4096
#endif

#ifndef PORT_X
#define PORT_X 8000
#endif

#ifndef PORT_Y
#define PORT_Y 8001
#endif

typedef int bool;
#define true 1
#define false 0

pthread_t worker_threads[2];
char username[ALLOWED_CHAR_LENGTH];

int listenFlag = 0;

void check_username_length(char* username) {
	if (strlen(username) >= 32) {
		errno = E2BIG;
		perror("Username has to be less than 32 bytes!");
	}
}

void check_path_length(char* path) {
	if (strlen(path) >= PATH_MAX) //4096 bytes
	{
		errno = E2BIG;
		perror("Path has to be less than 4096 bytes!");
	}
}

void check_file_length(char* filename) {
	if (strlen(filename) >= NAME_MAX) {
		errno = E2BIG;
		perror("Path has to be less than 255 bytes!");
	}
}

char** splitline(char *line, char* delimiter) {
	int buffer = 64;
	int pos = 0;
	char **args = malloc(buffer * sizeof(char*));
	char *token;

	token = strtok(line, delimiter);
	while (token != NULL) {
		args[pos] = token;
		pos += 1;

		if (pos >= buffer) {
			buffer += buffer;
			args = realloc(args, buffer * sizeof(char*));
		}

		token = strtok(NULL, delimiter);
	}
	args[pos] = NULL;
	return args;
}

void sigproc()

{
	signal(SIGQUIT, sigproc);
	printf(" Trap. Quitting.\n");
	//	pthread_exit(-1);
	raise(SIGINT);
	// kill(getpid(), SIGINT);
	exit(-1);
}

int file_exists(char *path) {
	struct stat st;
	int result = stat(path, &st);
	return result;
}

int file_size(char *path) {
	struct stat st;
	stat(path, &st);
	int size = st.st_size;
	return size;
}

void strip_line_endings(char* input) {
	/* strip of /r and /n chars to take care of Windows, Unix, OSx line endings. */
	input[strcspn(input, "\r\n")] = 0;
}

void resolve_path(char* path) {
	char resolved_path[ALLOWED_CHAR_LENGTH];
	realpath(path, resolved_path);
	strcpy(path, resolved_path);
}

void init(char* username) {
	printf("\n\n================== Authenticating.... ==================\n");

	sleep(1);

	system("clear");

	printf("================== Welcome to rudiIRC! ==================\n\n");

	char *wd = NULL;
	wd = getcwd(wd, ALLOWED_CHAR_LENGTH);
	check_path_length(wd);

	printf("Hello! You are at %s\n\n", wd);
}

void save_file(int socket) {
	while (0) {
		/* code */
	}
}

int read_dstmsg(char* msg) {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "r");

	if (file_pointer == NULL) {
		return -1;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	int line_number = 0;

	int val = 0;
	while ((read = getline(&line, &len, file_pointer)) != -1) {
		strip_line_endings(line);
		if (line_number == 0) {
			val = atoi(line);
		} else if (line_number == 1) {
			strcpy(msg, line);
//			printf("%s\n", line);
		}
		line_number++;
	}

	if (line) {
		free(line);
	}
	fclose(file_pointer);
	return val;
}

int send_file(int socket, char* path, int size) {

	if (file_exists(path) != 0) {
		errno = ECANCELED;
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	FILE* file_pointer;
	file_pointer = fopen(path, "rb");

	if (file_pointer == NULL) {
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		fread(buffer, sizeof(char), BYTES_READ, file_pointer);
		send(socket, buffer, BYTES_READ, 0);

//		printf("%s", buffer);
		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;

		fseek(file_pointer, i, SEEK_SET);
	}
	puts("");
	fclose(file_pointer);

	return 1;
}

int recv_file(int socket, char* filename, int size, char* dst_user) {

	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".files/.");
	strcat(path, filename);
	strcat(path, "_");
	strcat(path, dst_user);

	FILE* file_pointer;
	file_pointer = fopen(path, "wb");

	if (file_pointer == NULL) {
		errno = ECANCELED;
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	strcpy(path, "");

	char file_buffer[ALLOWED_CHAR_LENGTH];
	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		recv(socket, buffer, BYTES_READ, 0);
		strcat(file_buffer, buffer);

		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;
	}

	printf("bu\n");
	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, file_buffer, usage);

	fclose(file_pointer);
	return 1;
}

void reset_dstmsg() {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "w+");

	if (file_pointer == NULL) {
		return;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	strcpy(buffer, "0\n\n");

	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, buffer, usage);

	fclose(file_pointer);
}

void interface(char* username, int socket) {

	char m[ALLOWED_CHAR_LENGTH];
	if (read_dstmsg(m) == 1) {
		printf("Message: %s \n", m);
		strcpy(m, "\n");
		reset_dstmsg();
	}

	printf("$ ");

	char cmd[ALLOWED_CHAR_LENGTH];
	fgets(cmd, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(cmd);
	send(socket, cmd, ALLOWED_CHAR_LENGTH, 0);

	char success[ALLOWED_CHAR_LENGTH];
	recv(socket, success, ALLOWED_CHAR_LENGTH, 0);

	if (strcmp(success, "1") == 0) {
		// /who
		char result[ALLOWED_CHAR_LENGTH];
		recv(socket, result, ALLOWED_CHAR_LENGTH, 0);

		printf(result);

	} else if (strcmp(success, "2") == 0) {
		// /msg

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);

		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
//		printf("Message %s", rc);

//		listenFlag = 1;

	} else if (strcmp(success, "3") == 0) {
		// /create_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "4") == 0) {
		// /join_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "5") == 0) {
		// /send

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);
		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		printf("Filename: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);
		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		int size = file_size(msg);
		send(socket, &size, sizeof(int), 0);

		send_file(socket, msg, size);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s\n", rc);

	} else if (strcmp(success, "6") == 0) {
		// /msg_grp

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "7") == 0) {
		// /recv
		printf("Recieving pending files ....\n");

	} else {
		printf("Command not supported!\n");
	}

}

void *connection_handler1(void *connection_socket) {

	int* _socket = (int *) connection_socket;

	while (1) {
		interface(username, _socket);
	}

	return 0;
}

void *connection_handler(void *connection_socket) {

	int* _socket = (int *) connection_socket;
	// // where socketfd is the socket you want to make non-blocking
	// int status = fcntl(_socket, F_SETFL, fcntl(_socket, F_GETFL, 0) | O_NONBLOCK);
	//
	// if (status == -1){
	//   perror("calling fcntl");
	//   // handle the error.  By the way, I've never seen fcntl fail in this way
	// }

	char rc[ALLOWED_CHAR_LENGTH];
	while (1) {
		recv(_socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("%s", rc);
		strcpy(rc, "");
	}
	return 0;
}

int main(int argc, char const *argv[]) {

// signal(SIGQUIT, sigproc);
	int client_socket_descriptor;
	struct sockaddr_in server_address;
	socklen_t address_size;

	client_socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
	if (client_socket_descriptor == -1) {
		errno = EBADR;
		perror("Error creating socket!");
	} else {
		printf("socket initialized...\n");
	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(PORT_Y);

	memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));
	address_size = sizeof(server_address);

	if (connect(client_socket_descriptor, (struct sockaddr *) &server_address,
			address_size) < 0) {
		errno = ECONNREFUSED;
		perror("Error connecting to the server!\n");
		exit(-1);
	} else {
		printf("you are connected to the server...\n");
	}

	printf("Hello! Please enter your username to login.\n\n> ");

	fgets(username, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(username);

	check_username_length(username);

	if (send(client_socket_descriptor, username, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Send failed");
		exit(-1);
	}

	char success[ALLOWED_CHAR_LENGTH];

	if (recv(client_socket_descriptor, success, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Recv failed");
		exit(-1);
	}

	strip_line_endings(success);

	if (strcmp(success, "connected") == 0) {

		printf("You are %s\n", success);
		init(username);

		while (1) {
			interface(username, client_socket_descriptor);
		}
//		pthread_create(&worker_threads[0], NULL, connection_handler,
//				(void *) client_socket_descriptor);
//
//		pthread_create(&worker_threads[1], NULL, connection_handler1,
//				(void *) client_socket_descriptor);
//
//		pthread_join(worker_threads[0], NULL);
//
//		pthread_join(worker_threads[1], NULL);
	} else {
		errno = ECONNREFUSED;
		perror("Invalid username! Please try again!\n");
		exit(-1);
	}

	close(client_socket_descriptor);
	return 0;
}
ECONNREFUSED;
		per\n", line);
		}
		line_number++;
	}

	if (line) {
		free(line);
	}
	fclose(file_pointer);
	return val;
}

int send_file(int socket, char* path, int size) {

	if (file_exists(path) != 0) {
		errno = ECANCELED;
		printf("Can't access path \n", path);
		perror("Cannot open file!");
		return -1;
	}

	FILE* file_pointer;
	file_pointer = fopen(path, "rb");

	if (file_pointer == NULL) {
		printf("Can't access path #include <arpa/inet.h>
#include <asm-generic/errno.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <limits.h>clude <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BYTES_READ
#define BYTES_READ 128
#endif

#ifndef ALLOWED_CHAR_LENGTH
#define ALLOWED_CHAR_LENGTH 4096
#endif

#ifndef PORT_X
#define PORT_X 8000
#endif

#ifndef PORT_Y
#define PORT_Y 8001
#endif

typedef int bool;
#define true 1
#define false 0

pthread_t worker_threads[2];
char username[ALLOWED_CHAR_LENGTH];

int listenFlag = 0;

void check_username_length(char* username) {
	if (strlen(username) >= 32) {
		errno = E2BIG;
		perror("Username has to be less than 32 bytes!");
	}
}

void check_path_length(char* path) {
	if (strlen(path) >= PATH_MAX) //4096 bytes
	{
		errno = E2BIG;
		perror("Path has to be less than 4096 bytes!");
	}
}

void check_file_length(char* filename) {
	if (strlen(filename) >= NAME_MAX) {
		errno = E2BIG;
		perror("Path has to be less than 255 bytes!");
	}
}

char** splitline(char *line, char* delimiter) {
	int buffer = 64;
	int pos = 0;
	char **args = malloc(buffer * sizeof(char*));
	char *token;

	token = strtok(line, delimiter);
	while (token != NULL) {
		args[pos] = token;
		pos += 1;

		if (pos >= buffer) {
			buffer += buffer;
			args = realloc(args, buffer * sizeof(char*));
		}

		token = strtok(NULL, delimiter);
	}
	args[pos] = NULL;
	return args;
}

void sigproc()

{
	signal(SIGQUIT, sigproc);
	printf(" Trap. Quitting.\n");
	//	pthread_exit(-1);
	raise(SIGINT);
	// kill(getpid(), SIGINT);
	exit(-1);
}

int file_exists(char *path) {
	struct stat st;
	int result = stat(path, &st);
	return result;
}

int file_size(char *path) {
	struct stat st;
	stat(path, &st);
	int size = st.st_size;
	return size;
}

void strip_line_endings(char* input) {
	/* strip of /r and /n chars to take care of Windows, Unix, OSx line endings. */
	input[strcspn(input, "\r\n")] = 0;
}

void resolve_path(char* path) {
	char resolved_path[ALLOWED_CHAR_LENGTH];
	realpath(path, resolved_path);
	strcpy(path, resolved_path);
}

void init(char* username) {
	printf("\n\n================== Authenticating.... ==================\n");

	sleep(1);

	system("clear");

	printf("================== Welcome to rudiIRC! ==================\n\n");

	char *wd = NULL;
	wd = getcwd(wd, ALLOWED_CHAR_LENGTH);
	check_path_length(wd);

	printf("Hello! You are at %s\n\n", wd);
}

void save_file(int socket) {
	while (0) {
		/* code */
	}
}

int read_dstmsg(char* msg) {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "r");

	if (file_pointer == NULL) {
		return -1;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	int line_number = 0;

	int val = 0;
	while ((read = getline(&line, &len, file_pointer)) != -1) {
		strip_line_endings(line);
		if (line_number == 0) {
			val = atoi(line);
		} else if (line_number == 1) {
			strcpy(msg, line);
//			printf("%s\n", line);
		}
		line_number++;
	}

	if (line) {
		free(line);
	}
	fclose(file_pointer);
	return val;
}

int send_file(int socket, char* path, int size) {

	if (file_exists(path) != 0) {
		errno = ECANCELED;
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	FILE* file_pointer;
	file_pointer = fopen(path, "rb");

	if (file_pointer == NULL) {
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		fread(buffer, sizeof(char), BYTES_READ, file_pointer);
		send(socket, buffer, BYTES_READ, 0);

//		printf("%s", buffer);
		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;

		fseek(file_pointer, i, SEEK_SET);
	}
	puts("");
	fclose(file_pointer);

	return 1;
}

int recv_file(int socket, char* filename, int size, char* dst_user) {

	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".files/.");
	strcat(path, filename);
	strcat(path, "_");
	strcat(path, dst_user);

	FILE* file_pointer;
	file_pointer = fopen(path, "wb");

	if (file_pointer == NULL) {
		errno = ECANCELED;
		printf("Can't access path %s\n", path);
		perror("Cannot open file!");
		return -1;
	}

	strcpy(path, "");

	char file_buffer[ALLOWED_CHAR_LENGTH];
	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		recv(socket, buffer, BYTES_READ, 0);
		strcat(file_buffer, buffer);

		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;
	}

	printf("bu\n");
	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, file_buffer, usage);

	fclose(file_pointer);
	return 1;
}

void reset_dstmsg() {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "w+");

	if (file_pointer == NULL) {
		return;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	strcpy(buffer, "0\n\n");

	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, buffer, usage);

	fclose(file_pointer);
}

void interface(char* username, int socket) {

	char m[ALLOWED_CHAR_LENGTH];
	if (read_dstmsg(m) == 1) {
		printf("Message: %s \n", m);
		strcpy(m, "\n");
		reset_dstmsg();
	}

	printf("$ ");

	char cmd[ALLOWED_CHAR_LENGTH];
	fgets(cmd, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(cmd);
	send(socket, cmd, ALLOWED_CHAR_LENGTH, 0);

	char success[ALLOWED_CHAR_LENGTH];
	recv(socket, success, ALLOWED_CHAR_LENGTH, 0);

	if (strcmp(success, "1") == 0) {
		// /who
		char result[ALLOWED_CHAR_LENGTH];
		recv(socket, result, ALLOWED_CHAR_LENGTH, 0);

		printf(result);

	} else if (strcmp(success, "2") == 0) {
		// /msg

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);

		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
//		printf("Message %s", rc);

//		listenFlag = 1;

	} else if (strcmp(success, "3") == 0) {
		// /create_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "4") == 0) {
		// /join_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "5") == 0) {
		// /send

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);
		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		printf("Filename: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);
		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		int size = file_size(msg);
		send(socket, &size, sizeof(int), 0);

		send_file(socket, msg, size);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s\n", rc);

	} else if (strcmp(success, "6") == 0) {
		// /msg_grp

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "7") == 0) {
		// /recv
		printf("Recieving pending files ....\n");

	} else {
		printf("Command not supported!\n");
	}

}

void *connection_handler1(void *connection_socket) {

	int* _socket = (int *) connection_socket;

	while (1) {
		interface(username, _socket);
	}

	return 0;
}

void *connection_handler(void *connection_socket) {

	int* _socket = (int *) connection_socket;
	// // where socketfd is the socket you want to make non-blocking
	// int status = fcntl(_socket, F_SETFL, fcntl(_socket, F_GETFL, 0) | O_NONBLOCK);
	//
	// if (status == -1){
	//   perror("calling fcntl");
	//   // handle the error.  By the way, I've never seen fcntl fail in this way
	// }

	char rc[ALLOWED_CHAR_LENGTH];
	while (1) {
		recv(_socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("%s", rc);
		strcpy(rc, "");
	}
	return 0;
}

int main(int argc, char const *argv[]) {

// signal(SIGQUIT, sigproc);
	int client_socket_descriptor;
	struct sockaddr_in server_address;
	socklen_t address_size;

	client_socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
	if (client_socket_descriptor == -1) {
		errno = EBADR;
		perror("Error creating socket!");
	} else {
		printf("socket initialized...\n");
	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(PORT_Y);

	memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));
	address_size = sizeof(server_address);

	if (connect(client_socket_descriptor, (struct sockaddr *) &server_address,
			address_size) < 0) {
		errno = ECONNREFUSED;
		perror("Error connecting to the server!\n");
		exit(-1);
	} else {
		printf("you are connected to the server...\n");
	}

	printf("Hello! Please enter your username to login.\n\n> ");

	fgets(username, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(username);

	check_username_length(username);

	if (send(client_socket_descriptor, username, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Send failed");
		exit(-1);
	}

	char success[ALLOWED_CHAR_LENGTH];

	if (recv(client_socket_descriptor, success, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Recv failed");
		exit(-1);
	}

	strip_line_endings(success);

	if (strcmp(success, "connected") == 0) {

		printf("You are %s\n", success);
		init(username);

		while (1) {
			interface(username, client_socket_descriptor);
		}
//		pthread_create(&worker_threads[0], NULL, connection_handler,
//				(void *) client_socket_descriptor);
//
//		pthread_create(&worker_threads[1], NULL, connection_handler1,
//				(void *) client_socket_descriptor);
//
//		pthread_join(worker_threads[0], NULL);
//
//		pthread_join(worker_threads[1], NULL);
	} else {
		errno = ECONNREFUSED;
		perror("Invalid username! Please try again!\n");
		exit(-1);
	}

	close(client_socket_descriptor);
	return 0;
}
ECONNREFUSED;
		per\n", path);
		perror("Cannot open file!");
		return -1;
	}

	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		fread(buffer, sizeof(char), BYTES_READ, file_pointer);
		send(socket, buffer, BYTES_READ, 0);

//		printf("(null)", buffer);
		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;

		fseek(file_pointer, i, SEEK_SET);
	}
	puts("");
	fclose(file_pointer);

	return 1;
}

int recv_file(int socket, char* filename, int size, char* dst_user) {

	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".files/.");
	strcat(path, filename);
	strcat(path, "_");
	strcat(path, dst_user);

	FILE* file_pointer;
	file_pointer = fopen(path, "wb");

	if (file_pointer == NULL) {
		errno = ECANCELED;
		printf("Can't access path Cannot open file!");
		return -1;
	}

	strcpy(path, "");

	char file_buffer[ALLOWED_CHAR_LENGTH];
	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		recv(socket, buffer, BYTES_READ, 0);
		strcat(file_buffer, buffer);

		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;
	}

	printf("bu\n");
	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, file_buffer, usage);

	fclose(file_pointer);
	return 1;
}

void reset_dstmsg() {
	char path[ALLOWED_CHAR_LENGTH];
	strcpy(path, ".msg/.");
	strcat(path, username);

	FILE* file_pointer;
	file_pointer = fopen(path, "w+");

	if (file_pointer == NULL) {
		return;
	}

	char buffer[ALLOWED_CHAR_LENGTH];
	strcpy(buffer, "0\n\n");

	char *usage = "Usage %s, [options] ... ";
	fprintf(file_pointer, buffer, usage);

	fclose(file_pointer);
}

void interface(char* username, int socket) {

	char m[ALLOWED_CHAR_LENGTH];
	if (read_dstmsg(m) == 1) {
		printf("Message: %s \n", m);
		strcpy(m, "\n");
		reset_dstmsg();
	}

	printf("$ ");

	char cmd[ALLOWED_CHAR_LENGTH];
	fgets(cmd, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(cmd);
	send(socket, cmd, ALLOWED_CHAR_LENGTH, 0);

	char success[ALLOWED_CHAR_LENGTH];
	recv(socket, success, ALLOWED_CHAR_LENGTH, 0);

	if (strcmp(success, "1") == 0) {
		// /who
		char result[ALLOWED_CHAR_LENGTH];
		recv(socket, result, ALLOWED_CHAR_LENGTH, 0);

		printf(result);

	} else if (strcmp(success, "2") == 0) {
		// /msg

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);

		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
//		printf("Message %s", rc);

//		listenFlag = 1;

	} else if (strcmp(success, "3") == 0) {
		// /create_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "4") == 0) {
		// /join_grp

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "5") == 0) {
		// /send

		printf("Send to: ");
		char user[ALLOWED_CHAR_LENGTH];
		fgets(user, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(user);
		send(socket, user, ALLOWED_CHAR_LENGTH, 0);

		printf("Filename: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);
		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		int size = file_size(msg);
		send(socket, &size, sizeof(int), 0);

		send_file(socket, msg, size);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s\n", rc);

	} else if (strcmp(success, "6") == 0) {
		// /msg_grp

		printf("Message: ");
		char msg[ALLOWED_CHAR_LENGTH];
		fgets(msg, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(msg);

		send(socket, msg, ALLOWED_CHAR_LENGTH, 0);

		printf("Name of the group: ");
		char grp[ALLOWED_CHAR_LENGTH];
		fgets(grp, ALLOWED_CHAR_LENGTH, stdin);
		strip_line_endings(grp);

		send(socket, grp, ALLOWED_CHAR_LENGTH, 0);

		char rc[ALLOWED_CHAR_LENGTH];
		recv(socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("result %s", rc);

	} else if (strcmp(success, "7") == 0) {
		// /recv
		printf("Recieving pending files ....\n");

	} else {
		printf("Command not supported!\n");
	}

}

void *connection_handler1(void *connection_socket) {

	int* _socket = (int *) connection_socket;

	while (1) {
		interface(username, _socket);
	}

	return 0;
}

void *connection_handler(void *connection_socket) {

	int* _socket = (int *) connection_socket;
	// // where socketfd is the socket you want to make non-blocking
	// int status = fcntl(_socket, F_SETFL, fcntl(_socket, F_GETFL, 0) | O_NONBLOCK);
	//
	// if (status == -1){
	//   perror("calling fcntl");
	//   // handle the error.  By the way, I've never seen fcntl fail in this way
	// }

	char rc[ALLOWED_CHAR_LENGTH];
	while (1) {
		recv(_socket, rc, ALLOWED_CHAR_LENGTH, 0);
		printf("%s", rc);
		strcpy(rc, "");
	}
	return 0;
}

int main(int argc, char const *argv[]) {

// signal(SIGQUIT, sigproc);
	int client_socket_descriptor;
	struct sockaddr_in server_address;
	socklen_t address_size;

	client_socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
	if (client_socket_descriptor == -1) {
		errno = EBADR;
		perror("Error creating socket!");
	} else {
		printf("socket initialized...\n");
	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(PORT_Y);

	memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));
	address_size = sizeof(server_address);

	if (connect(client_socket_descriptor, (struct sockaddr *) &server_address,
			address_size) < 0) {
		errno = ECONNREFUSED;
		perror("Error connecting to the server!\n");
		exit(-1);
	} else {
		printf("you are connected to the server...\n");
	}

	printf("Hello! Please enter your username to login.\n\n> ");

	fgets(username, ALLOWED_CHAR_LENGTH, stdin);
	strip_line_endings(username);

	check_username_length(username);

	if (send(client_socket_descriptor, username, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Send failed");
		exit(-1);
	}

	char success[ALLOWED_CHAR_LENGTH];

	if (recv(client_socket_descriptor, success, ALLOWED_CHAR_LENGTH, 0) < 0) {
		perror("Recv failed");
		exit(-1);
	}

	strip_line_endings(success);

	if (strcmp(success, "connected") == 0) {

		printf("You are %s\n", success);
		init(username);

		while (1) {
			interface(username, client_socket_descriptor);
		}
//		pthread_create(&worker_threads[0], NULL, connection_handler,
//				(void *) client_socket_descriptor);
//
//		pthread_create(&worker_threads[1], NULL, connection_handler1,
//				(void *) client_socket_descriptor);
//
//		pthread_join(worker_threads[0], NULL);
//
//		pthread_join(worker_threads[1], NULL);
	} else {
		errno = ECONNREFUSED;
		perror("Invalid username! Please try again!\n");
		exit(-1);
	}

	close(client_socket_descriptor);
	return 0;
}
ECONNREFUSED;
		per\n", path);
		perror("Cannot open file!");
		return -1;
	}

	strcpy(path, "");

	char file_buffer[ALLOWED_CHAR_LENGTH];
	char buffer[BYTES_READ];

	int i = BYTES_READ;
	while (i <= size) {

		recv(socket, buffer, BYTES_READ, 0);
		strcat(file_buffer, buffer);

		strcpy(buffer, "");
//		sleep(1);

		i += BYTES_READ;
	}

	printf("bu\n");
	char *usage = "Usage  _socket = (int *) connection_socket;
	// // where socketfd is the socket you want to make non-blocking
	// int status = fcntl(_socket, F_SETFL, fcntl(_sock