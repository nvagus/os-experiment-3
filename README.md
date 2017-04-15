# 编译
用cmake,支持外部编译  
mkdir build  
cd build  
cmake ..  
make  
可执行文件分别为bin/msg, bin/fifo, bin/pipe  
# 源码
源码在src文件夹下，头文件在include文件夹下
msg，fifo，pipe分别对应消息队列、命名管道和（匿名）管道的通信方式
# 执行
三种通信方法的输入输出过程均是：在控制台向发送信息的进程输入一行（回车换行结束）文本信息，然后接收信息的进程会讲之显示出来
重复过程，直到输入#号（回车换行）代表结束
## pipe
pipe是由一个进程fork出子进程来测试，没有参数
## fifo
fifo需要创建两个进程，分别执行bin/fifo -r（读），和bin/fifo -w（写），并需要指定文件名（前面会统一加上/tmp/fifo-）
例如： bin/fifo -r file 和 bin/fifo -w file
如果没有指定文件名，则根据进程号建立fifo文件（会主动输出）
例如： bin/fifo -r 和 bin/fifo -w 1234(前者的pid)
## msg
msg需要创建两个进程，分别执行bin/msg -r（接收），和bin/msg -s（发送），并需要指定key值
例如： bin/msg -r 50 和 bin/msg -s 50 
如果没有指定key值，则以进程号代替（会主动输出）
例如： bin/msg -r 和 bin/msg -s 1234(前者的pid)
## 延时
两次输入之间会有一秒的延时
结束后释放资源延时四秒再执行
