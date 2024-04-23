#include <stdio.h>
#include <tgbot/tgbot.h>
#include <locale>


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    TgBot::Bot bot("7006433103:AAGmJU1DGdxUrLQ31OdzluHaADTN-oSceBk");



    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hello, enter the day of the week, and I will send the current schedule for you (ISIP-923 groups).");

        });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {

        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        else if (StringTools::startsWith(message->text, "monday")) {
            bot.getApi().sendMessage(message->chat->id, "1. 08:30-10:00. Pestov Alexander Igorevich - 309a cl.hour\n\n2. 10:10-11:40. Azovtseva Vera Vladimirovna - 202\n\n3. 12:20-13:13-50. Kirill Yurievich Ninkin - 212\n\n4. 14:00-15:30. Radionova Natalia Vladimirovna - 211\n\n5. 15:50-17:20. Vorobyov Ivan Stanislavovich - 210");
            return;
        }
        else if (StringTools::startsWith(message->text, "tuesday")) {
            bot.getApi().sendMessage(message->chat->id, "1. 8:30-10:00. Botalova Nadezhda Fedorovna - 210 / Luxurious Olga Vladimirovna - 213\n\n2. 10:10-11:40. Anna Vasilyevna Parfenova - 205\n\n3. 12:20-13:13-50. Azovtseva Vera Vladimirovna - 202a\n\n4. 14:00-15:30. Anna Vasilyevna Parfenova - 205");
            return;
        }
        else if (StringTools::startsWith(message->text, "wednesday")) {
            bot.getApi().sendMessage(message->chat->id, "2. 10:10-11:40. Vorobyov Ivan Stanislavovich - 210\n\n3. 12:20-13:13-50. Radionova Natalia Vladimirovna - 211\n\n4. 14:00-15:30. Azovtseva Vera Vladimirovna - 202a");
            return;
        }
        else if (StringTools::startsWith(message->text, "thursday")) {
            bot.getApi().sendMessage(message->chat->id, "1. 08:30-10:00. Leshtaeva Daria Denisovna - 111 / Ninkin Kirill Yurievich - 212\n\n2. 10:10-11:40. Azovtseva Vera Vladimirovna - 202\n\n3. 12:20-13:13-50. Doctors Andrey Alekseevich - 305\n\n4. 14:00-15:30. Anton Andreevich Tomilov - sports hall");
            return;
        }
        else if (StringTools::startsWith(message->text, "friday")) {
            bot.getApi().sendMessage(message->chat->id, "2. 10:10-11:40. Vorobyov Ivan Stanislavovich - 210\n\n3. 12:20-13:13-50. Commander Alla Valeryevna - 215\n\n4. 14:00-15:30. Leshtaeva Daria Denisovna - 111 / Chakova Valeria Alexandrovna - 129");
            return;
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "I dont't know!");
        }
        

        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}