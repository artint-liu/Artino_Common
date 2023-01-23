#ifndef _FONT_H_
#define _FONT_H_

namespace Artint_HZK
{
  struct BITMAPFONT
  {
    const uint8_t* data;
    uint8_t width;
    uint8_t height;
  };

  class BitmapFont
  {
  protected:
    //const uint8_t* m_pData;
  public:
    virtual int8_t Query(const char* pText, size_t len, BITMAPFONT* pFont) = 0;
  };



  class BitmapFont_HZK16 : public BitmapFont
  {
  public:
    virtual int8_t Query(const char* pText, size_t len, BITMAPFONT* pFont);
  };

  class BitmapFont_ASC16 : public BitmapFont
  {
  public:
    virtual int8_t Query(const char* pText, size_t len, BITMAPFONT* pFont);
  };

  class BitmapFont_NUM32 : public BitmapFont
  {
  public:
    virtual int8_t Query(const char* pText, size_t len, BITMAPFONT* pFont);
  };

  extern BitmapFont_HZK16 hzk16;
  extern BitmapFont_ASC16 asc16;
  extern BitmapFont_NUM32 num32;
}

#endif // _FONT_H_