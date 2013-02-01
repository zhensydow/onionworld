//------------------------------------------------------------------------------
#ifndef RENDER_VERSION_H
#define RENDER_VERSION_H

//------------------------------------------------------------------------------
#include <string>

//------------------------------------------------------------------------------
namespace Render{
  class Version{
  public:
    Version( const std::string &versionStr );
    Version( unsigned int ma, unsigned int mi );

    bool operator == (const Version & v) const;
    bool operator != (const Version & v) const;

    unsigned int mayor;
    unsigned int minor;
  };

  inline Version::Version( const unsigned int ma, const unsigned int mi ){
      this->mayor = ma;
      this->minor = mi;
  }

  inline bool Version::operator ==(const Version & v) const{
      return ((this->mayor == v.mayor) and (this->minor == v.minor));
  }

  inline bool Version::operator !=(const Version & v) const{
      return (not ((*this) == v));
  }
}

//------------------------------------------------------------------------------
#endif//RENDER_VERSION_H

//------------------------------------------------------------------------------
