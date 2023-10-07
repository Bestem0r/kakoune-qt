#include "atom.hpp"

namespace RPC
{
Atom::Atom(Face face, QString contents) : m_face(face), m_contents(contents)
{
}

QString Atom::getContents()
{
    return m_contents;
}

void Atom::draw(const DrawContext &context, const QPoint &position, const Face &default_face)
{
    QColor fg = m_face.getFg().toQColor(default_face.getFg());
    QColor bg = m_face.getBg().toQColor(default_face.getBg());

    int inf = 999;

    context.painter.setPen(fg);
    context.painter.fillRect(position.x(), position.y(), context.cell_size.width() * m_contents.size(),
                             context.cell_size.height(), bg);
    context.painter.drawText(QRect(position.x(), position.y(), inf, inf), Qt::AlignTop, m_contents);
}
} // namespace RPC
