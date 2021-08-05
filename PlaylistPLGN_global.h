#ifndef PLAYLISTPLGN_GLOBAL_H
#define PLAYLISTPLGN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLAYLISTPLGN_LIBRARY)
#  define PLAYLISTPLGN_EXPORT Q_DECL_EXPORT
#else
#  define PLAYLISTPLGN_EXPORT Q_DECL_IMPORT
#endif

#endif // PLAYLISTPLGN_GLOBAL_H
