#参数说明
#-g 带有调试信息 ，包括: 指令地址、对应源码、行号   


#静态库编译
clang -g -c myAdd.c
libtool -static -o libMyAdd.a myAdd.o
#-----------

#链接静态库与编译执行代码
clang -g -o dm01_testStaticLib dm01_testStaticLib.c -I . -L . -lMyAdd
