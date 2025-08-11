#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include <string>
#include <functional>

class DataProcessor {
public:
    DataProcessor(const std::string& filePath, size_t chunkSize = 24);
    ~DataProcessor();
    
    void startProcessing();
    void stopProcessing();
    
    // 设置自定义处理回调
    void setHandler(const std::function<void(const char*, size_t)>& handler);

private:
    void processLoop();
    bool checkFileUpdate();

    std::string filePath_;
    size_t chunkSize_;
    bool running_;
    long filePosition_;
    std::function<void(const char*, size_t)> dataHandler_;
};

#endif
