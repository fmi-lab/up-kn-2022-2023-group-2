# How to install Visual Studio Code and C++ Compiler for Windows

## 1) Download Visual Studio Code from the following [link](https://code.visualstudio.com/download)

## 2) Install the C/C++ extension for Visual Studio Code

After you install and open Visual Studio Code in the Extension View (Ctrl + Shift + X) search for 'c++' and install 'C/C++' by Microsoft (and optionally 'C/C++ Extension Pack')

![Image](https://code.visualstudio.com/assets/docs/cpp/cpp/cpp-extension.png)

## 3) Install Mingw-w64 Compiler

First install MSYS2 from this [link](https://www.msys2.org/) and follow the instructionson the website to install Mingw-w64 Compiler. Don't close MSYS2 terminal after the installation yet.

## 4) Install the Mingw-w64 toolchain

In the MSYS2 terminal run the following command: `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`

Accept the default to install all the members in the toolchain group.

## 5) Add the path to your Mingw-w64 bin folder to the Windows PATH environment variable

To do so follow the steps below:
- In the Windows search bar, type 'Edit environment variables for your account'
- Click on 'Environment Variables...'
- Choose the Path variable in your System variables and then select Edit (should work if you choose the Path variable in User variables as well)
- Select New and add the Mingw-w64 destination folder path (where you installed Mingw-w64) to the system path. Usually the path is: C:\msys64\mingw64\bin
- Select OK to save the updated PATH. You will need to reopen any console windows for the new PATH location to be available

## 6) Check your MingW installation

To check that your Mingw-w64 tools are correctly installed and available, open a new Command Prompt and type the following 3 commands:

gcc --version

g++ --version

gdb --version

- If the output of every command shows the current version of the corresponding resource then you are good to go.
- If you don't receive the expected output check the PATH variable or if you only have problem with gdb open the MSYS2 terminal and type: `pacman -S mingw-w64-x86_64-gdb`

## 7) How to build and run your .cpp files

When you have opened a .cpp file in Visual Studio Code open the terminal (Ctrl + \`) and type: `g++ {name_of_your_file}.cpp`

This command builds your file and creates executable with the name 'a.exe' (you can change the name by adding `-o {name_of_your_exe}` in the above command)

Then the only thing you need to do to run your program is type: `{name_of_your_exe}` (this command may be different depending on the terminal you use)

- Quick note: the fastest way to build and run your programms is by typing: `g++ *.cpp && a` (this command builds all .cpp files in your directory and runs the newly created a.exe)