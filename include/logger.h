#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum logLevel {  // объявление перечисления для задания уровней логирования
    INFO,
    WARNING,
    ERROR
};

class logger {
public:
    logger(const string& filename, logLevel level);  // конструктор
    ~logger();                                       // деструктор 

    void choiceLogLevel(logLevel newLevel);               // метод для изменения уровня логирования
    void logging(logLevel level, const string& message);  // метод для логирования сообщений
    
    void info(const string& message);     // вспомогательный метод для info
    void warning(const string& message);  // вспомогательный метод для warning
    void error(const string& message);    // вспомогательный метод для error
    
private:
    ofstream logFile;  // поток для записи логов в файл
    logLevel level;    // уровень логирования
    string GetTime();  // время для записи в лог
};