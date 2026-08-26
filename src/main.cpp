#include <conetime.h>

int main() {
	std::cout << "Input desired seconds to wait : ";
	int sched_time;
	std::cin >> sched_time;

	auto time0 = std::chrono::high_resolution_clock::now();
	std::cout << "Task started... waiting for " << sched_time << " seconds.\n";

    std::thread thread1([sched_time, time0]() { 
        helper_check_time(sched_time, time0); 
    });
	std::thread thread2([sched_time]() {
		print_check_time(sched_time); 
	});

	thread1.join();
	thread2.join();
}
