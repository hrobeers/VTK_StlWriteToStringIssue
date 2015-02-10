# StlWriteIssue
This repository contains code to reproduce an issue with writing an STL file to a binary string.


## The issue
To make the vtkSTLWriter object write to a string instead of a file, the following method is called: 
WriteToOutputStringOn().

When calling the Write() method, vtk produces the following error message: "vtkSTLWriter (0x823bac0): Please specify 
FileName to write".
Why should a FileName be specified when writing to a binary string?

The GetOutputString() method returns a null pointer, so vtkSTLWriter didn't write to the OutputString.


## How to reproduce?
Run the following scripts in the current folder:

$ ./build.sh
$ ./run.sh


## Details
Tested on:

- Arch Linux
- vtk-5.10
- gcc 4.9.2
