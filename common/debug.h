//------------------------------------------------------------------------------
#ifndef COMMON_DEBUG_H
#define COMMON_DEBUG_H

//------------------------------------------------------------------------------
#define str(A) #A
#define xstr(A) str(A)

//------------------------------------------------------------------------------
#if defined(DEBUG)
#if defined(QT_VERSION)
#include <QMessageBox>
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
#else
#include <iostream>
#define oassert(EXPR) {                                                 \
        static bool ignore = false;                                     \
        if( !ignore && !(EXPR) ){                                       \
            std::cout << "Assert: " #EXPR << std::endl;                 \
            std::cout << __FILE__ ":" xstr(__LINE__) << std::endl;      \
            std::cout << "(b)reak, (i)gnore, ignore (a)lways? ";        \
            char ret;                                                   \
            std::cin >> ret;                                            \
            switch(ret){                                                \
            case 'b':                                                   \
            case 'B':                                                   \
                exit( EXIT_FAILURE ); break;                            \
            case 'a':                                                   \
            case 'A':                                                   \
                ignore = true; break;                                   \
            }                                                           \
        }                                                               \
    }
#endif//QT_VERSION

//------------------------------------------------------------------------------
#elif defined(RELEASE)
#define oassert(EXPR)

//------------------------------------------------------------------------------
#else
#error Unknown Build Type
#endif

//------------------------------------------------------------------------------
#endif//COMMON_DEBUG_H

//------------------------------------------------------------------------------
