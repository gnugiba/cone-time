#pragma once

#include <chrono>
#include <iostream>
#include <thread>


inline void helper_check_time(int sched_time, auto time0) {
	std::this_thread::sleep_for(std::chrono::seconds(sched_time));
	auto time1 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::seconds>(time1 - time0).count() << " seconds passed! task finished.\n";
}

inline void print_check_time(int sched_time) {
	for (auto i = 0; i != sched_time-1; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i+1 << " sec\n";
	}
}


