#include "shared_memory_chat.h"
#include <iostream>

using namespace boost::interprocess;

  

int main() {

    try {

        // открываем open_only shared_memory
	// ...
        // mapping
	// ... 
        // указатель на чат

        // ...
  

        // открываем семафоры
        // ...
       
        // ...
  

        // сообщение о запуске reader
        // ...
  

        while (true) {

            // Ждем сообщение от писателя

	    // ...
            // Проверяем, есть ли сообщение

            if (!chat->is_empty) {

                std::cout << "Получено: " << chat->message << std::endl;
 
                chat->is_empty = true;

            }

  

            // Сигнализируем писателю

	    // ...           

        }

    }

    catch (interprocess_exception& ex) {

        std::cerr << "Ошибка: " << ex.what() << std::endl;

        return 1;

    }

  

    return 0;

}
