window平台的新建线程封装类，可用于控制台程序和MFC程序，实现时新建一个类以公有方式继承Cpp_Win_Thread
类，并重载run函数，最终通过start函数开启线程，线程回调回调函数可视为子类的成员函数run；