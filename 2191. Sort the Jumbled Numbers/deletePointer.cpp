// new一个指针和delete一个指针的问题
#include <iostream>
#include <stdio.h>
#include "sortTheJumbledNumbers.cpp"
#include "classA.cpp"

int main()
{
    Solution sol;
    // 通过new只能创建一个指针
    Solution *p = new Solution();

    cout << "通过声明的sol的类型：" << typeid(sol).name() << endl;
    cout << "通过new的指针p的类型：" << typeid(p).name() << endl;

    cout << "p的地址：" << &p << endl;
    delete(p);
    cout << "delete指针p之后，p的地址：" << &p << endl;

    cout << "此时再创建一个新的指针"  << endl;
    Solution *new_p = new Solution();
    cout << "new_p的地址：" << &new_p << endl;

    cout << "---------换一个class-------" << endl;

    A a;
    A *ap = new A();
    cout << "通过声明的A的类型：" << typeid(a).name() << endl;
    cout << "通过new的指针ap的类型：" << typeid(ap).name() << endl;

    cout << "ap的地址: " << &ap << endl;
    // class中的成员变量正常读取到为0
    cout << "ap的成员变量: " << ap->a << endl;
    cout << "删除ap" << endl;
    delete(ap);
    // class中的成员变量是一个随机值
    cout << "delete指针ap之后, ap的地址: " << &ap << endl;
    cout << "ap的成员变量: " << ap->a << endl;

    cout << "此时再创建一个新的指针bp"  << endl;
    A *bp = new A();
    cout << "bp的地址: " << &bp << endl;

    // 此时ap虽然被删了，但是地址是0x61fde8。但是成员变量已经是一个随机值。
    // 此时bp的地址是0x61fde0，成员变量正常。
    ap->a = 10;
    cout << "ap的成员变量: " << ap->a << endl;
    // ap的成员变量居然也被修改了

    /*
    这个测试的主要问题就是证明，当一个指针被delete之后，一定要赋值为null。
    否则会出现这样的情况：
    一个指针被delete，内存被编译器释放，但是这个指针没有被置为null。
    因此这块内存区域还是可以访问，内存中的数值还是可以修改。
    同时，又因为内存被释放了，编译器有可能会把这块区域分配出去，也就有可能会有另外的指针指向这个区域。

    https://blog.csdn.net/qq_36570733/article/details/80043321

    所以最好的办法就是养成习惯，要把指针一旦delete之后就将指针置为null。
    一旦置为null之后，再无论怎么delete都是没有影响的。
    */
}