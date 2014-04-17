listuser
========

Simple unix tool that display a list of all system users based on prefered options

listuser is written in C++ and uses only standard libraries

Example
========
```
petanb@debian:~$ sudo listuser
Listing of all users in the system:
+--------------------+---------+-------+------+--------------------------------+
|Username:           |Is root:*|Login: |UID:  |Groups:                         |
+--------------------+---------+-------+------+--------------------------------+
|root                |Yes      |No     |0     |root                            |
|daemon              |No       |No     |1     |daemon                          |
|bin                 |No       |No     |2     |bin                             |
|sys                 |No       |No     |3     |sys                             |
|sync                |No       |No     |4     |nogroup                         |
|games               |No       |No     |5     |games                           |
|man                 |No       |No     |6     |man                             |
|lp                  |No       |No     |7     |lp                              |
|mail                |No       |No     |8     |mail                            |
|news                |No       |No     |9     |news                            |
|uucp                |No       |No     |10    |uucp                            |
|proxy               |No       |No     |13    |proxy                           |
|www-data            |No       |No     |33    |www-data                        |
|backup              |No       |No     |34    |backup                          |
|list                |No       |No     |38    |list                            |
|irc                 |No       |No     |39    |irc                             |
|gnats               |No       |No     |41    |gnats                           |
|nobody              |No       |No     |65534 |nogroup                         |
|libuuid             |No       |No     |100   |libuuid                         |
|petanb              |No       |Yes    |1000  |adm cdrom floppy sudo audio d...|
|sshd                |No       |No     |102   |nogroup                         |
|pulse               |No       |No     |109   |audio pulse                     |
|dnsmasq             |No       |No     |115   |nogroup                         |
+--------------------+---------+-------+------+--------------------------------+
 * This property is based on user ID as well as SUDO policies,
   proper detection of this property requires this tool to be
   run with superuser privileges
```

How to build
=============
cd listuser and type
```
make
```

Note: you need to have C++ compiler in order to build listuser
