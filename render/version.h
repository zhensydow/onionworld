//------------------------------------------------------------------------------
#ifndef RENDER_VERSION_H
#define RENDER_VERSION_H

//------------------------------------------------------------------------------
#include <string>

//------------------------------------------------------------------------------
namespace Render{
  class Version{
  public:
    Version( unsigned int ma = 0, unsigned int mi = 0 );
    Version( const std::string &versionStr );

    Version( const Version& v);

    bool operator == (const Version & v) const;
    bool operator != (const Version & v) const;

    unsigned int mayor;
    unsigned int minor;
  };

  inline Version::Version( const unsigned int ma, const unsigned int mi ){
      this->mayor = ma;
      this->minor = mi;
  }

  inline Version::Version( const Version & v ){
      this->mayor = v.mayor;
      this->minor = v.minor;
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
