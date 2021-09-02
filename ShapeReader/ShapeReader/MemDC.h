#pragma once

class MemDC : public CDC 
{
private:
    CBitmap    m_bitmap;        // Offscreen bitmap
    CBitmap* m_oldBitmap; // bitmap originally found in CMemDC
    CDC* m_pDC;           // Saves CDC passed in constructor
    CRect      m_rect;          // Rectangle of drawing area.
    BOOL       m_bMemDC;        // TRUE if CDC really is a Memory DC.
public:

    MemDC(CDC* pDC, const CRect* pRect = NULL);

    ~MemDC();
   

    MemDC* operator->() { return this; }
  
    operator MemDC* () { return this; }

};