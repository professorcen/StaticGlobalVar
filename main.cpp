//静态生产期从程序的执行到程序的结束，比如变量的作用域是在文件区
//还有函数块里面的变量，但是需要在变量前加static

#include <QCoreApplication>
#include <iostream>
using namespace std;
//全局变量
int static_global_var=1000;

void StaticBlockFun()
{
    //声明局部静态变量并初始化它
    //JingTaiVar1/2变量为块内的局部变量，具有全局寿命，局部可见
    //只进入函数第一次时候初始化
    static int static_local_var1= 2;
    static int static_local_var2;

    //非静态块内局部变量
    int non_static_var1 = 10;
    cout<<"---jingTaiKuai---"<<endl;
    cout<<"作用域为全局，因为是全局，所以块内可以访问，静态生存期　static_global_var :"<<static_local_var1<<endl;
    cout<<"作用域为局部，因为是局部，只有在块内才能访问　，static_local_var1 :"<<static_local_var2<<endl;
    cout<<"作用域为局部，因为是局部，只能在块内访问，static_local_var2:"<<static_local_var2<<endl;

   // static_local_var1 +=3;
    non_static_var1 +=3;
}

int main()
{
    cout<<"全局变量static_global:"<<static_global_var<<endl;
    //第一次调用函数StaticBlockFun,这个时候声明了局部变量，并初始化
    StaticBlockFun();
    cout<<"全局变量static_global:"<<static_global_var<<endl;
    //第二次调用函数StaticBlockFun,查看是否局部静态变量有没有变化,再次调用函数，静态变量值不变．但是非静态变量值已经不是初始化的值了
    StaticBlockFun();

}
