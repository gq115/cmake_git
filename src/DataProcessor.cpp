#include "DataProcessor.hpp"
#include <fstream>
#include <thread>
#include <chrono>
#include <stdexcept>

using namespace std::chrono_literals;

DataProcessor::DataProcessor(const std::string& filePath, size_t chunkSize)
    : filePath_(filePath), chunkSize_(chunkSize), running_(false), filePosition_(0) {}

DataProcessor::~DataProcessor() {
    stopProcessing();
}

void DataProcessor::startProcessing() {
    running_ = true;
    std::thread([this]() { processLoop(); }).detach();
}

void DataProcessor::stopProcessing() {
    running_ = false;
}

void DataProcessor::setHandler(const std::function<void(const char*, size_t)>& handler) {
    dataHandler_ = handler;
}

bool DataProcessor::checkFileUpdate() {
    std::ifstream file(filePath_, std::ios::binary | std::ios::ate);
    if (!file) return false;
    
    long currentSize = file.tellg();
    return (currentSize - filePosition_) >= static_cast<long>(chunkSize_);
}

void DataProcessor::processLoop() {
    while (running_) {
        if (checkFileUpdate()) {
            std::ifstream file(filePath_, std::ios::binary);
            if (!file) {
                std::this_thread::sleep_for(100ms);
                continue;
            }

            file.seekg(filePosition_);
            char buffer[24];
            file.read(buffer, chunkSize_);
            
            if (file.gcount() == chunkSize_) {
                if (dataHandler_) {
                    dataHandler_(buffer, chunkSize_);
                }
                filePosition_ += chunkSize_;
            }
        }
        std::this_thread::sleep_for(100ms);
    }
}
