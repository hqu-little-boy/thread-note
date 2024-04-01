//#include <iostream>
//#include <bits/stdc++.h>
//
//void PrintThradTest() {
////    std::this_thread::sleep_for(std::chrono::seconds(10));
//    std::cout << "PrintThradTest thread id: " << std::this_thread::get_id() << "  " << 1 << std::endl;
//    std::cout << "PrintThradTest thread id: " << std::this_thread::get_id() << "  " << 2 << std::endl;
//    std::cout << "PrintThradTest thread id: " << std::this_thread::get_id() << "  " << 3 << std::endl;
//    std::cout << "PrintThradTest thread id: " << std::this_thread::get_id() << "  " << 4 << std::endl;
//    std::cout << "PrintThradTest thread id: " << std::this_thread::get_id() << "  " << 5 << std::endl;
//}
//
//int main() {
//    // std::thread是一个类，std::thread t1(PrintThradTest);创建一个线程对象t1，t1开始执行PrintThradTest函数
//    std::thread t1(PrintThradTest); // 2个作用：1.创建线程对象t1 2.线程对象t1开始执行PrintThradTest函数
//
////    std::cout << "main thread id: " << std::this_thread::get_id() << "  " << 1 << std::endl;
////    std::cout << "main thread id: " << std::this_thread::get_id() << "  " << 2 << std::endl;
//    t1.detach(); // 设置主线程等待t1线程执行完毕，阻塞主线程，直到t1线程执行完毕，才会继续执行主线程
////    std::cout << "main thread id: " << std::this_thread::get_id() << "  " << 3 << std::endl;
////    std::cout << "main thread id: " << std::this_thread::get_id() << "  " << 4 << std::endl;
//    std::cout << "main thread id: " << std::this_thread::get_id() << "  " << 5 << std::endl;
//    return 0;
//}

//#include <iostream>
//#include <thread>
//
//using namespace std;
//
////void myPrint(const int &i,char *s) {
////    cout << i << endl; // 使用指针判断，通过std::thread t(myPrint, iRef, s);声明里写的是传递的是引用，但是实际上是值传递
////    cout << s << endl; // 指针在detach之后，可能会被释放，所以在detach之后，可能会出现段错误，所以detach之后，不要再使用指针，会出问题
////    // 应该如何传递字符串呢？可以使用std::string传递引用，再使用c_str()转换为char *
////    cout << "myPrint thread id: " << this_thread::get_id() << endl;
////}
//// 如果不用const & 传递参数，会出现什么问题呢？
//// 会出现拷贝三次的问题
//void myPrint(const int &i,const string &s) {
//    cout << i << endl; // 使用指针判断，通过std::thread t(myPrint, iRef, s);声明里写的是传递的是引用，但是实际上是值传递
//    cout << s.c_str() << endl; // 指针在detach之后，可能会被释放，所以在detach之后，可能会出现段错误，所以detach之后，不要再使用指针，会出问题
//    // 应该如何传递字符串呢？可以使用std::string传递引用，再使用c_str()转换为char *
//    cout << "myPrint thread id: " << this_thread::get_id() << endl;
//}
//int main() {
//    int i = 10;
//    int &iRef = i;
//    char s[] = "hello";
////    // s什么时候转成了std::string类型的？
////    // std::thread t(myPrint, iRef, s);这里传递的是char *类型的，但是myPrint函数里接收的是std::string类型的，
////    // 事实上可能，s已经被释放了，才将s转换成std::string类型的，所以依然存在问题
////    thread t(myPrint, iRef, s);
//    // 为什么这里要增加std::string类型的转换呢？
//    // 因为std::string可以新创建一个临时对象，这样传递参数，子线程一定能在主线程执行完毕前，拷贝到自己的线程中，这样是安全的
//    thread t(myPrint, iRef, std::string (s));
//
////    t.join();
//    t.detach();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    return 0;
//}
//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//int tickets = 50;
//mutex m;
//void sell() {
//    while (true) {
//        if (tickets > 0) {
//            m.lock();
//            this_thread::sleep_for(chrono::milliseconds(10));
//            cout << "sell: " << tickets-- << endl;
//            m.unlock();
//        }
//    }
//}
//void refund() {
//    while (true) {
//        if (tickets < 100) {
//            m.lock();
//            this_thread::sleep_for(chrono::milliseconds(10));
//            cout << "refund: " << tickets++ << endl;
//            m.unlock();
//        }
//    }
//}
//int main() {
//    thread t0(sell);
//    thread t1(sell);
//    thread t2(refund);
//    thread t3(refund);
//    t1.join();
//    t2.join();
//    return 0;
//}
//#include <future>
//#include <iostream>
//#include <thread>
//
//int MyThreadFunc() {
//    std::cout<<"thread id:" << std::this_thread::get_id() << std::endl;
//    std::this_thread::sleep_for(std::chrono::seconds(3));
//    std::cout<<"thread id:" << std::this_thread::get_id() << std::endl;
//    return 5;
//}
//
//int main() {
//
//    std::cout<<"main thread id:" << std::this_thread::get_id() << std::endl;
//    std::future<int> result = std::async(MyThreadFunc);
//    std::cout << "main thread do other things..." << std::endl;
//    // get会阻塞主线程，直到异步操作完成，才返回值
//    std::cout<<"result:" << result.get() << std::endl;
//    return 0;
//}
//
//#include <future>
//#include <iostream>
//#include <thread>
//
//int main() {
//    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
//    std::future<int> result1 = std::async(std::launch::async, []() {
//        std::cout << "async task 1" << std::endl;
//        std::cout << "async task 1 id: " << std::this_thread::get_id() << std::endl;
//        return 1;
//    });
//    // 根本没有启动新线程，而是在主线程中执行了任务
//    std::future<int> result2 = std::async(std::launch::deferred, []() {
//        std::cout << "deferred task 2" << std::endl;
//        std::cout << "deferred task 2 id: " << std::this_thread::get_id() << std::endl;
//        return 2;
//    });
//
//    std::cout << "main thread do other things..." << std::endl;
//
//    std::cout << "result1: " << result1.get() << std::endl;
//    std::cout << "result2: " << result2.get() << std::endl;
//
//    return 0;
//}

//#include <future>
//#include <iostream>
//#include <thread>
//
//int main()
//{
//    std::packaged_task<int()> task([]
//                                   {
//                                       std::cout << "task id: " << std::this_thread::get_id() << std::endl;
//                                       return 42;
//                                   });
//
//    std::future<int> result = task.get_future();
//    std::thread(std::move(task)).detach();
//
//    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
//
//    std::cout << "result: " << result.get() << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <thread>
#include <future>

int main()
{
//    std::promise<int> promise;
//    std::future<int> future = promise.get_future();
//
//    std::thread t([](std::promise<int> p)
//                  {
//                      std::this_thread::sleep_for(std::chrono::seconds(2));
//                      p.set_value(42);
//                  }, std::move(promise));
//
//    std::cout << "future.get(): " << future.get() << std::endl;
//
//    t.join();
    std::time_t start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::future<int> result = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "async task" << std::endl;
        return 42;
    });
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::future_status state = result.wait_for(std::chrono::seconds(10));
    std::time_t end = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    //打印运行时间
    std::cout << "async task run time: " << end - start << "s" << std::endl;
    if (state == std::future_status::ready) {
        std::cout << "async task result: " << result.get() << std::endl;
    }
    else if (state == std::future_status::timeout) {
        std::cout << "async task timeout" << std::endl;
    }

    std::cout << "main thread do other things..." << std::endl;

//    result.wait();
//    state = result.wait_for(std::chrono::seconds(10));
//    if (state == std::future_status::ready) {
//        std::cout << "async task result: " << result.get() << std::endl;
//    }
//    else if (state == std::future_status::timeout) {
//        std::cout << "async task timeout" << std::endl;
//    }

//    std::cout << "result: " << result.get() << std::endl;
    return 0;
}

