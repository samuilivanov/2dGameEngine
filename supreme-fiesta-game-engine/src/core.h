#ifndef CORE_H
#define CORE_H

#include <QtCore/qglobal.h>

#if defined(SUPREMEFIESTAGAMEENGINE_LIBRARY)
#  define SFGE_API Q_DECL_EXPORT
#else
#  define SFGE_API Q_DECL_IMPORT
#endif

#endif // CORE_H
