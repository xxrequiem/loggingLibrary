#include <logger.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <stdexcept>

using namespace std;

string logLevelToString(logLevel level) {  // перевод уровня логирования в строку
    switch (level) {
        case logLevel::INFO:
            return "INFO";
        
        case logLevel::WARNING:
            return "WARNING";
        
        case logLevel::ERROR:
            return "ERROR";
    }
    
    throw invalid_argument("Error: Incorrect level value!");
}