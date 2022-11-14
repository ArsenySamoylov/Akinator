CMD_DEF (QUIT,      0, "Закончить",
                    {
                    GoodBye ();
                    })

CMD_DEF (GUESS,     1, "Гадать", 
                    {
                    Guess ((data_base.data_tree)->root);
                    })

CMD_DEF (SEARCH,    2, "Поиск",
                    {
                    // Search
                    })

CMD_DEF (COMPARE,   3, "Сравнить", 
                    {
                    // Compare
                    })

CMD_DEF (SHOW_BASE, 4, "Базу показать",
                    {
                    VisualDump (&data_base);
                    system ("xdg-open ./graphics/sample.png");
                    })


CMD_DEF (MEOW,      5, "Кот", 
                    {
                    system ("xdg-open https://youtu.be/unWZgBU4U10");
                    })

CMD_DEF (SHUT_DOWN, 6, "Выключить", 
                    {
                    assertlog (NULL, EOF, log("Turnig off the system\n"));
                    })
