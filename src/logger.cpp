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

logger::logger(const string& filename, logLevel level) {         // конструктор для инициализации потока и установки уровня логирования
    logFile.open(filename, ios::app, ios::ate);                  // открытие файла в режиме дозаписи
    if (!logFile.is_open()) {                                    // проверка корректности открытия файла
        throw runtime_error("Error: Failed to open the file!");  // исключение, если файл не удалось открыть
    }
}

logger::~logger() {           // деструктор для закрытия файла
    if (logFile.is_open()) {  // проверка, открыт ли файл
        logFile.close();      // закрытие файла
    }
}

void logger::choiceLogLevel(logLevel newLevel) {  // метод для установки уровня логирования
    level = newLevel;
}

void logger::logging(logLevel level, const string& message) {  // основной метод логирования
    if (level < newLevel) {                                    // проверка соответствия минимальному уровню логирования
        return 0;
    }
    
    string fullLog = "Level: " + logLevelToString(level) + "; " + message + "\n";  // формирование строки для записи в лог
    
    cout << fullLog;                        // сообщение для отладки
    logFile << fullLog << logFile.flush();  // запись строки в файл
}

void logger::info(const string& message) {     // вспомогательный метод для вызова logging с нужным уровнем логирования (info)
    logging(logLevel::INFO, message);
}

void logger::warning(const string& message) {  // вспомогательный метод для вызова logging с нужным уровнем логирования (warning)
    logging(logLevel::WARNING, message);
}

void logger::error(const string& message) {    // вспомогательный метод для вызова logging с нужным уровнем логирования (error)
    logging(logLevel::ERROR, message);
}