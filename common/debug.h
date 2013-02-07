#ifndef COMMON_DEBUG_H
#define COMMON_DEBUG_H

#include <QMessageBox>

#define str(A) #A
#define xstr(A) str(a)

#if defined(DEBUG)
#define oassert(EXPR) {                                                 \
        static bool ignore = false;                                     \
        if( !ignore && !(EXPR) ){                                       \
            QMessageBox msgBox;                                         \
            msgBox.setText("Assert: " #EXPR);                           \
            msgBox.setInformativeText(__FILE__ ":" xstr(__LINE__));     \
            msgBox.setStandardButtons( QMessageBox::Abort|QMessageBox::Yes|QMessageBox::YesAll ); \
            msgBox.setDefaultButton( QMessageBox::Ok );                 \
            int ret = msgBox.exec();                                    \
            switch(ret){                                                \
            case QMessageBox::Abort:                                    \
                exit( EXIT_FAILURE ); break;                            \
            case QMessageBox::YesAll:                                   \
                ignore = true; break;                                   \
            }                                                           \
        }                                                               \
    }
#elif defined(RELEASE)
#define oassert(EXPR)
#else
#error Unknown Build Type
#endif

#endif//COMMON_DEBUG_H
