#include "limagecharsetfixedcolor.h"

LImageCharsetFixedColor::LImageCharsetFixedColor(LColorList::Type t) : CharsetImage (t)
{
    Clear();
    m_type = LImage::Type::CharMapMultiColorFixed;

    m_colors.resize(40*25);

}

void LImageCharsetFixedColor::SetColor(uchar col, uchar idx)
{
    CharsetImage::SetColor(col,idx);
/*    if (idx==3)
        m_colors[m_currencChar] = col;
        */
}

void LImageCharsetFixedColor::SaveBin(QFile &file)
{
    file.write( ( char * )( &m_background ),  1 );
    file.write( ( char * )( &m_border ), 1 );
    file.write( ( char * )( &m_extraCols[1] ), 1 );
    file.write( ( char * )( &m_extraCols[2] ), 1 );
    file.write( ( char * )( &m_extraCols[3] ), 1 );
    file.write( ( char * )( &m_data ),  25*40*12 );
    for (int i=0;i<25*40;i++)
        m_colors[i] = m_data[i].c[3];

    file.write( m_colors );
}

void LImageCharsetFixedColor::LoadBin(QFile &file)
{
    file.read( ( char * )( &m_background ),1 );
    file.read( ( char * )( &m_border ), 1);
    file.read( ( char * )( &m_extraCols[1] ), 1 );
    file.read( ( char * )( &m_extraCols[2] ), 1 );
    file.read( ( char * )( &m_extraCols[3] ), 1 );
    file.read( ( char * )( &m_data ),  25*40*12 );
    m_colors = file.read( 25*40 );

    // Applycolors:
    for (int i=0;i<25*40;i++) {
        m_data[i].c[3] = m_colors[i];
    }
}

/*void LImageCharsetFixedColor::setPixel(int x, int y, unsigned int color)
{

}
*/
