#pragma once

class MemDC : public CDC 
{
    
public:

    MemDC(CDC* pDC, const CRect* pRect = NULL);

    ~MemDC();
   

    MemDC* operator->() { return this; }
  
    operator MemDC* () { return this; }

private:
    CBitmap m_bitmap;
    CBitmap* m_oldBitmap;
    CDC* m_pDC;
    CRect m_rect;
    BOOL  m_bMemDC;

};