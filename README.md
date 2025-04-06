# Description
Right-click on any file or folder in Windows Explorer, and you'll see the option "Copy full path" in the context menu. Clicking it will copy the full path of the file/folder to the clipboard.
 
# Build
- Using MinGW
```cli
g++ -O3 -mwindows -municode --static -static-libgcc -o copy-explorer-path.exe main.cpp
``` 

# Install
- Copy copy-explorer-path.exe into C:\Windows\copy-explorer-path.exe
- run this reg file:

```reg
Windows Registry Editor Version 5.00
[HKEY_CLASSES_ROOT\AllFilesystemObjects\shell\CopyFullPath]
@="Copy full path"
"Icon"="imageres.dll,-94"

[HKEY_CLASSES_ROOT\AllFilesystemObjects\shell\CopyFullPath\command]
@="copy-explorer-path.exe %1"
```
