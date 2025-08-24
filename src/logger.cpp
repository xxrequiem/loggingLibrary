#include <logger.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <stdexcept>

using namespace std;

string logLevelToString(logLevel level) {  // перевод "уровня логирования" в строку
    switch (level) {
        case logLevel::INFO:
            return "INFO";
        
        case logLevel::WARNING:
            return "WARNING";
        
        case logLevel::ERROR:
            return "ERROR";
    }
    
    throw invalid_argument("Error: Incorrect level value!");     // исключение, если выбран некорректный уровень логирования
}

logger::logger(const& string filename, logLevel level) {         // конструктор для инициализации потока и установки уровня логирования
    logFile.open(filename, ios::app, ios::ate);                  // открытие файла для дозаписи
    if (!logFile.is_open()) {                                    // проверка корректности открытия файла
        throw runtime_error("Error: Failed to open the file!");  // исключение, если файл не удалось открыть
    }
}

logger::~logger() {           // деструктор для закрытия файла
    if (logFile.is_open()) {  // проверка, открыт ли файл
        logFile.close();      // закрытие файла
    }
}

void logger::choiceLogLevel(logLevel newLevel) {  // функция для установки уровня логирования
    level = newLevel;
}

void logger::logging(logLevel level, const string& message) {  // функция для логирования
    if (level < newLevel) {                                    // проверка соответствия минимальному уровню логирования
        return 0;
    }
    
    string fullLog = "Level: " + logLevelToString(level) + "; " + message + "\n";  // формирование строки для записи в лог
    
    cout << fullLog;                        // сообщение для отладки
    logFile << fullLog << logFile.flush();  // запись строки в файл
}