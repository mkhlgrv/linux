
```bash
rm -f /tmp/chat_user1_in
rm -f /tmp/chat_user1_out
rm -f /tmp/chat_user2_in
rm -f /tmp/chat_user2_out

mkfifo /tmp/chat_user1_in
mkfifo /tmp/chat_user1_out
mkfifo /tmp/chat_user2_in
mkfifo /tmp/chat_user2_out

ln -sf /tmp/chat_user1_out /tmp/chat_user2_in
ln -sf /tmp/chat_user2_out /tmp/chat_user1_in

# компиляция
g++ chat.cpp -o chat -pthread
# запуск

# терминал 1
./chat user1

# терминал 2
./chat user2
```
