# system_info_cli

Prints out system information: disk usage and RAM usage. Works on Linux machines (tested on Ubuntu 24.04).  

### Getting started
To install the program so it can be run from anywhere:
```
make
sudo make install
```
Now the program should be avaialbe everywhere.    
    

To build without installing:
```
make
```

### Example usage
Display current disk space:
```
peeter@zbook:~/code/personal/system_info_cli$ sys_info -d
Disk info:
  Total:            2013991550976 bytes (1875.68 GB)
  Available:        1771958001664 bytes (1650.26 GB)
  Used:              139652845568 bytes (130.06 GB)
```
Display RAM usage:
```
peeter@zbook:~/code/personal/system_info_cli$ ./sys_info -m
RAM info:
  Total RAM:              33304084480 bytes (31.02 GB)
  Available RAM:          19329126400 bytes (18.00 GB)
  Used RAM:               13974958080 bytes (13.02 GB)
  ```

### Uninstall
To uninstall: 
```
sudo make uninstall
make clean
```