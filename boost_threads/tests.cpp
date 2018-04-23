#include <gtest/gtest.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <iostream>

class Worker {

    private:
        boost::thread workerThread;

    public:
        void threadFunction(int d) {

            boost::posix_time::seconds duration(d);
            boost::this_thread::sleep(duration);

        }

        int start(int d) {

            workerThread = boost::thread(&Worker::threadFunction, this, d);
        
        }

        int join() {

            workerThread.join();
        
        }

};

void sleepFor3Seconds() {

    std::cout << "2 thread active" << std::endl;

    boost::posix_time::seconds duration(3);
    boost::this_thread::sleep(duration);

    std::cout << "2 thread ends work" << std::endl;
    
}

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}

TEST(Threads, Sleep) {

    boost::posix_time::seconds workTime(3);
    boost::this_thread::sleep(workTime);

}

TEST(Threads, Join) {

    boost::thread testThread(sleepFor3Seconds);
    std::cout << "1 thread waits" << std::endl;
    testThread.join();
    std::cout << "1 thread active" << std::endl;

}

TEST(Threads, ObjectWithThread) {

    Worker testWorker;
    
    std::cout << "wait 1 second" << std::endl;
    testWorker.start(1);
    testWorker.join();

    std::cout << "wait 2 second" << std::endl;
    testWorker.start(2);
    testWorker.join();

    std::cout << "wait 3 second" << std::endl;
    testWorker.start(3);
    testWorker.join();

}

TEST(Threads, Join) {

    boost::thread testThread(sleepFor3Seconds);
    std::cout << "1 thread waits" << std::endl;
    testThread.join();
    std::cout << "1 thread active" << std::endl;

}