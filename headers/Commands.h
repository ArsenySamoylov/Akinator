CMD_DEF (Quit,     0, "Закончить",
                    {
                    GoodBye ();
                    })

CMD_DEF (Guess,    1, "Гадать", 
                    {
                    // Guess ()
                    })

CMD_DEF (Search,   2, "Поиск",
                    {
                    // Search
                    })

CMD_DEF (Compare,    3, "Сравнить", 
                    {
                    // Compare
                    })

CMD_DEF (Base,     4, "Базу показать",
                    {
                    VisualDump (&data_base);
                    })


CMD_DEF (Cat,      5, "Кот", 
                    {
                    system ("xdg-open https://youtu.be/unWZgBU4U10");
                    })

CMD_DEF (ShutDown, 6, "Выключить", 
                    {
                    assertlog (NULL, EOF, log("Turnig off the system\n"));
                    })
