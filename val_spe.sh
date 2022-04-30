#! /bin/bash

name=ZhangSan
# "" 双引号里的特殊字符,会使用其特殊含义
echo "the person is $name"

# '' 单引号中的特殊字符不会使用其特殊含义
echo 'the person is $name'

# `` 反引号 获取一个shell 命令的输出结果  也可用 $()
echo "today is date"
echo "today is `date`"
echo 'today is `date`'
echo "My dir is $(pwd)"

# 转义字符 使用时要在 echo 后加 -e 
echo "**************"
echo "this \n is\ta\ntest"
echo -e "this \n is\ta\ntest"

num=100
#有子shell完成,不影响当前shell的变量
(num=999;echo "1 $num")
echo 1:$num

#在当前shell中执行,影响当前变量 {}内侧两边要有空格,echo 最后还要加分号 ; 结束
{ num=666;echo "2 $num"; }
echo 2:$num
