#include "face.h"

namespace RPC
{
Face::Face() : m_fg("default"), m_bg("default"), m_attributes()
{
}

Face::Face(Color fg, Color bg, QList<Attribute> attributes) : m_fg(fg), m_bg(bg), m_attributes(attributes)
{
}

Color Face::getFg() const
{
    return m_fg;
}

Color Face::getBg() const
{
    return m_bg;
}
} // namespace RPC
