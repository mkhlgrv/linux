#include <iostream>
#include <thread>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <atomic>

class ChatClient {
private:
    std::string username_;
    int read_fd_;
    int write_fd_;
    std::atomic<bool> running_{true};

    void createFifo(const std::string& path) {
        // Создать FIFO с помощью mkfifo с правами доступа 0666
    }

    void readMessages() {
	    // Чтение:
        // 1. Создать буфер для чтения (1024 байта)
        // 2. В цикле while(running_) читать сообщения из read_fd_
        // 3. Если прочитали > 0 байт - вывести сообщение
        // 4. Добавить задержку в 100 мс (std::this_thread::sleep_for)
    }

    void writeMessages() {
        // Отправка:
        // 1. В цикле читать строки из std::cin
        // 2. Если введено "exit" - установить running_ = false и выйти
        // 3. Добавить к сообщению имя пользователя и \n
        // 4. Отправить сообщение в write_fd_
    }

public:
    ChatClient(const std::string& username, 
              const std::string& read_path, 
              const std::string& write_path) 
        : username_(username) {
        // 1. Создать FIFO для чтения и записи
        // 2. Открыть FIFO для чтения (O_RDONLY | O_NONBLOCK)
        // 3. Открыть FIFO для записи (O_WRONLY)
    }

    void start() {
        // 1. Создать и запустить поток для чтения
        // 2. Создать и запустить поток для записи
        // 3. Дождаться завершения потоков
    }

    ~ChatClient() {
        // Закрыть файловые дескрипторы
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <username>\n";
        return 1;
    }

    std::string username = argv[1];
    ChatClient client(username, 
                     "/tmp/chat_" + username + "_in",
                     "/tmp/chat_" + username + "_out");
    client.start();

    return 0;
}
