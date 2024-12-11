```shell
# Компиляция

g++ signal_handler.cpp -o signal_handler
# Запуск
./signal_handler &

# Тестирование
kill -SIGUSR1 <PID>  
kill -SIGUSR2 <PID>  
kill -SIGTERM <PID>  
```
