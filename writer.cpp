#include "shared_memory_chat.h"

#include <iostream>

#include <string>

  

using namespace boost::interprocess;

  

int main() {

    try {

        // Создаем разделяемую память

        shared_memory_object shm(create_only, "chat_memory", read_write);

        shm.truncate(sizeof(ChatMessage));

        mapped_region region(shm, read_write);

        ChatMessage* chat = static_cast<ChatMessage*>(region.get_address());

        chat->is_empty = true;

  

        // Создаем семафоры

        named_semaphore writer_sem(create_only, "writer_sem", 0);

        named_semaphore reader_sem(create_only, "reader_sem", 1);

  

        std::cout << "Чат запущен (пишущий процесс). Введите сообщения:\n";

        std::string input;

  

        while (true) {

            // Ждем читателя
	    //  ...
           

  

            // Читаем ввод пользователя в input
	    // ...
            

  

            if (input == "exit") {

                break;

            }

  

            // Копируем сообщение в разделяемую память

            strncpy(chat->message, input.c_str(), MAX_MESSAGE_LENGTH - 1);

            chat->message[MAX_MESSAGE_LENGTH - 1] = '\0';

            chat->is_empty = false;

  

            // Сигнализируем читателю
	    // ...
           

        }

  

        // Очистка

        shared_memory_object::remove("chat_memory");

        named_semaphore::remove("writer_sem");

        named_semaphore::remove("reader_sem");

    }

    catch (interprocess_exception& ex) {

        std::cerr << "Ошибка: " << ex.what() << std::endl;

        return 1;

    }

  

    return 0;

}
