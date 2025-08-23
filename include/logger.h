#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum logLevel {  // объявление перечисления для задания уровней логгирования
    INFO,
    WARNING,
    ERROR
};

class logger {
public:
    logger(const string& filename, logLevel level);  // конструктор
    ~logger();                                       // деструктор 

    void choiceLogLevel(logLevel newLevel);               // функция для изменения уровня логирования
    void logging(logLevel level, const string& message);  // функция для логирования сообщений
    
private:
    ofstream logFile;  // поток для записи логов в файл
    logLevel level;    // уровень логирования
};