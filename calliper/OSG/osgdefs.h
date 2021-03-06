#ifndef OSGDEFS_H
#define OSGDEFS_H

#include <QMouseEvent>
#include <QtDebug>
#include <osg/Matrixd>

namespace OSGDefs
{
    // Why on earth OSG doesn't actually enum these I don't know.
    enum MouseButton
    {
        NoButton = 0,
        LeftButton = 1,
        MiddleButton = 2,
        RightButton = 3
    };

    MouseButton QtToOSGMouseButton(Qt::MouseButton button);
    Qt::MouseButton OSGToQtMouseButton(MouseButton button);
}

static inline QDebug operator<<(QDebug stream, const osg::Vec2f& vec)
{
    QDebugStateSaver stateSaver(stream);
    stream.noquote() << QString("Vec2f(%0,%1)").arg(vec[0]).arg(vec[1]);
    return stream;
}

static inline QDebug operator<<(QDebug stream, const osg::Vec2d& vec)
{
    QDebugStateSaver stateSaver(stream);
    stream.noquote() << QString("Vec2d(%0,%1)").arg(vec[0]).arg(vec[1]);
    return stream;
}

static inline QDebug operator<<(QDebug stream, const osg::Vec3f& vec)
{
    QDebugStateSaver stateSaver(stream);
    stream.noquote() << QString("Vec3f(%0,%1,%2)").arg(vec[0]).arg(vec[1]).arg(vec[2]);
    return stream;
}

static inline QDebug operator<<(QDebug stream, const osg::Vec3d& vec)
{
    QDebugStateSaver stateSaver(stream);
    stream.noquote() << QString("Vec3d(%0,%1,%2)").arg(vec[0]).arg(vec[1]).arg(vec[2]);
    return stream;
}

static inline QDebug operator <<(QDebug stream, const osg::Matrixd& mat)
{
    QDebugStateSaver stateSaver(stream);
    stream.noquote() << QString("Matrixd(\n")
                     << QString(" %0,%1,%2,%3\n").arg(mat(0,0)).arg(mat(0,1)).arg(mat(0,2)).arg(mat(0,3))
                     << QString(" %0,%1,%2,%3\n").arg(mat(1,0)).arg(mat(1,1)).arg(mat(1,2)).arg(mat(1,3))
                     << QString(" %0,%1,%2,%3\n").arg(mat(2,0)).arg(mat(2,1)).arg(mat(2,2)).arg(mat(2,3))
                     << QString(" %0,%1,%2,%3\n").arg(mat(3,0)).arg(mat(3,1)).arg(mat(3,2)).arg(mat(3,3))
                     << QString(")");
    return stream;
}

#endif // OSGDEFS_H
