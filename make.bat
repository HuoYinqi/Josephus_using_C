:: 文件名: make.bat
echo off
mingw32-make
echo Main编译完毕
mingw32-make clean
echo 删除中间文件完毕
 
::执行编译后的文件
main.exe
echo 文件执行完毕