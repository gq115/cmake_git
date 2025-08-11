#include "DataProcessor.hpp"
#include <iostream>

void processData(const char* data, size_t size) {
    std::cout << "Received new data chunk: ";
    for (size_t i = 0; i < size; ++i) {
        printf("%02X ", static_cast<unsigned char>(data[i]));
    }
    std::cout << std::endl;
}

int main() {
    DataProcessor processor("data.bin");
    processor.setHandler(processData);
    processor.startProcessing();

    // 保持程序运行
    std::cout << "Monitoring data file... Press Enter to exit." << std::endl;
    std::cin.get();
    return 0;
}
