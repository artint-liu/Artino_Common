#pragma once

namespace Artino
{
    struct MENU_ITEM
    {
        const char* text;
    };

    struct RECT
    {
        int16_t left;
        int16_t top;
        int16_t right;
        int16_t bottom;
    };

    enum MenuKey
    {
        MenuKey_None,
        MenuKey_Down,
        MenuKey_Up,
        MenuKey_PageDown,
        MenuKey_PageUp,
        MenuKey_Confirm,
    };

    template<class MenuItemT>
    class Menu
    {
        const MenuItemT* m_items;
        uint16_t m_count;
        uint8_t m_item_height;
        RECT m_rect;
        //uint16_t m_select;

    public:
        Menu(const MenuItemT* items, uint16_t count, uint8_t item_height, const RECT* lprc)
            : m_items(items)
            , m_count(count)
            , m_item_height(item_height)
            , m_rect(*lprc)
        {
        }

        uint16_t Loop()
        {
            MenuKey key = MenuKey_None;
            const uint16_t font_height = m_item_height;
            int16_t select = 0;
            int16_t topindex = 0;

            while (key != MenuKey_Confirm)
            {
                int16_t y = m_rect.top - font_height * topindex;
                OnBeginDrawItem();
                for (uint16_t i = 0; i < m_count; i++, y += font_height)
                {
                    if (y + font_height < m_rect.top)
                    {
                        continue;
                    }
                    else if(y > m_rect.bottom)
                    {
                        break;
                    }
                    OnDrawItem(m_rect.left, y, m_items + i, select == i);
                }
                OnEndDrawItem();

                key = GetKey();
                if (key == MenuKey_Up)
                {
                    select--;
                    if (select < 0)
                    {
                        select = 0;
                    }
                    if (select < topindex)
                    {
                      topindex = select;
                    }
                }
                else if (key == MenuKey_Down)
                {
                    select++;
                    if (select >= m_count)
                    {
                        select = m_count - 1;
                    }

                    if ((select - topindex + 1) * font_height > m_rect.bottom)
                    {
                      topindex = select - (m_rect.bottom - m_rect.top) / font_height + 1;
                    }
                }
                else if (key == MenuKey_PageUp)
                {
                    select -= (m_rect.bottom - m_rect.top) / m_item_height;
                    if (select < 0)
                    {
                        select = 0;
                    }
                    if (select < topindex)
                    {
                        topindex = select;
                    }
                }
                else if (key == MenuKey_PageDown)
                {
                    select += (m_rect.bottom - m_rect.top) / m_item_height;
                    if (select >= m_count)
                    {
                        select = m_count - 1;
                    }
                    if ((select - topindex + 1) * font_height > m_rect.bottom)
                    {
                        topindex = select - (m_rect.bottom - m_rect.top) / font_height + 1;
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
        virtual void OnDrawItem(int16_t x, int16_t y, const MenuItemT* pItem, bool selected) = 0;
        virtual void OnBeginDrawItem() {}
        virtual void OnEndDrawItem() {}
    };
}