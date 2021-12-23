#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include "../libs/point/include/point.hpp"
#include "zombie.hpp"
#include "player.hpp"
#include "spider.hpp"

using std::unique_ptr, std::make_unique, std::shared_ptr, std::make_shared,
    std::string, std::cout, std::thread, std::vector;

// Create and cout classes

// Mutex example
std::mutex g_m;
const int PAUSE_TIME_MS = 1;

// adds an element to s after a pause;
int slowAddElement(long long &s, long long a)
{
    // Scope lock. With this `m` is released when `lock` goes out of scope
    // This is a RAII class
    const std::lock_guard<std::mutex> lock(g_m);
    // g_m.lock();
    //   cout << "Slow add\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_TIME_MS));
    s += a;
    // g_m.unlock();
}

// Reads an element after a pause
int slowReadElement(const vector<long long> *constResource, const long long idx)
{
    // cout << "Slow read\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_TIME_MS));
    return constResource->at(idx);
}
void read_and_add(
    const vector<long long> *constResource,
    const unsigned int idx,
    long long &writeResource)
{
    const int elem = slowReadElement(constResource, idx);
    slowAddElement(writeResource, elem);
}

void readAndAdd2(
    const vector<long long> *constResource,
    const unsigned int begin,
    const unsigned int end,
    long long &writeResource)
{
    for (unsigned int i = begin; i < end; ++i)
    {
        const int elem = slowReadElement(constResource, i);
        slowAddElement(writeResource, elem);
    }
}
int main()
{

    // Point p1;
    // Point p2(3, 4);
    // Zombie z1(p1, p2, 25);
    // Player pl1(p1, p2);
    // Spider sp1(p1, p2);
    // std::cout << z1 << '\n';
    // std::cout << pl1 << '\n';
    // std::cout << sp1 << '\n';

    // // move
    // std::cout << "Move" << '\n';
    // z1.move();
    // pl1.move();
    // sp1.move();
    // cout << z1 << '\n';
    // cout << pl1 << '\n';
    // cout << sp1 << '\n';

    // // attack
    // std::cout << "Attack" << '\n';
    // z1.attack(pl1);
    // pl1.attack(z1);
    // cout << pl1 << '\n';
    // cout << z1 << '\n';

    // // Lab 5

    // cout << "Lab 5" << '\n';

    // Point p10, p20, p30;
    // p10 = p20 = p30 = Point(3, 4);
    // p10 += p20 += Point(1, 1);

    // cout << p10 << p20 << p30 << '\n';

    // // Assigement to self
    // p10 = p10;
    // p20 = p30;
    // // Copy zombie
    // cout << "Copy zombie" << '\n';
    // Zombie z2 = z1;
    // // z2 = z1;
    // cout << z2 << '\n';

    cout << "Lab 6" << '\n';

    // Lab 6
    // Looking at ptr types
    {
        // Point *p = new Point(1, 2);
        //  unique_ptr<Point> p = unique_ptr<Point>(new Point{1, 2});
        //  It's better to use this instead to avoid the use of "new".
        // The make_unique function is a factory function that returns a unique_ptr.
        // and is exception safe
        unique_ptr<Point> p1 = make_unique<Point>(1, 2);
        unique_ptr<Point> p10 = make_unique<Point>(0, 2);

        cout << *p1 << '\n';
        // unique_ptr<Point> p2 = p1;            // Fail: you cannot copy ownership
        unique_ptr<Point> p2 = std::move(p1); // Move ownership
        cout << "p2 after move: " << *p2 << '\n';
        cout << "p2.get(): " << p2.get() << '\n'; // p2.get() returns a pointer to the object
        // Point *p3 = p2.release(); // Release ownership;
        p2.reset(p10.release()); // Reset the unique_ptr to point to a new object. The old data gets destroyed
        cout << "After reset: " << *p2 << '\n';
    }

    {
        // Point *p = new Point(1, 2);
        // shared_ptr<Point> p1 = shared_ptr<Point>(new Point{3, 4});
        shared_ptr<Point> p1 = make_shared<Point>(3, 4);
        shared_ptr<Point> p2 = p1;
        cout << p1.use_count() << '\n';
        {
            shared_ptr<Point> p3 = p2;
            cout << p1.use_count() << '\n';
        }
        cout << p1.use_count() << '\n';
        cout << *p2 << '\n';
        // Destroyed once;
    }

    // Double free
    // Point point(5, 6);
    // {
    //     unique_ptr<Point> p = unique_ptr<Point>(&point);
    //     cout << *p << '\n';
    //     // `p` is destroyed here and destroys `point` with him
    // }
    // `point` is destroyed again here for the 2nd time -> failure

    {
        // Long array add
        const auto n = 10000;
        vector<long long> vect(n);
        long long real_s = 0;
        for (auto i = 0; i < n; i++)
        {
            vect[i] = i;
            real_s += i;
        }

        long long sum = 0;

        cout << std::thread::hardware_concurrency() << '\n';
        // vector<thread> ts(vect.size());
        // int i = 0;
        // for (auto &t : ts)
        // {
        //     t = thread(read_and_add, &vect, i++, std::ref(sum));
        // }

        // Split by number of threads

        const auto num_threads = std::thread::hardware_concurrency();
        vector<thread> ts(num_threads);
        auto i = 0;
        for (auto i = 0; i < num_threads; i++)
        {
            ts[i] = thread(readAndAdd2, &vect, i * vect.size() / num_threads, (i + 1) * vect.size() / num_threads, std::ref(sum));
        }
        for (auto &t : ts)
        {
            t.join();
        }
        cout << "real sum: " << real_s << '\n';
        cout << "sum: " << sum << '\n';
    }
    return 0;
}
