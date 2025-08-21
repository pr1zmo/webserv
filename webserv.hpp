#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <unistd.h>           // execve, dup, dup2, pipe, fork, chdir, close, read, write, access
#include <cerrno>             // errno
#include <cstring>            // strerror
#include <csignal>            // signal, kill
#include <sys/types.h>        // waitpid, socket, bind, accept, listen, recv, send, setsockopt, getsockname, getprotobyname, stat, opendir, readdir, closedir
#include <sys/socket.h>       // socket, socketpair, accept, listen, send, recv, bind, connect, setsockopt, getsockname
#include <netinet/in.h>       // htons, htonl, ntohs, ntohl, sockaddr_in
#include <arpa/inet.h>        // inet_pton, inet_ntop (not listed, but often needed with sockaddr)
#include <netdb.h>            // getaddrinfo, freeaddrinfo, gai_strerror, getprotobyname
#include <sys/wait.h>         // waitpid
#include <fcntl.h>            // fcntl
#include <sys/stat.h>         // stat
#include <dirent.h>           // opendir, readdir, closedir
#include <sys/select.h>       // select, FD_SET, FD_CLR, FD_ISSET, FD_ZERO
#include <poll.h>             // poll
#include <sys/epoll.h>        // epoll_create, epoll_ctl, epoll_wait
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#endif