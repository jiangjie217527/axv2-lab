# 运行环境

OS: Ubuntu 22.04.3 LTS

CPU: Intel® Core™ i7-6500U CPU @ 2.50GHz × 4（双核四线程）

内存：DDR3 16.0G 1600MHz 双通道

g++ -v: version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)

# 运行说明

**注**：如果是windows环境，只需把aligned_alloc改成malloc并且加上头文件#include<stdlib.h>（如果没有的话）即可

首先在根目录使用make编译

使用
~~~
make new_data_1
make new_data_2
~~~
分别得到1和2的随机数据

然后使用

~~~
sh run_task1.sh
sh run_task2.sh
~~~

得到task1与task2的运行时间数据

如果需要重新生成数据，先确定数据大小，如果需要修改则修改产生数据的cpp

接着make clean清除可执行文件与上次的输入输出

重复第一步

获得数据之后对res.txt进行处理（去除多余的信息，留下需要的数字），扔到excel里面生成图表与随机数。
