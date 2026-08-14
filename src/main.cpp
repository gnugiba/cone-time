#include <thread>
#include <chrono>
#include <iostream>

void helper_check_time(int sched_time, auto time0) {
	std::this_thread::sleep_for(std::chrono::seconds(sched_time));
	auto time1 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::seconds>(time1 - time0).count() << " seconds passed! Task finished.\n";
}

void print_check_time(int sched_time) {
	for (auto i = 0; i != sched_time; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i+1 << "sec\n";
	}
}

int main() {
	int sched_time = 10;

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
