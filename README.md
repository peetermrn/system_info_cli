# system_info_cli

Prints out system information: disk usage and RAM usage. Works on Linux machines (tested on Ubuntu 24.04).  

### Getting started
To install the program so it can be run from anywhere:
```
make
sudo make install
```
Now the program should be avaialbe everywhere.    
    

### Example usage
Display current disk space:
```
peeter@zbook:~$ sys_info -d
Disk info:
  Total:            2013991550976 bytes (1875.68 GB)
  Available:        1762513604608 bytes (1641.47 GB)
  Used:              149097242624 bytes (138.86 GB)

```
Display RAM usage:
```
peeter@zbook:~$ sys_info -m
RAM info:
  Total RAM:              33304072192 bytes (31.02 GB)
  Available RAM:          15601356800 bytes (14.53 GB)
  Used RAM:               17702715392 bytes (16.49 GB)

  ```

### Uninstall
To uninstall: 
```
sudo make uninstall
make clean
```
