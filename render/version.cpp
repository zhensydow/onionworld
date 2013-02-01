#include "version.h"

#include <boost/regex.hpp>
#include <cstdio>
#include <sstream>

namespace Render{
    Version::Version( const std::string &versionStr ){
        boost::regex vreg( "^([[:digit:]]+)\\.([[:digit:]]+)" );
        boost::match_results<std::string::const_iterator> what;

        this->mayor = 0;
        this->minor = 0;

        if( boost::regex_search( versionStr, what, vreg ) ){
            std::stringstream ss1( std::string(what[1].first, what[1].second) );
            std::stringstream ss2( std::string(what[2].first, what[2].second) );

            unsigned int i1, i2;
            if( not (ss1 >> i1).fail() ){
                this->mayor = i1;
            }

            if( not (ss2 >> i2).fail() ){
                this->minor = i2;
            }
        }
    }
}
