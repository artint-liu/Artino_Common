#pragma once

namespace Artino
{
    struct MENU_ITEM
    {
        const char* text;
    };

    enum MenuKey
    {
        MenuKey_None,
        MenuKey_Down,
        MenuKey_Up,
        MenuKey_Confirm,
    };

    class Menu
    {
        const MENU_ITEM* m_items;
        uint16_t m_count;
        //uint16_t m_select;

    public:
        Menu(const MENU_ITEM* items, uint16_t count)
            : m_items(items)
            , m_count(count)
        {
        }

        uint8_t Loop()
        {
            MenuKey key = MenuKey_None;
            const uint16_t font_height = 16;
            int16_t select = 0;
            while (key != MenuKey_Confirm)
            {
                for (uint16_t i = 0; i < m_count; i++)
                {
                    OnDrawItem(0, font_height * i, m_items[i].text, select == i);
                }

                key = GetKey();
                if (key == MenuKey_Up)
                {
                    select--;
                    if (select < 0)
                    {
                        select = 0;
                    }
                }
                else if (key == MenuKey_Down)
                {
                    select++;
                    if (select >= m_count)
                    {
                        select = m_count - 1;
                    }
                }
                else if (key == MenuKey_Confirm)
                {
                    break;
                }
            }
            return select;
        }

        virtual MenuKey GetKey() = 0;
        virtual void OnDrawItem(int x, int y, const char* text, bool selected) = 0;
    };
}